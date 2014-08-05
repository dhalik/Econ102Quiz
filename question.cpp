#include <string>
#include <vector>
#include "question.h"

using namespace std;

Question::Question(string q, vector<string> resp, char ans):answers(resp), answer(ans),question(q){
    answered = false;
}

char Question::getAnswer(){
    return answer;
}

string Question::getQuestion(){
    return question;
}

bool Question::isAnswered(){
    return answered;
}

string Question::getAnswers(){
    string total = "";
    for (vector<string>::iterator it = answers.begin(); it < answers.end(); it++){
        total = total + (char)('A' + (it - answers.begin()));
        total = total + ')';
        total = total + " ";
        total += *it + "\n";
    }
    return total;
}

void Question::setAnswered(){
    answered = true;
}

vector<string> Question::getAnswerList(){
    return answers;
}
