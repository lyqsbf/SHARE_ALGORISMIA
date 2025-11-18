// Diu si un graf no dirigit es un bosc (si no te cicles). Versio 1.


#include <iostream>
#include <vector>
using namespace std;


using VI = vector<int>;
using VVI = vector<VI>;
using VB = vector<bool>;


int n;
VVI G;
VB vist;


// retorna el nombre de vertexs i el (doble del) nombre d'arestes del component
void dfs(int x, int& v, int& a) {
  if (vist[x]) return;
  vist[x] = true;
  ++v;
  a += G[x].size();
  for (int y : G[x]) dfs(y, v, a);
}


bool es_bosc() {
  vist = VB(n, false);
  for (int x = 0; x < n; ++x)
    if (not vist[x]) {
      int v = 0;
      int a = 0;
      dfs(x, v, a);
      if (a > 2*(v - 1)) return false;
    }
  return true;
}


int main() {
  int m;
  while (cin >> n >> m) {
    G = VVI(n);
    while (m--) {
      int x, y;
      cin >> x >> y;
      G[x].push_back(y);
      G[y].push_back(x);
    }
    cout << (es_bosc() ? "si" : "no") << endl;
  }
}
