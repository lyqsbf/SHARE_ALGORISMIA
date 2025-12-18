#include <iostream>
#include <vector>
using namespace std;


vector<double> p;
vector<vector<double>> M;

double f(int i, int j) {
	double& d = M[i][j];
	if (d != -1) return d;
	if (i - 1 > j) return d = 0;
	if (i == 0) return d = (1 - p[j]) * f(0, j - 1);
	return d = (f(i - 1, j - 1) - f(i, j - 1)) * p[j] + f(i, j - 1);
}

int main() {
	cout.setf(ios::fixed);
	cout.precision(4);

	int n, k;
	while (cin >> n >> k) {
		if (n) {
			p = vector<double>(n);
			for (double& x : p) cin >> x;
			M = vector<vector<double>>(k + 1, vector<double>(n, -1));
			M[0][0] = 1 - p[0];
			if (k) M[1][0] = p[0];
			cout << f(k, n - 1) << endl;
		}
		else cout << 1.0000 << endl;
	}
}
