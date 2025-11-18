// P22482


#include <iostream>
#include <vector>
using namespace std;


using VD = vector<double>;
using VVD = vector<VD>;


int m, n;
VD prob;
VVD R;


// probabilitat que l'Anna guanyi si han sortit exactament h cares i t creus
double f(int h, int t) {
  double& res = R[h][t];
  if (res != -1) return res;
  if (h == m) return res = 1;
  if (t == n) return res = 0;
  return res = prob[t]*f(h + 1, t) + (1 - prob[t])*f(h, t + 1);
}


int main() {
  cout.setf(ios::fixed);
  cout.precision(4);

  while (cin >> m >> n) {
    prob = VD(n);
    for (double& p : prob) cin >> p;

    R = VVD(m + 1, VD(n + 1, -1));
    cout << f(0, 0) << endl;
  }
}
