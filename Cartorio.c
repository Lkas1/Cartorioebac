#include <stdio.h> //bibliotea de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // biblioteca de aloca��es de texto por regi�o
#include <string.h> //Biblioteca respons�vel por cuidar das strings
int registro() //fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//Inicio da cria��o de vari�veis/string
	char arquivo[40];
	char CPF[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", CPF); //%s refere-se a strings
	
	strcpy(arquivo, CPF); //Respons�vel por copiar os valores das strings
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo, o "w" siginifica escrever
	fprintf(file,"CPF: ");
	fprintf(file,CPF); //Salvo o valor da vari�vel
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,"\n");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,"Nome: ");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"\n");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,"Sobrenome: ");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"\n");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	file = fopen(arquivo, "a");
	fprintf(file,"Cargo: ");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}
int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char CPF[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",CPF);
	
	FILE *file;
	file = fopen(CPF,"r");
	
	if(file == NULL)
	{
		printf("O arquivo n�o foi localizado");
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
	char CPF[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",CPF); 
	
	remove(CPF);
	
		
	FILE *file;
	file = fopen(CPF,"r");
	
	
	if(file == NULL)
	{
		printf("Usu�rio n�o encontrado\n");
		system("pause");
		
	}

	
}

int main()
{
	int opcao=0; //Definindo as vari�veis
	int x=1;
	
				
	for(x=1;x=1;)
	{
		
		system("cls");
		
	    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	    printf("### Cart�rio da EBAC ###\n\n"); //In�cio do menu
	    printf("##### Bem vindo #####\n\n");
	    printf("Escolha a op��o desejada do menu: \n\n");
	    printf("\t1 - Registrar nomes\n");
  	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n");
	    printf("Op��o: "); //Fim do menu
	
	    scanf("%d", &opcao); //Armazenando a escolha do usu�rio
	
	    system("cls"); //Respons�vel por limpar a tela
	    
	    
	    switch(opcao) //In�cio da sele��o do menu
	    {
	    	case 1:
	        registro(); //Chamada de fun��es
	        break;
	        
	        case 2:
	        consulta();
	        break;
	        
	        case 3:
	        deletar();
	        break;
	        
	        
			default:
			printf("Essa opc�o n�o est� dispon�vel\n");
		    system("pause");
			break;	
			   		
		}//Fim da sele��o
	
        
    }
}
