#include <iostream>
#include <vector>
using namespace std;


using VI = vector<int>;
using VB = vector<bool>;
VB usat;
VI V;
int n;


void escriu() {
	for (int i = 0; i < n; ++i) {
		if (i == 0) cout << V[i];
		else cout << ' ' << V[i];
	}
	cout << endl;
}


void f(int i) {
	if (i == n) escriu();
	
	for (int k = 0; k < n; ++k) {
		if (usat[k] == false) {
			if (i == 0 or (V[i - 1] != k - 1 and V[i - 1] != k + 1)) {
				V[i] = k;
				usat[k] = true;
				f(i + 1);
				usat[k] = false;
			}
		}
	}
}


int main(){
	while (cin >> n){
		V = VI(n);
		usat = VB(n, false);
		f(0);
		cout << "********************" << endl;
	}
}
