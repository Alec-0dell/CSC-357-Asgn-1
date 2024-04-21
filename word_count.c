#include <stdio.h>
#include <ctype.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int word_count = 0, line_count = 0, byte_count = 0, character, prev_character = 'a';

    FILE *file = stdin;

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

    while ((character = fgetc(file)) != EOF)
    {
        if (isspace(character))
        {
            if (!isspace(prev_character))
            {
                word_count++;
            }
        }
        if (character == '\n')
        {
            line_count++;
        }
        byte_count = byte_count + sizeof(char);
        prev_character = character;
    }

    if (file != stdin)
    {
        fclose(file);
    }

    printf("%d %d %d\n", line_count, word_count, byte_count);

    return 0;
}
