#include <iostream>
#include "tester.h"
#include <string>
#include <cstdlib>

using namespace std;

int main(){
	char answer;
	int right=0,wrong=0;

	cout << "##########################################################" << endl;
	cout << "##########################################################" << endl;
	cout << "#                  ECON 102 Review Guide                 #" << endl;
	cout << "#       Questions from Parkin and Bades 8th US Edition   #" << endl;
	cout << "##########################################################" << endl;
	cout << "##########################################################" << endl;
	
	cout << "Enter a chapter number between 20 and 31 that you would like to study from: ";
	int n;
	cin >> n;
	Tester * tester = new Tester(n);

	while (tester->done() && answer != 'q'){
		string * q =  tester->readQuestion();
		cout << q[0];
		cin >> answer;
		if (answer == 's'){
			delete[] q; 
			continue;
		}
		if (answer == q[1][q[1].length()-2] || answer == q[1][q[1].length()-2]+32)
			right++;
		else
			wrong++;
		cout << "Correct Answer: " << q[1][q[1].length()-2]<< endl << endl;
		delete [] q;
	}

	cout << "right " << right << endl;
	cout << "wrong " << wrong << endl;

	delete tester;

	return 0;
}
