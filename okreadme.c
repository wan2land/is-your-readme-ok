
#include <stdio.h>
#include <string.h>
#include "okreadme_lib.h"

typedef char* string;

int main(int argc, string argv[])
{
    bool isDebug = false;
    string filename = "README.ok.md";
    if (argc >= 2) {
        if (strcmp(argv[1], "-v") == 0) {
            printf("OK Readme 0.1.0\nIs Your Readme OK? :-)\n");
            return 0;
        }
        int i;
        for (i = 1; i < argc; i++) {
            if (strcmp(argv[i], "--debug") == 0) {
                isDebug = true;
            } else {
                filename = argv[i];
            }
        }
    }

    FILE* fp = fopen(filename, "r");
    if (!fp) {
        printf("File %s does not exist!\n", filename);
        return 1;
    }

    printf("%s\n", okreadme_parse_file(fp, isDebug));

    fclose(fp);
    return 0;
}