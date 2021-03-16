#include<stdio.h>
#include <locale.h>
int main()
{
	float preco, preco_n, faturamento;
	int resp, fileira, coluna, Cadeira[70], i, l, c, k, j, z, reservadas, livres;

	//preço do ingresso *padrão*
	preco = 2.;
	
	//numerando cadeiras
	for(i=0; i<=69; i++)
	{
       Cadeira[i] = i+1;
	}
	
	setlocale(LC_ALL,"");
	printf("\t***Bem-vindo ao sistema de cinema***\n");
	do{
		printf("\t***Menu***\n\n");
		printf("\t...Preço do ingresso: %.2f...\n\n", preco);
		printf("\t1-Visualizar a sala\n");
		printf("\t2-Reservar uma cadeira\n");
		printf("\t3-Cancelar reserva da cadeira\n");
		printf("\t4-Quantidade de cadeiras (disponíveis/reservadas)\n");
		printf("\t5-Atualizar preço do ingresso \n");
		printf("\t6-Faturamento atual da sala\n");
		printf("\t0-Se desejar encerrar o sistema\n\n");
		scanf ("%d", &resp);
		
		switch(resp)
		{
			case 1:
				z=0;
				printf("\nVisão geral da sala de cinema. \nObs: [ ] = cadeira vazia, [X] = cadeira ocupada.\n\n");
				for(l=0;l<=6;l++)
				{
					for(k=0;k<=9;k++)
					{
						printf(" %d,%d ",l,k);
					}
					printf("\n");
					for(c=0;c<=9;c++)
					{
						z++;
						//printf("%d\n", z);
						if(Cadeira[z-1]==0)
							printf(" [X] ");	
						else
							printf(" [ ] ");
					}
					printf("\n\n");
				}
			break;
			case 2:
				printf("\nDigite o número da fileira e da coluna do assento que deseja reservar.\n");
				do{
					printf("Fileira(0-6): ");
					scanf("%d", &fileira);
				}while(fileira>6 || fileira<0);

				do{
					printf("Coluna(0-9): ");
					scanf("%d", &coluna);
				}while(coluna>9 || coluna<0);
				
				printf("\n");
				//printf("\n%d,%d",fileira, coluna);
				j=0;
				for(l=0;l<=6;l++)
				{
					for(c=0;c<=9;c++)
					{
						j++;
						if(l==fileira)
						{
							if(c==coluna)
							{
								if(Cadeira[j-1]==0)
								{
									printf("Cadeira não disponível!\n");
								}
								else
								{
									printf("Cadeira reservada!\n");
									Cadeira[j-1]=0;
								}
							}	
						}
					}
				}
			break;
			case 3:
				printf("Digite o número da fileira e da coluna do assento que deseja cancelar a reserva.\n");
				do{
					printf("Fileira(0-6): ");
					scanf("%d", &fileira);
				}while(fileira>6 || fileira<0);

				do{
					printf("Coluna(0-9): ");
					scanf("%d", &coluna);
				}while(coluna>9 || coluna<0);
				printf("\n");
				//printf("\n%d,%d",fileira, coluna);
				j=0;
				for(l=0;l<=6;l++)
				{
					for(c=0;c<=9;c++)
					{
						j++;
						if(l==fileira)
						{
							if(c==coluna)
							{
								if(Cadeira[j-1]==0)
								{
									Cadeira[j-1]=j++;
									printf("Reserva cancelada com sucesso!\n\n");
								}
								else
								{
									printf("A cadeira não estava reservada, pode ter ocorrido um engano!\n\n");
								}
							}	
						}
					}
				}
			break;
			case 4:
				reservadas=0;
				livres=0;
				z=0;
				for(l=0;l<=6;l++)
				{
					for(c=0;c<=9;c++)
					{
						z++;
						//printf("%d\n", z);
						if(Cadeira[z-1]==0)
							reservadas++;	
						else
							livres++;
					}
				}
				printf("Cadeiras livres:%d \n", livres);
				printf("Cadeiras reservadas:%d \n\n", reservadas);
			break;	
			case 5:
				printf("Valor atual: %.2f", preco);
				do{
				printf("\nDigite o novo valor do ingresso (valor positivo R$): ");
				scanf("%f", &preco_n);
				}while(preco_n<0);
				preco = preco_n;
				printf("Valor alterado com sucesso: %.2f\n\n", preco_n);
			break;
			case 6:
				z=0;
				faturamento=0;
				for(l=0;l<=6;l++)
				{
					for(c=0;c<=9;c++)
					{
						z++;
						//printf("%d\n", z);
						if(Cadeira[z-1]==0)
							faturamento = preco+faturamento;	
						else
							faturamento = faturamento;
					}
				}
				printf("\nO total faturado da sala até agora é de: %.2f\n\n", faturamento);
			break;
		}
	}while(resp!=0);
	fflush(stdin);	
}
