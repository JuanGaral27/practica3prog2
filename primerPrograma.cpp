#include <iostream>
using namespace std;

struct punto {
    int x;
    int y;
}p;


void determinarCuadrante(const punto &pt) {
    if (pt.x > 0 && pt.y > 0) {
        cout << "La coordenada (" << pt.x << ", " << pt.y << ") esta en el Cuadrante 1." << endl;
    } else if (pt.x < 0 && pt.y > 0) {
        cout << "La coordenada (" << pt.x << ", " << pt.y << ") esta en el Cuadrante 2." << endl;
    } else if (pt.x < 0 && pt.y < 0) {
        cout << "La coordenada (" << pt.x << ", " << pt.y << ") esta en el Cuadrante 3." << endl;
    } else if (pt.x > 0 && pt.y < 0) {
        cout << "La coordenada (" << pt.x << ", " << pt.y << ") esta en el Cuadrante 4." << endl;
    } else if (pt.x == 0 && pt.y != 0) {
        cout << "La coordenada (" << pt.x << ", " << pt.y << ") esta en el eje Y." << endl;
    } else if (pt.x != 0 && pt.y == 0) {
        cout << "La coordenada (" << pt.x << ", " << pt.y << ") esta en el eje X." << endl;
    } else {
        cout << "La coordenada (" << pt.x << ", " << pt.y << ") esta en el origen." << endl;
    }
}

int main() {
    punto p;  
    char opcion;

    do {
        
        cout << "Ingrese la p X: ";
        cin >> p.x;
        cout << "Ingrese la p Y: ";
        cin >> p.y;

       
        determinarCuadrante(p);

        cout << "Desea ingresar otra p? (s/n): ";
        cin >> opcion;

    } while (opcion == 's' || opcion == 'S');

    return 0;
}
