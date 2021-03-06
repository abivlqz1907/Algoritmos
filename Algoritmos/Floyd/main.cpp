//
//  main.cpp
//  Algoritmos
//
//  Abigail Guadalupe Velazquez Sanchez A01566592 Grupo1
//  Creado el 23/03/2021
#include <iostream>
#include <climits>

using namespace std;

// mat = matriz de costos
// p   = matriz de recorridos
void leeArcos(int mat[100][100], int p[100][100], int m){
    int a,b,c;
    //inicializar
    for (int i = 0; i<100; i++) {
        mat[i][i] = p[i][i] = 0;
        for (int j = i+1; j<100; j++) {
            mat[i][j] = mat[j][i] = INT_MAX;
            p[i][j] = p[j][i] = -1;
        }
    }
    
    // Lectura
    for (int i = 1; i<=m; i++) {
        cin>> a >> b >> c;
        mat[a-1][b-1] = mat[b-1][a-1] = c;
    }
}

void floyd(int mat[100][100], int p[100][100], int n){
    
    for (int k = 0 ; k< n; k++) {
        for (int i = 0; i<n; i++) {
            for (int j = 0 ; j<n; j++) {
                if (mat[i][k] != INT_MAX && mat[k][j] != INT_MAX && mat[i][k] + mat[k][j] < mat[i][j] ){
                    mat[i][j] = mat[i][k]+mat[k][j];
                    p[i][j] = k;
                }
            }
        }
    }

}

void checaTrayectoria(int p[100][100], int a, int b){
    if(p[a][b]!=-1){
        checaTrayectoria(p, a, p[a][b]);
        cout<< (p[a][b])+1<< "-";
        checaTrayectoria(p, p[a][b], b);
    }
    
}

void consulta(int mat[100][100], int p[100][100], int q){
    int a,b;
    for (int i = 1 ; i<=q; i++) {
        cin >> a >> b;
        if (mat[a-1][b-1] == INT_MAX) {
            cout<< "no path"<<endl;
        }else{
            cout<< "Costo: "<<mat[a-1][b-1]<< " Path: " << a << "-";
            checaTrayectoria(p, a-1, b-1);
            cout<< b <<endl;
            
        }
    }
}

int main(){
    int mat[100][100];
    int p[100][100];
    int n, m, q;
    // n - Cant Nodos
    // m - Cant Arcos
    // q - Cant de Consultas
    cin >> n >> m >> q; //nodos , arcos , consultas
    leeArcos(mat, p, m);
    floyd(mat, p, n);
    consulta(mat, p, q);
}
/*
7 11 5
1 2 2
1 3 4
1 4 6
2 3 2
2 5 6
3 4 1
3 5 3
4 5 2
5 7 5
6 4 3
6 7 4
1 7
2 6
6 2
4 5
5 2
*/

