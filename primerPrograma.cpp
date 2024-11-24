#include <iostream>
using namespace std;

// Función para determinar el cuadrante
void determinarCuadrante(int x, int y) {
    if (x > 0 && y > 0) {
        cout << "La coordenada (" << x << ", " << y << ") se encuentra en el Cuadrante 1." << endl;
    } else if (x < 0 && y > 0) {
        cout << "La coordenada (" << x << ", " << y << ") se encuentra en el Cuadrante 2." << endl;
    } else if (x < 0 && y < 0) {
        cout << "La coordenada (" << x << ", " << y << ") se encuentra en el Cuadrante 3." << endl;
    } else if (x > 0 && y < 0) {
        cout << "La coordenada (" << x << ", " << y << ") se encuentra en el Cuadrante 4." << endl;
    } else if (x == 0 && y != 0) {
        cout << "La coordenada (" << x << ", " << y << ") se encuentra en el eje Y." << endl;
    } else if (x != 0 && y == 0) {
        cout << "La coordenada (" << x << ", " << y << ") se encuentra en el eje X." << endl;
    } else {
        cout << "La coordenada (" << x << ", " << y << ") se encuentra en el origen." << endl;
    }
}

// Función para determinar si tres puntos se encuentran en la misma línea
bool estanEnLaMismaLinea(int x1, int y1, int x2, int y2, int x3, int y3) {
    // Usamos la fórmula de la pendiente (y2 - y1) / (x2 - x1) == (y3 - y1) / (x3 - x1)
    // Evitamos la división, multiplicamos en cruz
    return (y2 - y1) * (x3 - x1) == (y3 - y1) * (x2 - x1);
}

// Función para calcular la ecuación de la recta (y = mx + b)
void calcularEcuacionRecta(int x1, int y1, int x2, int y2) {
    if (x1 == x2) { // Caso especial cuando la línea es vertical
        cout << "La ecuacion de la recta es: x = " << x1 << endl;
    } else {
        // Calculamos la pendiente m
        double m = double(y2 - y1) / (x2 - x1);
        // Calculamos la intersección con el eje Y (b)
        double b = y1 - m * x1;
        
        cout << "La ecuacion de la recta es: y = " << m << "x + " << b << endl;
    }
}

int main() {
    int n;
    cout << "Introduce el numero de coordenadas: ";
    cin >> n;

    // Arrays para almacenar las coordenadas
    int x[n], y[n];

    // Leer las coordenadas
    for (int i = 0; i < n; i++) {
        cout << "Introduce la coordenada #" << i + 1 << " (x, y): ";
        cin >> x[i] >> y[i];

        // Determinar en qué cuadrante se encuentra la coordenada
        determinarCuadrante(x[i], y[i]);
    }

    // Verificar si las coordenadas se encuentran en la misma línea
    bool estanEnLinea = true;
    for (int i = 2; i < n; i++) {
        if (!estanEnLaMismaLinea(x[0], y[0], x[1], y[1], x[i], y[i])) {
            estanEnLinea = false;
            break;
        }
    }

    if (estanEnLinea) {
        cout << "Las coordenadas se encuentran en la misma linea." << endl;
        calcularEcuacionRecta(x[0], y[0], x[1], y[1]);
    } else {
        cout << "Las coordenadas no se encuentran en la misma linea." << endl;
    }

    return 0;
}
