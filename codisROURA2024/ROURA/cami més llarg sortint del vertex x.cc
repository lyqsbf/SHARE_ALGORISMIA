// Donat un DAG, calcula per a cada vertex x
// la longitud del cami mes llarg que surt d'x.


#include <iostream>
#include <vector>
using namespace std;


using VI = vector<int>;
using VVI = vector<VI>;


VVI G;
VI R;


// longitud del cami mes llarg que surt d'x
int f(int x) {
  int& res = R[x];
  if (res != -1) return res;
  res = 0;
  for (int y : G[x]) res = max(res, 1 + f(y));
//  for (int i = 0; i < (int)G[x].size(); ++i)
//    res = max(res, 1 + f(G[x][i]));
  return res;
}


int main() {
  int n, m;
  while (cin >> n >> m) {
    G = VVI(n);
    while (m--) {
      int x, y;
      cin >> x >> y;
      G[x].push_back(y);
//      G[y].push_back(x); no dirigit
    }

    R = VI(n, -1);
    for (int x = 0; x < n; ++x) cout << f(x) << endl;
  }
}
