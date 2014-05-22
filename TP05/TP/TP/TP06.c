#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
	struct Elemento *Anterior;
    struct Elemento *Proximo;
	Carro Carro;
} Elemento;

typedef struct
{
    Elemento *Primeiro;
    Elemento *Ultimo; 
} Lista;

void CriarLista(Lista *lista);

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
    lista->Primeiro->Anterior = NULL;
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
   
    if (elemento->Carro.Ano < MIN_ANO || elemento.Carro.Ano > MAX_ANO)
    {
    	valido = 0;
    	printf("Ano invalido. Deve estar entre %d e %d.", MIN_ANO, MAX_ANO);
    }
    
    if (StringVazia(elemento.Carro.Cor))
    {
    	valido = 0;
    	printf("Cor invalida. Digite um texto.", MAX_CARROS);
    }
    
    if (StringVazia(elemento.Carro.Modelo))
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


int main()
{
	return 0;
};
