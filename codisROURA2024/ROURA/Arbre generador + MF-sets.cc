// Arbre generador + MF-sets


#include <iostream>
#include <vector>
using namespace std;


using P = pair<int, int>;
using VP = vector<P>;
using VI = vector<int>;


int n, m;
VP V;
VI pare;


int repre(int x) {
  if (pare[x] == -1) return x;
  int r = repre(pare[x]);
  pare[x] = r;
  return r;
}


void arbre_generador() {
  int q = n;
  pare = VI(n, -1);
  for (auto [x, y] : V) {
    int rx = repre(x);
    int ry = repre(y);
    if (rx != ry) {
      pare[ry] = rx;
      cout << x << ' ' << y << endl;
      if (--q == 1) return; // suposant n > 1
    }
  }
}


int main() {
  cin >> n >> m;
  V = VP(m);
//  for (P& p : V) cin >> p.first >> p.second;
  for (auto& [x, y] : V) cin >> x >> y;
  arbre_generador();
}
