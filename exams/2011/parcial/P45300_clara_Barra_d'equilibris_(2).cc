#include <iostream>
#include <vector>
using namespace std;

using VI = vector<long long>;
using VVI = vector<VI>;
VI V;
int m, n;
VVI memo;


int main(){
	cin >> m >> n;
	V = VI(n);
	memo = VVI(m + 1, VI(n + 1, 0));
	for (int i = 0; i < n; ++i){
		int k;
		cin >> k;
		V[i] = k;
	}
	memo[m/2][0] = 1;
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m + 1; ++j){
			if (j - V[i] >= 0) memo[j - V[i]][i + 1] = (memo[j - V[i]][i + 1] + memo[j][i])%100000007;
			if (j + V[i] <= m) memo[j + V[i]][i + 1] = (memo[j + V[i]][i + 1] + memo[j][i])%100000007;
		}
	}
	for (int i = 0; i < m + 1; ++i) {
		if (memo[i][n] != 0) cout << i - m/2 << ' ' << memo[i][n] << endl;
	}
	//for (int i = 0; i < m + 1; ++i) cout << memo[i] << ' ';
}
