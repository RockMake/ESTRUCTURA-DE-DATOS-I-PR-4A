// dada una lista simple apuntada por cabecera(cab), la cual contiene numeros entereos cualquiera esscriba un programa si - no pasado por referencia(procedimiento, pasa valor pero no devuelve, devuelve un parametro bolean en el main) el cual permita determinar si la lista de numero cumple o no la condicion de la serie de fibonacci.

// Notas 1.
//  determine el prototipo,
//  la invocacion y el cuerpo.2. el resultado no se muestra dentro del sub programa
//  3. la serie de fibonacci tiene el siguiente comportamiento 0,1 --, 1, 2, 3, 4, 8, 13, 21, 34, ....

struct nodo
{
    int dato;
    nodo *sig;
};
// prototipo
void cumple_serie_fibonacci(nodo *cab, bool &resultado);
// invocación
cumple_serie_fibonacci(cab);
// cuerpo
void cumple_serie_fibonacci(nodo *cab, bool &resultado)
{
    // variables locales
    int a = 0, b = 1, c = 0;
    nodo *p = cab;

    if (cab == NULL || cab->sig == NULL || cab->sig->sig == NULL)
    {
        resultado = true;
    }

    else
    {
        while (p != NULL)
        {
            c = a + b;
            if (p->dato != c)
            {
                resultado = false;
            }
            a = b;
            b = c;
            p = p->sig;
        }
        resultado = true;
    }
}