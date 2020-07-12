#include "shell.h"

void prompt(void)
{
    char buff[] = "pratz$ ";
    fprintf(stdout, "%s", buff);
    fflush(stdout);
}

