#include <stdio.h>

char* SolicitaTexto()
{
	char *texto = malloc(sizeof(char)* 20);
	scanf("%[^\n]%*c", texto);

	return texto;
}

//
// Exibe o menu e solicita a operação desejada
//
char ImprimirMenu()
{
	//
	// Limpa a tela
	//
	system("CLS");

	printf("Selecione uma opcao:\n");

	printf("\t\"1\" Comparar duas strings.\n");
	printf("\t\"2\" Conta quantidade de vogais.\n");
	printf("\t\"3\" Conta quantidade de consoantes.\n");
	printf("\t\"4\" Conta quantidade de letras em geral, excluindo espacos.\n");
	printf("\t\"x\" Para sair.\n");

	printf("\t");

	//
	// Correção de leitura de caracteres especiais (linha em branco)
	//
	char* operacao = SolicitaTexto();

	return operacao[0];
}

int CompararStrings(const char *a, const char *b)
{
	for (;; a++, b++) {
		int d = tolower(*a) - tolower(*b);
		if (d != 0 || !*a)
			return d;
	}
}

int ContarQuantidadeVogal(const char *str)
{
	int indice = 0;
	int quantidadeVogais = 0;

	while (str[indice] != '\0')
	{
		int c = tolower(str[indice]);

		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
			quantidadeVogais++;

		indice++;
	}

	return quantidadeVogais;
}

int ContarQuantidadeConsoante(const char *str)
{
	int indice = 0;
	int quantidadeConsoantes = 0;

	while (str[indice] != '\0')
	{
		int c = tolower(str[indice]);

		if (c == 'b' || c == 'c' || c == 'd' || c == 'f' || c == 'g' || c == 'h' || c == 'j' || c == 'k' || c == 'l'
			|| c == 'm' || c == 'n' || c == 'p' || c == 'q' || c == 'r' || c == 's' || c == 't' || c == 'v' 
			|| c == 'w' || c == 'x' || c == 'y' || c == 'z')
			quantidadeConsoantes++;

		indice++;
	}

	return quantidadeConsoantes;
}

int ContarLetrasSemEspaco(const char *str)
{
	int indice = 0;
	int quantidadeLetras = 0;

	while (str[indice] != '\0')
	{
		int c = tolower(str[indice]);

		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
			quantidadeLetras++;

		indice++;
	}

	return quantidadeLetras;
}

int ExecutaOperacao()
{
	int alunoInserido = 0;

	while (1)
	{
		char* entrada1;
		char* entrada2;
		char* saida;
		char operacao;
		int resultadocmp;

		printf("Digite uma palavra:\n");
		entrada1 = SolicitaTexto();

		operacao = ImprimirMenu();

		if (operacao == 'x' || operacao == 'X')
			break;

		switch (operacao)
		{
			case '1':

				printf("Digite uma outra palavra:\n");
				entrada2 = SolicitaTexto();

				resultadocmp = CompararStrings(entrada1, entrada2);

				printf("Resultador:\n");

				if (resultadocmp == 0)
				{
					printf("\t\"1\"e \"2\" Iguais\n");
				}
				else if (resultadocmp > 0)
				{
					printf("\t\"1\" eh maior\n");
				}
				else if (resultadocmp < 0)
				{
					printf("\t\"2\" eh maior\n");
				}

				break;

			case '2':
				printf("Resultado:\n");
				printf("\t\"1\" %d\n", ContarQuantidadeVogal(entrada1));

				break;

			case '3':
				printf("Resultado:\n");
				printf("\t\"1\" %d\n", ContarQuantidadeConsoante(entrada1));

				break;

			case '4':
				printf("Resultado:\n");
				printf("\t\"1\" %d\n", ContarLetrasSemEspaco(entrada1));

				break;
		}

		system("PAUSE");
	}
}

int main()
{
	ExecutaOperacao();

	return 0;
};