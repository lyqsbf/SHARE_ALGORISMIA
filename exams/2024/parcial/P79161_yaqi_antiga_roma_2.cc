//antiga roma 2 (solucio atenea)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


using VI = vector<int>;
using VVI = vector<VI>;


int n, m;
VVI M, R;


// maxim benefici amb les dones i, i + 1, ... i els homes j, j + 1, ...
int f(int i, int j) {
  if (i == n or j == m) return 0;
  int& res = R[i][j];
  if (res != -1) return res;
  return res = max({M[i][j] + f(i + 1, j + 1), f(i + 1, j), f(i, j + 1)});
}


void solucio(int i, int j) {
  if (i == n) return;

  if (j == m) {
    cout << 0 << endl;
    return solucio(i + 1, j);
  }

  int r1 = M[i][j] + f(i + 1, j + 1);
  int r2 = f(i + 1, j);
  int r3 = f(i, j + 1);
  if (r1 > r2 and r1 > r3) {
    cout << j + 1 << endl;
    solucio(i + 1, j + 1);
  }
  else if (r2 > r3) {
    cout << 0 << endl;
    solucio(i + 1, j);
  }
  else solucio(i, j + 1);
}


int main() {
  while (cin >> n >> m) {
    M = VVI(n, VI(m));
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j) cin >> M[i][j];

    R = VVI(n, VI(m, -1));
    cout << "benefici: " << f(0, 0) << endl;
    solucio(0, 0);
    cout << string(10, '-') << endl;
  }
}
