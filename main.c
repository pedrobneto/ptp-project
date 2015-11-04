#include <stdio.h>
#include <string.h>

// cabeçalho do arquivo ppm
#define cab "P3"

// definir as cores
typedef struct {
	int r, g, b;
} Cores;
// largura, altura, cor máxima do arquivo ppm
int lar, alt, c_max;

int main() {
    // iteradores
	int i, j;
    // nome do arquivo sem extensão e nome do arquivo com extensão
    char arq[50], arq_ext[50];
    // lê o nome do arquivo
    printf("Digite o nome do arquivo sem extensao: ");
    scanf("%s", arq);
	// copia o nome do arquivo sem extensão
	strcpy(arq_ext, arq);
	// concatena o nome do arquivo sem extensão com a extensão .ppm
	strcat(arq_ext, ".ppm");
    // começa a abertura do arquivo
    FILE * arq_img;
	
	// abre o arquivo apenas para leitura
    arq_img = fopen(arq_ext, "r");
	// verifica se ocorreu algum erro na abertura do arquivo
	if (arq_img == NULL)
		printf("Erro ao abrir imagem.\n");
	else
		printf("Imagem aberta com sucesso\n");
    // lê a largura, a altura e a cor máxima do arquivo .ppm
	fscanf(arq_img, "P3 %i %i %i", &lar, &alt, &c_max);
	// verifica se ocorreu algum erro ao ler os dados do arquivo
	if(lar == 0 || alt == 0 || c_max == 0)
		printf("Erro ao ler dados do arquivo.\n");
    // cria a matriz de cores do arquivo
	Cores img[lar][alt];
	// lê as cores do arquivo
	for (i = 0; i < lar; i++)
		for(j = 0; j < alt; j++)
			fscanf(arq_img, "%i %i %i", &img[i][j].r, &img[i][j].g, &img[i][j].b);
    // fecha o arquivo
	fclose(arq_img);

    return 0;
}
