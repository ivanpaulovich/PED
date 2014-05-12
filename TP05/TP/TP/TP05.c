#include <stdio.h>

//
// Entidade Carro 1
//
typedef struct
{
	char*  Nome;
	char*  Modelo;
	int  Ano;
	char*  Cor;
} Carro;

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

	printf("\t\"1\" Cadastrar novo funcionario.\n");
	printf("\t\"2\" Imprimir todos os funcionarios cadastrados.\n");
	printf("\t\"3\" Pesquisar por ID do funcionario.\n");
	printf("\t\"4\" Excluir por ID do funcionario.\n");
	printf("\t\"x\" Fechar o programa.\n");

	printf("Digite a opcao:\t");

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
	char texto[20];
	scanf("%s", texto);

	return texto;
}

int SolicitaInteiro()
{
	int valor;
	scanf("%d", &valor);

	return valor;
}

int SolicitaReal()
{
	float valor;
	scanf("%f", &valor);

	return valor;
}

void Cadastrar(int id, char* nome, char* sobrenome, char* cargo, float salario)
{
	FILE *saida = fopen("funcionarios.txt", "a+");
	fprintf(saida, "%d %s %s %s %f\n", id, nome, sobrenome, cargo, salario);
	fclose(saida);
}

void Imprimir()
{
	FILE *fp = fopen("funcionarios.txt", "r");

	if (fp != NULL)
	{
		int id;
		char nome[20];
		char sobrenome[20];
		char cargo[20];
		float salario;

		while (fscanf(fp, "%d%*c %s%*c %s%*c %s%*c %f", &id, nome, sobrenome, cargo, &salario) != EOF)
		{
			printf("-------------------------- Funcionario %d -------------------------------\n", id);
			printf("Nome:\t\t%s %s\n", nome, sobrenome);
			printf("Cargo:\t\t%s\n", cargo);
			printf("Salario:\t%f\n", salario);
		}
	}

	fclose(fp);

	return 0;
}

void Pesquisar(int ID)
{
	FILE *fp = fopen("funcionarios.txt", "r");

	if (fp != NULL)
	{
		int id;
		char nome[20];
		char sobrenome[20];
		char cargo[20];
		float salario;

		while (fscanf(fp, "%d%*c %s%*c %s%*c %s%*c %f", &id, nome, sobrenome, cargo, &salario) != EOF)
		{
			if (id == ID)
			{
				printf("-------------------------- Funcionario %d -------------------------------\n", id);
				printf("Nome:\t\t%s %s\n", nome, sobrenome);
				printf("Cargo:\t\t%s\n", cargo);
				printf("Salario:\t%f\n", salario);
			}
		}
	}

	fclose(fp);

	return 0;
}

void Excluir(int ID)
{
	FILE *fp = fopen("funcionarios.txt", "r");
	FILE *fp2 = fopen("funcionarios_delete.txt", "w");

	int id;
	char nome[20];
	char sobrenome[20];
	char cargo[20];
	float salario;

	while (fscanf(fp, "%d%*c %s%*c %s%*c %s%*c %f", &id, nome, sobrenome, cargo, &salario) != EOF)
	{
		if (id != ID)
		{
			fprintf(fp2, "%d %s %s %s %f\n", id, nome, sobrenome, cargo, salario);
		}
	}

	fclose(fp);
	fclose(fp2);

	remove("funcionarios.txt");
	rename("funcionarios_delete.txt", "funcionarios.txt");
}

int ExecutaOperacao()
{
	while (1)
	{
		char operacao;
		int id;
		char nome[20];
		char sobrenome[20];
		char cargo[20];
		float salario;

		operacao = ImprimeMenu();

		if (operacao == 'x' || operacao == 'X')
			break;

		switch (operacao)
		{
			case '1':
				printf("Digite o ID\n\t");
				id = SolicitaInteiro();

				printf("Digite o Nome\n\t");
				strcpy(nome, SolicitaTexto());

				printf("Digite o Sobrenome\n\t");
				strcpy(sobrenome, SolicitaTexto());

				printf("Digite o Cargo\n\t");
				strcpy(cargo, SolicitaTexto());

				printf("Digite o Salario\n\t");
				salario = SolicitaReal();

				Cadastrar(id, &nome, &sobrenome, &cargo, salario);

				break;

			case '2':
				Imprimir();

				break;

			case '3':
				printf("Digite o ID\n\t");
				id = SolicitaInteiro();

				Pesquisar(id);

				break;

			case '4':
				printf("Digite o ID\n\t");
				id = SolicitaInteiro();

				Excluir(id);

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