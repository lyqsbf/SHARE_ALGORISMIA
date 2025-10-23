#include <iostream>
#include <vector>
using namespace std;


using VI = vector<int>;
using VB = vector<bool>;
using VVI = vector<VI>;
int n;
VI V;
VB usat;
VI suma;
VI resta;


void escriu(){
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			if (V[i] == j) cout << 'Q';
			else cout << '.';
		}
		cout << endl;
	}
	cout << endl;
}


bool diag(int i, int j){
	for (int k = 0; k < i; ++k){
		if (suma[k] == i + j) return false;
		if (resta[k] == i - j) return false;
	}
	return true;
}


void f(int i){
	if (i == n) escriu();
	
	else{
		for(int j = 0; j < n; ++j){
			if (usat[j] == false and diag(i, j) == true){
				V[i] = j;
				usat[j] = true;
				suma[i] = i + j;
				resta[i] = i - j;
				f(i + 1);
				usat[j] = false;
				suma[i] = -1;
				resta[i] = n;
			}
		}
	}	
}


int main(){
	cin >> n;
	V = VI(n);
	suma = VI(n, -1);
	resta = VI(n, n);
	usat = VB(n, false);
	f(0);
}
