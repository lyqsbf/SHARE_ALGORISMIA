#include <iostream>
#include <vector>
using namespace std;


using VI = vector<int>;
using MI = vector<VI>;


VI arthur, bob;
MI common;


int find_common(int n, int m) {
	if (common[n][m] != -1) return common[n][m];
	
	if (n == 0 or m == 0) return common[n][m] = 0;
	
	if (arthur[n - 1] == bob[m - 1]) {
		return common[n][m] = 1 + find_common(n - 1, m - 1);
	}
	
	else {
		return common[n][m] = max(find_common(n - 1, m), find_common(n, m -1));
	}
}


int main() {
	int n, m;
	while (cin >> n >> m) {
		arthur = VI (n, 0);
		bob = VI (m, 0);
		
		for (int& score : arthur) cin >> score;
		for (int& score : bob) cin >> score;
		
		common = MI (n + 1, VI (m + 1, -1));
		cout << find_common(n, m) << endl;
	}
}
