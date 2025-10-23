#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> M;
int bp, bc;
vector<int> s, u, bs;

void max_profit(int i, int p) {
	if (i == n) {
		if (bp < p) {
			bp = p;
			bs = s;
			bc = 1;
		}
		else if (bp == p) ++bc;
		return;
	}

	for (int j = 0; j < m; ++j){
		if (not u[j]) {
			u[j] = true;
			s[i] = j;
			max_profit(i + 1, p + M[i][j]);
			u[j] = false;
		}
	}
}

int main() {
	while (cin >> n >> m) {
	M = vector<vector<int>>(n, vector<int>(m));
	for (auto& Mi : M)
		for (auto& Mij: Mi)
			cin >> Mij;

	s = vector<int>(n);
	u = vector<int>(m, false);
	bp = 0;
	max_profit(0, 0);

	cout << "benefici: " << bp << endl;
	if (bc == 1)
		for (int bsi : bs) cout << bsi + 1 << endl;
	else cout << bc << " solucions" << endl;
	cout << string(10, '-') << endl;
	}
}
