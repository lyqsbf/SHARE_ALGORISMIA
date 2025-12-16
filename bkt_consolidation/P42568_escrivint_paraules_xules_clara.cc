#include <iostream>
#include <vector>
using namespace std;


using VC = vector<char>;
int n, v, x;
VC V;


void escriu(){
    for(int i = 0; i < n; ++i) cout << V[i];
    cout << endl;
}


void f(int i, int contv){
    if (n - i < v - contv) return;
    if (n - i - v + contv > v - contv + 1) return;
    if (i == n and contv == v) {
        escriu();
        return;
    }
    
    for(int k = 0; k < x; ++k){
        char c = 'a' + k;
        if (c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u') {
            if (contv < v){
                V[i] = c;
                ++contv;
                f(i + 1, contv);
                --contv;
            }
        }
        else{
            if (i == 0) {
                V[i] = c;
                f(i + 1, contv);
            }
            else {
                if (V[i - 1] == 'a' or V[i - 1] == 'e' or V[i - 1] == 'i' or V[i - 1] == 'o' or V[i - 1] == 'u') {
                    V[i] = c;
                    f(i + 1, contv);
                }
            }
        }
    }
}


int main(){
    cin >> n >> v >> x;
    V = VC(n);
    f(0, 0);
}
