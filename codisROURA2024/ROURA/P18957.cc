// P18957


#include <iostream>
#include <vector>
using namespace std;


using VS = vector<string>;
using VB = vector<bool>;


int n;
VS par;
VB triat;


void escriu() {
  bool primer = true;
  cout << '{';
  for (int i = 0; i < n; ++i)
    if (triat[i]) {
      if (primer) primer = false;
      else cout << ',';
      cout << par[i];
    }
  cout << '}' << endl;
}


void f(int i) {
  if (i == n) return escriu();

  triat[i] = false;
  f(i + 1);
  triat[i] = true;
  f(i + 1);
}


int main() {
  cin >> n;
  par = VS(n);
  for (string& s : par) cin >> s;
  triat = VB(n);
  f(0);
}
