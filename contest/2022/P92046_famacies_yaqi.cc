#include <iostream>
#include <vector>
using namespace std;

using ll = long long;
using VL = vector<ll>;
using VB = vector<bool>;
VL v;
VB vist;

int main(){
    ll n;

    while (cin >> n){
        v = VL(n);
        vist = VB(n, false);
        for(ll i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            v[i] = x - 1;
        }
        ll max_size = 0;
        for(ll i = 0; i < n; i++){
            if(not vist[i]){
                ll ac_size = 1;
                vist[i] = true;
                int k = v[i];
                while(not vist[k]){
                    vist[k] = true;
                    ac_size++;
                    k = v[k];
                }
                if (ac_size > max_size){
                    max_size = ac_size;
                }
            }
        }
        cout << max_size << endl;
        vist.clear();
    }
}