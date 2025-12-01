#include<iostream>
#include<vector>
using namespace std;


const int MOD = 1e8 + 7;
using VI = vector<int>;
using VVI = vector<VI>;
using VC = vector<char>;
VVI M;
string s, t, u;


int main(){
    while (cin >> s >> t >> u){
        M = VVI(int(t.size())+1,VI(int(s.size())+1,0));

        M[0][0] = 1;

        for (int i = 0; i <= int(t.size()); ++i){
            for (int j = 0; j <= int(s.size()); ++j){
                if (j > 0 and s[j-1] == u[i+j-1]) M[i][j] = (M[i][j] + M[i][j-1])%MOD;
                if (i > 0 and t[i-1] == u[i+j-1]) M[i][j] = (M[i][j] + M[i-1][j])%MOD;
            }
        }

        cout << M[int(t.size())][int(s.size())] << endl;
    }
}
