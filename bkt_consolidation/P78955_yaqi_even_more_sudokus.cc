#include <iostream>                                                                               
#include <vector>                                                                                 
using namespace std;                                                                              
                                                                                                  
using VI = vector<int>;                                                                           
using VVI = vector<VI>;                                                                           
using VVVI = vector<VVI>;                                                                         
VVI T;                                                                                            
VVVI q;                                                                                           
VVI row;                                                                                          
VVI col;                                                                                          
int n;                                                                                            
                                                                                                  
//escrivim la solucio                                                                             
void write(){                                                                      
        for(int i = 0; i < 9; i++){                                                               
                for(int j = 0; j < 9; j++) cout << (j ? " " : "") << ((j != 0 and j % 3 == 0)? "| ": "") << T[i][j];
                cout << endl;
                if(i != 8 and i % 3 == 2) cout << "------+-------+------" << endl;                
        }                                                                                         
        cout << endl;                                                                
}                                                                                  
                                                                                                  
bool f(int i, int j){                                                                             
        if (i == 9){                                                                              
                write();                                                                          
                return true;                                                                      
        }                                                                                         
        if (j == 9) return f(i + 1, 0);                                                           
        if(T[i][j]) return f(i, j + 1);                                                           
        for (int k = 1; k <= 9; k++){                                                             
                if(not row[i][k] and not col[j][k] and not q[i/3][j/3][k]){                       
                        T[i][j] = k;                                                              
                        row[i][k] = col[j][k] = q[i/3][j/3][k] = 1;                               
                        if(f(i, j + 1)) return true;                                              
                        T[i][j] = 0;                                                              
                        row[i][k] = col[j][k] = q[i/3][j/3][k] = 0;                               
                }                                                                                 
        }                                                                                         
        return false;                                                                             
}                                                                                                 
                                                                                                  
int main(){                                                                                       
        cin >> n;                                                                                 
        while (n--){                                                                              
                T = VVI(9, VI(9));                                                                
                q = VVVI(3, VVI(3, VI(10, 0)));                                                   
                row = col = VVI(9, VI(10, 0));                                                    
                //llegim l'entrada                                                                
                int a = 0;                                                                        
                while (a < 81){                                                                   
                        char c;                                                                   
                        cin >> c;                                                                 
                        if (c >= '0' and c <= '9'){                                               
                                int k = c - '0';                                                  
                                T[a/9][a%9] = k;                                                  
                                if(k) row[a/9][k] = col[a%9][k] = q[(a/9)/3][(a%9)/3][k] = 1;     
                                a++;                                                              
                        }                                                                         
                }                                                                                 
                f(0, 0);                                                                          
        }                                                                                         
}
