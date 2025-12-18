#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;
using VI = vector<int>;
using MI = vector<VI>;

const int oo = INT_MAX;
const int UNDEF = -1;

string w;
MI C;

//retorna el # minim de girs per convertir w en parentitzacio correcta
int cost(int i, int j){
    if(i > j) return 0;
    int& res = C[i][j];
    if(res != UNDEF) return res;
    res = +oo;
    for(int k = i+1; k <= j; k+= 2){
        res = min(res, (w[i] != '(') + (w[k] != ')') + cost(i+1, k-1) + cost(k+1, j));
    }
    return res;
}

int main(){
    while(cin >> w){
        int n = w.size();
        C = MI(n, VI(n, UNDEF));
        cout << cost(0, n-1) << endl;
    }
}

//[-2³¹, 2³¹ - 1] interval valors representables amb int, respresenta [-infinit, +infinit]
