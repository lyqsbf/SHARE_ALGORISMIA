// Problema 4, P35144

#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

map<string, int>      str2idx;
vector<int>           parent;
vector<int>           fixed_value;
vector< set<int> >    forbidden_values;

int index(string str) {
  auto [it, added] = str2idx.insert({str, parent.size()});
  if (added) {
    parent          .push_back(-1);
    fixed_value     .push_back(-1);
    forbidden_values.push_back({});
  }
  return it->second;
}

bool is_number(string str) {
  char c = str[0];
  return '0' <= c  and  c <= '9';
}

int representative(int x) {
  return (parent[x] == -1 ? x : parent[x] = representative(parent[x]));
}

int main() {
  int n;
  while (cin >> n) {
    str2idx         .clear();
    parent          .clear();
    fixed_value     .clear();
    forbidden_values.clear();
    
    int pos = -1;
    for (int k = 1; k <= n; ++k) {
      string larg, op, rarg;
      cin >> larg >> op >> rarg;
      if (pos == -1) {
        int  x = index(larg);
        int rx = representative(x);
        int&  fxd_rx =     fixed_value [rx];
        auto& fbd_rx = forbidden_values[rx];
        if (op == "==") {
          if (is_number(rarg)) {
            int a = stoi(rarg);
            if ((fxd_rx != -1 and fxd_rx != a) or fbd_rx.count(a)) pos = k;
            else fxd_rx = a;
          }
          else {
            int  y = index(rarg);
            int ry = representative(y);
            if (rx != ry) {
              int&  fxd_ry =     fixed_value [ry];
              auto& fbd_ry = forbidden_values[ry];
              if ((fxd_rx != -1 and fxd_ry != -1 and fxd_rx != fxd_ry)
                  or (fxd_ry != -1 and fbd_rx.count(fxd_ry))
                  or (fxd_rx != -1 and fbd_ry.count(fxd_rx)))
                pos = k;
              else {
                parent[ry] = rx;
                if (fxd_rx == -1) fxd_rx = fxd_ry;
                for (int a : fbd_ry) fbd_rx.insert(a);
              }
            }
          }
        }
        else {
          int a = stoi(rarg);
          if (fxd_rx != -1 and fxd_rx == a) pos = k;
          else fbd_rx.insert(a);
        }
      }
    }
    if (pos == -1) cout << "yes"             << endl;
    else           cout << "no from " << pos << endl;
  }
}
