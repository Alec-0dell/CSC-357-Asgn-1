#include <stdio.h>

int main(int argc, char *argv[])
{
    int space_count = 0;
    int line_count = 0;
    int character;
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

    while ((character = fgetc(file)) != EOF)
    {
        if (isspace(character))
        {
            space_count++;
        }
        if (character == '\n'){
            line_count++;
        }
    }

    fclose(file);
    printf("%d %d", space_count, line_count);
    return 0;
}
