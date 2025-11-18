// Cost minim de sortir d'un tauler amb peatges positius
// si nomes ens podem moure avall o a la dreta.


#include <iostream>
#include <vector>
using namespace std;


using VI = vector<int>;
using VVI = vector<VI>;


int n, m;
VVI M, R;


// cost minim de sortir del tauler estan a la posicio (i, j)
int f(int i, int j) {
  if (i >= n or j >= m) return 0;
  int& res = R[i][j];
  if (res != -1) return res;
  return res = M[i][j] + min(f(i + 1, j), f(i, j + 1));
}


int main() {
  while (cin >> n >> m) {
    M = VVI(n, VI(m));
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j) cin >> M[i][j];

    R = VVI(n, VI(m, -1));
    cout << f(0, 0) << endl;
  }
}
