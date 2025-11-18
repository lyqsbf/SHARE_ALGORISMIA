// Escriu la distancia minima per arribar a cada vertex des d'un vertex inicial.
// Escriu -1 per als vertexs als quals no es pot arribar.


#include <iostream>
#include <vector>
#include <queue>
using namespace std;


using VI = vector<int>;
using VVI = vector<VI>;


int n;
VVI G;


void BFS(int ini) {
  VI dist(n, -1);
  queue<int> Q;
  dist[ini] = 0;
  Q.push(ini);
  while (not Q.empty()) {
    int x = Q.front(); Q.pop();
    for (int y : G[x])
      if (dist[y] == -1) {
        dist[y] = dist[x] + 1;
        Q.push(y);
      }
  }

  for (int x = 0; x < n; ++x)
    cout << x << ' ' << dist[x] << endl;
}


int main() {
  int m;
  cin >> n >> m;
  G = VVI(n);
  while (m--) {
    int x, y;
    cin >> x >> y;
    G[x].push_back(y);
    G[y].push_back(x);
  }

  int ini;
  cin >> ini;
  BFS(ini);
}
