// dada una lista simple apuntada por la variable de control cab
//     la cual contiene información de las notas obtenidas por estudiantes de una asignatura cualquiera.escriba un si,
//     si que permita retornar cuantos estudiantes reprobaron dicha asignatura.

#include <iostream>

struct estudiante
{
    int cedula;
    char nombre[20];
    float nota1;
    estudiante *siguiente; // puntero a la siguiente estructura
} *cab;                    // variable de control que apunta a la cabeza de la lista

estudiante *cab = NULL; // variable de control que apunta a la cabeza de la lista

int contarReprobados(estudiante *cab); // prototipo de la función contarReprobados

int contarReprobados(estudiante *cab)
{
    if (cab == NULL) // si la lista está vacía
    {
        std::cout << "La lista está vacía." << std::endl; // imprimir mensaje
        if cab
            ->siguiente
            {
                /* code */
            }

        // retornar 0
    }

    int contador = 0;         // variable para contar los estudiantes reprobados
    estudiante *actual = cab; // puntero auxiliar para recorrer la lista

    while (actual != NULL) // mientras no se llegue al final de la lista
    {
        if (actual->nota1 < 10) // si la nota es menor a 10
        {
            contador++; // incrementar el contador
        }
        actual = actual->siguiente; // avanzar al siguiente nodo
    }
    return contador; // retornar el contador de estudiantes reprobados
}

int main()
{
}
