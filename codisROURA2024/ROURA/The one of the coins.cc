// The one of the coins.


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


using VI = vector<int>;
using VVI = vector<VI>;


VI V;
VVI R;
bool primer; // per les comes


// diu si es pot aconseguir suma s amb les i primeres monedes
int f(int i, int s) {
  if (s < 0) return false;
  int& res = R[i][s];
  if (res != -1) return res;
  if (i == 0) return res = (s == 0);
  return res = f(i, s - V[i-1]) or f(i - 1, s);
}


// escriu la solucio corresponent a (i, s)
void solucio(int i, int s) {
  if (i == 0) return;
  if (f(i, s - V[i-1])) {
    if (primer) primer = false;
    else cout << ',';
    cout << V[i-1];
    return solucio(i , s - V[i-1]);
  }
  solucio(i - 1, s);
}


int main() {
  int n;
  while (cin >> n) {
    V = VI(n);
    for (int& x : V) cin >> x;
    int C;
    cin >> C;
    sort(V.begin(), V.end());

    R = VVI(n + 1, VI(C + 1, -1));
    if (not f(n, C)) cout << -1 << endl;
    else {
      primer = true;
      solucio(n, C);
      cout << endl;
    }
  }
}
