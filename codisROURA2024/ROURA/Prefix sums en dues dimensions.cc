// "Prefix sums" en dues dimensions.


#include <iostream>
#include <vector>
using namespace std;


using VI = vector<int>;
using VVI = vector<VI>;
using VB = vector<bool>;
using VVB = vector<VB>;


VVI M, P;
VVB calculat;


// suma de tots els elements en posicions (x, y) amb x <= i i y <= j
int f(int i, int j) {
  if (i < 0 or j < 0) return 0;
  int& res = P[i][j];
  if (calculat[i][j]) return res;
  calculat[i][j] = true;
  return res = f(i, j - 1) + f(i - 1, j) - f(i - 1, j - 1) + M[i][j];
}


int main() {
  int n, m;
  cin >> n >> m;
  M = VVI(n, VI(m));
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) cin >> M[i][j];

  P = VVI(n, VI(m));
  calculat = VVB(n, VB(m, false));

  int i1, j1, i2, j2;
  while (cin >> i1 >> j1 >> i2 >> j2)
    cout << f(i2, j2) - f(i2, j1 - 1) - f(i1 - 1, j2) + f(i1 - 1, j1 - 1)
         << endl;
}
