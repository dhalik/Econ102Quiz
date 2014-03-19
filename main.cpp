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

	cout << "Deselecting Chapters" << endl;

	tester->deselectChapter(1);
	cout << tester->getRemaining() << endl;
	tester->deselectChapter(2);
	cout << tester->getRemaining() << endl;
	tester->deselectChapter(3);
	cout << tester->getRemaining() << endl;
	
	while (answer != 'q'){
		cout << tester->getQuestion() << endl;
		cin >> answer;
		if (tester->getAnswer(answer)){
			cout << "Correct!" << endl;
		}else{
			cout << "Wrong!" << endl;
		}
		cout << endl << endl;
		cout << tester->getRemaining() << " questions remaning." << ((tester->getTotal() - (float)tester->getRemaining())*100)/(float)tester->getTotal() << "% complete" << endl << endl;
	}

	delete tester;

	return 0;
}
