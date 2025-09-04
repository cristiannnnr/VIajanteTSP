
***

# Problema del Viajante de Comercio (TSP) Fuerza Bruta

EL programa en C++ resuelve el problema del viajante de comercio (TSP) para un conjunto pequeño de ciudades (máximo 10) utilizando un enfoque de fuerza bruta, probando todas las permutaciones posibles de rutas para encontrar el tour de costo mínimo.

## Descripción General

El código genera aleatoriamente una matriz de distancias entre ciudades (que no es simétrica) y luego calcula exhaustivamente el costo de cada posible recorrido que comienza y termina en la ciudad 0. Al final muestra la secuencia de ciudades del tour mínimo y su costo total.

***

## Explicación de Funciones y Código

### Cálculo del Costo Total del Tour

```cpp
int calcularCosto(const vector< vector<int> > &distancias, const vector<int> &tour) {
    int costo = 0;
    int n = tour.size();
    for (int i = 0; i < n - 1; i++) {
        costo += distancias[tour[i]][tour[i + 1]];
    }
    costo += distancias[tour[n - 1]][tour[0]];
    return costo;
}
```

- Esta función recibe la matriz de distancias y una secuencia (vector) que representa un tour.
- Suma las distancias entre cada ciudad consecutiva en el tour.
- Añade también la distancia de regreso desde la última ciudad a la ciudad inicial para cerrar el ciclo.
- Devuelve el costo total del recorrido.

***

### Entrada y Validación del Número de Ciudades

```cpp
int n;
cout << "Ingrese el numero de ciudades (n <= 10): ";
cin >> n;
if (n < 2 || n > 10) {
    cout << "Error: el numero de ciudades debe estar entre 2 y 10." << endl;
    return 0;
}
```

- Se solicita al usuario ingresar el número de ciudades.
- Se valida que el número esté entre 2 y 10, ya que el algoritmo de fuerza bruta es computacionalmente costoso para valores mayores.

***

### Generación de la Matriz de Distancias No Simétrica

```cpp
vector< vector<int> > distancias(n, vector<int>(n));
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        if (i == j) {
            distancias[i][j] = 0;
        } else {
            distancias[i][j] = (rand() % 50) + 10;
        }
    }
}
```

- Se crea una matriz cuadrada para distancias entre ciudades.
- La diagonal es 0 porque la distancia de una ciudad a sí misma es 0.
- Las demás distancias se generan aleatoriamente entre 10 y 59.
- La matriz no es simétrica, lo que significa que la distancia de la ciudad i a j puede ser diferente de la distancia de j a i.

***

### Búsqueda Exhaustiva de la Mejor Ruta

```cpp
vector<int> ciudades;
for (int i = 1; i < n; i++) {
    ciudades.push_back(i);
}
int mejorCosto = numeric_limits<int>::max();
vector<int> mejorTour;

do {
    vector<int> tour;
    tour.push_back(0);
    for (size_t i = 0; i < ciudades.size(); i++) {
        tour.push_back(ciudades[i]);
    }
    int costo = calcularCosto(distancias, tour);
    if (costo < mejorCosto) {
        mejorCosto = costo;
        mejorTour = tour;
    }
} while (next_permutation(ciudades.begin(), ciudades.end()));
```

- El vector `ciudades` contiene todas las ciudades salvo la ciudad 0, que se fija como punto de inicio y fin.
- Se generan todas las permutaciones posibles de las ciudades con `next_permutation`.
- Para cada permutación se calcula el costo del tour incluyendo la vuelta a la ciudad inicial.
- Se guarda el tour con el costo mínimo encontrado.

***

### Resultado Final

```cpp
cout << "\nEl tour minimo es: ";
for (size_t i = 0; i < mejorTour.size(); i++) {
    cout << mejorTour[i] << " -> ";
}
cout << "0" << endl;
cout << "Costo minimo: " << mejorCosto << endl;
```

- Se muestra la secuencia óptima de ciudades a visitar.
- Se muestra el costo total mínimo del recorrido.

***
