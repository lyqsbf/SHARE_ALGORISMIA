#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

using QS = queue<string>;
using VQ = vector<QS>;
VQ lletres(26);
QS Q;

void f(int pos){
    string str;
    while(pos >=0){
        while (!Q.empty()){
            str = Q.front();
            Q.pop();
            lletres[str[pos]-'a'].push(str);
        }
        for(int i = 0; i < 26; i++){
            while(!lletres[i].empty()){
                string word = lletres[i].front();
                lletres[i].pop();
                Q.push(word);
            }
        }
        pos--;
    }
}

int main(){
    string word;
    while (cin >> word){
        Q.push(word);
    }
    int n = Q.front().size();
    f(n-1);
    int i = 0;
    while (!Q.empty()){
        cout << (i ? " " : "") << Q.front();
        i++;
        Q.pop();
    }
    cout << endl;
}
