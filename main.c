#include <stdio.h>
#include <string.h>

int main()

{

    char file[50];
    printf("Digite o nome do arquivo sem extensao.");
    scanf("%s", file);

    FILE * img;

    img = fopen ("file.ppm", "r");

    return 0;

}

