#include <stdio.h> //bibliotea de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> // biblioteca de alocações de texto por região
#include <string.h> //Biblioteca responsável por cuidar das strings
int registro() //função responsável por cadastrar os usuários no sistema
{
	//Inicio da criação de variáveis/string
	char arquivo[40];
	char CPF[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", CPF); //%s refere-se a strings
	
	strcpy(arquivo, CPF); //Responsável por copiar os valores das strings
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo, o "w" siginifica escrever
	fprintf(file,"CPF: ");
	fprintf(file,CPF); //Salvo o valor da variável
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
		printf("O arquivo não foi localizado");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

	
int deletar()
{
	char CPF[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",CPF); 
	
	remove(CPF);
	
		
	FILE *file;
	file = fopen(CPF,"r");
	
	
	if(file == NULL)
	{
		printf("Usuário não encontrado\n");
		system("pause");
		
	}

	
}

int main()
{
	int opcao=0; //Definindo as variáveis
	int x=1;
	
				
	for(x=1;x=1;)
	{
		
		system("cls");
		
	    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	    printf("### Cartório da EBAC ###\n\n"); //Início do menu
	    printf("##### Bem vindo #####\n\n");
	    printf("Escolha a opção desejada do menu: \n\n");
	    printf("\t1 - Registrar nomes\n");
  	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n");
	    printf("Opção: "); //Fim do menu
	
	    scanf("%d", &opcao); //Armazenando a escolha do usuário
	
	    system("cls"); //Responsável por limpar a tela
	    
	    
	    switch(opcao) //Início da seleção do menu
	    {
	    	case 1:
	        registro(); //Chamada de funções
	        break;
	        
	        case 2:
	        consulta();
	        break;
	        
	        case 3:
	        deletar();
	        break;
	        
	        
			default:
			printf("Essa opcão não está disponível\n");
		    system("pause");
			break;	
			   		
		}//Fim da seleção
	
        
    }
}
