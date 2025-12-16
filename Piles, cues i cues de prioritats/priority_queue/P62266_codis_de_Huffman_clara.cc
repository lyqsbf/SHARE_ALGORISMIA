#include <iostream>
#include <queue>
#include <vector>
using namespace std;


int main(){

    cout.setf(ios::fixed);
    cout.precision(4);

    priority_queue<double> huffman;

    int n;
    cin >> n;
    double bits = 0;

    for (int i = 0; i < n; ++i){
        double x;
        cin >> x;
        huffman.push(-x);
    }

    while (huffman.top() != -100){
        double x = huffman.top();
        huffman.pop();
        double y = huffman.top();
        huffman.pop();
        bits += x+y;
        huffman.push(x + y);
    }

    cout << "nombre esperat de bits per lletra: " << -bits/100 << endl;
}
