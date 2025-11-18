// Exemple d'us de cues de prioritats.


#include <iostream>
#include <queue>
using namespace std;


int main() {
  priority_queue<int> cua;
  int x;
  while (cin >> x) cua.push(x);

  cout << "mida:" << cua.size() << endl;

  while (not cua.empty()) {
    cout << cua.top() << endl;
    cua.pop();
  }
}
