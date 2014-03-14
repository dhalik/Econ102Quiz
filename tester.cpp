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

bool isQuestion(string s){
	if (cond == "Difficulty:") return false;
	if (cond == "Learning") return false;
	if (cond == "Section") return false;
	if (cond == "Feedback:") return false;
	if (cond == "Copyright") return false;
	return true;
}

void Tester::readQuestion(){
	string temp;
	bool done = false;
	while(!done){
		if (in->eof())
			return;
		getline(*in,temp);
		stringstream ss(temp);
		
		string cond;
		ss >> cond;
		if (cond == "Answer:") break;
		if (cond.length() == 2 && (cond[0]-60) > 0) questions[questions.size()]+="\t";
		questions[questions.size()]+=temp;
		q[0]+="\n";
	}
	q[0]+="\n";
	q[1]+=temp;
	q[1]+="\n";
	return q;
}

bool Tester::done(){
	return !in->eof();
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
