// Us de KMP per comptar totes les aparicions d'una paraula w en un text t.


#include <iostream>
#include <vector>
using namespace std;


using VI = vector<int>;


VI kmp(string s) {
  int n = s.size();
  VI P(n);
  int j = -1;
  for (int i = 0; i < n; ++i) {
    while (j >= 0 and s[j] != s[i]) j = (j ? P[j-1] : -1);
    P[i] = ++j;
  }
  return P;
}


int main() {
  string t, w;
  cin >> t >> w;
  string s = w + "#" + t;
  VI P = kmp(s);
  int q = 0;
  for (int x : P)
    if (x == (int)w.size()) ++q;
  cout << "nombre d'aparicions: " << q << endl;
}
