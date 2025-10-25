#include <iostream>
#include <vector>
using namespace std;


using VI = vector<int>;
using VVI = vector<VI>;
using VB = vector<bool>;
VB usat;
VVI V;
VI H;
int n, cost;


void escriu(){
	cout << 0;
	for (int i = 0; i < n; ++i) cout << ' ' << H[i];
	cout << " (" << cost << ')';
	cout << endl;
}


void f(int i, int ant){
	if (i == n and H[n - 1] == 0) escriu();
	
	for (int k = 0; k < n; ++k){
		if (usat[k] == false and V[ant][k] != 0){
			usat[k] = true;
			H[i] = k;
			cost += V[ant][k];
			f(i + 1, k);
			cost -= V[ant][k];
			usat[k] = false;
		}
	}
}


int main(){
	while (cin >> n){
		V = VVI(n, VI(n));
		for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> V[i][j];
		H = VI(n);
		usat = VB(n, false);
		cost = 0;
		f(0, 0);
		cout << "--------------------" << endl;
	}
}
