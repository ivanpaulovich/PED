#include <stdio.h>

typedef struct
{
	char*  Nome;
	char*  Sobrenome;
	char*  Matricula;
	int  AnoNascimento;
	int  MesNascimento;
	int  DiaNascimento;
} Aluno;

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

	printf("\t\"1\" Inserir aluno a ser analisado.\n");
	printf("\t\"2\" Calcular idade do aluno.\n");
	printf("\t\"3\" Imprimir aluno.\n");
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

int SolicitaInteiro()
{
	int valor;
	scanf("%d", &valor);

	return valor;
}

Aluno InserirAluno()
{
	Aluno novoAluno;

	printf("Digite o nome:\n");
	novoAluno.Nome = SolicitaTexto();

	printf("Digite o sobrenome:\n");
	novoAluno.Sobrenome = SolicitaTexto();

	printf("Digite a matricula:\n");
	novoAluno.Matricula = SolicitaTexto();

	printf("Digite o dia de nascimento:\n");
	novoAluno.DiaNascimento = SolicitaInteiro();

	printf("Digite o mes de nascimento (ex: 1 para Janeiro):\n");
	novoAluno.MesNascimento = SolicitaInteiro();

	printf("Digite o ano de nascimento (ex: 1986):\n");
	novoAluno.AnoNascimento = SolicitaInteiro();

	return novoAluno;
}

void CalcularIdade(Aluno *aluno)
{
	const anoAtual = 2014;
	const mesAtual = 2;
	const diaAtual = 20;
	const quantidadeDiasNoAno = 360;
	const quantidadeDiasNoMes = 30;

	int dataAtual = (anoAtual * quantidadeDiasNoAno) + (mesAtual * quantidadeDiasNoMes) + diaAtual;
	int dataNascimento = (aluno->AnoNascimento * quantidadeDiasNoAno) + ((aluno->MesNascimento - 1) * quantidadeDiasNoMes) + aluno->DiaNascimento;

	int diferencaAnos = (dataAtual - dataNascimento) / quantidadeDiasNoAno;
	int diferencaDias = (dataAtual - dataNascimento) - (diferencaAnos * quantidadeDiasNoAno);

	printf("Idade:\t\t\t%d anos e %d dias\n", diferencaAnos, diferencaDias);
}

void ImprimirAluno(Aluno *aluno)
{
	printf("Nome Completo:\t\t%s %s\n", aluno->Nome, aluno->Sobrenome);
	printf("Matricula:\t\t%s\n", aluno->Matricula);
	printf("Data de Nascimento:\t%d/%d/%d\n", aluno->DiaNascimento, aluno->MesNascimento, aluno->AnoNascimento);
	CalcularIdade(aluno);
}

int ExecutaOperacao()
{
	int alunoInserido = 0;

	while (1)
	{
		Aluno novoAluno;
		char operacao = ImprimeMenu();

		if (operacao == 'x' || operacao == 'X')
			break;

		switch (operacao)
		{
			case '1': 
				novoAluno = InserirAluno();
				alunoInserido = 1;
				break;

			case '2':

				if (alunoInserido == 0)
				{
					printf("Insira um aluno\n");
					break;
				}

				CalcularIdade(&novoAluno);
				break;

			case '3':

				if (alunoInserido == 0)
				{
					printf("Insira um aluno\n");
					break;
				}

				ImprimirAluno(&novoAluno);
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