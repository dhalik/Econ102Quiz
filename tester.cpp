#include "tester.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <time.h>
#include "rapidxml/rapidxml.hpp"
#include "rapidxml/rapidxml_utils.hpp"
#include "econ.cpp"

using namespace std;
using namespace rapidxml;


//locally def function
char toUpper(char v){
    if ('a' <= v and v <= 'z')
        v-=32;
    return v;
}

Tester::Tester(){
    readQuestion();
    srand(time(0));
}

void Tester::readQuestion(){
    xml_document<> doc;
    doc.parse<0>(question_data);

    xml_node<>* root = doc.first_node("econ");
    for (xml_node<> * chapter_node = root->first_node("chapter"); chapter_node; chapter_node = chapter_node->next_sibling()){
        for (xml_node<> * q_node = chapter_node->first_node("question"); q_node; q_node = q_node->next_sibling()){
            vector<string> ans;
            string question = q_node->first_node("q")->value();
            ans.push_back(q_node->first_node("a")->value());
            ans.push_back(q_node->first_node("b")->value());
            ans.push_back(q_node->first_node("c")->value());
            ans.push_back(q_node->first_node("d")->value());
            ans.push_back(q_node->first_node("e")->value());
            string answerString = q_node->first_node("ans")->value();
            char answer = answerString[0];
            if (question.find(" Figure ") != string::npos)
                continue;
            if (question.find("Refer to Table") != string::npos)
                continue;
            if (question.find("Refer to Fact") != string::npos)
                continue;
            Question q(question,ans,answer);
            questions.push_back(q);
        }
        chapters.push_back(questions.size());
    }
    totalQ.push_back(*chapters.begin());
    for (vector<int>::iterator i = chapters.begin(); i != chapters.end(); i++){
        selectedChapters.push_back(true);
        totalQ.push_back(*(i+1)-*i);
    }
#ifdef DEBUG
    for (vector<int>::iterator i = totalQ.begin(); i != totalQ.end(); i++){
        cout << *i << endl;
    }
#endif
}

bool Tester::done(){
    return (getRemaining() == 0);
}

string Tester::getQuestion(){
    randInt = (rand() % questions.size());
    while (!selectedChapters[getChapter(randInt+1)] || questions[randInt].isAnswered()) //make sure getchapter is > 0.... Thats for later though.
        randInt = (rand() % questions.size());
#ifdef DEBUG_L1
    cout << "Choosing " << randInt << " from chapter " << getChapter(randInt+1) << ". Luckily it satisfies: sc and ans: " << !selectedChapters[getChapter(randInt+1)] << !questions[randInt].isAnswered() << endl;
#endif
    return questions[randInt].getQuestion() + "\n" + questions[randInt].getAnswers();
}

char Tester::getAnswer(char v){
    if (toUpper(questions[randInt].getAnswer()) == toUpper(v)){
        questions[randInt].setAnswered();
#ifdef DEBUG_L1
        cout << "Since you answered " << randInt << " correctly, it is now " << questions[randInt].isAnswered() << endl;
#endif
        return v;
    }
    return questions[randInt].getAnswer();
}

int Tester::getCorrect(){
    int correct = 0;
    for (vector<Question>::iterator i = questions.begin(); i < questions.end(); i++)
        if (i->isAnswered())
            correct++;
    return correct;
}

int Tester::getRemaining(){
    int q = 0;
    for (unsigned int i = 0; i < questions.size(); i++)
        if (selectedChapters[getChapter(i+1)] && !questions[i].isAnswered())
            q++;
    return q;
}

int Tester::getTotal(){
    int q = 0;
    for (unsigned int i = 0; i < totalQ.size(); i++)
        if (selectedChapters[i])
            q+=totalQ[i];
    return q;
}

Tester::~Tester(){
}

vector<bool> Tester::getAllSelected(){
    return selectedChapters;
}

void Tester::deselectChapter(unsigned int n){
    bool alldes = false;
    if (n > selectedChapters.size())
        return;
    selectedChapters[n-1] = false;
    for (vector<bool>::iterator it = selectedChapters.begin(); it < selectedChapters.end(); it++)
        alldes = alldes || *it;
    if (!alldes)
        selectedChapters[n-1] = true;
    return;
    selectedChapters[n-1] = false;
}

void Tester::selectChapter(int n){
    selectedChapters[n-1] = true;
}

int Tester::getChapter(int q){
#ifdef DEBUG_L1
    cout << q << " is the question we are searching for" << endl;
#endif
    for (vector<int>::iterator i = chapters.begin(); i < chapters.end(); ++i)
        if (q <= *i) return (i-chapters.begin());
    return -1;
}
