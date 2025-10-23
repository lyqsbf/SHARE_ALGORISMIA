#include <iostream>
#include <vector>
using namespace std;


using VC = vector<char>;
using VVC = vector<VC>;
using VB = vector<bool>;
using VVB = vector<VB>;


int n, m;
VVC M;
VVB vist;
char c; // '?': indefinit, '.': diferents


void dfs1(int i, int j) {
  if (i < 0 or i >= n or j < 0 or j >= m or M[i][j] == 'X' or vist[i][j]) return;
  vist[i][j] = true;
  if (M[i][j] != '.') {
    if (c == '?') c = M[i][j];
    else if (M[i][j] != c) c = '.';
    M[i][j] = '.'; // esborrem totes les lletres
  }
  dfs1(i + 1, j);
  dfs1(i - 1, j);
  dfs1(i, j + 1);
  dfs1(i, j - 1);
}


void dfs2(int i, int j) {
  if (i < 0 or i >= n or j < 0 or j >= m or M[i][j] != '.') return;
  M[i][j] = c;
  dfs2(i + 1, j);
  dfs2(i - 1, j);
  dfs2(i, j + 1);
  dfs2(i, j - 1);
}


int main() {
  while (cin >> n >> m) {
    M = VVC(n, VC(m));
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j) cin >> M[i][j];

    vist = VVB(n, VB(m, false));
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        if (M[i][j] != 'X' and not vist[i][j]) {
          c = '?';
          dfs1(i, j);
          if (c != '?' and c != '.') dfs2(i, j);
        }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) cout << M[i][j];
      cout << endl;
    }
    cout << endl;
  }
}
