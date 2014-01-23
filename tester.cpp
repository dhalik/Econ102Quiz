#include "tester.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>

using namespace std;

Tester::Tester(int n){
	stringstream ss;
	ss << n << ".dat";
	this->in = new ifstream(ss.str().c_str());
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
		if (cond == "Topic:") continue;
		if (cond == "Skill:") continue;
		if (cond == "AACSB:") continue;
		if (cond == "Question") continue;
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
