// dada una lista simple apuntada por cabecera
// la cual contiene nueros enteros positivos cualquiera diferentes a 0, escriban una función que permita retornar el promedio de los números impares contenidos en la lista

struc serie
{
    int numero;
    serie *siguiente; // puntero a la siguiente estructura
}
*cab; // variable de control que apunta a la cabeza de la lista

float promedioImpares(serie *cab); // prototipo de la función promedioImpares

float promedioImpares(serie *cab)
{
    int contador = 0; // variable para contar los números impares
    int suma = 0;     // variable para sumar los números impares
    if (cab == NULL)  // si la lista está vacía
    {
        std::cout << "La lista está vacía." << std::endl; // imprimir mensaje
        if cap
            ->siguiente
            {
                while (cab != NULL) // mientras no se llegue al final de la lista
                {
                    if (cab->numero % 2 != 0) // si el número es impar
                    {
                        suma += cab->numero; // sumar el número impar
                        contador++;          // incrementar el contador
                    }
                    cab = cab->siguiente; // avanzar al siguiente nodo
                }
                        }
    }
}