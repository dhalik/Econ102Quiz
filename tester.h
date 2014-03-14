//tester.h

#include <fstream>
#include <string>

class Tester{
	std::ifstream * in;
	int totalQ;
	int randInt;
	vector<string> questions;
	vector<string> answers;
	vector<int> chapters; // location of the first question of each chapter

private:
	void readQuestion();
public:
	explicit Tester(std::string);
	bool done();
	string getQuestion();
	string getAnswer();
	string getRemaning();
	string getTotal();
};
