// Compta els components connexos d'un graf no dirigit,
// i escriu per separat els vertexs de cada component.


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
  cout << x << endl;
  for (int y : G[x]) dfs(y);
}


int main() {
  int n, m;
  while (cin >> n >> m) {
    G = VVI(n);
    while (m--) {
      int x, y;
      cin >> x >> y;
      G[x].push_back(y);
      G[y].push_back(x);
    }

    vist = VB(n, false);
    int res = 0;
    for (int x = 0; x < n; ++x)
      if (not vist[x]) {
        ++res;
        dfs(x);
        cout << string(10, '-') << endl;
      }
    cout << "nombre components: " << res << endl;
  }
}
