#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;

using VI = vector<int>;
using VVI = vector<VI>;

VI V;
VVI R;

// maxim nombre de taronges amb els i primers arbres i les j primeres persones
int f(int i, int j) {
  if (j == 0) return 0;
  if (i <= 0) return -INF;
  int& res = R[i][j];
  if (res != -1) return res;
  return res = max(V[i-1] + f(i - 2, j - 1), f(i - 1, j));
}

int main() {
  int n, m;
  while (cin >> n >> m) {
    V = VI(n);
    for (int& x : V) cin >> x;
    R = VVI(n + 1, VI(m + 1, -1));
    cout << f(n, m) << endl;
  }
}
