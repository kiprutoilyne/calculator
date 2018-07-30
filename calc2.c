#include <stdio.h>
#include <stdlib.h>

#include "functions.c"

int main (int argc, char **argv) {

    if (argc != 4) {
        fprintf (stderr, "error: invalid number of parameters\n"
                         "usage: num [ +,-,*, / ] num (e.g. 1 * 1 )\n");
        return 1;
    }
    int res, fstnum = atoi (argv[1]), scnnum = atoi (argv[3]);
    char op = *argv[2];

    switch (op) {
        case '+': res = fstnum + scnnum;
         break;
        case '*': res = fstnum * scnnum; 
        break;
        case '-': res = fstnum - scnnum; 
        break;
        case '%': res = fstnum % scnnum; 
        break;
        case '/':
            if (!scnnum) {
                fprintf (stderr, "error: divide by zero\n");
                return 1;
            } else res = fstnum / scnnum; break;
        default:
            fprintf (stderr, "error: invalid operator\n");
            return 1;
    }

    printf (" %d %c %d = %d\n", fstnum, op, scnnum, res);

    return 0;
}
