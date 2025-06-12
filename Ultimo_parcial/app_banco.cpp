#include <iostream>
#include <stdio.h>
using namespace std;

// ESTRUCTURAS
struct CUENTAS
{
    int num_cuenta;
    int cc_titular;
    float saldo;
    CUENTAS *sig;
};

struct MOVIMIENTOS
{
    int tipo_mov;
    float sum;
    int num_cuenta;
    MOVIMIENTOS *sig;
};

//  PROTOTIPOS
void insertarCuenta(CUENTAS *&cab1);
void imprimirCuentas(CUENTAS *cab);
void consignar(CUENTAS *cab1, int num_cuenta, float valor, float &nuevoSaldo, MOVIMIENTOS *&cab2);
void retirar(CUENTAS *cab1, int num_cuenta, float valor, MOVIMIENTOS *&cab2);
void transferir(CUENTAS *cab1, int origen, int destino, float valor, MOVIMIENTOS *&cab2);
void consultarSaldo(CUENTAS *cab1, int num_cuenta, float &saldo, MOVIMIENTOS *&cab2);
void cancelarCuenta(CUENTAS *&cab1, int num_cuenta);
int cuentaExiste(CUENTAS *cab1, int num_cuenta);
void registrarMovimiento(MOVIMIENTOS *&cab2, int tipo, int cuenta, float valor);
void imprimirMovimientos(MOVIMIENTOS *cab);
// void aplicarMovimientos(CUENTAS *&cab1, MOVIMIENTOS *&cab2);

int main()
{
    CUENTAS *cab1 = NULL;     // lista de cuentas
    MOVIMIENTOS *cab2 = NULL; // lista de movimientos
    int opcion;

    do
    {
        printf("\n= BANCO JD ==\n");
        printf("1. ingresar nueva cuenta\n");
        printf("2. ver todas las cuentas\n");
        printf("3. consignar\n");
        printf("4. retirar\n");
        printf("5. transferir\n");
        printf("6. consultar saldo\n");
        printf("7. cancelar cuenta\n");
        printf("9. ver movimientos registrados\n");
        printf("10. Salir\n");
        printf("Seleccione una opcion: ");
        cin >> opcion;

        if (cin.fail()) // verifico que la entrada es un numero
        {
            cin.clear();              // limpia el error
            while (cin.get() != '\n') // descarta el resto de la entrada
                ;
            printf("entrada incorrecta \n");
            opcion = -1; // asigno un valor malo para que no se ejecute el switch
            continue;
        }

        int cuen1, cuen2;   // varible para guardar el numero de cuenta
        float valor, saldo; // aqui guardo el valor para consignar, retirar o tranferir

        switch (opcion)
        {
        case 1:
            insertarCuenta(cab1);
            break;
        case 2:
            imprimirCuentas(cab1);
            break;
        case 3:
            printf("Numero de cuenta: ");
            cin >> cuen1;
            if (cuentaExiste(cab1, cuen1)) // verifico que la cuenta exista
            {
                printf("Valor a consignar: ");
                cin >> valor;
                consignar(cab1, cuen1, valor, saldo, cab2);
                printf("nuevo saldo: %.2f\n", saldo); // muestro el nuevo saldo
            }
            else
                printf("cuenta no encontrada.\n");
            break;
        case 4:
            printf("ingrese numero de cuenta: ");
            cin >> cuen1;
            if (cuentaExiste(cab1, cuen1))
            {
                printf("cuanto va a retirar: ");
                cin >> valor;
                retirar(cab1, cuen1, valor, cab2); // procedo a retirar
            }
            else
                printf("no se encontrado la cuenta \n");
            break;
        case 5:
            printf("cuenta origen: ");
            cin >> cuen1;
            printf("cuenta destino: ");
            cin >> cuen2;
            if (cuen1 == cuen2) // miro que no se mande plata el mismo
            {
                printf("no puedes enviar a la misma cuenta\n");
            }
            else if (cuentaExiste(cab1, cuen1) && cuentaExiste(cab1, cuen2)) // verifico que ambas cuentas existan
            {
                printf("valor a transferir: ");
                cin >> valor;
                transferir(cab1, cuen1, cuen2, valor, cab2);
            }
            else
            {
                printf("1 o las 2 cuentas no existen\n");
            }
            break;
        case 6:
            printf("numero de cuenta: ");
            cin >> cuen1;
            if (cuentaExiste(cab1, cuen1))
            {
                // consultarSaldo(cab1, cuen1, saldo, cab2);
                printf("su saldo es: %.2f\n", saldo);
            }
            else
                printf("cuenta no encontrada\n");
            break;
        case 7:
            printf("numero de cuenta a cancelar: ");
            cin >> cuen1;
            cancelarCuenta(cab1, cuen1);
            break;
        case 8:
            imprimirMovimientos(cab2);
            break;
        // case 9:
        //     aplicarMovimientos(cab1, cab2);
        //     break;
        case 10:
            printf("Saliendo...\n");
            break;
        default:
            printf("opcion incorrecta\n");
        }
        if (opcion < 1 || opcion > 10)
            printf("elija una opcion correcta\n");
    } while (opcion != 10);

    return 0;
}

