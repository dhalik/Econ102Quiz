//tester.h

#ifndef __TESTER_H__
#define __TESTER_H__

#include <fstream>
#include <string>
#include <vector>
#include "question.h"

class Tester{
	std::ifstream * in;
	int randInt;

	int correct;

	std::vector<Question> questions;
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
	void deselectChapter(unsigned int);
	void selectChapter(int);
	std::vector<bool> getAllSelected();
};


#endif
