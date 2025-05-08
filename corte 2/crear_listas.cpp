/*este programa crea una lista simple numera y la imprime
a traves de un SI- NO (pasa parametro pero no retorna un procedimiento), asi mismo imprime a traves de un si si (pasa valor y retorna un valor )
el promedio de los numeros almaecnados en la lista.. se debe imprimir en main

*/

#include <iostream> // cin, cout
#include <stdio.h>  // printf
using namespace std;

/* Segmento de declaracion de estructuras y variables */
struct nodo
{
    int info;
    nodo *sig;
};
/* Prototipos */
void imprimir_lista(nodo *cab);
float resul_promedio(nodo *cab);
/* Segmento de Programa Principal*/
int main()
{
    int opc = 1;

    struct nodo *cab, *q, *nuevo;
    /* Segmento de creación de la lista */
    cab = NULL;
    while (opc == 1)
    {

        nuevo = new (nodo);
        printf("\nSuministre un numero:");
        cin >> nuevo->info; // se ingresa la informacion al nodo
        nuevo->sig = NULL;
        if (cab == NULL)
        {
            cab = nuevo;
            q = cab;
        }
        else
        {
            q->sig = nuevo;

            q = nuevo;
        }
        printf("\n Desea continuar ? (1:SI, 2: NO) ? :");
        cin >> opc;
    }

    /* segmento de impresion de la lista */
    printf("\n La lista creada fue :\n");
    imprimir_lista(cab);
    printf("\n\n El promedio de los numeros es : %d", resul_promedio(cab));
}

void imprimir_lista(nodo *cab)
{
    nodo *q;
    q = cab;
    while (q != NULL)
    {
        printf("  %d  ---> ", q->info);

        q = q->sig;
    }

    printf("NULL  \n");
}
float resul_promedio(nodo *cab)
{
    nodo *q;
    int suma = 0, cont = 0;
    q = cab;
    while (q != NULL)
    {
        suma = suma + q->info;
        cont++;
        q = q->sig;
    }

    if (cont == 0)
    {
        return 0;
    }
    else
    {
        return suma / cont;
    }
}

/* los nuevos requerimientos son
1. agregen un si si que permita retornar, cantos numeros de la lista estuvieron dentro del intervalo cerrado 5,10, imprima el resultado en main
2. agrege, un si - no (parametro por referencia) que permita regresar el menor numero encontrado en la lista. se imprime en main. en caso en que todos los numeros sean iguales imprima en main el mensaje apropiado  */


#include <iostream> // cin, cout
#include <stdio.h>  // printf

using namespace std;

/* Segmento de declaracion de estructuras y variables */
struct nodo {
    int info;
    nodo *sig;
};

/* Prototipos */
void imprimir_lista(nodo *cab);
float resul_promedio(nodo *cab);
int contar_intervalo(nodo *cab); // SI - SI
void encontrar_menor(nodo *cab, int &menor, bool &iguales); // SI - NO

/* Segmento de Programa Principal*/
int main() {
    int opc = 1;
    struct nodo *cab, *q, *nuevo;
    cab = NULL;

    /* Segmento de creación de la lista */
    while (opc == 1) {
        nuevo = new (nodo);
        printf("\nSuministre un numero: ");
        cin >> nuevo->info;
        nuevo->sig = NULL;

        if (cab == NULL) {
            cab = nuevo;
            q = cab;
        } else {
            q->sig = nuevo;
            q = nuevo;
        }

        printf("\nDesea continuar ? (1:SI, 2:NO) : ");
        cin >> opc;
    }

    /* segmento de impresion de la lista */
    printf("\nLa lista creada fue:\n");
    imprimir_lista(cab);

    // Promedio con decimales
    printf("\n\nEl promedio de los numeros es: %.2f", resul_promedio(cab));

    // Requerimiento 1: SI - SI
    int cantidad_en_intervalo = contar_intervalo(cab);
    printf("\n\nCantidad de numeros entre 5 y 10 (incluidos): %d", cantidad_en_intervalo);

    // Requerimiento 2: SI - NO (por referencia)
    int menor = 0;
    bool iguales = false;
    encontrar_menor(cab, menor, iguales);
    if (iguales) {
        printf("\n\nTodos los numeros en la lista son iguales: %d", menor);
    } else {
        printf("\n\nEl menor numero encontrado en la lista es: %d", menor);
    }

    return 0;
}

/* Imprimir Lista */
void imprimir_lista(nodo *cab) {
    nodo *q = cab;
    while (q != NULL) {
        printf("  %d  ---> ", q->info);
        q = q->sig;
    }
    printf("NULL\n");
}

/* Calcular promedio */
float resul_promedio(nodo *cab) {
    nodo *q = cab;
    int suma = 0, cont = 0;
    while (q != NULL) {
        suma += q->info;
        cont++;
        q = q->sig;
    }

    if (cont == 0) return 0.0;
    return (float)suma / cont;  // casteo para asegurar flotante
}

/* Requerimiento 1 - SI-SI: contar valores en [5, 10] */
int contar_intervalo(nodo *cab) {
    int cont = 0;
    nodo *q = cab;
    while (q != NULL) {
        if (q->info >= 5 && q->info <= 10) {
            cont++;
        }
        q = q->sig;
    }
    return cont;
}

/* Requerimiento 2 - SI-NO: menor valor y si todos son iguales */
void encontrar_menor(nodo *cab, int &menor, bool &iguales) {
    if (cab == NULL) {
        menor = 0;
        iguales = true;
        return;
    }

    nodo *q = cab;
    menor = q->info;
    int primero = q->info;
    iguales = true;

    q = q->sig;
    while (q != NULL) {
        if (q->info < menor) {
            menor = q->info;
        }
        if (q->info != primero) {
            iguales = false;
        }
        q = q->sig;
    }
}






