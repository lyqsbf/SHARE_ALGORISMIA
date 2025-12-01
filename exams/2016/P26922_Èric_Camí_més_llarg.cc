#include<iostream>
#include<vector>
using namespace std;

using VI = vector<int>;
using VVI = vector<VI>;
VVI G;
VI R;
int n, m;


//Longitud del cami mes llarg que surt de i.
int f(int i){
    int& res = R[i];
    if(res != -1) return res;
    res = 0;
    for(int v : G[i]) res = max(res,1 + f(v));
    return res;

}


int main(){
    while(cin >> n >> m){
        G = VVI(n,VI(0));
        R = VI(n,-1);
        int x, y;
        for(int i = 0; i < m; ++i){
            cin >> x >> y;
            G[x].push_back(y);
        }

            int A = 0;
            for(int j = 0; j < n; ++j) A = max(A,f(j));
            cout << A << endl;
    }
}
