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
	cout << "Setting up class" << endl;
	file = s;
	this->in = new ifstream(s.c_str());
	getIgnores();
	readQuestion();
	srand(time(0));
	totalQ = questions.size();
	cout << "class setup sucessful" << endl;	
	cout << "Quest.size() " << questions.size() << endl;
	cout << "Ans.size() " << answers.size() << endl;
	cout << "Chapters.size() " << chapters.size() << endl;
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
				cout << "Creating new chapter at question " << questions.size() << endl;			
				chapters.push_back(questions.size());
				selectedChapters.push_back(true);
			}
			else{
				if (cond.length() == 2 && (cond[0]-60) > 0) questions[questions.size()-1]+="\t";
				questions[questions.size()-1]+=temp;
				questions[questions.size()-1]+="\n";
			}
		}

		if (in->eof()){
			done = true;
			questions.pop_back();
		}
	}
}

bool Tester::done(){
	return questions.size()==0;
}

string Tester::getQuestion(){
	randInt = rand() % getRemaining();
	while (getChapter(randInt) > 0 && !selectedChapters[getChapter(randInt)])
		randInt = rand() % getRemaining();
	return questions[randInt];
}

bool Tester::getAnswer(char v){
	if (answers[randInt] == toUpper(v)){
		questions.erase(questions.begin()+randInt);
		answers.erase(answers.begin()+randInt);
		return true;
	}
	cout << "Question from Chapter " << getChapter(randInt);
	cout << "Correct Answer is: " << answers[randInt] << endl;
	return false;
}

int Tester::getCorrect(){
	return correct;
}

int Tester::getRemaining(){
	return questions.size();
}

int Tester::getTotal(){
	return totalQ;
}

Tester::~Tester(){
	delete in;
}

void Tester::deselectChapter(int n){
	bool alldes = false;
	for (vector<bool>::iterator it = selectedChapters.begin(); it < selectedChapters.end(); it++)
		alldes = alldes || *it;
	if (alldes)
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
