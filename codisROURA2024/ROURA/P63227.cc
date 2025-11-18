// P63227


#include <iostream>
#include <vector>
using namespace std;


using VI = vector<int>;


int n, x;
VI repe;


void escriu() {
  bool primer = true;
  cout << '{';
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < repe[i]; ++j) {
      if (primer) primer = false;
      else cout << ',';
      cout << i + 1;
    }
  cout << '}' << endl;
}


void f(int i) {
  if (i == n) return escriu();

  for (int j = 0; j <= x; ++j) {
    repe[i] = j;
    f(i + 1);
  }
}


int main() {
  cin >> n >> x;
  repe = VI(n);
  f(0);
}
