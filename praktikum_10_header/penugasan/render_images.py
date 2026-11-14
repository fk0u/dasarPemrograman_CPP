import os
import subprocess
from PIL import Image
import pygments
from pygments.lexers import CppLexer
from pygments.formatters import HtmlFormatter

BASE_DIR = os.path.dirname(os.path.abspath(__file__))
ASSETS_DIR = os.path.join(BASE_DIR, 'assets')
os.makedirs(ASSETS_DIR, exist_ok=True)

CHROME_BIN = '/Applications/Google Chrome.app/Contents/MacOS/Google Chrome'

CSS_TEMPLATE = '''
@import url('https://fonts.googleapis.com/css2?family=Fira+Code:wght@400;500;600&display=swap');

* {
    box-sizing: border-box;
}

html, body {
    margin: 0;
    padding: 0;
    background: transparent;
    font-family: 'Fira Code', 'JetBrains Mono', Menlo, Monaco, Consolas, monospace;
}

.card-container {
    display: inline-block;
    padding: 38px 44px;
    background: #8e9ea9;
    border-radius: 16px;
    overflow: hidden;
}

.window {
    background: #232738;
    border-radius: 12px;
    box-shadow: 0 20px 45px rgba(0, 0, 0, 0.4);
    min-width: 680px;
    width: max-content;
}

.header {
    background: #1c1e2b;
    padding: 13px 20px;
    display: flex;
    align-items: center;
    border-top-left-radius: 12px;
    border-top-right-radius: 12px;
}

.traffic-lights {
    display: flex;
    gap: 8px;
}

.dot {
    width: 12px;
    height: 12px;
    border-radius: 50%;
}

.dot.red { background: #ff5f56; }
.dot.yellow { background: #ffbd2e; }
.dot.green { background: #27c93f; }

.title {
    color: #8c93a8;
    font-size: 13.5px;
    font-weight: 500;
    margin: 0 auto;
    transform: translateX(-18px);
}

.editor-body {
    padding: 22px 26px;
    font-size: 14.5px;
    line-height: 1.62;
}

table.highlighttable {
    border-spacing: 0;
    width: auto;
}

td.linenos {
    text-align: right;
    padding-right: 18px;
    color: #555b77;
    user-select: none;
    border-right: 1px solid rgba(255, 255, 255, 0.08);
    font-size: 14px;
}

td.code {
    padding-left: 20px;
    white-space: pre;
}

pre {
    margin: 0;
    font-family: inherit;
    color: #cdd3de;
    white-space: pre;
}

/* Material Pale Night */
.c, .c1, .cm { color: #676e95; font-style: italic; }
.k, .kd, .kn, .kp, .kr { color: #c792ea; font-weight: 500; }
.kt { color: #ffcb6b; font-weight: 500; }
.s, .s1, .s2 { color: #c3e88d; }
.mi, .mf, .mh, .il { color: #f78c6c; }
.nb { color: #82aaff; }
.nf { color: #82aaff; }
.p, .o { color: #89ddff; }
.cp { color: #c792ea; }
.cpf { color: #c3e88d; }

/* Terminal Specific Styles */
.terminal-window {
    background: #181a24;
}

.terminal-body {
    padding: 22px 26px;
    font-size: 14.5px;
    line-height: 1.65;
    color: #e2e8f0;
}

.prompt-line {
    margin-bottom: 14px;
    white-space: nowrap;
}

.prompt-symbol {
    color: #4ade80;
    font-weight: bold;
}

.prompt-path {
    color: #38bdf8;
    font-weight: bold;
}

.prompt-git {
    color: #f472b6;
    margin: 0 4px;
}

.prompt-cmd {
    color: #f8fafc;
    font-weight: 600;
}

.term-output {
    color: #cbd5e1;
    white-space: pre;
    line-height: 1.6;
}
'''


def render_html_to_png(html_content, output_png):
    temp_html = output_png.replace('.png', '.html')
    with open(temp_html, 'w', encoding='utf-8') as f:
        f.write(html_content)

    cmd = [
        CHROME_BIN,
        '--headless',
        '--disable-gpu',
        f'--screenshot={output_png}',
        '--window-size=1800,3200',
        '--hide-scrollbars',
        '--default-background-color=00000000',
        temp_html
    ]
    subprocess.run(cmd, check=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)

    im = Image.open(output_png)
    bbox = im.getbbox()
    if bbox:
        cropped = im.crop(bbox)
        cropped.save(output_png)

    if os.path.exists(temp_html):
        os.remove(temp_html)
    print(f"Generated: {output_png} ({im.size if not bbox else cropped.size})")


def make_code_card(title, code):
    formatter = HtmlFormatter(style='material', linenos=True, cssclass='codehilite')
    highlighted = pygments.highlight(code, CppLexer(), formatter)

    return f'''<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<style>
{CSS_TEMPLATE}
</style>
</head>
<body>
  <div class="card-container">
    <div class="window">
      <div class="header">
        <div class="traffic-lights">
          <div class="dot red"></div>
          <div class="dot yellow"></div>
          <div class="dot green"></div>
        </div>
        <div class="title">{title}</div>
      </div>
      <div class="editor-body">
        {highlighted}
      </div>
    </div>
  </div>
</body>
</html>'''


