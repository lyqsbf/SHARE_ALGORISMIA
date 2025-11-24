#include <iostream>
#include <vector>
#include <string>
using namespace std;

using VS = vector<string>;
using VB = vector<bool>;
int n;
int m;
VS V;
VB usat;

void write(){
	int k = 0;
	cout << "{";
	for(int i = 0; i < m; i++){
		if(usat[i]){
			cout << (k ? ",": "") << V[i];
			k++;
		}
	}
	cout << "}" << endl;
}

void comb(int i, int select, int no_select){
	if(select < 0 or no_select < 0) return;
	if (i == m) return write();
	usat[i] = false;
	comb(i + 1, select, no_select - 1);
	usat[i] = true;
	comb(i + 1, select - 1, no_select);
}

int main(){
	cin >> n >> m;
	V = VS(m);
	usat = VB(m);
	for(string& s : V) cin >> s;
	comb(0, n, m-n);
}
