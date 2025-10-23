#include <iostream>
#include <vector>
#include <string>
using namespace std;

using VS = vector<string>;
using VI = vector<int>;
int n;
int p;
VS V;
VI group;

void write(){
	for(int i = 0; i < p; i++){
		cout << "subset " << i + 1 << ": {";
		int k = 0;
		for(int j = 0; j < n; j++)
			if(group[j] == i){
				cout << (k? ",": "") << V[j];
				k++;
			}
		cout << "}" << endl;
	}
	cout << endl;
}

void partition(int j, int colocats){
	if(colocats == n) return write();
	for(int i = 0; i < p; i++){
		group[j] = i;
		partition(j + 1, colocats + 1);
	}
}

int main(){
	cin >> n;
	V = VS(n);
	group = VI(n);
	for(string& s : V) cin >> s;
	cin >> p;
	partition(0, 0);
}
