// ejemplo de bubble sort

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
void ordenar_bubble(nodo *cab);

/* Segmento de Programa Principal*/
int main()
{
    int opc = 1;

    struct nodo *cab, *q, *nuevo;
    /* Segmento de creación de la lista */
    cab = NULL;
    while (opc == 1)
    {

        nuevo = new nodo;
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
    ordenar_bubble(cab);
}

void ordenar_bubble(nodo *cab)
{
    nodo *q, *p;
    int temp;
    q = cab;
    while (q != NULL)
    {
        p = q->sig;
        while (p != NULL)
        {
            if (q->info > p->info)
            {
                temp = q->info;
                q->info = p->info;
                p->info = temp;
            }
            p = p->sig;
        }
        q = q->sig;
    }
    printf("\n\n La lista ordenada es :\n");
    imprimir_lista(cab);
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

// /* tarea de la lista */

// leo todo un string y guardo cada letra  en un nodo
// y como leer un string y guardarlo en una lista