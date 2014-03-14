#include <iostream>
#include "tester.h"
#include <string>
#include <cstdlib>

using namespace std;

int main(){
	char answer = 'a';
	int right=0,wrong=0;

	Tester * tester = new Tester("QuestionBank/is.dat");



	delete tester;

	return 0;
}
