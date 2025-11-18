// Floyd-Warshall


#include <iostream>
#include <vector>
using namespace std;


const int INF = 1e8;


using VI = vector<int>;
using VVI = vector<VI>;


int main() {
  int n, m;
  cin >> n >> m;
  VVI M(n, VI(n, INF));
  while (m--) {
    int x, y, c;
    cin >> x >> y >> c;
    M[x][y] = c;
  }

  for (int x = 0; x < n; ++x) M[x][x] = 0;

  for (int k = 0; k < n; ++k)
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j) M[i][j] = min(M[i][j], M[i][k] + M[k][j]);

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j)
      cout << (j ? " " : "") << (M[i][j] == INF ? -1 : M[i][j]);
    cout << endl;
  }
}
