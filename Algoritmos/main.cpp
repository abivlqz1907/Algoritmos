// Matrícula: A01566592
// Nombre: Abigail Guadalupe Velazquez Sanchez
#include <iostream>
using namespace std;

//Complejidad: O(n)
char check(string st){
    
    int cont = 1;
    int mayor= 0;
    long n = st.size();
    int pos=0;
    for (int i = 0; i<n; i++) {
        if (st[i]==st[i+1]&& i!=n-1 ) {
            cont++;
        }else{
            if (cont>mayor) {
               pos = i;
               mayor = cont;
            }
            cont=1;
        }
    }
    return st[pos];
}

int main(){
    string st;
    cin >> st;
    cout << check(st)<<endl;
}

