LAPORAN PRAKTIKUM 3: BASIC DATA TYPES

Basic Programming Practicum (INF1053)

Program Studi: Teknik Informatika

Fakultas: Sains & Teknologi

Universitas Muhammadiyah Kalimantan Timur

Kota: Samarinda, 2025

Nama: Al-Ghani Desta Setyawan

NIM: 2611102441026

Main Topic

Basic Data Types in C++

Learning Objective

Implement and manipulate basic data types, arithmetic operations, library functions (<cmath>, <string>, <typeinfo>), and type casting mechanisms in C++.

1. Exercise 3.1: Arithmetic Operations on Numeric Data Types

Problem Statement

Fix the provided C++ program by addressing:

Variable naming inconsistencies (e.g., using num_1 / num_2 when variables were declared as num1 and num2).

Missing statement terminators (semicolons ; after calls to max(), min(), and round()).

Correct calculation of addition, subtraction, multiplication, explicit double division, modulus, max, min, and rounded division.

Fixed C++ Source Code

#include <iostream>
#include <cmath> // Required for max(), min(), round()

using namespace std;

int main() {
// User input
int num1;
int num2;
cout << "Enter the first number: ";
cin >> num1;
cout << "Enter the second number: ";
cin >> num2;

    // Arithmetic operations
    int addition = num1 + num2;
    int subtraction = num1 - num2;
    int multiplication = num1 * num2;
    double division = (double)num1 / num2; // Explicit casting to avoid integer division
    int modulus = num1 % num2;

    // Other operations using <cmath> and standard algorithms
    int maximum = max(num1, num2);
    int minimum = min(num1, num2);
    double rounded_division = round(division);

    // Output results
    cout << "Addition Result: " << addition << endl;
    cout << "Subtraction Result: " << subtraction << endl;
    cout << "Multiplication Result: " << multiplication << endl;
    cout << "Division Result: " << division << endl;
    cout << "Modulus Result: " << modulus << endl;
    cout << "Maximum Number: " << maximum << endl;
    cout << "Minimum Number: " << minimum << endl;
    cout << "Rounded Division: " << rounded_division << endl;

    return 0;

}

Example Input & Output

Input:

Enter the first number: 25
Enter the second number: 7

Output:

Addition Result: 32
Subtraction Result: 18
Multiplication Result: 175
Division Result: 3.57143
Modulus Result: 4
Maximum Number: 25
Minimum Number: 7
Rounded Division: 4

Explanation 3.1

Syntax & Naming Corrections: Fixed variable identifier mismatches from num_1 and num_2 to num1 and num2. Added missing semicolons ; at lines 24–26.

Arithmetic Logic:

Addition ($num1 + num2$), Subtraction ($num1 - num2$), Multiplication ($num1 \times num2$), and Modulus ($num1 \pmod{num2}$).

Division uses explicit type casting (double)num1 / num2 to ensure float division rather than truncating integer division.

Built-in Functions: max() finds $\max(num1, num2)$, min() finds $\min(num1, num2)$, and round() rounds the floating-point quotient to the nearest integer.

2. Exercise 3.2: Functions on Numeric Data (<cmath>)

Problem Statement

Fix the program to take dynamic input from the user for num1 and num2 of type double, and compute:

Exponentiation: $num1^{num2}$ using pow(num1, num2)

Absolute Value: $\vert{}-num1\vert{}$ using fabs(-num1)

Rounding: $\text{round}(num2)$ using round(num2)

Fixed C++ Source Code

#include <iostream>
#include <cmath> // Required for pow(), fabs(), round()

using namespace std;

int main() {
double num1, num2;

    // User input initialization
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;

    // Calculate the power: num1 ^ num2
    double powerResult = pow(num1, num2);

    // Calculate the absolute value of -num1
    double absoluteValue = fabs(-num1);

    // Round num2 to the nearest integer
    double roundNumber = round(num2);

    // Output formatted results
    cout << "Power Result: " << powerResult << endl;
    cout << "Absolute Value: " << absoluteValue << endl;
    cout << "Rounded Value: " << roundNumber << endl;

    return 0;

}

Example Input & Output

Input:

Enter the first number: 5.69
Enter the second number: 3.14159

Output:

Power Result: 235.642
Absolute Value: 5.69
Rounded Value: 3

