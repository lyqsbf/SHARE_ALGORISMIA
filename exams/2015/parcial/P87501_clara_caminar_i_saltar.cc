#include <iostream>
#include <vector>
using namespace std;


using VC = vector<char>;
using VVC = vector<VC>;
using VI = vector<long long>;
using VVI = vector<VI>;
int const N = 1e8+7;

int main(){
	int n, m;
	while (cin >> n >> m) {
		VVC V = VVC(n, VC(m));
		VVI dp = VVI(n, VI(m, 0));
		for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> V[i][j];
		dp[0][0] = 1;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (V[i][j] == '.')  {
					if (i == 0 and j == 0);
					else if (i == 0 and V[i][j - 1] == '.') dp[i][j] = (dp[i][j] + dp[i][j - 1])%N;
					else if (i == 0 and j > 1) dp[i][j] = (dp[i][j] + dp[i][j - 2])%N;
					else if (j == 0 and V[i - 1][j] == '.') dp[i][j] = (dp[i][j] + dp[i - 1][j])%N;
					else if (j == 0 and i > 1) dp[i][j] = (dp[i][j] + dp[i - 2][j])%N;
					else if (V[i - 1][j] == 'X' and V[i][j - 1] == 'X' and i > 1 and j > 1) dp[i][j] = (dp[i][j] + dp[i - 2][j] + dp[i][j - 2])%N;
					else if (V[i - 1][j] == 'X' and i > 1) dp[i][j] = (dp[i][j] + dp[i - 2][j] + dp[i][j - 1])%N;
					else if (V[i][j - 1] == 'X' and j > 1) dp[i][j] = (dp[i][j] + dp[i][j - 2] + dp[i - 1][j])%N;
					else dp[i][j] = (dp[i][j] + dp[i -1][j] + dp[i][j - 1])%N;
					
				}
			}
		} 
		//for (int i = 0; i < n; ++i) {
			//for (int j = 0; j < m; ++j) {
				 //cout << ' ' << dp[i][j];
			// }
			 //cout << endl;
		 //}
		 //cout << endl;
		cout << dp[n - 1][m - 1]%N << endl;
	}
}
