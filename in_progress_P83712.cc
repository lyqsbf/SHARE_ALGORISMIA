//Parcial 2012 Two rows of numbers
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

using VI = vector<int>;
VI num;
VI usat;
VI X;
VI Y;
int n;

void write(){
    for(int i = 0; i < n; i++) cout << (i ? " ": "") << X[i];
    cout << endl;
    for(int j = 0; j < n; j++) cout << (j ? " ": "") << Y[j];
    cout << endl << endl;
}

void f(int a, int b){
    if(a == n){
        if(b == n) return write();
        for(int i = 0; i < 2*n; i++){
            if(not usat[i]){
                usat[i] = 1;
                Y[b] = num[i];
                f(a, b+1);
                usat[i] = 0;
            }
        }
    }
    for(int i = 0; i < 2 *n; i++){
        if(a == 0 and not usat[i]){
            usat[i] = 1;
            X[a] = num[i];
            f(a+1, b);
            usat[i] = 0;
        }
    }
}

int main(){
    cin >> n;
    num = VI(2*n);
    X = Y = VI(n);
    usat = VI(2*n, 0);
    for(int i = 0; i < 2*n ; i++){
        cin >> num[i];
    }
    sort(num.begin(), num.end());
    f(0, 0);
}
