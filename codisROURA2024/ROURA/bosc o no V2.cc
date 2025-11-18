// Diu si un graf no dirigit es un bosc (si no te cicles). Versio 2.


#include <iostream>
#include <vector>
using namespace std;


using VI = vector<int>;
using VVI = vector<VI>;
using VB = vector<bool>;


VVI G;
VB vist;


void dfs(int x) {
  if (vist[x]) return;
  vist[x] = true;
  for (int y : G[x]) dfs(y);
}


int main() {
  int n, m;
  while (cin >> n >> m) {
    G = VVI(n);
    for (int r = 0; r < m; ++r) {
      int x, y;
      cin >> x >> y;
      G[x].push_back(y);
      G[y].push_back(x);
    }

    vist = VB(n, false);
    int q = 0;
    for (int x = 0; x < n; ++x)
      if (not vist[x]) {
        ++q;
        dfs(x);
      }
    cout << (q + m == n ? "si" : "no") << endl;
  }
}
