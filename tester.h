//tester.h

#ifndef __TESTER_H__
#define __TESTER_H__

#include <fstream>
#include <string>
#include <vector>

class Tester{
	std::ifstream * in;
	int randInt;

	int correct;

	std::vector<std::string> questions;
	std::vector<char> answers;
	std::vector<int> chapters; // location of the first question of each chapter
	std::vector<std::string> ignoreList;
	std::vector<bool> selectedChapters;
	std::string file;
	std::vector<int> totalQ;

private:
	void readQuestion();
	int getChapter(int);
	bool isQuestion(std::string);
	void getIgnores();

public:
	explicit Tester(std::string);
	~Tester();

	bool done();
	std::string getQuestion();
	char getAnswer(char);
	int getRemaining();
	int getTotal();
	int getCorrect();
	void deselectChapter(int);
	void selectChapter(int);
};


#endif
