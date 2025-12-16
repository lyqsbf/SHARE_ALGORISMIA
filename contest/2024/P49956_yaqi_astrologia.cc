#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

using MAPA = map<pair<int, int>, int>;
MAPA rectes;

//calcula el MCD de a i b
int f_mcd(int a, int b){
    if(b == 0) return a;
    int r = a%b;
    return f_mcd(b, r);
}

int main(){
    int n;
    int x, y;
    while(cin >> n){
        int count = 0;
        while(n --){
            cin >> x >> y;
            int mcd = f_mcd(x, y);
            x = x / mcd;
            y = y / mcd;
            if(x < 0 or (x == 0 and y < 0)){
                x = -x;
                y = -y;
            }
            rectes[{x, y}]++;
        }
        for(auto p : rectes){
            int m = p.second;
            count += (m*(m-1))/2;
        }
        cout << count << endl;
        rectes.clear();
    }
}