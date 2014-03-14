//tester.h

#include <fstream>
#include <string>
#include <vector>

class Tester{
	std::ifstream * in;
	int totalQ;
	int randInt;

	int correct;

	std::vector<std::string> questions;
	std::vector<char> answers;
	std::vector<int> chapters; // location of the first question of each chapter
	std::vector<std::string> ignoreList;
	std::vector<bool> selectedChapters;
	std::string file;

private:
	void readQuestion();
public:
	explicit Tester(std::string);
	~Tester();

	bool done();
	bool isQuestion(std::string);
	std::string getQuestion();
	bool getAnswer(char);
	int getRemaining();
	int getTotal();
	int getCorrect();
	void getIgnores();
	void deselectChapter(int);
	bool isSelected();
};
