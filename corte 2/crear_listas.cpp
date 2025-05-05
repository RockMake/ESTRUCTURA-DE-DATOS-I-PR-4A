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