#include <iostream>
#include <vector>

using namespace std;

int n, l;

const int big = 900000;

using vs = vector<string>;
using vi = vector<int>;

int f(vector<vs>& data, vector<vi>& v, int i, int j){
    if(i>l-1 or (j>n-1 or j<0)) return big;
    if (i==l-1){
        if (data[i][j] == "T") return 3;
        if (data[i][j] == ".") return 0;
        if (data[i][j] == "*") return big;
    }

    int& res = v[i][j];
    if (res!=-1) return res;
    int pre = min(f(data, v, i+1, j), 1 + min(f(data, v, i+1, j-1), f(data, v, i+1, j+1)));
    if (data[i][j] == "*" or pre>=big) return res = big;
    
    return res = ((data[i][j] == "T") ? 3 : 0) + pre;
}

int main(){

    int start;
    cin >> n >> l;


    vector<vi> v(l, vi(n, -1));
    vector<vs> data(l, vs(n));
    string s;

    cin >> s;
    for (int i=0;i<n;i++){
        if(s[i] == 'M'){
            start=i;
            data[0][i]=".";
        }
        else {
            data[0][i]=s[i];
        }
    }

    for (int i=1;i<l;i++){
        cin >> s;
        for (int j=0;j<n;j++){
            data[i][j] = s[j];
        }
    }
    cout << ((f(data, v, 0, start) >= big) ? "IMPOSSIBLE" : to_string(v[0][start])) << endl;
}
