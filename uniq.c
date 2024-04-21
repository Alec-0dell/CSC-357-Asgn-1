#include <stdio.h>

int main(int argc, char *argv[])
{
    
    FILE *file;
    if (argc != 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Error opening file '%s'\n", argv[1]);
        return 1;
    }

    fclose(file);
    return 0;
}