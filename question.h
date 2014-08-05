#ifndef __QUESTION__H__
#define __QUESTION__H__

#include <string>
#include <vector>

class Question{
    private:
        std::vector<std::string> answers;
        char answer;
        bool answered;
        std::string question;
    public:
        Question(std::string, std::vector<std::string>, char);
        char getAnswer();
        bool isAnswered();
        void setAnswered();
        std::string getQuestion();
        std::string getAnswers();
        std::vector<std::string> getAnswerList();
};

#endif
