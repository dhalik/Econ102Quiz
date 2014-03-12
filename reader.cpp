#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>

using namespace std;

ifstream in("30");

string * readQuestion(){
	string * q = new string[2];
	string temp;
	bool done = false;
	while(!done){
		getline(in,temp);
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

int main(){
	char answer;
	int right=0,wrong=0;
	while (!in.eof() && answer != 'q'){
		string * q =  readQuestion();
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
	return 0;
}
