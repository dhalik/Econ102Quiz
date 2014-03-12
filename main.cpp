#include <iostream>
#include "tester.h"
#include <string>
#include <cstdlib>
#include <vector>
#include <time.h>

using namespace std;

int main(){
	char answer = 'a';
	int right=0,wrong=0;
	srand(time(0));


	Tester * tester = new Tester("QuestionBank/is.dat");
	vector<string*> v;
	while (v.size() < 282){
		v.push_back(tester->readQuestion());
	}

	int n;

	while (answer != 'q'){
		if ((v.size() - 1) == 0)
			break;
		
		n = rand() % (v.size() - 1);		
		string * q = v[n];

		cout << q[0];


		cin >> answer;
		if (answer == q[1][q[1].length()-2] || answer == q[1][q[1].length()-2]+32){
			right++;
			v.erase(v.begin()+n);
		}
		else
			wrong++;
		cout << "Correct Answer: " << q[1][q[1].length()-2] << endl;
		cout << "right " << right << endl;
		cout << "wrong " << wrong << endl;
		cout << endl;
	}	

	cout << "QUIT... Or you finished all of the questions" << endl;
	cout << "right " << right << endl;
	cout << "wrong " << wrong << endl;

	delete tester;

	return 0;
}
