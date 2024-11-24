#include <iostream>
#include <cmath>
using namespace std;

struct Punto {
    double x;
    float y;
};

double distanciap(const Punto& p1, const Punto& p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

bool estaEnCuadrante(const Punto& p, int xMin, int xMax, int yMin, int yMax) {
    return (p.x >= xMin && p.x <= xMax && p.y >= yMin && p.y <= yMax);
}

double distanciaMaximaEnCuadrante(Punto puntos[], int numPuntos, int xMin, int xMax, int yMin, int yMax) {
    double maxDistancia = 0.0;
    
    for (int i = 0; i < numPuntos; ++i) {
        if (!estaEnCuadrante(puntos[i], xMin, xMax, yMin, yMax))
            continue;
        
        for (int j = i + 1; j < numPuntos; ++j) {
            if (estaEnCuadrante(puntos[j], xMin, xMax, yMin, yMax)) {
                double distancia = distanciap(puntos[i], puntos[j]);
                if (distancia > maxDistancia) {
                    maxDistancia = distancia;
                }
            }
        }
    }
    
    return maxDistancia;
}

int main() {
    
    int xMin, xMax, yMin, yMax;
    cout << "Ingrese los limites del cuadrante (xMin, xMax, yMin, yMax): ";
    cin >> xMin >> xMax >> yMin >> yMax;

  
    int numPuntos;
    cout << "Ingrese el numero de puntos: ";
    cin >> numPuntos;
    Punto puntos[numPuntos];
    for (int i = 0; i < numPuntos; ++i) {
        cout << "Ingrese las coordenadas del punto " << i + 1 << " (x y): ";
        cin >> puntos[i].x >> puntos[i].y;
    }

    double maxDistancia = distanciaMaximaEnCuadrante(puntos, numPuntos, xMin, xMax, yMin, yMax);
    cout << "La distancia maxima entre dos puntos dentro del cuadrante es: " << maxDistancia << endl;

    return 0;
}
