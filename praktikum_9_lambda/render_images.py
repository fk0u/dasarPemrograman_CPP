import os
import subprocess
from PIL import Image
import pygments
from pygments.lexers import CppLexer
from pygments.formatters import HtmlFormatter

BASE_DIR = '/Users/kou/Project/dasarPemrograman_CPP/praktikum_9'
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

/* Custom Token Styling matching Material Pale Night */
.c, .c1, .cm { color: #676e95; font-style: italic; }
.k, .kd, .kn, .kp, .kr { color: #c792ea; font-weight: 500; }
.kt { color: #ffcb6b; font-weight: 500; }
.s, .s1, .s2 { color: #c3e88d; }
.mi, .mf, .mh, .il { color: #f78c6c; }
.nb { color: #82aaff; }
.nf { color: #82aaff; }
.p, .o { color: #89ddff; }
.cp { color: #c792ea; }

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
        '--window-size=1800,2400',
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

def make_terminal_card(title, command, output):
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
          <span class="prompt-path">praktikum_9</span>
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
        "id": "9_1",
        "file": "9_1.cpp",
        "title": "9_1.cpp — Cube Volume Function",
        "term_title": "zsh — clang++ 9_1.cpp & ./9_1",
        "compile_cmd": "clang++ -std=c++17 9_1.cpp -o 9_1 && ./9_1",
        "run_cmd": "./9_1"
    },
    {
        "id": "9_2",
        "file": "9_2.cpp",
        "title": "9_2.cpp — Function without Return Value (void)",
        "term_title": "zsh — clang++ 9_2.cpp & ./9_2",
        "compile_cmd": "clang++ -std=c++17 9_2.cpp -o 9_2 && ./9_2",
        "run_cmd": "./9_2"
    },
    {
        "id": "9_3",
        "file": "9_3.cpp",
        "title": "9_3.cpp — Function with Default Value Parameter",
        "term_title": "zsh — clang++ 9_3.cpp & ./9_3",
        "compile_cmd": "clang++ -std=c++17 9_3.cpp -o 9_3 && ./9_3",
        "run_cmd": "./9_3"
    },
    {
        "id": "9_4",
        "file": "9_4.cpp",
        "title": "9_4.cpp — Prototype Function",
        "term_title": "zsh — clang++ 9_4.cpp & ./9_4",
        "compile_cmd": "clang++ -std=c++17 9_4.cpp -o 9_4 && ./9_4",
        "run_cmd": "./9_4"
    },
    {
        "id": "9_5",
        "file": "9_5.cpp",
        "title": "9_5.cpp — Lambda Exercise I",
        "term_title": "zsh — clang++ 9_5.cpp & ./9_5",
        "compile_cmd": "clang++ -std=c++17 9_5.cpp -o 9_5 && ./9_5",
        "run_cmd": "./9_5"
    },
    {
        "id": "9_6",
        "file": "9_6.cpp",
        "title": "9_6.cpp — Lambda Exercise II (Capture vs Parameter)",
        "term_title": "zsh — clang++ 9_6.cpp & ./9_6",
        "compile_cmd": "clang++ -std=c++17 9_6.cpp -o 9_6 && ./9_6",
        "run_cmd": "./9_6"
    },
    {
        "id": "9_7",
        "file": "9_7.cpp",
        "title": "9_7.cpp — Individual Task (Recursion as Loop)",
        "term_title": "zsh — clang++ 9_7.cpp & ./9_7",
        "compile_cmd": "clang++ -std=c++17 9_7.cpp -o 9_7 && ./9_7",
        "run_cmd": "./9_7"
    }
]

for task in TASKS:
    cpp_path = os.path.join(BASE_DIR, task["file"])
    with open(cpp_path, 'r', encoding='utf-8') as f:
        code = f.read().strip()
    
    code_html = make_code_card(task["title"], code)
    code_png = os.path.join(ASSETS_DIR, f"code_{task['id']}.png")
    render_html_to_png(code_html, code_png)
    
    res = subprocess.run(task["compile_cmd"], shell=True, cwd=BASE_DIR, capture_output=True, text=True)
    out_text = res.stdout.strip()
    
    term_html = make_terminal_card(task["term_title"], task["run_cmd"], out_text)
    term_png = os.path.join(ASSETS_DIR, f"output_{task['id']}.png")
    render_html_to_png(term_html, term_png)

print("All code and output images for Praktikum 9 generated successfully!")

