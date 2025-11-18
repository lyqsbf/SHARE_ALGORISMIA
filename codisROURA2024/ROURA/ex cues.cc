// Exemple d'us de cues.


#include <iostream>
#include <queue>
using namespace std;


int main() {
  queue<int> cua;
  int x;
  while (cin >> x) cua.push(x);

  cout << "mida:" << cua.size() << endl;

  while (not cua.empty()) {
    cout << cua.front() << endl;
    cua.pop();
  }
}
