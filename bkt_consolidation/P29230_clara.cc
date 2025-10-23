#include <iostream>
#include <vector>
using namespace std;


using VI = vector<int>;
VI mon, V;
int n;
bool primer;


void escriu(){
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < V[i]; ++j) {
            if (primer == true) {
                cout << mon[i];
                primer = false;
            }
            else cout << ' ' << mon[i];
        }
    }
    cout << endl;
}


void f(int sum, int pos){
    if (sum == n) {
        primer = true;
        escriu();
    }
    if (sum > n) return;
    
    for (int i = pos; i < 6; ++i){
        V[i] += 1;
        f(sum + mon[i], i);
        V[i] -= 1;
    }
}


int main(){
    mon = VI(6);
    V = VI(6, 0);
    mon[0] = 50;
    mon[1] = 20;
    mon[2] = 10;
    mon[3] = 5;
    mon[4] = 2;
    mon[5] = 1;
    while (cin >> n) {
        f(0, 0);
        cout << endl;
    }
}
