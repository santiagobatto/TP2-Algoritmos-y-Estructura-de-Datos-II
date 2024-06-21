#include <stdbool.h>
#include <assert.h>

#include "fixstring.h"


unsigned int fstring_length(fixstring s) {
    unsigned int l = 0;
    while (l < FIXSTRING_MAX && s[l] != '\0'){
        l++;
    }
    return l;   
}

bool fstring_eq(fixstring s1, fixstring s2) {
    unsigned int l1 = fstring_length(s1);
    unsigned int l2 = fstring_length(s2);
    
    if (l1 != l2 || l1 > FIXSTRING_MAX){
        return false;
    }

    for (unsigned int i = 0u; i < l1; i++){
        if (s1[i] != s2[i]){
            return false;
        }
    }
    return true;
}

bool fstring_less_eq(fixstring s1, fixstring s2) {
    unsigned int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]){
        i++;
    }
    return s1[i] <= s2[i];
}

void fstring_set(fixstring s1, const fixstring s2) {
    int i=0;
    while (i<FIXSTRING_MAX && s2[i]!='\0') {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
}

void fstring_swap(fixstring s1,  fixstring s2) {
    fixstring aux;
    fstring_set(aux, s1);
    fstring_set(s1, s2);
    fstring_set(s2, aux);
}