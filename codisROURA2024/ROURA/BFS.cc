// Escriu els vertexs d'un graf en ordre de distancia a un vertex inicial.
// No escriu els vertexs als quals no es pot arribar.


#include <iostream>
#include <vector>
#include <queue>
using namespace std;


using VI = vector<int>;
using VVI = vector<VI>;
using VB = vector<bool>;


int n;
VVI G;


void BFS(int ini) {
  VB vist(n, false);
  queue<int> Q;
  vist[ini] = true;
  Q.push(ini);
  cout << ini << endl;
  while (not Q.empty()) {
    int x = Q.front(); Q.pop();
    for (int y : G[x])
      if (not vist[y]) {
        vist[y] = true;
        Q.push(y);
        cout << y << endl;
      }
  }
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
