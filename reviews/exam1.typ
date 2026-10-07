#set page(paper: "us-letter", margin: 1in)
#set text(font: "New Computer Modern Math", size: 11pt)
#set list(indent: 1.5em)

#align(center)[
  = Exam One Review
  = Paul Robinson 
  September 21, 2026
]

#line(length:100%)
+ Assuming all numbers are stored as integers
  #set enum(numbering: "a)")
    + $2+3*4-6 = 8$
    + $5+11/3 = 8$
    + $11%3 *4= 8$
    + $(2+1)*3-1 = 8$

+ Create Boolean Test Conditions
  #set enum(numbering: "a)")
    + (myHeight>2)
    + (y%2==0) && (y\<10)
    + (x==3) || (y==3)
    + (t>2.1) && (t\<2.3)

+ What is the Output? \
  + The output is "12"

+ What is the Output? \
  + The output is "1"

+ What is the Output? \
  + The output is "Have a good day!"

+ What is the Output? \
  + The output is "2"

+ What is the Output? \
  #set enum(numbering: "a)")
  + The output is "4"  
  + The output is then "4.5" \
  + The output is then "4.5" \
  + The output is then "4.5" \

+ What is the Output? \
  #set enum(numbering: "a)")
  + The output is "6 5" \ 
  + The output is then "7 7" \ 

+ Find all errors \
  #set enum(numbering: "a)")
    + z is not given a type
    + y is not typecasted inside of the brackets

+ Write if/else code\
  #set enum(numbering: "a)")
    + cout << "your score was: " << exam_score << endl;

    + int get_score(int exam_score) { \
      #h(2em)  if (exam_score \<80) {return "C"}\
      #h(2em)  if (exam_score \<90) {return "B"}\
      #h(2em)  return "A"\
      }

+ Write loop code\
  #set enum(numbering: "a)")
    + ```cpp
      //Yeah I know we're supposed to start from 0, but why waste a loop call 
      int index = 1; 
      int max; 
      cout << "Give a number to count odd numbers to: ";
      cin max;

      while (index\<=max) { 
        cout << index << endl;
        index+=2;
      }```

    + ```cpp
      int max; 
      cout << "Give a number to count odd numbers to: "
      cin max;

      for (index=1; index\<=max; index+=2) { 
        cout << index << endl;
      }```
+ Rewrite as a Switch
  #h(2em) ```cpp
    switch(rank) {
      case(1):
        cout << "Lower Division" << endl;
       break;
      case(2):
        cout << "Lower Division" << endl;
       break;
      case(3):
        cout << "Upper Division" << endl;
       break;
      case(4):
        cout << "Upper Division" << endl;
       break;
      case(5):
        cout << "Graduate Student" << endl;
       break;
      default:
        cout << "Invalid Rank" << endl;
       break;
    }
    ```
+ True/False
  #set enum(numbering: "a)")
    + ```rbx True ```
    + ```rbx False ```
    + ```rbx True ```
    + ```rbx False ```

+ Rewrite as a for loop\
  #set enum(numbering: "a)")
    + ```cpp
        for (int i=2; i<=18; i+=3) {
          cout << "*";
        }
      ```
    + The output is ```rbx ******```

+ What is the output? \
  #h(2em) The output is: ```rbx 0 ```

+ What is the output? \
  #h(2em) The output is:  $infinity$ ```rbx or integer overflow ```

+ What is the output? \
  #h(2em) The output is: ```rbx 90 ```

+ What is the output? \
  #h(-.5em) The output is: ```rbx ******
    *****
    ***
    **```
+ Write a program
  #h(2em)
  ```cpp
  //This Program should produce ten random integers
  //They should be between the bounds 1,100
  #include <random>
  #include <iostream>
 
  using namespace std;

  int get_random_number(int min, int max) {
    
    random_device rd;
    mt19937gen(rd());
    uniform_int_distribution<int> distrib(min,max);

    return distrib(gen);
  }

  int main() {
    for (int i=0; i<10;i++) {
      cout << i << ": " << get_random_number(1,100) endl;
    }
    return 0;
  }
  ```
+ True or False \ 
  #set enum(numbering: "a)")
    + True
    + False

+ What is the output?
  #h(2em) ```rbx 
   x = 0
   y = 0
   (The function should take in parameters as pointers rather than variables)
  ```
  
+ What is the output?
  #h(2em) ```rbx 
   d = 34
   (The function should return a double so in practice may give warnings and otherwise you do need to either change it or add a type cast to the function call)
  ```

+ Which are legal statements? \
  #h(2em) A, B, and F are legal statements. The others either have an issue with the return type or the parameters.
  
+ Write Functions 
  #set enum(numbering: "a)")
  +
    ```cpp
    //no return and no functionality
    void cool_func() {
      //be pointless
      return;
    }
    ```
  +
    ```cpp
    //double return and no functionality
    double cool_func() {
      //do something 
      double d = ?;
      return d;
    }
    ```
  +
    ```cpp
    //integer return and no functionality
    int neutral_func(int foo, double bar, char baz) {
      //do something 
      int return_val = ?;
      return return_val;
    }
    ```
+ Write a funciton 
  #h(2em) ```cpp
  //gets the area of a square of whole numbers
  int get_area(int base) {
    return base*base;
  }
  ```
+ Find the errors
  #set enum(numbering: "a)")
    + The function should be defined before main
    + add_one doesn't return anything
    + add_one doesn't return a type
    + ```cpp int 7;``` should be replaced with ```cpp int x=7;```
    + add_one's call should have x be set to it
+ Memory Questions
  #set enum(numbering: "a)")
    + The sign of the number
    + If the integer is signed the maximum number of stored integers is halfed
+ Data Type Modifiers
  #set enum(numbering: "a)")
    + ```cpp unsigned long long int allows the computer to store only positive integers from 0 to 2^64```
    + ```cpp long long int allows the computer to store positive and negative integers from 0 to 2^63```
    + One allows for negative numbers and one doesn't which doubles the amount of numbers that it can store.
+ Data Type Modifiers Extended \ 
  #h(2em) B is the answer because the unsigned portion of the int doesn't mean that the computer can't store negative numbers, it just stores it as the maximum value of the signed integer plus the absolute value it's trying to be assigned to

+ Building
  \ #h(2em) Objects are larger in size than c++ files because they contain the full code and the header files associated with it.
+ Makefiles
  #set enum(numbering: "a)")
    + Makefiles allow us to only update any files that get updated during compilation and it also automates all the linking text / complier calls to outside libraries.
    + We separate the steps to make it easier to track steps within each step.
+ Write a Function
  #h(2em) ```cpp
  //takes in a base value (height also works since they're the same) and draws an ascii tree
  void make_tree(int base) {
    for(int i=0; i<base; i++) {
      for (int j=0; j<base; j++) {
        int spaces = i-(base)/2; 
        int leaves = i*2+1;

        for (int k=0; k<spaces; k++) {
          cout << " ";
        }
        for (int k=0; k<leaves; k++) {
          cout << "*";
        }
      }
      cout << endl;
    }

    int spaces = base-(base)/2; 
    for (int j=0; j<base; j++) {
      for (int k=0; k<spaces; k++) {
        cout << " ";
      }
      cout << "x";
    }
  }
  ```
