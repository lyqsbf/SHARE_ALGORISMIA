#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<string> t;
string p;

void gen(int i, int j) {
  if (i >= n or j >= m) cout << p << endl;
  else {
    if (t[i][j] == '.' or t[i][j] == 'A') { p.push_back('A'); gen(i+1, j); p.pop_back(); }
    if (t[i][j] == '.' or t[i][j] == 'D') { p.push_back('D'); gen(i, j+1); p.pop_back(); }
  }
}

int main() {
  while (cin >> n >> m) {
    t = vector<string>(n);
    for (auto& ti : t) cin >> ti;
    gen(0, 0);
    cout << string(10, '-') << endl;
  }
}
