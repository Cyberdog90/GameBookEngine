//
// Created by CYBAiGNU on 2020/02/17.
//

#include "input.h"
#include <stdio.h>
#include "write_console.h"

char *input() {
    write_console(">>>");
    char string[256];
    scanf("%s", &string);
    return string;
}
