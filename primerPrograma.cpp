#include <iostream>
using namespace std;

struct punto {
    int x;
    int y;
};

void cuadrante(const punto &p) {
    if (p.x > 0 && p.y > 0) {
        cout << "La coordenada (" << p.x << ", " << p.y << ") se encuentra en el 1er cuadrante." << endl;
    } else if (p.x < 0 && p.y > 0) {
        cout << "La coordenada (" << p.x << ", " << p.y << ") se encuentra en el 2do cuadrante." << endl;
    } else if (p.x < 0 && p.y < 0) {
        cout << "La coordenada (" << p.x << ", " << p.y << ") se encuentra en el 3er cuadrante." << endl;
    } else if (p.x > 0 && p.y < 0) {
        cout << "La coordenada (" << p.x << ", " << p.y << ") se encuentra en el 4to cuadrante." << endl;
    } else if (p.x == 0 && p.y != 0) {
        cout << "La coordenada (" << p.x << ", " << p.y << ") se encuentra en el eje Y." << endl;
    } else if (p.x != 0 && p.y == 0) {
        cout << "La coordenada (" << p.x << ", " << p.y << ") se encuentra en el eje X." << endl;
    } else {
        cout << "La coordenada (" << p.x << ", " << p.y << ") se encuentra en el origen." << endl;
    }
}

int main() {
    punto p;  // Definimos p aquí para evitar el conflicto con la declaración global
    char opcion;

    do {
        cout << "Ingrese la coordenada X: ";
        cin >> p.x;
        cout << "Ingrese la coordenada Y: ";
        cin >> p.y;

        cuadrante(p);

        cout << "Desea ingresar otra coordenada? (s/n): ";
        cin >> opcion;

    } while (opcion == 's' || opcion == 'S');

    return 0;
}
