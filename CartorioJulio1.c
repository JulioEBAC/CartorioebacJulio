#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // biblioteca de aloca��o de texto por regi�o
#include <string.h> // biblioteca responsavel por cuidar das string

int registro() //Fun��o responsavel por cadastrar os usu�rios
{
	
	setlocale(LC_ALL, "Portuguese"); //Definindo Linguaguem
	
	//inicio da cira��o de variaveis /string
	char arquivo[40];
	char cpf[40];
	char nome [40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis /string
	
	printf("Digite o CPF a ser cadastrado: "); //texto que aparece no programa
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" siginifica escrever 
	fprintf(file,cpf); //salvo valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o aqruivo e o "a" significa atualizar
	fprintf(file,","); //cria a virgula no sistema
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //texto que aparece no programa
	scanf("%s",nome); //alocando na string
	
	file = fopen(arquivo, "a"); //abrindo arquivo e atualizando
	fprintf(file,nome); //salva valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");//abrindo arquivo e atualizando
	fprintf(file,",");//coloca a virgula no programa para separar as variaveis
	fclose(file);//fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");//abrindo arquivo e atualizando
	fprintf(file,sobrenome);//salva valor da variavel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//novo arquivo pra virgula
	fprintf(file,",");//virgula no programa para seprar as variaveis
	fclose(file);//fecha o arquivo
	
	printf ("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system ("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo Linguaguem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL) //equipara se o arquivo for nulo 
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo Linguaguem
	char cpf[40];
	
	printf("Digite o cpf do usus�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf); //removendo o arquivo
	
	FILE *file; //local onde esta o arquivo
	file = fopen(cpf,"r"); //abrindo o arquivo
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema.\n");
		system("pause");
		
	}
}

int main()
{
	int opcao=0; //Definindo Vari�veis
	int laco=1;
		
	for(laco=1;laco=1;)
	{

		system ("cls");
	   	
		setlocale(LC_ALL, "Portuguese"); //Definindo Linguaguem
	
		printf("### Cartorio da EBAC ### \n\n"); //Inicio do Menu
		printf("Escolha a op��o desejada no menu da EBAC: \n\n");
		printf("\t1 - Registrar Nomes \n");
		printf("\t2 - Consultar Nomes \n");
		printf("\t3 - Deletar Nomes \n\n");
		printf("\t4 - Sair do sistema \n\n");
		printf("Op��o: "); 	// fim do menu
	
		scanf("%d", &opcao); // armazenando a escolha do usu�rio
	
		system("cls"); //responsavel por limpar a tela
		
		
		switch(opcao)
		{
			case 1:
			registro(); //chamada de fun��es
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			
			default:
			printf("Essa op��o nao est� disponivel.\n");
			system("pause");
	    }
	}

}
	
