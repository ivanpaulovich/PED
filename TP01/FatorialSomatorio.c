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

	printf("\t\"1\" Para calcular fatorial.\n");
	printf("\t\"2\" Para calcular somatorio.\n");
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
int solicitaNumero()
{
	int numero;

	do
	{
		printf("Digite o numero:\n");
		scanf("%d", &numero);
	} while (numero < 0);

	return numero;
}

int calculaFatorial(int numero)
{
	int valor = 1;
	int contador = 1;

	while (++contador <= numero)
		valor *= contador;

	return valor;
}

int calculaSomatorio(int numero)
{
	int valor = 1;
	int contador = 1;

	for (int i = 0; i < numero; i++)
		valor += valor;

	return valor;
}

int main()
{
	while (1)
	{
		char operacao = solicitaOperacao();

		if (operacao == 'x' || operacao == 'X')
			break;

		int numero = solicitaNumero();

		switch (operacao)
		{
		case '1': printf("O fatorial vale: %d\n", calculaFatorial(numero));
			break;
		case '2': printf("O somatorio vale: %d\n", calculaSomatorio(numero));
			break;
		}

		system("PAUSE");
	}

	return 0;
};