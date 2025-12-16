#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using ll = long long;
using VI = vector<int>;

ll solve_1d(VI&coords){
    ll sol = 0;

    sort(coords.begin(), coords.end());
    ll size = coords.size();
    for(ll i = 0; i < size; i++){
        sol += coords[i] * (2 * i - size + 1);
    }
    return sol;
}

int main(){
    ll n;
    while(cin >> n){
        VI coord_x;
        VI coord_y;
        ll x;
        ll y;
        while(n--){
            cin >> x >> y;
            coord_x.push_back(x+y);
            coord_y.push_back(x-y);
        }
        ll a = solve_1d(coord_x);
        ll b = solve_1d(coord_y);
        cout << (a+b)/2 << endl;
    }
}