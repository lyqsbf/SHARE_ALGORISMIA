// Calcula els components fortament connexos d'un graf dirigit.


#include <iostream>
#include <vector>
using namespace std;


using VI = vector<int>;
using VVI = vector<VI>;


VVI G, I;
VI vist, vertex, repre;
int temps = 0;


void dfs1(int x) {
  if (vist[x]) return;
  vist[x] = true;
  for (int y : I[x]) dfs1(y);
  vertex[temps++] = x;
}


void dfs2(int x, int r) {
  if (repre[x] != -1) return;
  repre[x] = r;
  for (int y : G[x]) dfs2(y, r);
  cout << x << endl;
}


int main() {
  int n, m;
  cin >> n >> m;
  G = I = VVI(n);
  while (m--) {
    int x, y;
    cin >> x >> y;
    G[x].push_back(y);
    I[y].push_back(x);
  }

  vist = VI(n, false);
  vertex = VI(n);
  for (int x = 0; x < n; ++x) dfs1(x);

  int q = 0;
  repre = VI(n, -1);
  for (int t = n - 1; t >= 0; --t) {
    int x = vertex[t];
    if (repre[x] == -1) {
      dfs2(x, x);
      cout << string(10, '-') << endl;
      ++q;
    }
  }

  cout << endl;
  cout << "nombre de components connexos: " << q << endl;
  cout << endl;
  cout << "representant de cada vertex:" << endl;
  for (int x = 0; x < n; ++x) cout << x << ' ' << repre[x] << endl;
}
