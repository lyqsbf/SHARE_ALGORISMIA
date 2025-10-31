#include <iostream>
#include <vector>
using namespace std;

const int N = 1001;

using ll = long long;
using VL = vector<ll>;

int fib(int n, int m){
  VL F(N);
  F[0] = 0;
  F[1] = 1;
  for (int i = 2; i < N; ++i) F[i] = (F[i-2] + F[i-1])%m;
  return F[n];

}

int main() {
  int n;
  int m;
  while (cin >> n >> m) cout << fib(n, m) << endl;
}
