#ifndef MINHEAP
#define MINHEAP
#include <cassert>

// Min-heap sobre un array, igual al que vimos en clase.
// insertar y eliminarTope: O(log N). tope: O(1).
//
// Se crea con una capacidad fija y una funcion comparadora. La funcion recibe
// dos elementos y devuelve:
//   un numero negativo si el primero va antes (sale primero del heap),
//   cero si son iguales,
//   un numero positivo si el primero va despues.
//
// 1) Sale primero el mas chico:
//
//      int comparar(int a, int b) { return a - b; }
//      ...
//      MinHeap<int> heap(100, comparar);   // entran hasta 100 elementos
//      heap.insertar(4);
//      heap.insertar(1);
//      heap.tope();          // 1
//      heap.eliminarTope();  // saca el 1
//
// 2) Sale primero el mas grande: return b - a;
//
// 3) Cualquier tipo, con un criterio propio:
//
//      struct Curso { int inicio; int fin; };
//      int porFin(Curso a, Curso b) { return a.fin - b.fin; }
//      ...
//      MinHeap<Curso> heap(cantidad, porFin);
//
// insertar en un heap lleno hace caer el programa: revisar la capacidad.
// Para pasarlo a una funcion, usar una referencia: void f(MinHeap<int> &heap).

template <class T>
class MinHeap
{
private:
    T *arr;
    int posTope;
    int capacidad;
    int (*funcionComparadora)(T, T);

    int izq(int pos)
    {
        return pos * 2;
    }

    int der(int pos)
    {
        return (pos * 2) + 1;
    }

    int padre(int pos)
    {
        return pos / 2;
    }

    void intercambiar(int pos1, int pos2)
    {
        T aux = this->arr[pos1];
        this->arr[pos1] = this->arr[pos2];
        this->arr[pos2] = aux;
    }

    void flotar(int pos)
    {
        // trato de flotar si no soy la raiz
        if (pos > 1)
        {
            int posPadre = padre(pos);
            if (funcionComparadora(this->arr[posPadre], this->arr[pos]) > 0)
            {
                intercambiar(posPadre, pos);
                flotar(posPadre);
            }
        }
    }

    void hundir(int pos)
    {
        int posHijoIzq = izq(pos);
        int posHijoDer = der(pos);

        // si tengo mis dos hijos
        if (posHijoIzq < posTope && posHijoDer < posTope)
        {
            int posHijoMenor = funcionComparadora(arr[posHijoIzq], arr[posHijoDer]) < 0 ? posHijoIzq : posHijoDer;
            if (funcionComparadora(arr[pos], arr[posHijoMenor]) > 0)
            {
                intercambiar(pos, posHijoMenor);
                hundir(posHijoMenor);
            }
            
        }
        // si tengo solo hijo izquierdo
        else if (posHijoIzq < posTope)
        {
            if (funcionComparadora(arr[pos], arr[posHijoIzq]) > 0)
            {
                intercambiar(pos, posHijoIzq);
                hundir(posHijoIzq);
            }
        }
    }

public:
    MinHeap(int unaCapacidad, int (*unaFuncionComparadora)(T, T))
    {

        this->arr = new T[unaCapacidad + 1]();
        this->posTope = 1;
        this->capacidad = unaCapacidad;
        this->funcionComparadora = unaFuncionComparadora;
    }

    T tope()
    {
        assert(!estaVacio());
        return this->arr[1];
    }

    void eliminarTope()
    {
        assert(!estaVacio());
        this->arr[1] = this->arr[posTope - 1];
        this->posTope--;
        hundir(1);
    }

    void insertar(T el)
    {
        assert(!estaLleno());
        this->arr[posTope++] = el;
        flotar(posTope - 1);
    }

    bool estaLleno()
    {
        return this->posTope > this->capacidad;
    }

    bool estaVacio()
    {
        return this->posTope == 1;
    }
};
#endif
