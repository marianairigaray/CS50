#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height, aux = 1;

    do
    {
        height = get_int("Height ");
    }
    while (height < 1 || height > 8);

    for (int i = 0; i < height; i++)
    {
        for (int k = 0; k < (height - aux); k++)
            printf(" ");
        for (int l = 0; l < aux; l++)
            printf("#");
        printf("  ");
        for (int l = 0; l < aux; l++)
            printf("#");
        aux++;
        printf("\n");
    }
}
