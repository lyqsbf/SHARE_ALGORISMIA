#include <iostream>
#include <vector>
using namespace std;

using ll = long long;
using VI = vector<long long>;
using VVI = vector<VI>;

int const N = 26;


VVI cas(N, VI(N, -1));

ll par(int n, int m) {
  ll& res = cas[n][m];
  if (n < 1) res = 0;
  if (res != -1) return res;
  if (n == 1) return res = m;
  res = 0;
  if (n >= 7) for (int i = 1; i <= n - 6; i += 2) res += par(i, m)*par(n - i - 5, m);
  res += par(n - 2, m);
  return res;
}



int main() {
  int n, m;
  while (cin >> n >> m) {
	  if (n%2 == 0) cout << 0 << endl;
	  else cout << par(n, m) << endl;
  }
}
