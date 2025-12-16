#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	while(n--) {
		vector<vector<char>> M(3, vector<char>(3));
		int nx = 0, no = 0;
		for (int i = 0; i < 3; ++i)
			for (char& j : M[i]) {
				cin >> j;
				if (j == 'X') ++nx;
				else if (j == 'O') ++no;
			}
		if (nx == 1 and no == 0) cout << 'X' << endl;
		else if (nx > no) cout << 'O' << endl;
		else cout << 'X' << endl;
	}
}
