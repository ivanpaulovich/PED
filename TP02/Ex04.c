#include <stdio.h>


//
// Exibe o menu e solicita a operação desejada
//
char ImprimeMenu()
{
	//
	// Limpa a tela
	//
	system("CLS");

	printf("Selecione uma opcao:\n");

	printf("\t\"1\" Para copiar a primeira string para a segunda.\n");
	printf("\t\"2\" Para concatenar na primeira string o valor da primeira + o valor da segunda.\n");
	printf("\t\"3\" Para saber o tamanho da primeira string.\n");
	printf("\t\"4\" Para comparar as duas strings inseridas.\n");
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

char* SolicitaTexto()
{
	char *texto = malloc(sizeof(char)* 20);
	scanf("%s", texto);

	return texto;
}

char *PED_strcpy(char *dest, const char *src)
{
	int indice = 0;
	
	while (src[indice] != '\0')
	{
		dest[indice] = src[indice];
		indice++;
	}

	dest[indice] = '\0';

	return dest;
}

int PED_strcmp(const char *str1, const char *str2)
{
	int indice = 0;

	while ((str1[indice] != '\0') && (str2[indice] != '\0'))
		if (str1[indice] != str2[indice])
			break;
		else
			indice;

	return str1[indice] - str2[indice];
}

int PED_strlen(const char *str)
{
	int indice = 0;

	while (str[indice] != '\0')
		indice++;

	return indice;
}

char *PED_strcat(char *dest, const char *src)
{
	int indiceDestino = 0;
	int indice = 0;

	indiceDestino = PED_strlen(dest);

	while (src[indice] != '\0')
	{
		dest[indiceDestino] = src[indice];
		indice++;
		indiceDestino++;
	}

	dest[indiceDestino] = '\0';

	return dest;
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

		printf("Digite uma palavra:\n");
		entrada2 = SolicitaTexto();

		operacao = ImprimeMenu();

		if (operacao == 'x' || operacao == 'X')
			break;

		switch (operacao)
		{
			case '1':
				PED_strcpy(entrada2, entrada1);
				
				printf("Resultador:\n");
				printf("\t\"1\" %s\n", entrada1);
				printf("\t\"2\" %s\n", entrada2);

				break;

			case '2':
				PED_strcat(entrada1, entrada2);

				printf("Resultador:\n");
				printf("\t\"1\" %s\n", entrada1);
				printf("\t\"2\" %s\n", entrada2);

				break;

			case '3':
				printf("Resultador:\n");
				printf("\t\"1\" %d\n", PED_strlen(entrada1));

				break;

			case '4':
				resultadocmp = PED_strcmp(entrada1, entrada2);

				printf("Resultador:\n");

				if (resultadocmp == 0)
				{
					printf("\t\"1\"e \"2\" Iguais\n");
				}
				else if (resultadocmp > 0)
				{
					printf("\t\"1\" é maior\n");
				}
				else if (resultadocmp < 0)
				{
					printf("\t\"2\" é maior\n");
				}

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