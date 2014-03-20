#include <iostream>
#include "tester.h"
#include <string>
#include <cstdlib>

using namespace std;

int main(){
	char answer = 'a';
	string bank = "";

	cout << "Enter Question Bank (is or econ)" << endl;
	cin >> bank;

	Tester * tester = new Tester("QuestionBank/"+bank+".dat");

	while (answer != 'q'){
		cout << tester->getQuestion() << endl;
		cin >> answer;
		
		char ans = tester->getAnswer(answer);
		cout << ans << endl;
		
		
		if (ans==answer){
			cout << "Correct!" << endl;
		}else{
			cout << "Wrong!" << endl;
		}
		cout << tester->getRemaining() << " questions remaning." << ((tester->getCorrect())*100)/(float)tester->getTotal() << "% complete" << endl << endl;
	}

	delete tester;

	return 0;
}
