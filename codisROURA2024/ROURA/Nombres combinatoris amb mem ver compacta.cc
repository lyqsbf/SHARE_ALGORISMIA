// Nombres combinatoris. Versio eficient amb memoization.
// Versio compacta.


#include <iostream>
#include <vector>
using namespace std;


const int N = 51;


using ll = long long;
using VL = vector<ll>;
using VVL = vector<VL>;


VVL C(N, VL(N, -1));


ll combi(int n, int x) {
  ll& res = C[n][x];
  if (res != -1) return res;
  if (x == 0 or x == n) return res = 1;
  return res = combi(n - 1, x - 1) + combi(n - 1, x);
}


int main() {
  int n, x;
  while (cin >> n >> x) cout << combi(n, x) << endl;
}
