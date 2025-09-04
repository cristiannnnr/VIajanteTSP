# VIajanteTSP

1. Definición de variables principales y estructura de la clase

   private:
    int n; // Número de ciudades
    vector<vector<double>> dist; // Matriz de distancias entre ciudades
    vector<int> mejor_camino; // Arreglo que guarda la mejor ruta encontrada
    double menor_costo; // Costo mínimo encontrado en la búsqueda


Esta sección define las variables que guardan el número de ciudades (n), la matriz de distancias entre todas las ciudades (dist), el mejor camino encontrado (mejor_camino) y el costo mínimo de ese camino (menor_costo). Estas variables forman la base de almacenamiento para la búsqueda y comparación de rutas[fragmento propio].

2. Constructor para inicializar variables
cpp
Viajante::Viajante(const vector<vector<double>>& matriz_dist) {
    dist = matriz_dist;
    n = dist.size();
    menor_costo = 1e9; // Inicializa con un valor muy alto
}
En el constructor, se recibe la matriz de distancias y se almacenan. También se toma el tamaño de la matriz para saber cuántas ciudades hay y se inicializa el menor_costo con un valor alto para que cualquier ruta válida sea considerada en el primer cálculo. Esto prepara el objeto para empezar la búsqueda[fragmento propio].

3. Función recursiva para generar permutaciones de rutas
cpp
void Viajante::permutar(vector<int>& camino, int inicio) {
    if (inicio == n - 1) {
        double costo_actual = calcular_costo(camino);
        if (costo_actual < menor_costo) {
            menor_costo = costo_actual;
            mejor_camino = camino;
        }
    } else {
        for (int i = inicio; i < n; i++) {
            swap(camino[inicio], camino[i]);
            permutar(camino, inicio + 1);
            swap(camino[inicio], camino[i]);
        }
    }
}
Esta función genera todas las permutaciones posibles del vector que contiene la ruta actual (camino). Cuando llega a una permutación completa (inicio == n - 1), calcula el costo total de esa ruta. Si el costo es inferior al mejor costo encontrado hasta el momento, actualiza las variables. Esta es la función que implementa la búsqueda exhaustiva (fuerza bruta) en el problema del viajante[fragmento propio].

4. Función para calcular el costo total de un camino
cpp
double Viajante::calcular_costo(const vector<int>& camino) {
    double suma = 0;
    for (int i = 0; i < n - 1; i++) {
        suma += dist[camino[i]][camino[i + 1]];
    }
    suma += dist[camino[n - 1]][camino[0]];
    return suma;
}
Esta función suma las distancias entre ciudades consecutivas en la ruta y añade el regreso a la ciudad inicial para cerrar el ciclo. Devuelve la suma total de estas distancias, que es el costo de la ruta[fragmento propio].

5. Inicio de la búsqueda y configuración del vector de ruta
cpp
void Viajante::resolver() {
    vector<int> camino(n);
    for (int i = 0; i < n; i++) camino[i] = i;
    permutar(camino, 0);
}
Aquí se inicializa el camino con la secuencia natural de ciudades (0 hasta n-1) y se comienza la búsqueda de permutaciones desde la posición 0. Es el disparador de la función recursiva para comprobar todas las rutas posibles[fragmento propio].

6. Impresión del mejor resultado encontrado
cpp
void Viajante::imprimir_resultados() {
    cout << "Mejor ruta: ";
    for (int i = 0; i < n; i++) {
        cout << mejor_camino[i] << " ";
    }
    cout << mejor_camino[0] << endl;
    cout << "Costo minimo: " << menor_costo << endl;
}
Finalmente, se muestra en consola la mejor ruta encontrada y el costo mínimo para completar esa ruta[fragmento propio].
