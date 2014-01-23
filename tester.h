//tester.h

#include <fstream>

class Tester{
	std::ifstream * in;
public:
	std::string * readQuestion();
	explicit Tester(int n);
	bool done();
};
