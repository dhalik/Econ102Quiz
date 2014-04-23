#include <iostream>
#include "tester.h"
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

int main(){
	char answer = 'a';
	string bank = "";
	cout << "################################################################################" << endl;
	Tester * tester = new Tester("QuestionBank/is.dat");

	cout << "Welcome to IS Quizzing." << endl << "Currently, the following chapters are selected (i.e. questions will be asked form them): " << endl;
	vector<bool> sc = tester->getAllSelected();
	for (vector<bool>::iterator i = sc.begin(); i < sc.end(); i++){
		if (*i)
			cout << i - sc.begin()+1 << " ";
	}
	cout << endl;
	cout << "Enter a list of chapters seperated by spaces, terminated by -1 to deselect them from the quiz. (i.e. 1 3 6 -1)" << endl;
	
	int ds = 100000;
	while (ds > -1){
		if (cin >> ds)
			tester->deselectChapter(ds);
		else{
			cin.clear();
			cin.ignore();
		}
	}

	cout << "Current chapters selected: ";
	sc = tester->getAllSelected();
	for (vector<bool>::iterator i = sc.begin(); i < sc.end(); i++){
                if (*i)
                        cout << i - sc.begin()+1 << " ";
        }

	cout << endl;
	cout << "Quizzing will begin now." << endl;
	cout << "################################################################################" << endl << endl << endl;
	
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
		#ifdef DEBUG
			cout << "remaining " << tester->getRemaining() << " correct " << tester->getCorrect()  << " total " << tester->getTotal() << endl;
		#endif
		cout << tester->getRemaining() << " questions remaning. " << ((tester->getCorrect())*100)/((float)tester->getTotal()) << "% complete" << endl << endl;
	}

	cout << "################################################################################" << endl;

	delete tester;

	return 0;
}
