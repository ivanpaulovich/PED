#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//
// Funções de entrada e saída
//
int SolicitaInteiro();
char* SolicitaTexto();
int SolicitaReal();
int ImprimeMenu();

const int MIN_ANO = 1950;
const int MAX_ANO = 2014;
const int MAX_CARROS = 10;

//
// Entidade Carro
//
typedef struct
{
	char  Placa[100];
	char  Modelo[100];
	int  Ano;
	char  Cor[100];
} Carro;

typedef struct
{
	int Quantidade;
	Carro Registros[10];
} ListaCarro;

void CadastrarCarro(ListaCarro lista, Carro carro);
void ListarCarros(ListaCarro* lista);
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
	char texto[100];
	scanf("%s", texto);

	return texto;
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

	printf("\t\"1\" Cadastrar novo carro.\n");
	printf("\t\"2\" Imprimir todos os funcionarios cadastrados.\n");
	printf("\t\"3\" Pesquisar por ID do funcionario.\n");
	printf("\t\"4\" Excluir por ID do funcionario.\n");
	printf("\t\"9\" Fechar o programa.\n");

	printf("Digite a opcao:\t");

	//
	// Correção de leitura de caracteres especiais (linha em branco)
	//
	int operacao = SolicitaInteiro();

	return operacao;
}

void CadastrarCarro(ListaCarro *lista, Carro carro)
{
	int valido = 1;

	if (lista->Quantidade >= MAX_CARROS)
	{
		valido = 0;
		printf("Lista cheia. Quantidade máxima %d registro(s).", MAX_CARROS);
	}

	if (carro.Ano < MIN_ANO || carro.Ano > MAX_ANO)
	{
		valido = 0;
		printf("Ano invalido. Deve estar entre %d e %d.", MIN_ANO, MAX_ANO);
	}

	if (StringVazia(carro.Cor))
	{
		valido = 0;
		printf("Cor invalida. Digite um texto.", MAX_CARROS);
	}

	if (StringVazia(carro.Modelo))
	{
		valido = 0;
		printf("Modelo invalido. Digite um texto.", MAX_CARROS);
	}

	if (StringVazia(carro.Placa))
	{
		valido = 0;
		printf("Placa invalida. Digite um texto com 7 caracteres.", MAX_CARROS);
	}

	if (valido) 
	{
		lista->Registros[lista->Quantidade] = carro;
		lista->Quantidade++;
	}
}

void ListarCarros(ListaCarro lista)
{
	int valido = 1;

	if (!lista.Quantidade)
	{
		valido = 0;
		printf("Lista vazia.");
	}

	if (valido)
	{
		for (int i = 0; i < lista.Quantidade; i++)
		{
			printf("-------------------------- Carro com Placa %s -------------------------------\n", lista.Registros[i].Placa);
			printf("Modelo:\t%s\n", lista.Registros[i].Modelo);
			printf("Ano:\t%d\n", lista.Registros[i].Ano);
			printf("Cor:\t%s\n", lista.Registros[i].Cor);
		}
	}
}

void ProcurarCarro(ListaCarro lista, char* placa)
{
	int valido = 1;

	if (lista.Quantidade == 0)
	{
		valido = 0;
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

void ReiniciarCarros(ListaCarro* lista)
{
	lista->Quantidade = 0;

	for (int i = 0; i < MAX_CARROS; i++)
	{
		memset(&lista->Registros[i], 0, sizeof(Carro));
	}
}

void ExcluirCarro(ListaCarro lista, char* placa)
{
	int valido = 1;

	if (lista.Quantidade == 0)
	{
		valido = 0;
		printf("Lista vazia.");
	}

	if (valido)
	{
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

void SalvarArquivoListaCarros(ListaCarro lista)
{
}

void CarregarArquivoListaCarros(ListaCarro *lista)
{
	
}

int ExecutaOperacao()
{
	ListaCarro listaCarro;
	Carro carro;
	char placa[100];

	ReiniciarCarros(&listaCarro);

	while (1)
	{
		int operacao = ImprimeMenu();

		if (operacao == 9)
			break;

		switch (operacao)
		{
			case 1:
				printf("Digite a Placa\n\t");
				strcpy(carro.Placa, SolicitaTexto());

				printf("Digite o Modelo\n\t");
				strcpy(carro.Modelo,SolicitaTexto());

				printf("Digite o Ano\n\t");
				carro.Ano = SolicitaInteiro();

				printf("Digite a Cor\n\t");
				strcpy(carro.Cor, SolicitaTexto());

				CadastrarCarro(&listaCarro, carro);

				break;

			case 2:
				ListarCarros(listaCarro);

				break;

			case 3:
				ReiniciarCarros(&listaCarro);

				break;

			case 4:
				printf("Digite a Placa\n\t");
				strcpy(carro.Placa, SolicitaTexto());

				ProcurarCarro(listaCarro, placa);

				break;

			case 5:
				printf("Digite a Placa\n\t");
				strcpy(carro.Placa, SolicitaTexto());

				ExcluirCarro(listaCarro, placa);

				break;

			case 6:
				SalvarArquivoListaCarros(listaCarro, placa);

				break;

			case 7:
				CarregarArquivoListaCarros(&listaCarro, placa);

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
