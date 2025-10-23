// Problema 1, P76720

#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<string> t;

vector< vector<pair<int, int> > > v = {
  { {0, 0}, {0, 1}, {1, 0} },
  { {0, 0}, {0, 1}, {1, 1} },
  { {0, 0}, {1,-1}, {1, 0} },
  { {0, 0}, {1, 0}, {1, 1} }
};

void gen(int i, int j, int c);

void try_triangle(int i, int j, int c, const vector<pair<int, int>>& dirs) {
  for (const auto& [di, dj] : dirs) {
    int ii = i + di;
    int jj = j + dj;
    if (not (ii >= 0 and ii < n and jj >= 0 and jj < m and t[ii][jj] == 'X'))
      return;
  }
  for (const auto& [di, dj] : dirs) t[i + di][j + dj] = 'a' + c;
  gen(i, j+1, c+1);
  for (const auto& [di, dj] : dirs) t[i + di][j + dj] = 'X';
}

void gen(int i, int j, int c) {
  if (i == n) {
    for (const auto& ti : t) cout << ti << endl;
    cout << string(10, '-') << endl;
    return;
  }
  if (j == m)         return gen(i+1, 0, c);
  if (t[i][j] != 'X') return gen(i, j+1, c);
  for (int k = 0; k < int(v.size()); ++k)
    try_triangle(i, j, c, v[k]);
}

int main() {
  while (cin >> n >> m) {
    t = vector<string>(n, string(m, 'X'));
    gen(0, 0, 0);
    cout << string(20, '*') << endl;
  }
}
