#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> // biblioteca responsável por cuidar das string

int registrar()									//função que vai registrar os usuários
{
	setlocale(LC_ALL, "Portuguese");			//define a língua usada na função
	
	
	char arquivo[40];							//início da criação de variáveis
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo [40];							//final da criação de variáveis
	
	
	printf("Digite o CPF a ser cadastrado:");	//coletando informação do usuário
	scanf("%s", cpf);							//%s armazena dentro da string cpf, até 40 carac.
	
	strcpy(arquivo, cpf); 						//Copia valores das string
	
	FILE *file;									//Procura ou cria o arquivo
	file = fopen(arquivo, "w");					//W de Write, escreve valores copiados em strcpy
	fprintf(file,cpf);							//salva o valor da variável
	fclose(file);								//fecha o arquivo
	
	file = fopen(arquivo, "a");					//A de update,atualizar
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado:");	
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");					//A de update,atualizar
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado:");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");					//A de update,atualizar
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado:");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
}

int consultar()												//
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado:");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");									//r de read
	
	if(file == NULL)
	{
		printf("Não foi possível localizar o arquivo.");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário:");
		printf("%s", conteudo);
		printf("\n\n");	
	}
	
	system("pause");
}

int deletar()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	
	printf("Digite o CPF a ser deletado:");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O registro do CPF %s foi deletado com sucesso.\n", cpf);
		system("pause");
	}
		
}
int main()
{
	int opcao=0;	//definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)	
	{
	
		system("cls");
		
		setlocale(LC_ALL, "Portuguese");	//Definindo a linguagem
	
		printf("### Cartório da EBAC ###\n\n");			//início do menu
		printf("Escolha a opção desejada do menu: \n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n\n");
		printf("\t9 - Encerrar o programa\n\n\n");
		printf("Opção:");					//fim do menu
	
		scanf("%d", &opcao);				//armazenando a escolha do usuário
		
		system("cls");						//"limpa" a tela
	
		switch(opcao)				//seleção do menu. Os cases precisam ser constantes
		{
			case 1:
			registrar();
			break;
			
			case 2:
			consultar();
			break;
			
			case 3:
			deletar();
			break;
			
			case 9:
			printf("Encerrando o programa.\n\n");
			printf("Nós agradecemos por utilizar este programa!\n\n");
			exit(0);
			break;
		
			default:
			printf("Essa opção não está disponível.\n\n");
			system("pause");
					
		} 												//fim da seleção
	
	}
	
}
