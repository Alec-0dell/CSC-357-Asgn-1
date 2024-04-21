#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[])
{

    FILE *file = stdin;

    char cur_line[512];
    char prev_line[512] = "";

    if (argc > 2)
    {
        printf("Usage: %s [filename (optional)]\n", argv[0]);
        return 1;
    }

    if (argc == 2)
    {
        file = fopen(argv[1], "r");
        if (!file)
        {
            printf("Error opening file '%s'\n", argv[1]);
            return 1;
        }
    }

    while (fgets(cur_line, sizeof(cur_line), file) != NULL)
    {
        if (strcmp(cur_line, prev_line) != 0)
        {
            printf("%s", cur_line);
            strcpy(prev_line, cur_line);
        }
    }

    if (file != stdin)
    {
        fclose(file);
    }

    return 0;
}
