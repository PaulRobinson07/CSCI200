#include <fstream>
#include <iostream>
using namespace std;

int main() {
    cout << "Hello World!" << endl;

    ifstream fin("data.txt");
    if( fin.fail() ) {
      cerr << "Could not open data.txt" << endl;
	  return -1;
	}

    return 0;
}
