//tester.h

#include <fstream>
#include <string>

class Tester{
	std::ifstream * in;
public:
	std::string * readQuestion();
	explicit Tester(std::string);
	bool done();
};
