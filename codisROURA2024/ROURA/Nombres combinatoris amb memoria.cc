// Nombres combinatoris. Versio eficient amb memoization.


#include <iostream>
#include <vector>
using namespace std;


const int N = 51;


using ll = long long;
using VL = vector<ll>;
using VVL = vector<VL>;


VVL C(N, VL(N, -1));


ll combi(int n, int x) {
  if (C[n][x] != -1) return C[n][x];
  if (x == 0 or x == n) {
    C[n][x] = 1;
    return 1;
  }
  C[n][x] = combi(n - 1, x - 1) + combi(n - 1, x);
  return C[n][x];
}


int main() {
  int n, x;
  while (cin >> n >> x) cout << combi(n, x) << endl;
}
