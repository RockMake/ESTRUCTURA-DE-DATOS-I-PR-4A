// dada una lista simple apuntada por cabecera
// la cual contiene nueros enteros positivos cualquiera diferentes a 0, escriban una función que permita retornar el promedio de los números impares contenidos en la lista

struc serie
{
    int numero;
    serie *siguiente; // puntero a la siguiente estructura
} // variable de control que apunta a la cabeza de la lista

float promedioImpares(serie *cab); // prototipo de la función promedioImpares

float promedioImpares(serie *cab)
{
    int contador = 0;
    int suma = 0;
    if (cab == NULL)
    {
        std::cout << "La lista está vacía." << std::endl;
        if cap
            ->siguiente
            {
                while (cab != NULL)
                {
                    if (cab->numero % 2 != 0)
                    {
                        suma += cab->numero;
                        contador++;
                    }
                    cab = cab->siguiente;
                }
            }
    }
}