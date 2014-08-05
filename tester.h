//tester.h

#ifndef __TESTER_H__
#define __TESTER_H__

#include <fstream>
#include <string>
#include <vector>
#include "question.h"

class Tester{
    private:
    int randInt;
    int correct;

    std::vector<Question> questions;
    std::vector<int> chapters; // location of the first question of each chapter
    std::vector<bool> selectedChapters;
    std::string file;
    std::vector<int> totalQ;
    void readQuestion();
    int getChapter(int);

    public:
    explicit Tester();
    ~Tester();


    //basic test to check completion of test
    bool done();
    //return a random question
    std::string getQuestion();

    //checks answer
    char getAnswer(char);

    //completion stats
    int getRemaining();
    int getTotal();
    int getCorrect();

    //delsection and selection of various chaptesr
    void deselectChapter(unsigned int);
    void selectChapter(int);

    //
    std::vector<bool> getAllSelected();
};


#endif
