#include <stdbool.h>
#include <assert.h>

#include "fixstring.h"

unsigned int fstring_length(fixstring s) {
    unsigned int length = 0;
    for (unsigned int i = 0; i < FIXSTRING_MAX; i++){
        if (s[i] == '\0') break;
        length++;
    }
    return length;
}

bool fstring_eq(fixstring s1, fixstring s2){
    for(unsigned int i = 0; i < FIXSTRING_MAX; i++){
        if (s1[i] == s2[i]) i++;
        else return false; 
    }
    return true;
}

bool fstring_less_eq(fixstring s1, fixstring s2){
    unsigned int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]){
        i++;
    }

    return s1[i] <= s2[i];
}

