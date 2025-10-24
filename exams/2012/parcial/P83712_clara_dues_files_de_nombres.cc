#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


using VI = vector<int>;
using VB = vector<bool>;
VB usat;
VI V, X, Y;
int n;


void escriu(){
	for (int i = 0; i < n; ++i) {
		if (i == 0) cout << X[i];
		else cout << ' ' << X[i];
	}
	cout << endl;
	for (int i = 0; i < n; ++i) {
		if (i == 0) cout << Y[i];
		else cout << ' ' << Y[i];
	}
	cout << endl;
	cout << endl;
}


void f(int i){
	if (i == 2*n) escriu();
	
	
	for (int k = 0; k < 2*n; ++k){
		if (usat[k] == false){
			if (i < n) {
				if (i == 0) {
					X[i] = V[k];
					usat[k] = true;
					f(i + 1);
					usat[k] = false;
				}
				else if (X[i - 1] < V[k]) {
					X[i] = V[k];
					usat[k] = true;
					f(i + 1);
					usat[k] = false;
				}
			}
			else{
				if (X[i - n] < V[k]){
					if (i - n == 0) {
						Y[i - n] = V[k];
						usat[k] = true;
						f(i + 1);
						usat[k] = false;
					}
					else if (Y[i - n - 1] < V[k]){
						Y[i - n] = V[k];
						usat[k] = true;
						f(i + 1);
						usat[k] = false;
					}
					else return;
				}
				else return;
			}
		}
	}
	return;
}


int main(){
	cin >> n;
	V = VI(2*n);
	X = Y = VI(n);
	usat = VB(2*n, false);
	for (int i = 0; i < 2*n; ++i) cin >> V[i];
	sort(V.begin(), V.end());
	f(0);
}
