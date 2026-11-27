#include <cassert>
#include <string>
#include <iostream>
#include <limits>
// Estructuras disponibles (descomentar las que se usen):
// #include "../../adts/ListImp.cpp"
// #include "../../adts/QueueImp.cpp"
// #include "../../adts/StackImp.cpp"
// #include "../../adts/MinHeap.cpp"
// #include "../../helpers/MergeSort.cpp"
using namespace std;

// Ejercicio 3 - Cuanto me llevo
// La letra, el formato de entrada y de salida estan en el README.md de esta carpeta.

int robo(int *plata, int n)
{
    if (n == 0)
        return plata[0];
    if (n == 1)
        return plata[1];
    int *tab = new int[n + 1]();
    int ac=0;
    tab[0] = plata[0];
    bool *robe = new bool[n + 1]();
    for (int i = 2; i <= n; i++)
    {
        if (!robe[i - 1])
        {
            tab[i] = max(plata[i+1], plata[i]);;
            robe[i] = true;
        }
    }
    return tab[n];
}

int main()
{
    // Estas dos lineas son solo para optimizar: hacen que cin y cout sean mas
    // rapidos. No las borren. Con ellas, no mezclen cin/cout con scanf/printf.
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;

    int *plata = new int[N]();
    for (int i = 0; i < N; i++)
    {
        cin >> plata[i];
        cout << robo(plata, N) << endl;
    }

    return 0;
}
