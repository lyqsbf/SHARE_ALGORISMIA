// Calcula el cost esperat minim d'un BST a partir de les probabilitats
// d'acces a cadascuna de les n claus. Suposa que no hi ha probabilitats 0.
// Es una programacio dinamica amb cost quadratic en espai i cubic en temps.


#include <iostream>
#include <vector>
using namespace std;


const double INF = 1e9;


using VD = vector<double>;
using VVD = vector<VD>;


VD prob;
VVD R;


// cost optim esperat d'acces al subarbre [e..d]
// total es un parametre redundant amb la suma prob[e..d]
double f(int e, int d, double total) {
  if (e > d) return 0; // arbre buit

  double& res = R[e][d];
  if (res != -1) return res;

  res = INF;
  double esquerra = 0; // suma de probabilitats del fill esquerra
  double dreta = total; // suma de probabilitats del fill dret
  for (int a = e; a <= d; ++a) { // provem totes les arrels possibles
    dreta -= prob[a];
    res = min(res, 1 + esquerra/total*f(e, a - 1, esquerra)
                     + dreta/total*f(a + 1, d, dreta));
    esquerra += prob[a];
  }
  return res;
}


int main() {
  int n;
  while (cin >> n) {
    prob = VD(n);
    for (double& p : prob) cin >> p;

    R = VVD(n, VD(n, -1));
    cout << f(0, n - 1, 1) << endl;
  }
}
