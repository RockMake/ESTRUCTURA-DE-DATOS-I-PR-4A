// dada una lisa simple apuntada por cabecera la cual contiene números enteros cuales quieras distintos a 0, escriba cuantos números pares encontró que hay estados presedidos por números impares..utilicé un si - si (pasa parametro y recibe parametro)

//                                                                                                                                                                                nota :

//                                                                                                                                                                                1. no se requiere el programa main.2. determine el prototipo,
//   la invocación y el cuerpo del subprograma

//  multiplo divisor

#include <iostream>
using namespace std;

// prototipo

struct numero
{
    int dato;
    numero *sig;
};

int pares_precedidos_por_impares(numero *cab);
// invocación
resultado = pares_precedidos_por_impares(cab);

// cuerpo
int pares_procedidos_por_impares(numero *cab)
{
    // variables locales
    int contador = 0; // contador de pares precedidos por impares
    numero *p, *q     // numero *p; // puntero auxiliar para recorrer la lista
               if (cab == NULL)
    {
        cout << "La lista está vacía." << endl;
    }
    else
    {
        q = cab;    // inicializar el puntero auxiliar al inicio de la lista
        p = q->sig; // inicializar el puntero auxiliar al segundo nodo

        while (p != NULL)
        {
            if (p->dato % 2 == 0) // si el número es par
            {
                if (p->sig != NULL && p->sig->dato % 2 != 0) // si el siguiente número es impar
                {
                    contador++; // incrementar el contador
                }
            }
            p = p->sig; // avanzar al siguiente nodo
        }
        return contador; // devolver el resultado
    }
}