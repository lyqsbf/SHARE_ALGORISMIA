// Distancia d'edicio.


#include <iostream>
#include <vector>
using namespace std;


using ll = long long;
using VL = vector<ll>;
using VVL = vector<VL>;


string s, t;
VVL D;


// distancia d'edicio entre s[0..i-1] i t[0..j-1]
ll dis(int i, int j) {
  ll& res = D[i][j];
  if (res != -1) return res;
  if (i == 0) return res = j;
  if (j == 0) return res = i;
  if (s[i-1] == t[j-1]) return res = dis(i - 1, j - 1);
  return res = 1 + min(dis(i - 1, j - 1),
                 min(dis(i - 1, j), dis(i, j - 1)));
}


int main() {
  while (cin >> s >> t) {
    int n = s.size();
    int m = t.size();
    D = VVL(n + 1, VL(m + 1, -1));
    cout << dis(n, m) << endl;
  }
}
