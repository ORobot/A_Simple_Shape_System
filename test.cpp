#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	string str = "hello";
	vector<string> *svec;
	svec = new vector<string>(10, str);
	for(auto& P : * svec)
		P[2][3] = 'a';
	for(auto P : * svec)
		cout << P << endl;
}
