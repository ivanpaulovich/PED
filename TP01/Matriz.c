#include <stdio.h>

//
// Solicita um nome
//
void solicitaTamanhoMatriz(int *x, int *y)
{
	printf("Digite o numero de linhas.\n");
	scanf("%d", x);

	printf("Digite o numero de colunas.\n");
	scanf("%d", y);
}

int contaLetrasDoNome(char *nome1)
{
	int i = 0;

	while (nome1[i] != '\0') i++;

	return i;
}

int main()
{
	int i;
	int j;
	int linhas;
	int colunas;
	int *matriz;

	solicitaTamanhoMatriz(&linhas, &colunas);

	matriz = (int*)malloc(linhas * colunas * sizeof(int));

	for (i = 0; i < linhas; ++i)
		matriz[i] = (int *)malloc(colunas * sizeof(int));


	for (i = 0; i < linhas; ++i)
	{
		for (j = 0; j < colunas; ++j)
		{
			matriz[i*colunas + j] = (i * colunas + j) + 1;
		}
	}

	for (i = 0; i < linhas; ++i)
	{
		for (j = 0; j < colunas; ++j)
		{
			printf("%d\t", matriz[i*colunas + j]);
		}

		printf("\n");
	}


	while (1)
	{
		int x;
		int y;
		int novoValor;
		char continuar;

		solicitaTamanhoMatriz(&x, &y);

		printf("Digite o novo valor\n");
		scanf("%d", &novoValor);

		matriz[x*colunas + y] = novoValor;

		//
		// Limpa a tela
		//
		system("CLS");

		for (i = 0; i < linhas; ++i)
		{
			for (j = 0; j < colunas; ++j)
			{
				printf("%d\t", matriz[i*colunas + j]);
			}

			printf("\n");
		}

		printf("Continuar. S ou N?");

		do
		continuar = getchar();
		while (isspace(continuar));

		if (continuar != 'S' && continuar != 's')
			break;
	}

	system("PAUSE");

	return 0;
};