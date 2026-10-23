/* 
 * CSCI 200: Lecture 04: Conditionals Practice
 *
 * Author: Dr. Jeffrey Paone
 *
 * Exercises to properly create and use conditionals within a program
 * 
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 * 
 */

#include <iostream>                 // For cin, cout, etc.
using namespace std;                // saves us from having to specify std:: everytime

template<typename T>
T maxt(T a, T b) {
	return a < b? b:a;
}


int main() {
	cout << maxt(1,2) << endl;
	cout << maxt(1.0f,2.0f) << endl;
	cout << maxt(-1,2) << endl;
	cout << maxt(1,-2) << endl;
	cout << maxt('B','C') << endl;

   return 0;
}
