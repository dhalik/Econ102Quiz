#include "tester.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <time.h>

using namespace std;


//locally def function
char toUpper(char v){
	if ('a' < v and v < 'z')
		v-=32;
	return v;
}



Tester::Tester(string s){
	file = s;
	this->in = new ifstream(s.c_str());
	getIgnores();
	readQuestion();
	srand(time(0));
}

bool Tester::isQuestion(string s){
	for (vector<string>::iterator it = ignoreList.begin(); it != ignoreList.end(); ++it){
		if (*it == s) return false;
	}	
	return true;
}

void Tester::getIgnores(){
	string ignoreFile = file+".ign";
	
	ifstream in(ignoreFile.c_str());

	while (!in.eof()){
		string ignore;
		in >> ignore;
		ignoreList.push_back(ignore);
	}
}

void Tester::readQuestion(){
	string temp;
	bool done = false;
	questions.push_back("");
	while(!done){
		getline(*in,temp);
		stringstream ss(temp);		
		string cond;
		ss >> cond;

		if (isQuestion(cond)){
			if (cond == "Answer:"){
				answers.push_back(toUpper(temp[temp.length()-1]));
				questions.push_back("");
			}
			else if (cond == "Chapter"){
				chapters.push_back(questions.size());
				if (questions.size() > 1)
					totalQ.push_back(questions.size() -chapters[chapters.size()-2]);
			}
			else{
				if (cond.length() == 2 && (cond[0]-60) > 0) questions[questions.size()-1]+="\t";
				questions[questions.size()-1]+=temp;
				questions[questions.size()-1]+="\n";
			}
		}

		if (in->eof()){
			done = true;
			chapters.push_back(questions.size());
			totalQ.push_back(questions.size() - chapters[chapters.size()-2]);
			questions.pop_back();
		}
	}
	for (unsigned int i = 0; i < chapters.size(); i++){
		selectedChapters.push_back(true);
	}
}

bool Tester::done(){
	return questions.size()==0;
}

string Tester::getQuestion(){
	randInt = (rand() % questions.size());
	while (!selectedChapters[getChapter(randInt+1)-1]){ //make sure getchapter is > 0.... Thats for later though.
		randInt = (rand() % questions.size());
	}
	return questions[randInt];
}
char Tester::getAnswer(char v){
	if (answers[randInt] == toUpper(v)){
		questions.erase(questions.begin()+randInt);
		answers.erase(answers.begin()+randInt);
		correct++;
		return v;
	}
	return NULL;
}

int Tester::getCorrect(){
	return correct;
}

int Tester::getRemaining(){
	int q = 0;
	for (unsigned int i = 0; i < questions.size(); i++){
		if (selectedChapters[getChapter(i+1)-1]){
			q++;
		}
	}
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
	delete in;
}

void Tester::deselectChapter(int n){
	bool alldes = false;
	for (vector<bool>::iterator it = selectedChapters.begin(); it < selectedChapters.end(); it++)
		alldes = alldes || *it;
	if (!alldes)
		return;
	selectedChapters[n-1] = false;
}

void Tester::selectChapter(int n){
	selectedChapters[n-1] = true;
}

int Tester::getChapter(int q){
	for (vector<int>::iterator i = chapters.begin(); i < chapters.end(); ++i)
		if (q < *i) return (i-chapters.begin());
	return -1;
}
