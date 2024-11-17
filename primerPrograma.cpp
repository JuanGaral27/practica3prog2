#include <iostream>
#include <cmath>

using namespace std;

// Estructura para representar un punto en el plano cartesiano
struct Punto {
    int x;
    int y;
};

// Función para calcular la pendiente entre dos puntos
float calcularPendiente(const Punto &p1, const Punto &p2) {
    if (p1.x == p2.x) {
        // Caso especial: línea vertical
        throw invalid_argument("Pendiente indefinida (línea vertical).");
    }
    return static_cast<float>(p2.y - p1.y) / (p2.x - p1.x);
}

// Función para calcular el intercepto (b) usando y = mx + b
float calcularIntercepto(const Punto &p, float pendiente) {
    return p.y - pendiente * p.x;
}

// Función para verificar si un punto pertenece a la misma línea
bool perteneceALinea(const Punto &p, float pendiente, float intercepto) {
    return fabs(p.y - (pendiente * p.x + intercepto)) < 1e-5;
}

int main() {
    const int MAX_PUNTOS = 100;
    Punto puntos[MAX_PUNTOS];
    int numPuntos;

    cout << "Ingrese el número de puntos a evaluar (máximo " << MAX_PUNTOS << "): ";
    cin >> numPuntos;

    if (numPuntos < 2) {
        cout << "Se necesitan al menos 2 puntos para determinar una línea." << endl;
        return 1;
    }

    // Captura de los puntos
    for (int i = 0; i < numPuntos; ++i) {
        cout << "Ingrese la coordenada X del punto " << i + 1 << ": ";
        cin >> puntos[i].x;
        cout << "Ingrese la coordenada Y del punto " << i + 1 << ": ";
        cin >> puntos[i].y;
    }

    try {
        // Calcular pendiente y intercepto usando los dos primeros puntos
        float pendiente = calcularPendiente(puntos[0], puntos[1]);
        float intercepto = calcularIntercepto(puntos[0], pendiente);

        // Verificar si los demás puntos están en la misma línea
        bool todosEnLinea = true;
        for (int i = 2; i < numPuntos; ++i) {
            if (!perteneceALinea(puntos[i], pendiente, intercepto)) {
                todosEnLinea = false;
                break;
            }
        }

        if (todosEnLinea) {
            cout << "Todos los puntos están en la misma línea." << endl;
            cout << "La ecuación de la línea es: y = " << pendiente << "x + " << intercepto << endl;
        } else {
            cout << "No todos los puntos están en la misma línea." << endl;
        }
    } catch (const invalid_argument &e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
