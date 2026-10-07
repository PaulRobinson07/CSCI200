//improved formatting with AI
//All the work was done by me

// 1. Global Setup Styles
#set page(paper: "us-letter", margin: 1in)
#set text(font: "New Computer Modern Math", size: 11pt)
#set list(indent: 1.5em)

// This rule automatically applies "1." to primary questions and "a)" to sub-questions
#set enum(
  indent: 1em, 
  full: true, // Tells Typst to track all levels simultaneously
  numbering: (..n) => {
    let level = n.pos().len()
    if level == 1 {
      numbering("1.", n.pos().last()) // Level 1: 1., 2., 3.
    } else {
      numbering("a)", n.pos().last()) // Level 2: a), b), c)
    }
  }
)

// 2. Centered Clean Header
#align(center)[
  #text(size: 18pt, weight: "bold")[Exam One Review] \
  #text(size: 14pt, fill: gray.darken(20%))[Paul Robinson] \
  September 21, 2026
]
#v(0.5em)
#line(length: 100%, stroke: 0.5pt + gray)
#v(1em)

// 3. Exam Content Block
+ Assuming all numbers are stored as integers
  + \(2+3*4-6 = 8\)
  + \(5+11/3 = 8\)
  + \(11 \% 3 \* 4 = 8\)
  + \((2+1)\*3-1 = 8\)

+ Create Boolean Test Conditions
  + `(myHeight > 2)`
  + `(y % 2 == 0) && (y < 10)`
  + `(x == 3) || (y == 3)`
  + `(t > 2.1) && (t < 2.3)`

+ What is the Output?
  + The output is "12"

+ What is the Output?
  + The output is "1"

+ What is the Output?
  + The output is "Have a good day!"

+ What is the Output?
  + The output is "2"

+ What is the Output?
  + The output is "4"  
  + The output is then "4.5"
  + The output is then "4.5"
  + The output is then "4.5"

+ What is the Output?
  + The output is "6 5"
  + The output is then "7 7"

+ Find all errors
  + `z` is not given a type
  + `y` is not typecasted inside of the brackets

+ Write if/else code
  + `cout << "your score was: " << exam_score << endl;`
  + Inside a block:
    ```cpp
    int get_score(int exam_score) {
        if (exam_score < 80) { return "C"; }
        if (exam_score < 90) { return "B"; }
        return "A";
    }
    ```

+ Write loop code
  + ```cpp
    // Yeah I know we're supposed to start from 0, but why waste a loop call 
    int index = 1; 
    int max; 
    cout << "Give a number to count odd numbers to: ";
    cin >> max;

    while (index <= max) { 
      cout << index << endl;
      index += 2;
    }
    ```
  + ```cpp
    int max; 
    cout << "Give a number to count odd numbers to: ";
    cin >> max;

    for (int index = 1; index <= max; index += 2) { 
      cout << index << endl;
    }
    ```

+ Rewrite as a Switch
  ```cpp
  switch(rank) {
    case 1:
    case 2:
      cout << "Lower Division" << endl;
      break;
    case 3:
    case 4:
      cout << "Upper Division" << endl;
      break;
    case 5:
      cout << "Graduate Student" << endl;
      break;
    default:
      cout << "Invalid Rank" << endl;
      break;
  }
  ```

+ True/False
  + True
  + False
  + True
  + False

+ Rewrite as a for loop
  + ```cpp
    for (int i = 2; i <= 18; i += 3) {
      cout << "*";
    }
    ```
  + The output is: ```text ****** ```

+ What is the output?
  The output is: ```text 0 ```

+ What is the output?
  The output is: \(infinity\) or integer overflow.

+ What is the output?
  The output is: ```text 90 ```

+ What is the output?
  ```text
  ******
  *****
  ***
  **
  ```

+ Write a program
  ```cpp
  // This Program should produce ten random integers between 1 and 100
  #include <random>
  #include <iostream>
 
  using namespace std;

  int get_random_number(int min, int max) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distrib(min, max);
    return distrib(gen);
  }

  int main() {
    for (int i = 0; i < 10; i++) {
      cout << i << ": " << get_random_number(1, 100) << endl;
    }
    return 0;
  }
  ```

+ True or False
  + True
  + False

+ What is the output?
  ```text
  x = 0
  y = 0
  (The function should take in parameters as pointers or references rather than variables)
  ```
  
+ What is the output?
  ```text
  d = 34
  (The function should return a double, so in practice it may give warnings. Otherwise, you need to either change it or add a type cast to the function call)
  ```

+ Which are legal statements?
  Statements * A, B, and F * are legal statements. The others either have an issue with the return type or mismatched parameters.
  
+ Write Functions
  + ```cpp
    // no return and no functionality
    void cool_func() {
      // be pointless
      return;
    }
    ```
  + ```cpp
    // double return and no functionality
    double cool_func() {
      double d = 0.0;
      return d;
    }
    ```
  + ```cpp
    // integer return and no functionality
    int neutral_func(int foo, double bar, char baz) {
      int return_val = 0;
      return return_val;
    }
    ```

+ Write a function
  ```cpp
  // gets the area of a square of whole numbers
  int get_area(int base) {
    return base * base;
  }
  ```

+ Find the errors
  + The function should be defined before `main` (or use a forward declaration).
  + `add_one` doesn't return anything but has a return type assigned.
  + `int 7;` is illegal and should be replaced with `int x = 7;`.
  + `add_one`'s call should have `x` assigned to it: `x = add_one(x);`.

+ Memory Questions
  + It holds the sign of the number (Sign bit).
  + If the integer is signed, the maximum positive threshold value is halved to allow for negative numbers.

+ Data Type Modifiers
  + `unsigned long long int` allows storing only positive integers from \(0\) to \(2^{64}-1\).
  + `long long int` allows storing positive and negative integers from \(-2^{63}\) to \(2^{63}-1\).
  + One allows for negative numbers and one doesn't, which doubles the positive capacity spectrum.

+ Data Type Modifiers Extended
  `B` is the answer because assigning `-1` to an unsigned integer triggers a predictable wrap-around behavior due to modulo arithmetic, turning it into the maximum possible limit.

+ Building
  Object files are larger than C++ files because they contain verbose compiled machine code, symbol lookup tables, and the fully copy-pasted contents of every expanded `#include` header file.

+ Makefiles
  + Makefiles implement incremental builds, tracking modified file headers to only compile updated source files, saving massive amounts of build automation time.
  + We separate the compilation and linking phases so code changes only force a local item compilation without recalculating the entire project.

+ Write a Function
  ```cpp
  void make_tree(int base) {
      for(int i = 0; i < base; i++) {
          int spaces = base - i - 1; 
          int leaves = i * 2 + 1;

          for (int k = 0; k < spaces; k++) cout << " ";
          for (int k = 0; k < leaves; k++) cout << "*";
          cout << endl;
      }
      
      int trunk_spaces = base - 1; 
      for (int k = 0; k < trunk_spaces; k++) cout << " ";
      cout << "x" << endl;
  }
  ```

