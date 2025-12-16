#include <iostream>
#include <stack>
using namespace std;


string p;


bool correcte() {
    stack<char> pila;
    int s = p.size();
    for (int i = 0; i < s; ++i){
        char c = p[i];
        if (c == '(' or c == '[') pila.push(c);
        else if (pila.empty()) return false;
        else {
            char k = pila.top();
            if (c == ')' and k != '(') return false;
            else if (c == ']' and k != '[') return false;
            pila.pop();
        }
    }
    if (pila.empty()) return true;
    else return false;
}


int main() {
    while (cin >> p) {
        if (correcte()) cout << p << " es correcta" << endl;
        else cout << p << " es incorrecta" << endl;
    }
}
