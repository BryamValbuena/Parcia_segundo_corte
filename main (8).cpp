#include <iostream>

using namespace std;

void quicksort(int* arr, int izq, int der) {
    int i = izq;
    int j = der;
    int temporal;
    int pivote = arr[(izq + der) / 2];

    while (i <= j) {
        while (arr[i] < pivote) {
            i++;
        }

        while (arr[j] > pivote) {
            j--;
        }

        if (i <= j) {
            temporal = arr[i];
            arr[i] = arr[j];
            arr[j] = temporal;
            i++;
            j--;
        }
    }

    if (izq < j) {
        quicksort(arr, izq, j);
    }
    if (i < der) {
        quicksort(arr, i, der);
    }
}

int main() {
    cout << "Método quicksort: \n";
    int arr[20];
    int numeroElementos = 0;

    int opcion;
    do {
        cout << "\t MENU quicksort : \n";
        cout << "Escoja una opción: \n";
        cout << "1. Insertar dígitos \n";
        cout << "2. Mostrar dígitos en orden \n";
        cout << "3. Salir";

        cin >> opcion;

        switch (opcion) {

        case 1:
            if (numeroElementos < 20) {
                cout << "Ingrese un dígito: ";
                cin >> arr[numeroElementos];
                numeroElementos++;
                cout << "Dígito insertado. \n";
            } else {
                cout << "El arreglo está lleno, máximo 20";
            }
            break;
        case 2:
            if (numeroElementos > 0) {
                cout << "Lista original: \n ";
                for (int i = 0; i < numeroElementos; i++) {
                    cout << arr[i] << " ";
                }
                cout << "\n";

                quicksort(arr, 0, numeroElementos - 1);
                cout << "Lista ordenada: \n";
                for (int i = 0; i < numeroElementos; i++) {
                    cout << arr[i] << " ";
                }
                cout << "\n";
            } else {
                cout << "El arreglo está vacío";
            }
            break;
        case 3:
            cout << "Saliendo del programa \n";
            break;
        default:
            cout << "Opción no válida \n";
        }
    } while (opcion != 3);

    return 0;
}
