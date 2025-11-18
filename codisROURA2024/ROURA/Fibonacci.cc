// Calcula els nombres de Fibonacci eficientment, de forma iterativa.


#include <iostream>
#include <vector>
using namespace std;


const int N = 81;


using ll = long long;
using VL = vector<ll>;


int main() {
  VL F(N);
  F[0] = 0;
  F[1] = 1;
  for (int i = 2; i < N; ++i) F[i] = F[i-2] + F[i-1];

  int n;
  while (cin >> n) cout << F[n] << endl;
}
