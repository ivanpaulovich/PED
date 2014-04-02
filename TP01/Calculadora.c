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

	printf("\"+\" Para somar.\n");
	printf("\"-\" Para subtrair.\n");
	printf("\"*\" Para multiplicar.\n");
	printf("\"/\" Para dividir.\n");
	printf("\"%\" Para resto da divisao.\n");
	printf("\"x\" Para sair.\n");

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
float solicitaParcela()
{
	printf("Digite o valor da parcela.\n");
	float parcela;
	scanf("%f", &parcela);

	return parcela;
}

void exibeResultado(float resultado)
{
	printf("Resultado:\n%f.\n\n", resultado);

	system("PAUSE");
}

int main()
{
	while (1)
	{
		char operacao = solicitaOperacao();

		if (operacao == 'x' || operacao == 'X')
			break;

		float parcela1 = solicitaParcela();
		float parcela2 = solicitaParcela();

		switch (operacao)
		{
		case '+': exibeResultado(parcela1 + parcela2);
			break;
		case '-': exibeResultado(parcela1 - parcela2);
			break;
		case '*': exibeResultado(parcela1 * parcela2);
			break; 
		case '/': exibeResultado(parcela1 / parcela2);
			break;
		case '%': exibeResultado((int)parcela1 % (int)parcela2);
			break;
		}
	}

	return 0;
};