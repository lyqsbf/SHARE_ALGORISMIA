#include <iostream>
#include <vector>
using namespace std;


using VI = vector<long long>;
using VVI = vector<VI>;
VI taula;
VVI terminacions;


void seq(int n) {
	if (taula[n - 1] != -1) {
		taula[n] = terminacions[0][n - 1] + 2*terminacions[1][n - 1] + terminacions[2][n - 1];
		terminacions[0][n] = terminacions[1][n - 1] + terminacions[2][n - 1];
		terminacions[1][n] = terminacions[0][n - 1];
		terminacions[2][n] = terminacions[1][n - 1];
		return;
	}
	
	else {
		seq(n - 1);
		seq(n);
	}
}


int main() {
	int n;
	taula = VI(151, -1);
	terminacions = VVI(3, VI(151, -1));
	taula[0] = 1;
	taula[1] = 2;
	taula[2] = 3;
	terminacions[0][2] = terminacions[1][2] = terminacions[2][2] = 1;
	while (cin >> n) {
		if (taula[n] != -1) cout << taula[n] << endl;
		else {
			seq(n);
			cout << taula[n] << endl;
		}
	}
}
