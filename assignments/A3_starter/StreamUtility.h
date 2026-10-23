#ifndef STERAMUTILITY_H 
#define STERAMUTILITY_H 

#include <ostream>
#include <istream>

using namespace std;

//handles getting user input and output
class StreamUtility{
public:
	istream* selectInput();
	ostream* selectOutput();
};

#endif
