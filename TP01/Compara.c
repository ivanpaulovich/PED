#include <stdio.h>

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

	printf("\t\"1\" Para comparar nomes.\n");
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

int comparaNomes(char *nome1, char *nome2)
{
	for (int i = 0; i < 20; i++)
	{
		if (nome1[i] != nome2[i])
			return 0;
	}

	return 1;
}

int main()
{
	while (1)
	{
		char operacao = solicitaOperacao();

		if (operacao == 'x' || operacao == 'X')
			break;

		char* nome1 = solicitaNome();
		char* nome2 = solicitaNome();

		if (comparaNomes(nome1, nome2))
			printf("Nomes iguais.\n");
		else
			printf("Nomes diferentes.\n");

		system("PAUSE");
	}

	return 0;
};