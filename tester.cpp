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

	string q;
	char corr;
	vector<string> ans;

	while(!done){
		getline(*in,temp);
		stringstream ss(temp);		
		string cond;
		ss >> cond;

		if (isQuestion(cond)){
			if (cond == "Answer:"){
				corr = toUpper(temp[temp.length()-1]);
				questions.push_back(Question(q,ans,corr));
				q = '\0';
				ans.erase(ans.begin(),ans.end());
				corr = '\0';
			}
			else if (cond == "Chapter"){
				chapters.push_back(questions.size());
				#ifdef DEBUG
					cout << questions.size() << " ends the chapter" << endl;
				#endif
				if (questions.size() > 1)
					totalQ.push_back(questions.size() -chapters[chapters.size()-2]);
			}
			else{
				//if Uppercase letter, and of form xx. So an answer, then tab it
				if (cond.length() == 2 && (cond[0]-'a') > 0){
					temp = "\t" + temp;
					ans.push_back(temp);
				}
				else if (q.length() > 0){
					q = temp;
				}
			}
		}

		if (in->eof()){
			done = true;
			chapters.push_back(questions.size());
			#ifdef DEBUG
				cout << questions.size() << " ends the chapter" << endl;
			#endif
			totalQ.push_back(questions.size() - chapters[chapters.size()-2]);
		}
	}
	for (unsigned int i = 0; i < chapters.size() - 1; i++){
		selectedChapters.push_back(true);
	}
}

bool Tester::done(){
	for (vector<Question>::iterator i = questions.begin(); i < questions.end(); i++)
		if (!(i->isAnswered()))
			return false;
	return true;
}

string Tester::getQuestion(){
	randInt = (rand() % questions.size());
	while (!selectedChapters[getChapter(randInt+1)-1] && !questions[randInt].isAnswered()) //make sure getchapter is > 0.... Thats for later though.
		randInt = (rand() % questions.size());
	#ifdef DEBUG
		cout << "Choosing " << randInt << " from chapter " << getChapter(randInt+1) << endl;
	#endif
	return questions[randInt].getQuestion() + "\n" + questions[randInt].getAnswers();
}

char Tester::getAnswer(char v){
	if (toUpper(questions[randInt].getAnswer()) == toUpper(v)){
		questions[randInt].setAnswered();
		return v;
	}
	return questions[randInt].getAnswer();
}

int Tester::getCorrect(){
	int correct;
	for (vector<Question>::iterator i = questions.begin(); i < questions.end(); i++)
		if (i->isAnswered())
			correct++;
	return correct;
}

int Tester::getRemaining(){
	int q = 0;
	for (unsigned int i = 0; i < questions.size(); i++)
		if (selectedChapters[getChapter(i+1)-1] && !questions[i].isAnswered())
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
	delete in;
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
