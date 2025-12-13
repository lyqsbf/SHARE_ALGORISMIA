#include <iostream>
#include <stack>
using namespace std;


void escriu(int n) {
    stack <int> pila;
    pila.push(n);
    while (!pila.empty()) {
        int q = pila.top();
        if (q == 0) {
            pila.pop();
            continue;
        }
        else cout << ' ' << q;
        pila.pop();
        pila.push(q - 1);
        pila.push(q - 1);
    }
}

int main() {
    int n;
    while (cin >> n) {
        escriu(n);
        cout << endl;
    }
}
