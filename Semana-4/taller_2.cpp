#include <iostream>
using namespace std;

// variables globales pa la opcion 4
int sumaDiagonalSecundaria = 0;
int cantidadDiagonalSecundaria = 0;

// Prototipos de funciones
void leermatriz(int matriz[10][10], int& tamano);
int sumadiagonalprincipal(int matriz[10][10], int tamano);
void contarparesencimaDiagonal(int matriz[10][10], int tamano, int& cantidadPares);
void calculapromedioDiagonalSecundaria(int matriz[10][10], int tamano);
int menordebajodiagonalsecundaria(int matriz[10][10], int tamano);

int main() {
    int matriz[10][10];
    int tamano;
    int opcion;

    leermatriz(matriz, tamano);

    do {
        cout << "\nMenu principal:\n";
        cout << "1. Leer matriz de nuevo\n";
        cout << "2. Sumar diagonal principal\n";
        cout << "3. Contar numeros pares encima de la diagonal principal\n";
        cout << "4. Calcular promedio diagonal secundaria\n";
        cout << "5. Hallar menor debajo de la diagonal secundaria\n";
        cout << "6. Salir\n";
        cout << "Elija una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                leermatriz(matriz, tamano);
                break;
            case 2: {
                int suma = sumadiagonalprincipal(matriz, tamano);
                cout << "La suma de la diagonal principal es: " << suma << endl;
                break;
            }
            case 3: {
                int cantidadPares = 0;
                contarparesencimaDiagonal(matriz, tamano, cantidadPares);
                cout << "Cantidad de pares encima diagonal principal: " << cantidadPares << endl;
                break;
            }
            case 4:
                calculapromedioDiagonalSecundaria(matriz, tamano);
                if (cantidadDiagonalSecundaria != 0) {
                    float promedio = (float)sumaDiagonalSecundaria / cantidadDiagonalSecundaria;
                    cout << "Promedio diagonal secundaria: " << promedio << endl;
                } else {
                    cout << "No hay elementos en la diagonal secundaria\n";
                }
                break;
            case 5: {
                int menor = menordebajodiagonalsecundaria(matriz, tamano);
                cout << "El menor numero debajo diagonal secundaria es: " << menor << endl;
                break;
            }
            case 6:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opcion no valida, intente otra vez.\n";
        }

    } while (opcion != 6);

    return 0;
}

// lee la matriz
void leermatriz(int matriz[10][10], int& tamano) {
    cout << "Ingrese tamano de la matriz (maximo 10): ";
    cin >> tamano;

    for (int i = 0; i < tamano; i++) {
        for (int j = 0; j < tamano; j++) {
            cout << "Elemento [" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
        }
    }
}

// suma diagonal principal
int sumadiagonalprincipal(int matriz[10][10], int tamano) {
    int suma = 0;
    for (int i = 0; i < tamano; i++) {
        suma = suma + matriz[i][i];
    }
    return suma;
}

// contar pares encima diagonal principal
void contarparesencimaDiagonal(int matriz[10][10], int tamano, int& cantidadPares) {
    cantidadPares = 0;
    for (int i = 0; i < tamano; i++) {
        for (int j = i + 1; j < tamano; j++) {
            if (matriz[i][j] % 2 == 0) {
                cantidadPares++;
            }
        }
    }
}

// calcula promedio diagonal secundaria
void calculapromedioDiagonalSecundaria(int matriz[10][10], int tamano) {
    sumaDiagonalSecundaria = 0;
    cantidadDiagonalSecundaria = 0;

    for (int i = 0; i < tamano; i++) {
        int j = tamano - 1 - i;
        sumaDiagonalSecundaria += matriz[i][j];
        cantidadDiagonalSecundaria++;
    }
}

// menor debajo diagonal secundaria
int menordebajodiagonalsecundaria(int matriz[10][10], int tamano) {
    int menor = matriz[1][0]; // empieza en la primer posicion debajo de la diagonal secundaria

    for (int i = 0; i < tamano; i++) {
        for (int j = 0; j < tamano; j++) {
            if (i + j > tamano - 1) { // debajo diagonal secundaria
                if (matriz[i][j] < menor) {
                    menor = matriz[i][j];
                }
            }
        }
    }

    return menor;
}
