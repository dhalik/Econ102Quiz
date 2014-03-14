//tester.h

#include <fstream>
#include <string>
#include <vector>

class Tester{
	std::ifstream * in;
	int totalQ;
	int randInt;

	std::vector<std::string> questions;
	std::vector<char> answers;
	std::vector<int> chapters; // location of the first question of each chapter

private:
	void readQuestion();
public:
	explicit Tester(std::string);
	bool done();
	bool isQuestion(std::string);
	std::string getQuestion();
	bool getAnswer(char);
	int getRemaining();
	int getTotal();
};
