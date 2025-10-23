#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

using VC = vector<char>;
using VVC = vector<VC>;
using VI = vector<int>;
using VVI = vector<VI>;

VVC V;
VVI memo;  // Para almacenar resultados ya calculados
int n, m;

int f(int i, int j) {
    // Verificar límites
    if (i < 0 || j < 0 || i >= n || j >= m) return 0;
    
    // Si es obstáculo, no hay caminos
    if (V[i][j] == '*') return 0;
    
    // Si ya calculamos este estado, retornar el resultado
    if (memo[i][j] != -1) return memo[i][j];
    
    int result = 0;
    
    if (V[i][j] == 'C') {
        if (i == 0 || j == 0 || (j == 1 && i == 1)) {
            result = 2;
        }
        else if (i == 1 && j > 1) {
            result = 1 + f(i - 1, j - 2);
        }
        else if(j == 1 and i > 1){
			result = 1 + f(i - 2, j - 1);
		}
        else {
            result = f(i - 1, j - 2) + f(i - 2, j - 1);
        }
    }
    else if (V[i][j] == 'R') {
        if (j == 0 && i == 0) {
            result = 3;
        }
        else if (j == 0) {
            result = 2 + f(i - 1, j);
        }
        else if (i == 0) {
            result = 2 + f(i, j - 1);
        }
        else {
            result = f(i - 1, j) + f(i, j - 1) + f(i - 1, j - 1);
        }
    }
    
    // Almacenar resultado en memo
    memo[i][j] = result;
    return result;
}

int main() {
    while (cin >> n) {
        cin >> m;
        V = VVC(n, VC(m));
        memo = VVI(n, VI(m, -1));  // Inicializar memo con -1
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                char c;
                cin >> c;
                V[i][j] = c;
            }
        }
        
        cout << f(n - 1, m - 1) << endl;
    }
    return 0;
}
