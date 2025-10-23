//experiment fisic 2 (solucio atenea)
#include <iostream>
#include <vector>
using namespace std;


using VC = vector<char>;
using VVC = vector<VC>;
using VD = vector<double>;
using VVD = vector<VD>;


double p;
int n, m;
VVC M;
VVD R;


// probabilitat de sortir si estem a (i, j)
double f(int i, int j) {
  if (i == n or j == m) return 1;
  double& res = R[i][j];
  if (res != -1) return res;
  if (M[i][j] == 'X') return res = 0;
  if (M[i][j] == 'D') return res = f(i, j + 1);
  if (M[i][j] == 'A') return res = f(i + 1, j);
  return res = p*f(i, j + 1) + (1 - p)*f(i + 1, j);
}


int main() {
  cout.setf(ios::fixed);
  cout.precision(4);

  while (cin >> p >> n >> m) {
    M = VVC(n, VC(m));
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j) cin >> M[i][j];

    R = VVD(n, VD(m, -1));
    cout << f(0, 0) << endl;
  }
}
