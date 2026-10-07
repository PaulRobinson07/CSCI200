#include <iostream>
#include "Box.h"


using namespace std;

int main() {
    cout << "Hello World!" << endl;
	Box amazon_box = Box();
	amazon_box.length = 1.0f;
	amazon_box.height= 1.2f;
	amazon_box.depth= 1.0f;
	amazon_box.print_dimensions();
    return 0;
}
