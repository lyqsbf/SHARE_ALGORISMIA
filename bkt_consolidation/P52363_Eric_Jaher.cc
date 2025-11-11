#include<iostream>
#include<vector>
using namespace std;

using VI = vector<int>;
using VVI = vector<VI>;
using P = pair<int,int>;
using VP = vector<P>;
VP obj;
VVI M;
VI used;
int a, b, n;

void marcar(int i, int j, int x, int y, int m){
    for(int k = i; k < i + x; ++k){
        for (int l = j; l < j + y; ++l){
            if(k < a and l < b) M[k][l] = m;
        }
    }
}

bool posar(int i, int j, int x, int y){
    for(int k = i; k < i + x; ++k){
        for (int l = j; l < j + y; ++l){
            if(k >= a or l >= b or M[k][l]) return false;
        }
    }
    return true;
}

int f(int i, int j){
    if(j == b) return f(i+1,0);
    if(i == a) return 1;
    if(M[i][j]) return f(i,j+1);
    int res = 0;
    for (int k = 0; k < n; ++k){
        int dx = obj[k].first;
        int dy = obj[k].second;
        if(not used[k] and posar(i,j,dx,dy)){
            used[k] = 1;
            marcar(i,j,dx,dy,1);
            res += f(i,j+1);
            used[k] = 0;
            marcar(i,j,dx,dy,0);
        }
    }
    return res;
}

int main(){
    int cas = 1;
    while(cin >> a >> b >> n){
        obj = VP(n);
        M = VVI(a,VI(b,0));
        used = VI(n,0);
        
        for (int i = 0; i < n; ++i){
            cin >> obj[i].first >> obj[i].second;
        }
        
        cout << '#' << cas << ": " << f(0,0) << endl;
        ++cas;
    } 
}
