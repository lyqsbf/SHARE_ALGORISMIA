// P35251


#include <iostream>
#include <vector>
using namespace std;


const int MOD = 1e8 + 7;


using VI = vector<int>;
using VVI = vector<VI>;
using VVVI = vector<VVI>;


string s, t;
VVVI R;


// # maneres correctes amb les i primeres lletres d's
// i les j primeres lletres de t,
// acabant amb s[i-1] si k = 0,
// o acabant amb t[j-1] si k = 1.
int f(int i, int j, int k) {
  int& res = R[i][j][k];
  if (res != -1) return res;

  if (i + j == 1) return res = 1;

  res = 0;
  if (k == 0) {
    if (i > 1 and s[i-2] != s[i-1]) res += f(i - 1, j, 0);
    if (j > 0 and t[j-1] != s[i-1]) res += f(i - 1, j, 1);
  }
  else {
    if (j > 1 and t[j-2] != t[j-1]) res += f(i, j - 1, 1);
    if (i > 0 and s[i-1] != t[j-1]) res += f(i, j - 1, 0);
  }

  return res %= MOD;
}


int main() {
  while (cin >> s >> t) {
    int n = s.size();
    int m = t.size();
    R = VVVI(n + 1, VVI(m + 1, VI(2, -1)));
    cout << (f(n, m, 0) + f(n, m, 1))%MOD << endl;
  }
}
