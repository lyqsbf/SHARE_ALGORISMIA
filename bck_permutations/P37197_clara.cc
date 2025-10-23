#include <iostream>
#include <vector>
using namespace std;


using VC = vector<char>;
using VVC = vector<VC>;
using VB = vector<bool>;
using VVB = vector<VB>;
int n, m;
VC esp;
VC V;
VB posat;
VVB compatibles;



void escriu(){
	for(int i = 0; i < n; ++i) cout << V[i];
	cout << endl;
}


void f(int i, int ant){
	if (i == n) escriu();
	
	
	for (int k = 0; k < n; ++k){
		if (posat[k] == false){
			if (i == 0 or compatibles[ant][k] == true){
				V[i] = esp[k];
				posat[k] = true;
				f(i + 1, k);
				posat[k] = false;
			}
		}
	}
}


int main(){
	cin >> n;
	esp = V = VC(n);
	posat = VB(n, false);
	compatibles = VVB(n, VB(n, true));
	
	for (int i = 0; i < n; ++i){
		char c; 
		cin >> c;
		esp[i] = c;
	}
	
	cin >> m;
	
	for (int i = 0; i < m; ++i) {
		char e1, e2;
		cin >> e1 >> e2;
		
		for (int j = 0; j < n; ++j) {
			if (e1 == esp[j]) {
				for (int k = 0; k < n; ++k){
					if (e2 == esp[k]) compatibles[j][k]  = compatibles [k][j] = false;
				}
			}
		}
	}
	
	
	f(0, -1);
}
