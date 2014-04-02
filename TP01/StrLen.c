#include <stdio.h>

//
// Solicita um nome
//
char* solicitaNome()
{
	//
	// Limpa a tela
	//
	system("CLS");

	printf("Digite o nome:\n");
	char *nome = malloc(sizeof(char) * 100);
	scanf("%[^\n]s", nome);

	return nome;
}

int contaLetrasDoNome(char *nome1)
{
	int i = 0;

	while (nome1[i] != '\0') i++;

	return i;
}

int main()
{
	char* nome1 = solicitaNome();

	printf("Possui %d letra(s).\n", contaLetrasDoNome(nome1));

	system("PAUSE");

	return 0;
};