def make_terminal_card(title, folder, command, output):
    output_escaped = output.replace('&', '&amp;').replace('<', '&lt;').replace('>', '&gt;')
    return f'''<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<style>
{CSS_TEMPLATE}
</style>
</head>
<body>
  <div class="card-container">
    <div class="window terminal-window">
      <div class="header">
        <div class="traffic-lights">
          <div class="dot red"></div>
          <div class="dot yellow"></div>
          <div class="dot green"></div>
        </div>
        <div class="title">{title}</div>
      </div>
      <div class="terminal-body">
        <div class="prompt-line">
          <span class="prompt-symbol">➜</span>
          <span class="prompt-path">{folder}</span>
          <span class="prompt-git">git:(main)</span>
          <span class="prompt-cmd">{command}</span>
        </div>
        <div class="term-output">{output_escaped}</div>
      </div>
    </div>
  </div>
</body>
</html>'''


TASKS = [
    {
        "id": "10_1",
        "dir": "test_10_1",
        "files": [
            ("h", "cylinder.h", "test_10_1/cylinder.h — Header File"),
            ("cpp", "cylinder.cpp", "test_10_1/cylinder.cpp — Source File"),
            ("main", "main.cpp", "test_10_1/main.cpp — Main Program"),
        ],
        "term_title": "zsh — clang++ main.cpp cylinder.cpp -o main && ./main",
        "compile_cmd": "clang++ -std=c++17 main.cpp cylinder.cpp -o main && ./main",
        "stdin": None,
        "display_input": None,
    },
    {
        "id": "10_2",
        "dir": "test_10_2",
        "files": [
            ("h", "square.h", "test_10_2/square.h — Header File"),
            ("cpp", "square.cpp", "test_10_2/square.cpp — Source File"),
            ("main", "main.cpp", "test_10_2/main.cpp — Main Program"),
        ],
        "term_title": "zsh — clang++ main.cpp square.cpp -o main && ./main",
        "compile_cmd": "clang++ -std=c++17 main.cpp square.cpp -o main && ./main",
        "stdin": "5\n",
        "display_input": ("Enter the length of the side: ", "Enter the length of the side: 5\n"),
    },
    {
        "id": "10_3",
        "dir": "test_10_3",
        "files": [
            ("h", "arithmetic.h", "test_10_3/arithmetic.h — Header File"),
            ("cpp", "arithmetic.cpp", "test_10_3/arithmetic.cpp — Source File"),
            ("main", "main.cpp", "test_10_3/main.cpp — Main Program (Fixed)"),
        ],
        "term_title": "zsh — clang++ main.cpp arithmetic.cpp -o main && ./main",
        "compile_cmd": "clang++ -std=c++17 main.cpp arithmetic.cpp -o main && ./main",
        "stdin": None,
        "display_input": None,
    },
    {
        "id": "10_4",
        "dir": "test_10_4",
        "files": [
            ("h", "conversion.h", "test_10_4/conversion.h — Header File"),
            ("cpp", "conversion.cpp", "test_10_4/conversion.cpp — Source File"),
            ("main", "main.cpp", "test_10_4/main.cpp — Main Program"),
        ],
        "term_title": "zsh — clang++ main.cpp conversion.cpp -o main && ./main",
        "compile_cmd": "clang++ -std=c++17 main.cpp conversion.cpp -o main && ./main",
        "stdin": "212\nF\nK\n",
        "display_input": (
            "Enter Temperature        : Source Scale (C / F / K) : Target Scale (C / F / K) : ",
            "Enter Temperature        : 212\nSource Scale (C / F / K) : F\nTarget Scale (C / F / K) : K\n",
        ),
    },
    {
        "id": "10_5",
        "dir": "test_10_5",
        "files": [
            ("h", "geometry.h", "test_10_5/geometry.h — Header File"),
            ("cpp", "geometry.cpp", "test_10_5/geometry.cpp — Source File"),
            ("main", "main.cpp", "test_10_5/main.cpp — Main Program"),
        ],
        "term_title": "zsh — clang++ main.cpp geometry.cpp -o main && ./main",
        "compile_cmd": "clang++ -std=c++17 main.cpp geometry.cpp -o main && ./main",
        "stdin": None,
        "display_input": None,
    },
]

for task in TASKS:
    task_dir = os.path.join(BASE_DIR, task["dir"])
    for suffix, fname, title in task["files"]:
        fpath = os.path.join(task_dir, fname)
        with open(fpath, 'r', encoding='utf-8') as f:
            code = f.read().strip()
        code_html = make_code_card(title, code)
        code_png = os.path.join(ASSETS_DIR, f"code_{task['id']}_{suffix}.png")
        render_html_to_png(code_html, code_png)

    res = subprocess.run(
        task["compile_cmd"],
        shell=True,
        cwd=task_dir,
        input=task["stdin"],
        capture_output=True,
        text=True,
        check=True,
    )
    out_text = res.stdout.strip()
    if task["display_input"] is not None:
        raw_prompt, formatted_prompt = task["display_input"]
        out_text = out_text.replace(raw_prompt, formatted_prompt)

    term_html = make_terminal_card(task["term_title"], task["dir"], task["compile_cmd"], out_text)
    term_png = os.path.join(ASSETS_DIR, f"output_{task['id']}.png")
    render_html_to_png(term_html, term_png)

print("All code and output images for Praktikum 10 generated successfully!")
