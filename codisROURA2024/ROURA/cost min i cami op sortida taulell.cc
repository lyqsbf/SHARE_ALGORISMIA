// Cost minim i cami optim per sortir d'un tauler amb peatges positius
// si nomes ens podem moure avall o a la dreta.


#include <iostream>
#include <vector>
using namespace std;


using VI = vector<int>;
using VVI = vector<VI>;


int n, m;
VVI M, R;


// cost minim de sortir del tauler estant a la posicio (i, j)
int f(int i, int j) {
  if (i >= n or j >= m) return 0;
  int& res = R[i][j];
  if (res != -1) return res;
  return res = M[i][j] + min(f(i + 1, j), f(i, j + 1));
}


// cami optim per sortir del tauler des de la posicio (i, j),
// cap avall en cas d'empat
void solucio(int i, int j) {
  if (i >= n or j >= m) {
    cout << endl;
    return;
  }
  
  if (f(i + 1, j) <= f(i, j + 1)) {
    cout << 'A';
    solucio(i + 1, j);
  }
  else {
    cout << 'D';
    solucio(i, j + 1);
  }
}


int main() {
  while (cin >> n >> m) {
    M = VVI(n, VI(m));
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j) cin >> M[i][j];

    R = VVI(n, VI(m, -1));
    cout << f(0, 0) << endl;
    solucio(0, 0);
  }
}
