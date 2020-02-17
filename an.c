//
// Created by CYBAiGNU on 2020/02/17.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iso646.h>
#include "write_console.h"
#include "variables.h"
#include "input.h"
#include "read_file.h"
#include "an.h"


static int latest_num = -1;

void an(char string[]) {
    char *str;
    str = strtok(string, " \n\0");
    if (strcmp(str, "IF") == 0) {
        char *column = strtok(NULL, " \0");
        if (atoi(column) == -1) {
            for (int i = 1; i < latest_num + 1; i++) {
                char tmp[200];
                snprintf(tmp, 200, "%s%s%d\n", strtok(NULL, " \n\0"), " : ", i);
                write_console(tmp);
            }
        } else {
            for (int i = 0; i < atoi(column); i++) {
                set_choices(i, strtok(NULL, " \n\0"));
            }
            latest_num = atoi(column);
        }
    } else if (strcmp(str, "INPUT") == 0) {
        //char tmp[256];
        //strcpy(tmp, input());
        printf(">>>");
        int tmp;
        scanf("%d", &tmp);
        /*if (0 < atoi(tmp) and atoi(tmp) < latest_num) {
            set_file(get_choices(atoi(tmp) - 1));
        }*/if (0 < tmp and tmp < latest_num+1) {
            set_file(get_choices(tmp-1));
        } else {
            fprintf(stderr, "invalid\n");
            exit(EXIT_FAILURE);
        }
    }
}
