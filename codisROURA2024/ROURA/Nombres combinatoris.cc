// Nombres combinatoris. Versio eficient iterativa.


#include <iostream>
#include <vector>
using namespace std;


const int N = 51;


using ll = long long;
using VL = vector<ll>;
using VVL = vector<VL>;


int main() {
  VVL C(N, VL(N));
  for (int i = 0; i < N; ++i) C[i][0] = 1;
  for (int i = 0; i < N; ++i) C[i][i] = 1;
  for (int i = 1; i < N; ++i)
    for (int j = 1; j < i; ++j) C[i][j] = C[i-1][j-1] + C[i-1][j];

  int n, x;
  while (cin >> n >> x) cout << C[n][x] << endl;
}
