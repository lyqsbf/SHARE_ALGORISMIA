// Diu si un graf dirigit te algun cicle.


#include <iostream>
#include <vector>
#include <stack>
using namespace std;


using VI = vector<int>;
using VVI = vector<VI>;


int main() {
  int n, m;
  cin >> n >> m;
  VVI G(n);
  VI grau(n, 0);
  while (m--) {
    int x, y;
    cin >> x >> y;
    G[x].push_back(y);
    ++grau[y];
  }

  stack<int> pila;
  for (int x = 0; x < n; ++x)
    if (grau[x] == 0) pila.push(x);

  int q = 0;
  while (not pila.empty()) {
    ++q;
    int x = pila.top(); pila.pop();
    for (int y : G[x])
      if (--grau[y] == 0) pila.push(y);
  }

  cout << (q < n ? "te algun cicle" : "no te cap cicle") << endl;
}
