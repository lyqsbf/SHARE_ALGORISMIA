// LIS (longest increasing subsequence)
// Solucio amb programacio dinamica, amb cost quadratic.


#include <iostream>
#include <vector>
using namespace std;


using VI = vector<int>;


VI V, L;


// longitud de la subsequencia mes llarga estrictament creixent
// continguda dins de V[0..i], estant obligats a agafar V[i]
int lis(int i) {
  int& res = L[i];
  if (res != -1) return res;
  res = 1;
  for (int j = 0; j < i; ++j)
    if (V[j] < V[i]) res = max(res, lis(j) + 1);
  return res;
}


int main() {
  int n;
  cin >> n;
  V = VI(n);
  for (int& x : V) cin >> x;

  L = VI(n, -1);
  int res = 0;
  for (int i = 0; i < n; ++i) res = max(res, lis(i));
  cout << res << endl;
}