// FUNCIONES

void insertarCuenta(CUENTAS *&cab1)
{
    CUENTAS *nuevo = new CUENTAS; // creo un nuevo nodo
    printf("Ingresa los datos de la cuenta:\n");
    printf("nmero de cuenta: ");
    cin >> nuevo->num_cuenta;
    if (cuentaExiste(cab1, nuevo->num_cuenta)) // verifico que las cuentas existas si retorta 1 es por que ya existe / 1 representa true en c++ /
    {
        printf("ya existe\n");
        delete nuevo; // aqui libero la memoria del nodo si ya existe.
        return;       // me salgo de la funcion
    }
    printf("cedula titular: ");
    cin >> nuevo->cc_titular;
    printf("saldo inicial: ");
    cin >> nuevo->saldo;
    nuevo->sig = NULL; // pongo el siguiente nodo como NULL
    if (cab1 == NULL)
        cab1 = nuevo; // si la lista queda vacia el nuevo nodo se pone de primero
    else
    {
        CUENTAS *q = cab1;
        while (q->sig != NULL)
            q = q->sig; // recorro la lista hasta
        q->sig = nuevo; // si la lista no esta vacia la recorro hasta el final y pongo el nuevo nodo al final
    }
}

void imprimirCuentas(CUENTAS *cab)
{
    if (cab == NULL)
    {
        printf("no hay cuentas\n");
        return;
    }
    printf("\n CUENTAS \n");
    while (cab != NULL)
    {
        printf("Centa: %d | cedula: %d | saldo: %.2f\n", cab->num_cuenta, cab->cc_titular, cab->saldo);
        // imprimo los datos de la cuenta
        cab = cab->sig; // avanzo al siguiente nodo
    }
}

void consignar(CUENTAS *cab1, int num_cuenta, float valor, float &nuevoSaldo, MOVIMIENTOS *&cab2)
{
    while (cab1 != NULL)
    {
        if (cab1->num_cuenta == num_cuenta) //  busco la cuenta por su numero  de cuenta
        {
            cab1->saldo += valor; // aumento el saldo de la cuenta
            printf("ingreso exitosa. nuuevo saldo es: %.2f\n", cab1->saldo);
            nuevoSaldo = cab1->saldo;                        // y guardo el nuevo saldo en la variable pasada por referencia
            registrarMovimiento(cab2, 1, num_cuenta, valor); // procedo a guardar el movimiento
        }
        cab1 = cab1->sig; // avanzo al siguiente nodo
    }
}

void retirar(CUENTAS *cab1, int num_cuenta, float valor, MOVIMIENTOS *&cab2)
{
    while (cab1 != NULL)
    {
        if (cab1->num_cuenta == num_cuenta)
        {
            if (cab1->saldo - valor >= -50000) // verifico que no quede debajo de -50000 aja asi le permito que se endeude un poco
            {
                cab1->saldo -= valor;                            // resto el valor
                registrarMovimiento(cab2, 2, num_cuenta, valor); // y registro el movimiento
                printf("Retiro exitoso. Nuevo saldo: %.2f\n", cab1->saldo);
            }
            else
            {
                printf("Saldo insuficiente (límite -50000).\n");
            }
        }
        cab1 = cab1->sig;
    }
}

