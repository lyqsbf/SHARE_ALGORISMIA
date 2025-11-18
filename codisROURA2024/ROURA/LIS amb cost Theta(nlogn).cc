// LIS amb cost Theta(nlogn) en el cas pitjor.


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


using VI = vector<int>;


int main() {
  VI V;
  int x;
  while (cin >> x) {
    int i = lower_bound(V.begin(), V.end(), x) - V.begin();
//    si permetessim empats fariem
//    int i = upper_bound(V.begin(), V.end(), x) - V.begin();
    if (i < (int)V.size()) V[i] = x;
    else V.push_back(x);
  }
  cout << "longitud de la subsequencia estrictament creixent mes llarga: "
       << V.size() << endl;
}
