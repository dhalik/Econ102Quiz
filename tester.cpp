#include "tester.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

Tester::Tester(string s){
	this->in = new ifstream(s.c_str());
}

string * Tester::readQuestion(){
	string * q = new string[2];
	string temp;
	bool done = false;
	while(!done){
		getline(*in,temp);
		stringstream ss(temp);
		string cond;
		ss >> cond;
		if (cond == "Answer:"){
			done = true;
			break;
		}
		if (cond.length() == 2 && (cond[0]-60) > 0)
			q[0]+="\t";
		if (cond == "Difficulty:") continue;
		if (cond == "Learning") continue;
		if (cond == "Section") continue;
		if (cond == "Feedback:") continue;
		if (cond == "Copyright") continue;
		q[0]+=temp;
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
