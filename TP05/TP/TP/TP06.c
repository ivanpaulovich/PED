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

typedef struct
{
	char  Placa[100];
	char  Modelo[100];
	int  Ano;
	char  Cor[100];
} Carro;

//
// Entidade Elemento
//
typedef struct Elemento
{
	Carro Carro;
    Elemento *proximo;
} Elemento;

//
// Um conjunto é constituido por uma lista de elementos
//
typedef struct
{
    Elemento *Primeiro;
    Elemento *Ultimo; 
} Lista;

void CriarLista(Lista *lista);
int ListaVazia(Lista lista);
void InsereElemento(Lista *lista, Elemento elemento);
//void ListarCarros(Conjunto lista);
//void ExcluirCarro(Conjunto* lista, char* placa);
//void ProcurarCarro(Conjunto lista, char* placa);
//void SalvarArquivoListaCarros(Conjunto lista);
//void CarregarArquivoListaCarros(Conjunto *lista);

//
// Inicialização e execução
//
void ExecutaOperacao();
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

	while (getchar() != '\n');

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

void CriarLista(Lista *lista)
{     
    //
    // Cria o primeiro elemento
    //
    lista->Primeiro = (Elemento*)malloc(sizeof(Elemento));
    
    //
    // Como o conjunto está vazio o primeiro elemento 
    // e o último devem apontar para o mesmo lugar
    //
    lista->Ultimo = lista->Primeiro;
    
    //
    // O próximo elemento aponta pra lugar nenhum
    //
    lista->Primeiro->Proximo = NULL;    
}

int ListaVazia(Lista lista)
{
    //
    // Um conjunto está vazio se o primeiro 
    // e o último elemento apontam pro mesmo lugar
    //
    return lista.Primeiro == lista.Ultimo;   
}

void InsereElemento(Lista *lista, Elemento elemento)
{
    int valido = 1;
   
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
        //
        // Cria o elemento
        //
        lista->Ultimo->Proximo = (Elemento*)malloc(sizeof(Elemento));
        
        //
        // O último elemento aponta para o primeiro elemento
        //
        lista->Ultimo = lista->Ultimo->Proximo;
        
        //
        // O valor do último elemento é definido com valor à ser adicionado
        //
        lista->Ultimo->Ano = elemento.Ano;
        
        //
        // O próximo elemento do conjunto aponta pra lugar nenhum
        //
        lista->Ultimo->Proximo = NULL;      
    } 
}

