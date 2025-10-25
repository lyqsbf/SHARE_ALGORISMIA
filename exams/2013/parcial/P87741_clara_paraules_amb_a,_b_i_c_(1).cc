#include <iostream>
#include <vector>
using namespace std;


using VC = vector<char>;
VC V;
int n, f;


void escriu(){
	for (int i = 0; i < n; ++i) cout << V[i];
	cout << endl;
}


void g(int i){
	if (i == n) {
		escriu();
		return;
	}
	
	if (i != 0 and V[i - 1] == V[i]) return;
	
	if (V[i] != '0') g(i + 1);
	else{
		for (int k = 0; k < 3; ++k){
			if (i != 0 and V[i - 1] == 'a' + k) continue;
			V[i] = 'a' + k;
			g(i + 1);
			V[i] = '0';
		}
	}
}


int main(){
	while (cin >> n >> f){
		V = VC(n, '0');
		for (int i = 0; i < f; ++i){
			int pos;
			cin >> pos;
			cin >> V[pos];
		}
		g(0);
		cout << "--------------------" << endl;
	}
}
