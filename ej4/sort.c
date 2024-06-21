#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"

static unsigned int min_pos_from(int a[], unsigned int i, unsigned int length) {
    unsigned int min_pos = i;
    for (unsigned int j = i + 1; j < length; ++j) {
        if (!goes_before(a[min_pos],a[j])) {
            min_pos = j;
        }
    }
    return (min_pos);
}

void selection_sort(int a[], unsigned int length) {
    for (unsigned int i = 0u; i < length; ++i) {
        unsigned int min_pos = min_pos_from(a, i, length);
        swap(a, i, min_pos);
    }
}


static void insert(int a[], unsigned int i) {
    unsigned int j = i;
    while(j > 0 && goes_before(a[j], a[j-1])){
        swap(a, j, j-1);
        j--;
    }
}

void insertion_sort(int a[], unsigned int length) {
    for (unsigned int i = 1u; i < length; ++i) {
        insert(a, i);
        assert(array_is_sorted(a, i));
    }
    assert(array_is_sorted(a, length));
}


static unsigned int partition(int a[], unsigned int izq, unsigned int der) {
    unsigned int pivot = izq; //se toma el primer elemento como pivot
    unsigned int i = izq + 1; //se toma el segundo elemento como i
    unsigned int j = der; //se toma el ultimo elemento como j

    while (i <= j){
        if(goes_before(a[i], a[pivot])) i++; //si el elemento en i es menor o igual al pivot, se avanza i porque esta en el lugar correcto
        else if( goes_before(a[pivot], a[j])) j--; //si el elemento en j es mayor o igual al pivot, se retrocede j porque esta en el lugar correcto
        else swap(a, i, j); //si ambos elementos estan en el lugar incorrecto, se intercambian
    } 

    swap(a, pivot, j); //j es el ultimo elemento menor o igual al pivot
    pivot = j; //se actualiza el pivot
    return pivot;
}

static void quick_sort_rec(int a[], unsigned int izq, unsigned int der) {
    unsigned int pivot = partition(a, izq, der);
    if(izq < pivot){
        quick_sort_rec(a, izq, pivot - 1);
    }
    if(pivot < der){
        quick_sort_rec(a, pivot + 1, der);
    }
}

void quick_sort(int a[], unsigned int length) {
    quick_sort_rec(a, 0u, (length == 0u) ? 0u : length - 1u);
}

/*  CONCLUCIONES

Eficiencia: Quick Sort es el más eficiente generalmente, tanto en tiempo como en número de operaciones.

Recursos: Insertion Sort parece ser el menos eficiente en términos de intercambios.

Quick Sort es preferible por la eficiencia, Selection Sort e Insertion Sort pueden tener sus ventajas en contextos específicos
por ej cuando se trabaja con datos parcialmente ordenados (en Insertion Sort).

*/