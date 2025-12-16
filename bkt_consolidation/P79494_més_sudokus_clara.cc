#include <iostream>
#include <vector>
using namespace std;


using VI = vector<int>;
using VVI = vector<VI>;
using VVVI = vector<VVI>;


VVI S(9, VI(9));
VVI fila, colu;
VVVI quad;
bool sol;


void escriu() {
	for (int i = 0; i < 9; ++i) {
		if (i == 3 or i == 6) cout << "------+-------+------" << endl;
		for (int j = 0; j < 9; ++j){
			if (j == 0) cout << S[i][j];
			else if (j == 3 or j == 6) cout << " | " << S[i][j];
			else cout << ' ' << S[i][j];
		}
		cout << endl;
	}
	cout << endl;
}


void f(int i, int j) {
  if (j == 9) return f(i + 1, 0);

  if (i == 9) {
    escriu();
    sol = true;
    return;
  }

  if (S[i][j]) return f(i, j + 1);

  for (int x = 1; x <= 9; ++x){
    if (not fila[i][x] and not colu[j][x] and not quad[i/3][j/3][x]) {
      fila[i][x] = colu[j][x] = quad[i/3][j/3][x] = true;
      S[i][j] = x;
      f(i, j + 1);
      S[i][j] = 0;
      fila[i][x] = colu[j][x] = quad[i/3][j/3][x] = false;
    }
	}
	return;
}


int main() {
  int t;
  cin >> t;
  while (t--) {
	sol = false;
    fila = colu = VVI(9, VI(10, false));
    quad = VVVI(3, VVI(3, VI(10, false)));
    char k;
        for (int i = 0; i < 9; ++i){
            for (int j = 0;j < 9; ++j){
                cin >> k;
                while (k == '-' or k == '|' or k == '+') cin >> k;
                int num = k - '0';
                S[i][j] = num;
                if (k != '0') {
                    fila[i][num] = colu[j][num] = quad[i/3][j/3][num] = true;
                }
            }
        }
        f(0, 0);
        
        if (sol == false) {
			cout << "no solution" << endl;
		}
		cout << "******************************" << endl;
    }
}
