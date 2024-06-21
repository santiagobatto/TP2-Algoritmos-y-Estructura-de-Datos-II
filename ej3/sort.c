#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


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

    /* Permutes elements of a[izq..der] and returns pivot such that:
     - izq <= pivot <= der
     - elements in a[izq,pivot) all 'go_before' (according to function goes_before) a[pivot]
     - a[pivot] 'goes_before' all the elements in a(pivot,der]
    */
}

static void quick_sort_rec(int a[], unsigned int izq, unsigned int der) {
    unsigned int pivot = partition(a, izq, der);
    if(izq < pivot){ //si el pivot es el primer elemento, no se hace nada a la izquierda
        quick_sort_rec(a, izq, pivot - 1); //se ordena la parte izquierda
    }
    if(pivot < der){ //si el pivot es el ultimo elemento, no se hace nada a la derecha
        quick_sort_rec(a, pivot + 1, der); //se ordena la parte derecha
    }

}

void quick_sort(int a[], unsigned int length) {
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1); //se llama a la funcion recursiva que ordena el array
}