////
//// Exibe o menu e solicita a operação desejada
////
//int ImprimeMenu()
//{
//	//
//	// Limpa a tela
//	//
//	printf("Selecione uma opcao:\n");
//
//	printf("\t\"1\" Cadastrar novo carro.\n");
//	printf("\t\"2\" Imprimir todos os carros cadastrados.\n");
//	printf("\t\"3\" Reiniciar lista de carros.\n");
//	printf("\t\"4\" Procurar por placa do carro.\n");
//	printf("\t\"5\" Excluir por placa do carro.\n");
//	printf("\t\"6\" Salvar carros para o arquivo.\n");
//	printf("\t\"7\" Carregar carros do arquivo.\n");
//
//	printf("\t\"9\" Fechar o programa.\n");
//
//	printf("Digite a opcao:\t");
//
//	//
//	// Correção de leitura de caracteres especiais (linha em branco)
//	//
//	int operacao = SolicitaInteiro();
//
//	return operacao;
//}
//
//void ListarCarros(ListaCarro lista)
//{
//	int valido = 1;
//
//	if (!lista.Quantidade)
//	{
//		valido = 0;
//		printf("Lista vazia.");
//	}
//
//	if (valido)
//	{
//		for (int i = 0; i < lista.Quantidade; i++)
//		{
//			printf("----------- Carro com Placa %s -----------\n", lista.Registros[i].Placa);
//			printf("Modelo:\t%s\n", lista.Registros[i].Modelo);
//			printf("Ano:\t%d\n", lista.Registros[i].Ano);
//			printf("Cor:\t%s\n", lista.Registros[i].Cor);
//		}
//	}
//}
//
//void ProcurarCarro(NoCarro lista, char* placa)
//{
//	int valido = 1;
//
//	if (lista.Quantidade == 0)
//	{
//		valido = 0;
//		printf("Lista vazia.");
//	}
//
//	if (valido)
//	{
//		for (int i = 0; i < lista.Quantidade; i++)
//		{
//			if (strcmp(lista.Registros[i].Placa, placa) == 0)
//			{
//				printf("----------- Carro com Placa %s -----------\n", lista.Registros[i].Placa);
//				printf("Modelo:\t%s\n", lista.Registros[i].Modelo);
//				printf("Ano:\t%d\n", lista.Registros[i].Ano);
//				printf("Cor:\t%s\n", lista.Registros[i].Cor);
//			}
//		}
//	}
//}
//
//void ReiniciarCarros(NoCarro* lista)
//{
//	lista->Quantidade = 0;
//
//	for (int i = 0; i < MAX_CARROS; i++)
//	{
//		memset(&lista->Registros[i], 0, sizeof(Carro));
//	}
//}
//
//void ExcluirCarro(NoCarro* lista, char* placa)
//{
//	int valido = 1;
//
//	if (lista->Quantidade == 0)
//	{
//		valido = 0;
//		printf("Lista vazia.");
//	}
//
//	if (valido)
//	{
//		for (int i = 0; i < lista->Quantidade; i++)
//		{
//			if (strcmp(lista->Registros[i].Placa, placa) == 0)
//			{
//				for (int j = i; j < lista->Quantidade; j++)
//					lista->Registros[j] = lista->Registros[j + 1];
//
//				lista->Quantidade--;
//			}
//		}
//	}
//}
//
//void SalvarArquivoNoCarros(NoCarro lista)
//{
//	FILE *saida = fopen("carros.txt", "a+");
//
//	if (saida != NULL)
//	{
//		for (int i = 0; i < lista.Quantidade; i++)
//		{
//			fprintf(saida, "%s %s %s %d\n", lista.Registros[i].Placa, lista.Registros[i].Modelo, lista.Registros[i].Cor, lista.Registros[i].Ano);
//		}
//
//	}
//	fclose(saida);
//}
//
//void CarregarArquivoNoCarros(NoCarro *lista)
//{
//	FILE *fp = fopen("carros.txt", "r");
//
//	if (fp != NULL)
//	{
//		char placa[100];
//		char modelo[20];
//		char cor[20];
//		int ano;
//
//		while (fscanf(fp, "%s%*c %s%*c %s%*c %d", placa, modelo, cor, &ano) != EOF)
//		{
//			Carro carro;
//
//			strcpy(carro.Placa, placa);
//			strcpy(carro.Modelo, modelo);
//			carro.Ano = ano;
//			strcpy(carro.Cor, cor);
//
//			CadastrarCarro(lista, carro);
//		}
//	}
//
//	fclose(fp);
//}
//
//void ExecutaOperacao()
//{
//	NoCarro noCarro;
//	Carro carro;
//	char placa[100];
//
//	ReiniciarCarros(&noCarro);
//
//	while (1)
//	{
//		int operacao = ImprimeMenu();
//
//		if (operacao == 9)
//			break;
//
//		switch (operacao)
//		{
//		case 1:
//			printf("Digite a Placa\n\t");
//			strcpy(carro.Placa, SolicitaTexto());
//
//			printf("Digite o Modelo\n\t");
//			strcpy(carro.Modelo, SolicitaTexto());
//
//			printf("Digite o Ano\n\t");
//			carro.Ano = SolicitaInteiro();
//
//			printf("Digite a Cor\n\t");
//			strcpy(carro.Cor, SolicitaTexto());
//
//			CadastrarCarro(&noCarro, carro);
//
//			break;
//
//		case 2:
//
//			if (noCarro.Quantidade == 0)
//			{
//				printf("Lista vazia. Deseja carregar e listar os itens em backup? 1 para sim. 2 para nao.");
//
//				int continuar = SolicitaInteiro();
//
//				if (continuar == 1)
//				{
//					CarregarArquivoNoCarros(&noCarro);
//				}
//
//			}
//
//			ListarCarros(noCarro);
//			break;
//
//		case 3:
//			ReiniciarCarros(&noCarro);
//			break;
//
//		case 4:
//			printf("Digite a Placa\n\t");
//			strcpy(placa, SolicitaTexto());
//
//			ProcurarCarro(noCarro, placa);
//			break;
//
//		case 5:
//			printf("Digite a Placa\n\t");
//			strcpy(placa, SolicitaTexto());
//
//			ExcluirCarro(&noCarro, placa);
//			break;
//
//		case 6:
//			SalvarArquivoNoCarros(noCarro);
//			break;
//
//		case 7:
//			CarregarArquivoNoCarros(&noCarro);
//			break;
//
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
