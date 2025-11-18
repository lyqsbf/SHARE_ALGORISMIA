// P18760


#include <iostream>
#include <vector>
using namespace std;


using VC = vector<char>;
using VVC = vector<VC>;
using VI = vector<int>;
using VVI = vector<VI>;


VVC M;
VVI R;


// # maneres de sortir del tauler des de la posicio (i, j)
int f(int i, int j) {
  if (i < 0 or j < 0) return 1;
  int& res = R[i][j];
  if (res != -1) return res;
  if (M[i][j] == '*') return res = 0;
  if (M[i][j] == 'C') return res = f(i - 2, j - 1) + f(i - 1, j - 2);
  return res = f(i, j - 1) + f(i - 1, j) + f(i - 1, j - 1);
}


int main() {
  int n, m;
  while (cin >> n >> m) {
    M = VVC(n, VC(m));
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j) cin >> M[i][j];
  
    R = VVI(n, VI(m, -1));
    cout << f(n - 1, m - 1) << endl;
  }
}
