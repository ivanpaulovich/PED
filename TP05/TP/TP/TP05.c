#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//
// Funções de entrada e saída
//
int SolicitaInteiro();
char* SolicitaTexto();
int SolicitaInteiro();
int SolicitaReal();
int ImprimeMenu();

//
// Entidade Carro
//
typedef struct
{
	char*  Placa;
	char*  Modelo;
	int  Ano;
	char*  Cor;

	const MIN_ANO = 1950;
	const MAX_ANO = 2014;
} Carro;

typedef struct
{
	const MAX = 10;
	int Quantidade;
	Carro Registros[MAX];
} ListaCarro;

void CadastrarCarro(ListaCarro lista, Carro carro);
void ListarCarros(ListaCarro lista);
void ExcluirCarro(ListaCarro lista, char* placa);
void ProcurarCarro(ListaCarro lista, char* placa);
void SalvarArquivoListaCarros(ListaCarro lista);
void CarregarArquivoListaCarros(ListaCarro lista);

//
// Inicialização e execução
//
int ExecutaOperacao();
int main();

//
// Funções de entrada e saída
//

int SolicitaInteiro()
{
	int valor;
	scanf("%d", &valor);

	return valor;
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

int StringVazia(char* texto)
{
	if (texto) 
	{
		if (texto[0] == '\0') 
		{
			return 1;
		}
	}

	return 0;
}

//
// Exibe o menu e solicita a operação desejada
//
int ImprimeMenu()
{
	//
	// Limpa a tela
	//
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
	int operacao = SolicitaInteiro();

	return operacao;
}

void CadastrarCarro(ListaCarro lista, Carro carro)
{
	int valido = 1;

	if (lista.Quantidade < lista.MAX)
	{
		valido = 0;
		printf("Lista cheia. Quantidade máxima %d registro(s).", lista.MAX);
	}

	if (carro.Ano < carro.MIN_ANO || carro.Ano > carro.MAX_ANO)
	{
		valido = 0;
		printf("Ano invalido. Deve estar entre %d e %d.", carro.MIN_ANO, carro.MAX_ANO);
	}

	if (StringVazia(carro.Cor))
	{
		valido = 0;
		printf("Cor invalida. Digite um texto.", lista.MAX);
	}

	if (StringVazia(carro.Modelo))
	{
		valido = 0;
		printf("Modelo invalido. Digite um texto.", lista.MAX);
	}

	if (StringVazia(carro.Placa))
	{
		valido = 0;
		printf("Placa invalida. Digite um texto com 7 caracteres.", lista.MAX);
	}

	if (valido) 
	{
		lista.Quantidade++;
		lista.Registros[lista.Quantidade] = carro;
	}
}

void ListarCarros(ListaCarro lista)
{
	bool valido = 1;

	if (!lista.Quantidade)
	{
		valido = 0;
		printf("Lista vazia.");
	}

	if (valido)
	{
		for (int i = 0; i < lista.Quantidade; i++)
		{
			printf("-------------------------- Carro com Placa %d -------------------------------\n", lista.Registros[i].Placa);
			printf("Modelo:\t\t%s %s\n", lista.Registros[i].Modelo);
			printf("Ano:\t\t%s\n", lista.Registros[i].Ano);
			printf("Cor:\t%f\n", lista.Registros[i].Cor);
		}
	}
}

void ProcurarCarro(ListaCarro lista, char* placa)
{
	bool valido = true;

	if (lista.Quantidade == 0)
	{
		valido = false;
		printf("Lista vazia.");
	}

	if (valido)
	{
		for (int i = 0; i < lista.Quantidade; i++)
		{
			if (strcmp(lista.Registros[i].Placa, placa))
			{
				printf("-------------------------- Carro com Placa %d -------------------------------\n", lista.Registros[i].Placa);
				printf("Modelo:\t\t%s %s\n", lista.Registros[i].Modelo);
				printf("Ano:\t\t%s\n", lista.Registros[i].Ano);
				printf("Cor:\t%f\n", lista.Registros[i].Cor);
			}
		}
	}
}

void ReiniciarCarros(ListaCarro lista)
{
	lista.Quantidade = 0;
}

void ExcluirCarro(ListaCarro lista, char* placa)
{
	bool valido = true;

	if (lista.Quantidade == 0)
	{
		valido = false;
		printf("Lista vazia.");
	}

	if (valido)
	{
		bool registroEncontrado = false;

		for (int i = 0; i < lista.Quantidade; i++)
		{
			if (strcmp(lista.Registros[i].Placa, placa))
			{
				for (int j = i; i < lista.Quantidade; j++)
					lista.Registros[i] = lista.Registros[i + 1];

				lista.Quantidade--;
			}
		}
	}
}

void SalvarArquivoListaCarros(ListaCarro *lista)
{
}

void CarregarArquivoListaCarros(ListaCarro *lista)
{
	
}

//int ExecutaOperacao()
//{
//	while (1)
//	{
//		char operacao;
//		int id;
//		char nome[20];
//		char sobrenome[20];
//		char cargo[20];
//		float salario;
//
//		operacao = ImprimeMenu();
//
//		if (operacao == 'x' || operacao == 'X')
//			break;
//
//		switch (operacao)
//		{
//			case '1':
//				printf("Digite o ID\n\t");
//				id = SolicitaInteiro();
//
//				printf("Digite o Nome\n\t");
//				strcpy(nome, SolicitaTexto());
//
//				printf("Digite o Sobrenome\n\t");
//				strcpy(sobrenome, SolicitaTexto());
//
//				printf("Digite o Cargo\n\t");
//				strcpy(cargo, SolicitaTexto());
//
//				printf("Digite o Salario\n\t");
//				salario = SolicitaReal();
//
//				Cadastrar(id, &nome, &sobrenome, &cargo, salario);
//
//				break;
//
//			case '2':
//				Imprimir();
//
//				break;
//
//			case '3':
//				printf("Digite o ID\n\t");
//				id = SolicitaInteiro();
//
//				Pesquisar(id);
//
//				break;
//
//			case '4':
//				printf("Digite o ID\n\t");
//				id = SolicitaInteiro();
//
//				Excluir(id);
//
//				break;
//		}
//
//		system("PAUSE");
//	}
//}

int main()
{
	ExecutaOperacao();

	return 0;
};