void transferir(CUENTAS *cab1, int origen, int destino, float valor, MOVIMIENTOS *&cab2)
{
    CUENTAS *o = NULL, *d = NULL, *q = cab1; // creo 2 punteros para la s 2 cuentas y un puntero para recorrer la lista
    while (q != NULL)
    {
        if (q->num_cuenta == origen)
            o = q; // si el numero de cuenta es igual al origen guardo la cuenta en o
        if (q->num_cuenta == destino)
            d = q; // si el numero de cuenta es igual al destino guardo la cuenta en d
        q = q->sig;
    }
    if (o != NULL && d != NULL && o->saldo >= valor)
    {
        o->saldo -= valor; // resto el valor de la cuenta 1 cuenta
        d->saldo += valor; // aumento el valor de la 2gunda cuenta
        registrarMovimiento(cab2, 3, origen, valor);
        registrarMovimiento(cab2, 4, destino, valor);
        printf("transferencia exitosa\n");
    }
    else
    {
        printf("transferencia fallida. verifique saldos\n");
    }
}

// void consultarSaldo(CUENTAS *cab1, int num_cuenta, float &saldo, MOVIMIENTOS *&cab2)
// {
//     while (cab1 != NULL)
//     {
//         if (cab1->num_cuenta == num_cuenta)
//         {
//             saldo = cab1->saldo;
//             registrarMovimiento(cab2, 4, num_cuenta, 0);
//         }
//         cab1 = cab1->sig;
//     }
// }

void cancelarCuenta(CUENTAS *&cab1, int num_cuenta)
{
    CUENTAS *q = cab1, *ant = NULL; // creo un puntero para recorrer la lista y otro para guardar el nodo anterior
    while (q != NULL && q->num_cuenta != num_cuenta)
    {
        ant = q;    // guardo el nodo anterior
        q = q->sig; // avanzo al siguiente nodo
    }
    if (q == NULL)
    {
        printf("Cuenta no encontrada.\n");
        return;
    }
    if (q->saldo < 0)
    {
        printf("No puede cancelarse estas debiendo plata \n");
        return;
    }
    if (ant == NULL)
        cab1 = q->sig; // si el nodo a eliminar es el primero, actualizo la cabeza de la lista
    else
        ant->sig = q->sig;
    delete q;
    printf("cuenta eliminada\n");
}

int cuentaExiste(CUENTAS *cab1, int num_cuenta)
{
    while (cab1 != NULL)
    {
        if (cab1->num_cuenta == num_cuenta)
            return 1; // cuenta existe y retorna 1 que es true en c++
        cab1 = cab1->sig;
    }
    return 0;
}

void registrarMovimiento(MOVIMIENTOS *&cab2, int tipo, int cuenta, float valor)
{
    MOVIMIENTOS *nuevo = new MOVIMIENTOS; // creo un nuevo nodo para el movimiento
    nuevo->tipo_mov = tipo;               // tipo de movimiento 1 consignacion, 2 retiro, 3 transferencia desde, 4 transferencia hacia, 5 consulta saldo
    nuevo->num_cuenta = cuenta;
    nuevo->sum = valor;
    nuevo->sig = NULL; // pongo el siguiente nodo como NULL
    if (cab2 == NULL)  // si la lista de movimientos esta vacia
        cab2 = nuevo;  // el nuevo nodo se pone de primero
    else
    {
        MOVIMIENTOS *q = cab2; // creo un puntero para recorrer la lista del movimientos
        while (q->sig != NULL)
            q = q->sig; // recorro la lista hasta el final
        q->sig = nuevo; // pongo el nuevo nodo al final de la lista
    }
}

void imprimirMovimientos(MOVIMIENTOS *cab)
{
    if (cab == NULL)
    {
        printf("no hay movimientos.\n");
        return;
    }
    printf("____ MOVIMIENTOS ___ \n");
    while (cab != NULL)
    {
        printf("Cuenta: %d | Valor: %.2f | Tipo: %d\n", cab->num_cuenta, cab->sum, cab->tipo_mov);
        cab = cab->sig;
    }
}
