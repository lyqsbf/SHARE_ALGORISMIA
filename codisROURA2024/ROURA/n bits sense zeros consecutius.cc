// Nombre de sequencies d'n bits sense zeros consecutius.


#include <iostream>
#include <vector>
using namespace std;


const int N = 51;


using ll = long long;
using VL = vector<ll>;


VL Z(N, -1);
VL U(N, -1);


ll u(int n);


// # sequencies d'n bits sense dos o mes 0s adjacents, acabades en 0
ll z(int n) {
  ll& res = Z[n];
  if (res != -1) return res;
  if (n == 1) return res = 1;
  return res = u(n - 1);
}


// # sequencies d'n bits sense dos o mes 0s adjacents, acabades en 1
ll u(int n) {
  ll& res = U[n];
  if (res != -1) return res;
  if (n == 1) return res = 1;
  return res = z(n - 1) + u(n - 1);
}


int main() {
  int n;
  while (cin >> n) cout << z(n) + u(n) << endl;
}
