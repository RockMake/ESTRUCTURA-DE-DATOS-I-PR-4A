#include <iostream>
using namespace std;

// Prototipos
void promImpCen(int mat[10][10], int n, float &prom);
void vecBorde(int mat[10][10], int n);

int main()
{
    int n;
    int mat[10][10];

    cout << "Ingrese el tamanio de la matris (impar): ";
    cin >> n;

    // leer matris
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "Elem [" << i << "][" << j << "]: ";
            cin >> mat[i][j];
        }
    }

    // invocar funcion promedio impares centro
    float prom = 0;
    promImpCen(mat, n, prom);
    cout << "\nPromedio impares centro: " << prom << endl;

    // invocar funcion vector del borde
    vecBorde(mat, n);

    return 0;
}

// Cuerpo funcion 1
void promImpCen(int mat[10][10], int n, float &prom)
{
    int suma = 0, cant = 0;
    int cen = n / 2;

    // fila central
    for (int j = 0; j < n; j++)
    {
        if (mat[cen][j] % 2 != 0)
        {
            suma += mat[cen][j];
            cant++;
        }
    }

    // columna central (evitar el centro duplicado)
    for (int i = 0; i < n; i++)
    {
        if (i != cen && mat[i][cen] % 2 != 0)
        {
            suma += mat[i][cen];
            cant++;
        }
    }

    if (cant > 0)
        prom = (float)suma / cant;
    else
        prom = 0;
}

// Cuerpo funcion 2
void vecBorde(int mat[10][10], int n)
{
    int vec[100];
    int idx = 0;

    // fila sup
    for (int j = 0; j < n; j++)
    {
        vec[idx++] = mat[0][j];
    }

    // col der
    for (int i = 1; i < n - 1; i++)
    {
        vec[idx++] = mat[i][n - 1];
    }

    // fila inf
    for (int j = n - 1; j >= 0; j--)
    {
        vec[idx++] = mat[n - 1][j];
    }

    // col izq
    for (int i = n - 2; i > 0; i--)
    {
        vec[idx++] = mat[i][0];
    }

    // imprimir vector dentro de la funcion
    cout << "\nVector del borde:\n";
    for (int i = 0; i < idx; i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}
