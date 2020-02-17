//
// Created by CYBAiGNU on 2020/02/17.
//
#include <string.h>
#include "variables.h"

static char *next_choices[64][16];

void set_choices(int i, char string[]) {
    strcpy((char *) next_choices[i], string);
}

char *get_choices(int i) {
    return (char *) next_choices[i];
}