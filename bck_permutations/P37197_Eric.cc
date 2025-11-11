#include<iostream>
#include<vector>
using namespace std;

int n, m;
using VI = vector<int>;
using VVI = vector<VI>;
VI especies, perm, used;
VVI incomp;


int getval(char c){
    int v = int(c - 'A');

    if (v > 25) return v - 6;
    else return v;
}

void escriu(){
    for (int i = 0; i < n; ++i){
        if(perm[i] <= 25) cout << char('A' + perm[i]);
        else cout << char('A' + perm[i] + 6);
    }
    cout << endl;
}


void f(int i){
    if(i == n) return escriu();

    for (int j = 0; j < n; ++j){
        if((i == 0 or not incomp[perm[i-1]][especies[j]]) and not used[j]){
            perm[i] = especies[j];
            used[j] = 1;
            f(i+1);
            used[j] = 0;
        }
    }
}


int main(){
    incomp = VVI(52,VI(52,0));
    cin >> n;
    perm = used = especies = VI(n,0);
    char c;

    for (int i = 0; i < n; ++i){
        cin >> c;
        especies[i] = getval(c);
    }

    cin >> m;
    string inc;
    for (int i = 0; i < m; ++i){
        cin >> inc;
        int v1 = getval(inc[0]);
        int v2 = getval(inc[1]);
        incomp[v1][v2] = incomp[v2][v1] = 1;
    }

    f(0);
}
