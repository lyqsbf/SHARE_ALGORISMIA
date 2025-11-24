#include <iostream>
#include <vector>
using namespace std;

using VB = vector<bool>;
using VI = vector<int>;
VB usat;
VI numeros;
int s;
int n;

void write(){
    cout << "{";
    int k = 0;
    for(int i = 0; i < n; i++){
        if(usat[i]){
            cout << (k ? "," : "") << numeros[i];
            k++;
        }
    }
    cout << "}" << endl;
}

void f(int i, int sum){
    if(i == n){
        if(sum == s) return write();
        return ;
    }
    usat[i] = false;
    f(i + 1, sum);
    usat[i] = true;
    f(i + 1, sum + numeros[i]);
}

int main(){
    cin >> s >> n;
    numeros = VI(n);
    usat = VB(n);
    for(int& i : numeros) cin >> i;
    f(0, 0);
}
