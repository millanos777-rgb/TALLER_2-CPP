#include <iostream>
#include <iomanip>
#include <algorithm> 
using namespace std;

int main() {
    cout << "=== EJERCICIO 1: MEDIANA DE UN ARRAY ===\n\n";

    // Array creado directamente en el programa (puedes cambiar los valores)
    int arr[] = {10, 15, 25, 20, 5};
    int n = sizeof(arr) / sizeof(arr[0]); // número de elementos

    // Mostrar el array original
    cout << "Array original: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    // Ordenamos el array (modifica 'arr' en sitio)
    sort(arr, arr + n);

    // Mostrar el array ordenado
    cout << "Array ordenado:  ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    // Calcular la mediana
    double mediana;
    if (n == 0) {
        cout << "No hay elementos para calcular la mediana.\n";
        return 0;
    } else if (n % 2 == 0) {
        // Si hay par número de elementos, mediana = promedio de los dos del centro
        mediana = (arr[n/2 - 1] + arr[n/2]) / 2.0; // 2.0 para forzar double
    } else {
        // Si es impar, mediana = elemento central
        mediana = arr[n/2];
    }

    cout << "La mediana es: " << mediana << "\n\n";

    cout << "Fin del ejercicio 1.\n";
    return 0;
    
// 2. Implementa la búsqueda binaria en un array ordenado
    
    cout << "\n=== EJERCICIO 2: BUSQUEDA BINARIA ===\n";

    int num;
    cout << "¿Cuantos elementos tendra el array? ";
    cin >> num;

    int arr[num];
    cout << "Ingresa los " << num << " elementos:\n";
    for (int i = 0; i < num; i++) {
        cin >> arr[i];
    }

    // Ordenamos el array (requisito de la búsqueda binaria)
    sort(arr, arr + num);

    cout << "\nArray ordenado: ";
    for (int i = 0; i < num; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    // El usuario elige el elemento que quiere buscar
    int buscar;
    cout << "\nIngresa el numero que deseas buscar: ";
    cin >> buscar;

    // Búsqueda binaria
    int inicio = 0, fin = num - 1;
    bool encontrado = false;

    while (inicio <= fin) {
        int medio = (inicio + fin) / 2;

        if (arr[medio] == buscar) {
            cout << "Elemento " << buscar << " encontrado en la posicion " << medio << " (del array ordenado).\n";
            encontrado = true;
            break;
        }
        else if (arr[medio] < buscar) {
            inicio = medio + 1;
        }
        else {
            fin = medio - 1;
        }
    }

    if (!encontrado) {
        cout << "El elemento " << buscar << " no se encuentra en el array.\n";
    }
    
// 3. Desarrolla un programa que calcule la transpuesta de una matriz

    cout << "=== EJERCICIO 3: TRANSPUESTA DE UNA MATRIZ ===\n\n";

    int matriz[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Matriz original:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            cout << setw(3) << matriz[i][j];
        cout << endl;
    }

    cout << "\nMatriz transpuesta:\n";
    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < 3; i++)
            cout << setw(3) << matriz[i][j];
        cout << endl;
    }

    return 0;    
    
// 4. Crea un sistema de inventario simple con arrays

     cout << "=== EJERCICIO 4: INVENTARIO SIMPLE ===\n\n";

    const int TAM = 5;
    string productos[TAM] = {"Pan", "Leche", "Arroz", "Huevos", "Cafe"};
    int cantidades[TAM] = {10, 20, 15, 30, 5};

    cout << "Inventario inicial:\n";
    for (int i = 0; i < TAM; i++)
        cout << productos[i] << " - Cantidad: " << cantidades[i] << "\n";

    // Simulamos una venta
    cantidades[1] -= 13; // vendimos 13 Leches
    cantidades[3] -= 22; // vendimos 22 huevos 
    cantidades[0] -= 6; // vendimos 6 panes 
    cantidades[2] -= 7; // vendimos 7Lb de arroz 
    cantidades[4] -= 5; // vendimos 5K de cafe 
    cout << "\nInventario actualizado:\n";
    for (int i = 0; i < TAM; i++)
        cout << productos[i] << " - Cantidad: " << cantidades[i] << "\n";

    return 0;
    
// 5. Implementa el algoritmo de ordenamiento por selección

    cout << "=== EJERCICIO 5: ORDENAMIENTO POR SELECCION ===\n\n";

    int arr[] = {64, 25, 12, 22, 11, 34, 20,80,100, 1,17};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array original: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    // Selección
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) minIdx = j;
        }
        swap(arr[i], arr[minIdx]);
    }

    cout << "Array ordenado: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
    
// 6. Desarrolla un programa que encuentre elementos duplicados

     cout << "=== EJERCICIO 6: ELEMENTOS DUPLICADOS ===\n\n";

    int arr[] = {1, 2, 3, 2, 4, 5, 1, 7, 6, 4, 8, 9, 10, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);
    bool duplicado = false;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                cout << "Elemento duplicado encontrado: " << arr[i] << "\n";
                duplicado = true;
            }
        }
    }

    if (!duplicado)
        cout << "No hay elementos duplicados\n";

    return 0;
    
// 7.  Crea un juego de tres en raya usando arrays bidimensionales

    cout << "=== EJERCICIO 7: TRES EN RAYA ===\n\n";

    char tablero[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    int jugadas = 0;
    char jugador = 'X';
    bool ganador = false;

    while (jugadas < 9 && !ganador) {
        // Mostrar tablero
        cout << "\nTablero:\n";
        for (int i = 0; i < 3; i++) {
            cout << " ";
            for (int j = 0; j < 3; j++) {
                cout << tablero[i][j];
                if (j < 2) cout << " | ";
            }
            cout << "\n";
            if (i < 2) cout << "---+---+---\n";
        }

        int fila, col;
        cout << "\nTurno del jugador " << jugador << ". Ingresa fila (0-2) y columna (0-2): ";
        cin >> fila >> col;

        if (fila < 0 || fila > 2 || col < 0 || col > 2 || tablero[fila][col] != ' ') {
            cout << "Movimiento invalido. Intenta de nuevo.\n";
            continue;
        }

        tablero[fila][col] = jugador;
        jugadas++;

        // Verificar filas, columnas y diagonales
        for (int i = 0; i < 3; i++) {
            if (tablero[i][0] == jugador && tablero[i][1] == jugador && tablero[i][2] == jugador) ganador = true;
            if (tablero[0][i] == jugador && tablero[1][i] == jugador && tablero[2][i] == jugador) ganador = true;
        }
        if (tablero[0][0] == jugador && tablero[1][1] == jugador && tablero[2][2] == jugador) ganador = true;
        if (tablero[0][2] == jugador && tablero[1][1] == jugador && tablero[2][0] == jugador) ganador = true;

        if (ganador) {
            cout << "\n¡El jugador " << jugador << " ha ganado!\n";
            break;
        }

        // Cambiar jugador
        jugador = (jugador == 'X') ? 'O' : 'X';
    }

    if (!ganador)
        cout << "\nEmpate. No hay ganador.\n";

    return 0;

}