#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cstdlib>   
#include <ctime>     

using namespace std;

//Calcula el costo total de un recorrido (tour) sumando todas las distancias entre las ciudades del recorrido e incluyendo el regreso a la ciudad inicial
int calcularCosto(const vector< vector<int> > &distancias, const vector<int> &tour) {
    int costo = 0;
    int n = tour.size();

    // Sumar distancias entre ciudades consecutivas
    for (int i = 0; i < n - 1; i++) {
        costo += distancias[tour[i]][tour[i + 1]];
    }

    // Regresar a la ciudad inicial
    costo += distancias[tour[n - 1]][tour[0]];
    return costo;
}

int main() {
    srand(time(0)); // Inicializar generador aleatorio con la hora actual

    int n;
    cout << "Ingrese el numero de ciudades (n <= 10): ";
    cin >> n;

    if (n < 2 || n > 10) {
        cout << "Error: el numero de ciudades debe estar entre 2 y 10." << endl;
        return 0;
    }

    // Crear matriz de distancias aleatoria (NO simétrica)
    vector< vector<int> > distancias(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                distancias[i][j] = 0; // La diagonal siempre es 0
            } else {
                // Valor aleatorio entre 10 y 59
                distancias[i][j] = (rand() % 50) + 10;
            }
        }
    }

    // Mostrar la matriz generada
    cout << "\nMatriz de distancias generada:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << distancias[i][j] << "\t";
        }
        cout << endl;
    }

    // Acá se crean las permutaciones de las ciudades excepto la ciudad 0, que siempre es el punto de inicio.
    vector<int> ciudades;
    for (int i = 1; i < n; i++) {
        ciudades.push_back(i);
    }

    int mejorCosto = numeric_limits<int>::max();
    vector<int> mejorTour;

    // Fuerza bruta: probar todas las permutaciones de (n-1)!
    do {
        vector<int> tour;
        tour.push_back(0); // ciudad inicial
        for (size_t i = 0; i < ciudades.size(); i++) {
            tour.push_back(ciudades[i]);
        }

        int costo = calcularCosto(distancias, tour);

        if (costo < mejorCosto) {
            mejorCosto = costo;
            mejorTour = tour;
        }

    } while (next_permutation(ciudades.begin(), ciudades.end()));

    // Mostrar resultado
    cout << "\nEl tour minimo es: ";
    for (size_t i = 0; i < mejorTour.size(); i++) {
        cout << mejorTour[i] << " -> ";
    }
    cout << "0" << endl;

    cout << "Costo minimo: " << mejorCosto << endl;

    return 0;
}

