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

// Ejercicio 4 - Mao meno parecidas
// La letra, el formato de entrada y de salida estan en el README.md de esta carpeta.

int main()
{
    // Estas dos lineas son solo para optimizar: hacen que cin y cout sean mas
    // rapidos. No las borren. Con ellas, no mezclen cin/cout con scanf/printf.
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int canCambios = 0;

    int P;
    cin >> P;

    for (int i = 0; i < P; i++)
    {

        string pal1;
        cin >> pal1;

        string pal2;
        cin >> pal2;

        int largoPal1 = pal1.length();
        int largoPal2 = pal2.length();

        if (largoPal1 == 0)
        {
            return largoPal2;
        }

        if (largoPal2 == 0)
        {
            return largoPal1;
        }

        char *palabra1 = new char[largoPal1 + 1];
        char *palabra2 = new char[largoPal1 + 1];

        int cont = 0;

        while (cont <= largoPal1 && cont <= largoPal2)
        {
            if (palabra1[cont] != palabra2[cont])
            {
                canCambios++;
                cont++;
            }
        }

        canCambios += abs(largoPal1 - largoPal2);
    }

    cout << canCambios << endl;

    // TODO
    return 0;
}
