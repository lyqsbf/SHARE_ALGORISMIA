// Donat un vector d'enters V, calcula i escriu
// la suma de V[e..d] per a diversos parells e, d.
// Eficient, fent servir "prefix sums".


#include <iostream>
#include <vector>
using namespace std;


using VI = vector<int>;


int main() {
  int n;
  cin >> n;
  VI V(n);
  for (int& x : V) cin >> x;

  VI P(n);
  P[0] = V[0];
  for (int i = 1; i < n; ++i) P[i] = P[i-1] + V[i];

  int e, d;
  while (cin >> e >> d) cout << P[d] - (e ? P[e-1] : 0) << endl;
}
