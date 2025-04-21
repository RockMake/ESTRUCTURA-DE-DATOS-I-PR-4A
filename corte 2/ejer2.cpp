// dada una lista simple apuntada por cabecera (Cab) la cual contiene por cada nodo la edad de un estudiante de la universidad, escriba un si (pasa parametro)- no (no devuelve nada)
// que permita imprimir un mensaje para determinar si, se encontro al menos un estudiante menor de edad en la lista o nodo
#include <iostream>
struct estudiante
{
    int edad;
    estudiante *siguiente;
};

void menorEdad(estudiante *cab);

// invocacion
menorEdad(cab); // pasa como parametro la cabecera de la lista

void menorEdad(estudiante *cab)
{
    if (cab && cab->siguiente)
    {
        std::cout << "La lista está vacía o tiene un solo nodo." << std::endl;
        return;
    }

    estudiante *actual = cab;

    while (actual != NULL)
    {
        if (actual->edad < 18)
        {
            std::cout << "Se encontró un estudiante menor de edad." << std::endl;
            return;
        }
        actual = actual->siguiente;
    }
    std::cout << "No se encontró ningún estudiante menor de edad." << std::endl;
}