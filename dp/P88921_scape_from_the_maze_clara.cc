#include <iostream>
#include <vector>
#include <string>
using namespace std;


using VI = vector<long long>;
using MI = vector<VI>;
using VC = vector<char>;
using MC = vector<VC>;
MC mapa;
MI dp;


int main() {
	int n, m;
	while (cin >> n >> m and n + m != 0) {
		mapa = MC(n, VC(m));
		dp = MI(n, VI(m, 0));
		for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> mapa[i][j];
		if (mapa[n - 1][m - 1] != 'X') dp[n - 1][m - 1] = 1;
		for (int i = n - 1; i > -1; --i) {
			for (int j = m - 1; j > -1; --j) {
				if (mapa[i][j] != 'X') {
					if (i - 1 > -1 and mapa[i - 1][j] != 'X') {
						if (dp[i][j] >= 1e6) dp[i - 1][j] = 1e7;
						else dp[i - 1][j] += dp[i][j];
					}
					if (j - 1 > -1 and mapa[i][j - 1] != 'X') {
						if (dp[i][j] >= 1e6) dp[i][j - 1] = 1e7;
						else dp[i][j - 1] += dp[i][j];
					}
				}
			}
		}
		if (dp[0][0] >= 1e6) cout << "!!!" << endl;
		else cout << dp[0][0] << endl;
	}
}
