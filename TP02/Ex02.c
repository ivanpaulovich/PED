#include <stdio.h>

//
// Exibe o menu e solicita a operação desejada
//
char ImprimeOpcoes()
{
	//
	// Limpa a tela
	//
	system("CLS");

	printf("\"+\" Para somar.\n");
	printf("\"-\" Para subtrair.\n");
	printf("\"*\" Para multiplicar.\n");
	printf("\"/\" Para dividir.\n");
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

float RealizaSoma(float parcela1, float parcela2)
{
	return parcela1 + parcela2;
}

float RealizaSubtracao(float parcela1, float parcela2)
{
	return parcela1 - parcela2;
}

float RealizaMultiplicacao(float parcela1, float parcela2)
{
	return parcela1 * parcela2;
}

float RealizaDivisao(float parcela1, float parcela2)
{
	return parcela1 / parcela2;
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
		char operacao = ImprimeOpcoes();

		if (operacao == 'x' || operacao == 'X')
			break;

		float parcela1 = solicitaParcela();
		float parcela2 = solicitaParcela();

		switch (operacao)
		{
		case '+': exibeResultado(RealizaSoma(parcela1, parcela2));
			break;
		case '-': exibeResultado(RealizaSubtracao(parcela1, parcela2));
			break;
		case '*': exibeResultado(RealizaMultiplicacao(parcela1, parcela2));
			break;
		case '/': exibeResultado(RealizaDivisao(parcela1, parcela2));
			break;
		}
	}

	return 0;
};