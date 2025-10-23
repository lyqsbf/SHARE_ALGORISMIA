#include <iostream>
#include <vector>
using namespace std;


using VI = vector<int>;
using VB = vector<bool>;
VI V, f1, f2;
VB usat;
int n;


void f(int i, int j, int k){
    for (int s = 0; s < 2*n; ++s){
        if (usat[s] == false){
            if (j != 0 and f1[j - 1] < s) f1[j] = s;
            usat[s] = true;
        }
    }
}


int main(){
    cin >> n;
    V = VI(2*n);
    usat = VI(2*n, false);
    f1 = f2 = VI(n, -1);
    for (int i = 0; i < n; ++i) {
        int c;
        cin >> c;
        V[i] = c;
    }
    f(0, 0, 0);
}
