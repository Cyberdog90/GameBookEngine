//
// Created by CYBAiGNU on 2020/02/16.
//

#define max_line 364
static char *next_read = "File0.gbf";


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "write_console.h"
#include "an.h"
#include "read_file.h"

int read_file() {
    FILE *fp;
    char line[max_line];

    while (true) {
        if ((fp = fopen(next_read, "r")) == NULL) {
            fprintf(stderr, "%s open failed\n", next_read);
            exit(EXIT_FAILURE);
        }
        while (fgets(line, max_line, fp) != NULL) {
            switch (line[0]) {
                case '@': { /*command*/
                    an(&line[1]);
                    break;
                }
                case '#': { /*comment out*/
                    break;
                }
                case '!': { /*return code*/
                    return atoi(&line[1]);
                }
                case '\\': { /*escape char*/
                    strcpy(line, &line[1]);
                    write_console(line);
                    break;
                }
                default: {
                    write_console(line);
                    break;
                }
            }
        }
    }
}

void set_file(char string[]) {
    strcpy(next_read, string);
}