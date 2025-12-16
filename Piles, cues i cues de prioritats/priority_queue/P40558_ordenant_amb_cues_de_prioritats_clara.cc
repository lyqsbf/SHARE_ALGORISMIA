#include <iostream>
#include <queue>
using namespace std;


int main(){
    int s;
    priority_queue<int> heap1;
    priority_queue<int> heap2;

    while(cin >> s){
        heap1.push(s);
        heap2.push(-s);
    }

    while(!heap2.empty()){
        int par = - heap2.top();
        heap2.pop();
        cout << par;
        if (!heap2.empty()) cout << ' ';
    }
    cout << endl;

    while(!heap1.empty()){
        int par = heap1.top();
        heap1.pop();
        cout << par;
        if (!heap1.empty()) cout << ' ';
    }
    cout << endl;
}
