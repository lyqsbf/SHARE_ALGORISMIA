#include <iostream>
#include <vector>
using namespace std;


using VC = vector<char>;
using VVC = vector<VC>;
VC V;
VVC cas;
int n, m, k, cont;


void escriu() {
	for (int i = 0; i < n*m; ++i) {
		if (V[i] == '0') break;
		cout << V[i];
	}
	cout << endl;
}


void f(int i, int j, int y) {
	if (i == n - 1 and j == m - 1 and cont == k) {
		escriu();
		return;
	}
	
	if (i == n - 1 and j == m - 1) return;
	
	if (i < n -1) {
		if (cas[i + 1][j] == 'X' and cont < k) {
			++cont;
			V[y] = 'D';
			f(i + 1, j, y + 1);
			--cont;
		}
		if (cas[i + 1][j] == '.') {
			V[y] = 'D';
			f(i + 1, j, y + 1);
		}
	}
	
	if (j < m - 1) {
		if (cas[i][j + 1] == 'X' and cont < k) {
			++cont;
			V[y] = 'R';
			f(i, j + 1, y + 1);
			--cont;
		}
		if (cas[i][j + 1] == '.') {
			V[y] = 'R';
			f(i, j + 1, y + 1);
		}
	}
	
	return;
}


int main() {
	while (cin >> n >> m >> k){
		cont = 0;
		V = VC(n*m, '0');
		cas = VVC(n, VC(m));
		for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> cas[i][j];
		if (cas[0][0] == 'X') ++cont;
		f(0, 0, 0);
		cout << "----------" << endl;
	}
}
