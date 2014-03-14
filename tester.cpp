#include "tester.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <time.h>

using namespace std;

Tester::Tester(string s){
	this->in = new ifstream(s.c_str());
	readQuestion();
	srand(time(0));
}

bool Tester::isQuestion(string s){
	if (s == "Difficulty:") return false;
	if (s == "Learning") return false;
	if (s == "Section") return false;
	if (s == "Feedback:") return false;
	if (s == "Copyright") return false;
	return true;
}

void Tester::readQuestion(){
	string temp;
	bool done = false;
	questions.push_back("");
	while(!done){
		if (in->eof())
			return;
		getline(*in,temp);
		stringstream ss(temp);		
		string cond;
		ss >> cond;

		if (isQuestion(cond)){
			if (cond == "Answer:"){
				answers.push_back(temp[temp.length()-1]);
				questions.push_back("");			
			}
			else{
				if (cond.length() == 2 && (cond[0]-60) > 0) questions[questions.size()-1]+="\t";
				questions[questions.size()-1]+=temp;
				questions[questions.size()-1]+="\n";
			}
		}
	}
}

bool Tester::done(){
	return questions.size()==0;
}

string Tester::getQuestion(){
	randInt = rand() % getRemaining();
	return questions[randInt];
}

bool Tester::getAnswer(char v){
	if (answers[randInt] == v){
		questions.erase(questions.begin()+randInt);
		answers.erase(answers.begin()+randInt);
		return true;
	}
	return false;
}

int Tester::getRemaining(){
	return questions.size();
}

int Tester::getTotal(){
	return totalQ;
}

string getQuestion(){
	randInt = rand() % getRemaining();
	return questions[randInt];
}

bool answer(char v){
	if (answers[randInt] == v){
		questions.erase(questions.begin()+randInt);
		answers.erase(answers.begin()+randInt);
		return true;
	}
	return false;
}

string getRemaining(){
	return questions.size();
}

string getTotal(){
	return totalQ;
}