Explanation 3.2

Input Reading: Introduced cin >> num1; and cin >> num2; to read real-number inputs dynamically.

pow(base, exponent): Computes base raised to exponent ($x^y$).

fabs(x): Calculates the floating-point absolute magnitude ($\vert{}x\vert{}$), removing negative signs.

round(x): Rounds real number values to the nearest whole integer.

3. Exercise 3.3: String Data Type and Methods

Problem Statement

Construct a C++ program that prompts the user for their full name and demonstrates key <string> standard methods:

length(): Measure total string character length.

append(): Append text to the end of the string.

find(): Locate character index position of a substring.

substr(): Extract a segment of the string (e.g., first name).

C++ Source Code

#include <iostream>
#include <string>

using namespace std;

int main() {
string fullName;

    cout << "Enter your full name: ";
    getline(cin, fullName); // Capture full line input including spaces

    // 1. Calculate string length
    int nameLength = fullName.length();

    // 2. Find position of substring "kara"
    size_t pos = fullName.find("kara");

    // 3. Extract first name using substr()
    size_t spacePos = fullName.find(" ");
    string firstName = (spacePos != string::npos) ? fullName.substr(0, spacePos) : fullName;

    // 4. Append string suffix
    string appendedName = fullName;
    appendedName.append(" - Student");

    // Output results
    cout << "Name length: " << nameLength << endl;
    cout << "Name after appending text: " << appendedName << endl;
    if (pos != string::npos) {
        cout << "Position of the word 'kara' in the name: " << pos << endl;
    } else {
        cout << "Word 'kara' not found in the input." << endl;
    }
    cout << "First name (substring): " << firstName << endl;

    return 0;

}

Example Input & Output

Input:

Enter your full name: Baskara Saputra

Output:

Name length: 15
Name after appending text: Baskara Saputra - Student
Position of the word 'kara' in the name: 3
First name (substring): Baskara

Explanation 3.3

getline(cin, fullName): Safely inputs full text containing whitespace characters.

length(): Returns total count of characters, including space offsets.

append(str): Concatenates additional text string at the end of the source string.

find(sub): Searches for substring sub and returns 0-indexed position.

substr(start, count): Extracts count characters beginning from index start.

4. Exercise 3.4: Type Casting

Problem Statement

Fix the program to demonstrate type casting in C++:

Accept input of type float.

Inspect data type identifier using typeid().name() prior to conversion.

Perform explicit casting from float to int.

Perform implicit casting from float to double.

Display resulting type identifiers using <typeinfo>.

Fixed C++ Source Code

#include <iostream>
#include <string>
#include <typeinfo> // Required for typeid operator

using namespace std;

int main() {
// Enter a number of type float
float num;
cout << "Enter a number (float): ";
cin >> num;

    // Display the data type before conversion
    cout << "Real num data type: " << typeid(num).name() << endl;

    // Explicit casting to int
    int numInt = (int)num;

    // Implicit casting to double
    double numDouble = num;

    // Display the data type after conversion
    cout << "Num data type after casting to int: " << typeid(numInt).name() << endl;
    cout << "Num data type after casting to double: " << typeid(numDouble).name() << endl;

    return 0;

}

Example Input & Output

Input:

Enter a number (float): 45.67

Output:

Real num data type: f
Num data type after casting to int: i
Num data type after casting to double: d

Explanation 3.4

Header Inclusion: Added #include <typeinfo> to enable typeid() functionality.

Explicit Casting: (int)num manually truncates float values into integer values.

Implicit Casting: Assigning float variable num to double variable numDouble allows the C++ compiler to automatically promote precision without explicit casting syntax.

typeid().name(): Returns implementation-defined type representation tags (f = float, i = int, d = double).

5. Conclusion of Today's Lesson

Through this practical lab session on C++ basic data types, we conclude that:

Numeric & Math Operations: Using libraries such as <cmath> equips developers with mathematical algorithms ($pow$, $abs$, $round$, $min$, $max$) essential for precise scientific computing.

String Manipulation: Standard library string methods (length(), append(), find(), substr()) provide mechanisms for string parsing and string construction.

Type Conversion & Safety: Type casting mechanisms (explicit vs. implicit) allow developers to control memory representation and precision tradeoffs, while standard utilities like typeid help verify datatypes at runtime.
