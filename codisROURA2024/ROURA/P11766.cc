// P11766
 

#include <iostream>
#include <vector>
using namespace std;


const int N = 51;
const int MOD = 1e8 + 7;


using VI = vector<int>;
using VVI = vector<VI>;
using VVVI = vector<VVI>;
using VVVVI = vector<VVVI>;


VVVVI R(N, VVVI(N, VVI(N, VI(N, -1))));


// # paraules d'n lletres si es poder usar, com a maxim, a as, b bs i c cs
int f(int n, int a, int b, int c) {
  if (a < 0 or b < 0 or c < 0) return 0;
  int& res = R[n][a][b][c];
  if (res != -1) return res;
  if (n == 0) return res = 1;
  return res = (  f(n - 1, a - 1, b, c)
                + f(n - 1, a, b - 1, c)
                + f(n - 1, a, b, c - 1))%MOD;
}


int main() {
  int n, a, b, c;
  while (cin >> n >> a >> b >> c) cout << f(n, a, b, c) << endl;
}
