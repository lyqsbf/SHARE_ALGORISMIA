#include<iostream>
#include<vector>
using namespace std;

const int inf = 1e8;
using VI = vector<int>;
using VVI = vector<VI>;
using VC = vector<char>;
using VVC = vector<VC>;
VVC nivell;
VVI R;
int n, m;


int camins(int i, int j){
    if (j < 0 or j >= m) return inf;

    if (i == n) return 0;
    int& res = R[i][j];
    if (res != -1) return res;
    if (nivell[i][j] == '*') return res = inf;

    return res = 3*(nivell[i][j] == 'T') + min(camins(i + 1, j),
           min(1 + camins(i + 1, j - 1),1 + camins(i + 1, j + 1)));
}


int main(){
    cin >> m >> n;
    R = VVI(n, VI(m, -1));
    nivell = VVC(n, VC(m));
    int y = 0;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            cin >> nivell[i][j];
            if (nivell[i][j] == 'M') y = j;
        }
    }
    int p = camins(0,y);
    if (p >= inf) cout << "IMPOSSIBLE";
    else cout << p;
    cout << endl;
}
