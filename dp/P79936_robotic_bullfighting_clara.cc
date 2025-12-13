#include <iostream>
#include <vector>
using namespace std;


using VI = vector<int>;
using VVI = vector<VI>;


int main() {
	int w, h, c;
	cin >> w >> h >> c;
	VVI bulls(w, VI(h));
	for (int i = 0; i < w; ++i) for (int j = 0; j < h; ++j) cin >> bulls[i][j];
	VVI red(w - c + 1, VI(h - c + 1));
	int max = 0;
	int f1, f2;
	f1 = f2 = 0;
	for (int i = 0; i < w - c + 1; ++i) {
		for (int j = 0; j < h - c + 1; ++j) {
			if (j == 0) {
				int sum = 0;
				for (int k = 0; k < c; ++k) {
					for (int t = 0; t < c; ++t) {
						sum += bulls[i + k][j + t];
					}
				}
				red[i][j] = sum;
			}
			else {
				int sum = red[i][j - 1];
				for (int k = 0; k < c; ++k) {
					sum -= bulls[i + k][j - 1];
					sum += bulls[i + k][j + c - 1];
				}
				red[i][j] = sum;
			}
			
			if (red[i][j] > max) {
				max = red[i][j];
				f1 = i;
				f2 = j;
			}
		}
	}
	
	cout << f1 << ' ' << f2 << endl;
}
