#include <iostream>
#include <vector>
using namespace std;


using VI = vector<int>;
using VB = vector<bool>;
VB usat;
VI V;
int n;
int cont = 0;


void f(int i, int e, int d){
	if (i == n) {
		++cont;
		return;
	}
	
	for (int k = 0; k < n; ++k){
		if (usat[k] == false) {
			if (d + V[k] <= e){
				usat[k] = true;
				f (i + 1, e, d +V[k]);
			}
			usat[k] = true;
			f(i + 1, e + V[k], d);
			usat[k] = false;
		}
	}
}


int main(){
	while (cin >> n) {
		V = VI(n);
		usat = VB(n, false);
		for (int i = 0; i < n; ++i) {
			int s;
			cin >> s; 
			V[i] = s;
		}
		f(0, 0, 0);
		cout << cont << endl;
		cont = 0;
	}
}
