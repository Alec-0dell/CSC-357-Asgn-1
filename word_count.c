#include <stdio.h>
#include <ctype.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int space_count = 0, line_count = 0, byte_count = 0, character;


    FILE *file = stdin;

    if (argc > 2)
    {
        printf("Usage: %s [filename (optional)]\n", argv[0]);
        return 1;
    }

    if(argc == 2){
        file = fopen(argv[1], "r");
        if(!file){
            printf("Error opening file '%s'\n", argv[1]);
            return 1;
        }
    } else {
        space_count++;
    }

    while ((character = fgetc(file)) != EOF)
    {
        if (isspace(character))
        {
            space_count++;
        }
        if (character == '\n')
        {
            line_count++;
        }
        byte_count = byte_count + sizeof(char);
    }

    fclose(file);
    printf("%d %d %d\n",  line_count, space_count, byte_count);
    return 0;
}
