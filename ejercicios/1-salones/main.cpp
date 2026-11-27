#include <cassert>
#include <string>
#include <iostream>
#include <climits>
#include <limits>
// Estructuras disponibles (descomentar las que se usen):
#include "../../adts/ListImp.cpp"
// #include "../../adts/QueueImp.cpp"
// #include "../../adts/StackImp.cpp"
#include "../../adts/MinHeap.cpp"
// #include "../../helpers/MergeSort.cpp"
using namespace std;

// Ejercicio 1 - Salones de Bedelia
// La letra, el formato de entrada y de salida estan en el README.md de esta carpeta.

int funcionCom(int a, int b)
{
    return a - b;
}

int cantMinima(MinHeap<int> *comienzo, MinHeap<int> *fin)
{
    int cont = 0;
    int max = 0;

    while (!comienzo->estaVacio())
    {
        int sigCom = comienzo->tope();
        int sigFin = fin->tope();
        if (sigCom < sigFin)
        {
            cont++;
            comienzo->eliminarTope();
        }
        else
        {
            cont--;
            fin->eliminarTope();
        }

        max = cont > max ? cont : max;
    }
    return max;
}

int main()
{
    // Estas dos lineas son solo para optimizar: hacen que cin y cout sean mas
    // rapidos. No las borren. Con ellas, no mezclen cin/cout con scanf/printf.
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int veces;
    cin >> veces;

    int *mins = new int[veces];

    for (int k = 0; k < veces; k++)
    {
        int cant;
        cin >> cant;

        int comAux;
        int finAux;

        MinHeap<int> *comienzo = new MinHeap<int>(cant + 1, funcionCom);
        MinHeap<int> *fin = new MinHeap<int>(cant + 1, funcionCom);

        for (int i = 0; i < cant; i++)
        {
            cin >> comAux;
            comienzo->insertar(comAux);
        }

        for (int i = 0; i < cant; i++)
        {
            cin >> finAux;
            fin->insertar(finAux);
        }

        mins[k] = cantMinima(comienzo, fin);
    }

    for (int i = 0; i < veces; i++)
    {
        cout << mins[i] << endl;
    }

    return 0;
}
