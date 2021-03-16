#include <stdio.h>

int sala[7][10];
float preco = 10;

void gerar_sala_vazia(){
	int l, c;

	for(l=0; l<7; l++){
		for (c=0; c<10; c++){
			sala[l][c] = 0;
		}
	}
}

void printar_sala(){
	int l, c, j;
    printf("   \n");
	printf("   Lugares com [X] estao ocupados! \n");
	printf("   \n");
	
	for(l=0; l<7; l++){
		for (c=0; c<10; c++){			
			if(sala[l][c]==0){
				printf(" [ ] ");
			
					if(c==9){
						printf("\n");
						
						for (j=0; j<10;j++){
							printf(" %d,%d ", l, j);
						}
						printf("\n");
					}
			}
			else{
				printf(" [X] ", l, c);
			    if(c==9){
						printf("\n");
						for (j=0; j<10;j++){
							printf(" %d,%d ", l, j);
						}
						printf("\n");
				}
			}
		}
	}
	
	printf("   \n");
}

int calcular_lugares(){
	int qtd=0, l, c;
	
	for(l=0; l<7; l++){
		for (c=0; c<10; c++){	
			if(sala[l][c]==1){
			qtd++;
			}		
		}
	}
	
	return qtd;
		
}

int reservar_sala(int l,  int c)
{
	if(sala[l][c]==1){
		return 0;
	}
	else{
		sala[l][c]=1;
		return 1;
	}
}

int cancelar_assento(int l,  int c )
{
	if(sala[l][c]==0){
		return 0;
	}
	else{
		sala[l][c]=0;
		return 1;
	}
}

void menu(){

	printf("   \n");
	printf("	Bem vindo(a) ao CINEMA! \n");
	printf("   \n");
	printf("  	Por favor, escolha o numero com acao desejada \n");
	printf("   \n");
	printf("	1 - Visualizar sala! \n");
	printf("	2 - Reservar cadeira! \n");
	printf("	3 - Cancelar cadeira! \n");
	printf("	4 - Quantas cadeiras estao disponiveis? \n");
	printf("	5 - Atualizar preco da entrada! (Preco atual: R$ %.2f) \n", preco);
	printf("	6 - Faturamento da sala! \n");
	printf("	7 - Sair \n");
}

void main(){
	int escolha=0, resposta, l, c, fb, n, lv;
	float lucro;
	
		
	gerar_sala_vazia();
	
do
{
	menu();
	resposta=1;
	printf("	\n");
	printf("	");
	scanf("%d", &escolha);
	
	
	if(escolha==1)
	{
		printar_sala();		
	}

	if(escolha==2)
	{
		do{
		printar_sala();
		printf(" Escolha o assento a ser escolhido com a primeira coordenada seguida da segunda! \n");
		do{
		printf("	");
		scanf("%d",&l);
		printf("	");
		scanf("%d",&c);
		if(l>6 || l<0 || c>9 || c<0)
		{
			printf("	Lugar inexistente, tente outra vez!\n");
		}
		else
		{
			fb = reservar_sala(l,c);
		}
		
		}while(l>6 || l<0 || c>9 || c<0);
		
		
		 do {
			if (fb==0)
			{
				printf("	\n");
				printf("	Assento ocupado por favor escolha outro! \n");
				do{
					printf("	");
					scanf("%d",&l);
					printf("	");
					scanf("%d",&c);
					if(l>6 || l<0 || c>9 || c<0)
					{
						printf("	\n");
						printf("	Lugar inexistente, tente outra vez!\n");
					}
					else
					{
						fb = reservar_sala(l,c);
					}
		
				}while(l>6 || l<0 || c>9 || c<0);
			}					
			}while (fb!=1);
			
		printf("	\n");	
		printf("	Assento cadastrado com sucesso \n");
		printf("	\n");		
		printf("	Deseja cadastrar outro? \n	1 = sim \n	0 = nao \n");
		printf("	");
		scanf("%d", &resposta);
			 
		}while(resposta!=0);
	}

	if(escolha==3)
	{
		n = calcular_lugares();
		
		if(n!=0)
		{
		do{
		printar_sala();
		printf("	Qual assento deseja cancelar? \n");
		do{
			printf("	");
			scanf("%d",&l);
			printf("	");
			scanf("%d",&c);
			if(l>6 || l<0 || c>9 || c<0)
			{
				printf("	Lugar inexistente, tente outra vez!\n");
			}
			else
			{
				fb = cancelar_assento(l,c);
			}
		
		}while(l>6 || l<0 || c>9 || c<0);
	
		 do {
			if (fb==0)
			{   
						printf("	Assento ja encontra-se vazio, por favor escolha outro! \n");
						do{
							printf("	");
							scanf("%d",&l);
							printf("	");
							scanf("%d",&c);
							if(l>6 || l<0 || c>9 || c<0)
							{
								printf("	Lugar inexistente, tente outra vez!\n");
							}
							else
							{
								fb = cancelar_assento(l,c);
							}
		
						}while(l>6 || l<0 || c>9 || c<0);
	
					}					
				}while (fb!=1);
			
				printf("	Assento cancelado com sucesso \n"); 
				printf("   \n");
		
			if(calcular_lugares()==0){
				resposta=0;	
				printf("   \n");
				printf("   Nao existem mais lugares para serem cancelados!");
				printf("   \n");
			}
			else
			{
				printf("   \n");
				printf("	Deseja cancelar outro? \n	1 = sim \n	0 = nao \n");
				printf("	");
				scanf("%d", &resposta);
			}
			}while(resposta!=0);
		}
		else
		{
			printf("   \n");
			printf("  	Nao existem lugares reservados para serem cancelados!");
			printf("   \n");
		}
	}
	if(escolha==4)
	{
		n = calcular_lugares();
		lv=70-n;
		printf("	Lugares Vagos: %d  \n	Lugares Ocupados: %d", lv, n);
		printf("   \n");
		
	}
	if(escolha==5)
	{
		printf("	Preco atual de R$ %.2f \n", preco);
		printf("	Deseja Alterar? \n	1 = sim \n	0 = nao \n");
		printf("	");
		scanf("%d", &resposta);
				
		if (resposta==1){
			do{
			printf("	Digite o preco desejado (Nao negativo): \n");
			printf("	");
			scanf("%f", &preco);
	
			}while(preco<0);
			
			printf("	Novo preco: R$ %.2f cadastrado com sucesso!\n", preco);
		}
				
		
	}
	if(escolha==6)
	{
		n = calcular_lugares();
		lucro = preco*n;
		printf("	O faturamento atual da sala e de R$ %.2f !", lucro);
		printf("	\n");
	}
	
	if(escolha!=1 && escolha!=2 && escolha!=3 && escolha!=4 && escolha!=5 && escolha!=6 && escolha!=7)
	{
		printf("	Opcao inexitente, escolha outra! \n");
		printf("	\n");
	}		

	}while(escolha!=7);
}
	
	

