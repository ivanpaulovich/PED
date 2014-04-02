#include <stdio.h>
#include <string.h>

//
// Exibe o menu e solicita a operação desejada
//
char solicitaOperacao()
{
	//
	// Limpa a tela
	//
	system("CLS");

	printf("Selecione uma opcao:\n");

	printf("\t\"1\" Incluir nome.\n");
	printf("\t\"2\" Procurar nomes.\n");
	printf("\t\"x\" Para sair.\n");

	printf("\t");

	//
	// Correção de leitura de caracteres especiais (linha em branco)
	//
	char operacao;
	do
		operacao = getchar();
	while (isspace(operacao));

	return operacao;
}

//
// Solicita uma parcela
//
char* solicitaNome()
{
	printf("Digite o nome:\n");
	char *nome = malloc(sizeof(char) * 20);
	scanf("%s", nome);

	return nome;
}

int procuraLetra(char *nome1, char nome2)
{
	for (int i = 0; i < 20; i++)
	{
		if (nome1[i] == nome2)
			return 1;
	}

	return 0;
}

char* incluirNome(char *nome1)
{
	printf("Digite o nome:\n");
	char *nome = malloc(sizeof(char)* 20);
	scanf("%s", nome);

	return nome;
}

char* listarNomes(char *nome1)
{
	printf("Digite o nome:\n");
	char *nome = malloc(sizeof(char)* 20);
	scanf("%s", nome);

	return nome;
}

int main()
{
	char* nomes[10];
	int quantidade = 0;
	while (1)
	{
		char operacao = solicitaOperacao();

		if (operacao == 'x' || operacao == 'X')
			break;

		char* nome1 = solicitaNome();

		switch (operacao)
		{
		case '1': nomes[quantidade++] = nome1;
			break;
		case '2': 

			system("CLS");

			for (int i = 0; i < quantidade; i++)
			{
				if (procuraLetra(nomes[i], nome1[0]))
				{
					printf(nomes[i]);
					printf("\n");
				}
			}

			break;
		}

		system("PAUSE");
	}

	return 0;
};