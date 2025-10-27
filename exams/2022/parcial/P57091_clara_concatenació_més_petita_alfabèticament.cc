#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


using VS = vector<string>;
using VB = vector<bool>;
VB usat;
int n;
VS V, P;
bool fet;


void escriu(){
	for (int i = 0; i < n; ++i) {
		cout << P[i];
	}
	cout << endl;
}



void f(int i) {
	if (i == n) {
		if (fet == true) return;
		else {
			escriu();
			fet = true;
		}
	}
	
	for (int k = 0; k < n; ++k){
		if (fet == true) break;
		if (i == 0 and usat[k] == false) {
			P[i] = V[k];
			usat[k] = true;
			f(i + 1);
			usat[k] = false;
		}
		else if (usat[k] == false) {
			int n = P[i - 1].size();
		
			if (P[i - 1][n - 1] != V[k][0]) {
				P[i] = V[k];
				usat[k] = true;
				f(i + 1);
				usat[k] = false;
			}
		}
	}	
}


int main() {
	while (cin >> n) {
		fet = false;
		V = P = VS(n);
		usat = VB(n, false);
		for (int i = 0; i < n; ++i) cin >> V[i];
		sort(V.begin(), V.end());
		f(0);
		if (fet == false) cout << "NO" << endl;
	}
}
