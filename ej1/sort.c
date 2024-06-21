#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


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

/*
La funcion goes_before implemente la relacion de orden entre dos elementos de un arreglo.

Usa como criterio de orden el valor de los elementos, de menor a mayor.
*/
