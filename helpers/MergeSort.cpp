#ifndef MERGE_SORT
#define MERGE_SORT

// MergeSort: O(N log N) en tiempo, O(N) en espacio.
//
// 1) Enteros, de menor a mayor:
//
//      int numeros[5] = {4, 1, 3, 9, 7};
//      mergeSort(numeros, 5); // 1 3 4 7 9
//
// 2) Cualquier tipo, con un criterio propio. El criterio es una funcion que
//    recibe dos elementos y devuelve true si el primero va ANTES que el segundo:
//
//      struct Curso { int inicio; int fin; };
//      bool terminaAntes(Curso a, Curso b) { return a.fin < b.fin; }
//      ...
//      mergeSort(cursos, n, terminaAntes);

template <class T>
void mergeSortAux(T *arr, T *aux, int inicio, int fin, bool (*vaAntes)(T, T))
{
    if (inicio >= fin)
    {
        return;
    }
    int mitad = (inicio + fin) / 2;

    mergeSortAux(arr, aux, inicio, mitad, vaAntes);
    mergeSortAux(arr, aux, mitad + 1, fin, vaAntes);

    // intercalar las dos mitades ordenadas
    int i = inicio, j = mitad + 1, k = inicio;
    while (i <= mitad && j <= fin)
    {
        if (vaAntes(arr[j], arr[i]))
        {
            aux[k++] = arr[j++];
        }
        else
        {
            aux[k++] = arr[i++];
        }
    }
    while (i <= mitad)
    {
        aux[k++] = arr[i++];
    }
    while (j <= fin)
    {
        aux[k++] = arr[j++];
    }
    for (k = inicio; k <= fin; k++)
    {
        arr[k] = aux[k];
    }
}

template <class T>
void mergeSort(T *arr, int n, bool (*vaAntes)(T, T))
{
    if (n <= 1)
    {
        return;
    }
    T *aux = new T[n];
    mergeSortAux(arr, aux, 0, n - 1, vaAntes);
    delete[] aux;
}

bool enteroMenor(int a, int b)
{
    return a < b;
}

void mergeSort(int *arr, int n)
{
    mergeSort<int>(arr, n, enteroMenor);
}

#endif
