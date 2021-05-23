#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//struct que leva as propriedades comuns dos itens disponíveis
typedef struct 
{
	float preco;
	int quantidadeInt;	
} produtos;


int main(int argc, char** argv)
{
	setlocale(LC_ALL, "");
	
	//quanto o usuário terá que pagar
	float custo;
	
	//opção de escolha de sessão no início do programa
	int escolhaMenu;
	
	//tamanho do carrinho. Essa declaração vai servir pra garantir que o usuário não extrapole o tamanho máximo do carrinho.
	int tamanho;
	
	//seleção de que item da sessão o usuário vai querer comprar
	int selecao;
	
	//quantidade de itens que o usuário vai querer comprar
	int quantidade;
	
	//variáveis de contagem
	int i;
	int j;
	
	
	printf("////////// XFOODS ////////////\n\nBem vindo ao XFOODS, selecione uma sessão de alimentos:\n1. Frutas\n2. Verduras\n3. Legumes\n4. Proteínas\n5. Congelados\n6. Bebidas\n7. Bebidas alcoólicas\n8. Panificadora\n\nEscolha: ");
	//usuário escolhendo a sessão do menu para visualizar
	scanf("%d", &escolhaMenu);
	
	system("cls");
	
	switch(escolhaMenu)
	{
		case 1: // frutas: banana, maçã e uva
		{
			printf("////////////Sessão das frutas///////////////\n\nProdutos disponíveis:\n\n");
			
			//declaração variáveis cara cada produto da sessão mais as suas propriedades
			produtos banana;
			produtos maca;
			produtos uva;
			
			banana.preco = 5.25;
			banana.quantidadeInt = 30;
			
			maca.preco = 1;
			maca.quantidadeInt = 45;
			
			uva.preco = 3.50;
			uva.quantidadeInt = 25;
			
			//matriz que organiza os produtos disponíveis e as quantidades
			int matrizFrutas[2][3] = 
			{
			{1, 2, 3},
			{banana.quantidadeInt, maca.quantidadeInt, uva.quantidadeInt}
			};
			
			
			//printando a matriz
			for(i = 0; i < 2; ++i)
			{
				for(j = 0; j < 3; ++j)
				{
					if(i == 0)
					{
						switch(j)
						{
							case 0:
							{
								printf("Item: Bananas (R$5,25)   ");
							}break;
							
							case 1:
							{
								printf("Maçãs (R$1,00)   ");
							}break;
							
							case 2:
							{
								printf("Uvas (R$3,50)   ");
							}break;
						}
					}
					else if(i == 1 && j == 0)
					{
						printf("Quant.:\t   %d", matrizFrutas[1][0]);
					}
					else
					{
						printf("\t\t   %d", matrizFrutas[i][j]);
					}
				}
				printf("\n\n");
			}
			
			printf("Qual item você vai querer adicionar no carrinho:\n1 - Bananas\n2 - Maçãs\n3 - Uvas\n");
			//usuário selecionando o produto que vai querer comprar
			scanf("%d", &selecao);
			
			switch(selecao)
			{
				case 1:
				{
					printf("\nDigite a quantidade que você vai querer comprar: ");
					//usuário digitando a quantidade a ser comprada dos produtos
					scanf("%d", &quantidade);
					
					//definindo a nova quantidade de frutas como: quantidade de frutas atual - quantidade comprada
					banana.quantidadeInt -= quantidade;
					//definindo o custo do carrinho do usuário
					custo += quantidade*5.25;
					
				}break;
				
				case 2:
				{
					printf("\nDigite a quantidade que você vai querer comprar: ");
					scanf("%d", &quantidade);
					
					maca.quantidadeInt -= quantidade;
					custo += quantidade*1;
					
				}break;
				
				case 3:
				{
					printf("\nDigite a quantidade que você vai querer comprar: ");
					scanf("%d", &quantidade);

					uva.quantidadeInt -= quantidade;
					custo += quantidade*3.5;
						
				}break;
			}
			
			printf("\n\nSaldo do carrinho: R$%.2f\n", custo);
			
		}break;
		
		case 2://verduras: alface, brócolis, aipo
		{
			produtos alface;
			produtos brocolis;
			produtos aipo;
			
			alface.preco = 1.50;
			alface.quantidadeInt = 41;

			
			brocolis.preco = 3;
			brocolis.quantidadeInt = 35;

			
			aipo.preco = 3.50;
			aipo.quantidadeInt = 25;

			
			int matrizVerduras[2][3] = 
			{
			{1, 2, 3},
			{alface.quantidadeInt, brocolis.quantidadeInt, aipo.quantidadeInt}
			};
			
			for(i = 0; i < 2; ++i)
			{
				for(j = 0; j < 3; ++j)
				{
					if(i == 0)
					{
						switch(j)
						{
							case 0:
							{
								printf("Item: Alfaces (R$1,50)   ");
							}break;
							
							case 1:
							{
								printf("Brócolis (R$3,00)   ");
							}break;
							
							case 2:
							{
								printf("Aipo (R$3,50)   ");
							}break;
						}
					}
					else if(i == 1 && j == 0)
					{
						printf("Quant.:\t   %d", matrizVerduras[1][0]);
					}
					else
					{
						printf("\t\t   %d", matrizVerduras[i][j]);
					}
				}
				printf("\n\n");
			}
			
			printf("Qual item você vai querer adicionar no carrinho:\n1 - Alfaces\n2 - Brócolis\n3 - Aipo\n");
			scanf("%d", &selecao);
			
			switch(selecao)
			{
				case 1:
				{
					printf("\nDigite a quantidade que você vai querer comprar: ");
					scanf("%d", &quantidade);
					
				}break;
				
				case 2:
				{
					printf("\nDigite a quantidade que você vai querer comprar: ");
					scanf("%d", &quantidade);
					
				}break;
				
				case 3:
				{
					printf("\nDigite a quantidade que você vai querer comprar: ");
					scanf("%d", &quantidade);
					
				}break;
			}
			 	
		}break;
		
		case 3://legumes: pimentão, pepino, beringela
		{
			produtos pimentao;
			produtos pepino;
			produtos beringela;
			
			pimentao.preco = 4.35;
			pimentao.quantidadeInt = 30;
			
			pepino.preco = 5;
			pepino.quantidadeInt = 35;
			
			beringela.preco = 6;
			beringela.quantidadeInt = 28;
			
			int matrizLegumes[2][3] = 
			{
			{1, 2, 3},
			{pimentao.quantidadeInt, pepino.quantidadeInt, beringela.quantidadeInt}
			};
			
			for(i = 0; i < 2; ++i)
			{
				for(j = 0; j < 3; ++j)
				{
					if(i == 0)
					{
						switch(j)
						{
							case 0:
							{
								printf("Item: Pimentão (R$4,35)   ");
							}break;
							
							case 1:
							{
								printf("Pepino (R$5,00)   ");
							}break;
							
							case 2:
							{
								printf("Beringela (R$6,00)   ");
							}break;
						}
					}
					else if(i == 1 && j == 0)
					{
						printf("Quant.:\t   %d", matrizLegumes[1][0]);
					}
					else
					{
						printf("\t\t   %d", matrizLegumes[i][j]);
					}
				}
				printf("\n\n");
			}
			
			printf("Qual item você vai querer adicionar no carrinho:\n1 - Pimentão\n2 - Pepino\n3 - Beringela\n");
			scanf("%d", &selecao);
			
			switch(selecao)
			{
				case 1:
				{
					printf("\nDigite a quantidade que você vai querer comprar: ");
					scanf("%d", &quantidade);
					
				}break;
				
				case 2:
				{
					printf("\nDigite a quantidade que você vai querer comprar: ");
					scanf("%d", &quantidade);
					
				}break;
				
				case 3:
				{
					printf("\nDigite a quantidade que você vai querer comprar: ");
					scanf("%d", &quantidade);
					
				}break;
			}
			
		}break;
		
		case 4://proteínas: carne, frango, peixe
		{
			produtos fraldinha;
			produtos frango;
			produtos tucunare;
			
			fraldinha.preco = 30;
			fraldinha.quantidadeInt = 7;
			
			frango.preco = 23.85;
			frango.quantidadeInt = 12;
			
			tucunare.preco = 21.75;
			tucunare.quantidadeInt = 15;
			
			int matrizProteinas[2][3] = 
			{
			{1, 2, 3},
			{fraldinha.quantidadeInt, frango.quantidadeInt, tucunare.quantidadeInt}
			};
			
			for(i = 0; i < 2; ++i)
			{
				for(j = 0; j < 3; ++j)
				{
					if(i == 0)
					{
						switch(j)
						{
							case 0:
							{
								printf("Item: Fraldinha (R$30,00)   ");
							}break;
							
							case 1:
							{
								printf("Frango (R$23,85)   ");
							}break;
							
							case 2:
							{
								printf("Tucunaré (R$21,75)   ");
							}break;
						}
					}
					else if(i == 1 && j == 0)
					{
						printf("Quant.:\t   %d", matrizProteinas[1][0]);
					}
					else
					{
						printf("\t\t\t%d", matrizProteinas[i][j]);
					}
				}
				printf("\n\n");
			}
			
			printf("Qual item você vai querer adicionar no carrinho:\n1 - Fraldinha\n2 - Frango\n3 - Tucunaré\n");
			scanf("%d", &selecao);
			
			switch(selecao)
			{
				case 1:
				{
					printf("\nDigite a quantidade que você vai querer comprar: ");
					scanf("%d", &quantidade);
					
				}break;
				
				case 2:
				{
					printf("\nDigite a quantidade que você vai querer comprar: ");
					scanf("%d", &quantidade);
					
				}break;
				
				case 3:
				{
					printf("\nDigite a quantidade que você vai querer comprar: ");
					scanf("%d", &quantidade);
					
				}break;
			}
			
		}break;
		
		case 5://congelados: picolé, sorvete, iogurte
		{
			produtos picole;
			produtos sorvete;
			produtos iogurte;
			
			picole.preco = 2.5;
			picole.quantidadeInt = 20;
			
			sorvete.preco = 12;
			sorvete.quantidadeInt = 13;
			
			iogurte.preco = 3.50;
			iogurte.quantidadeInt = 25;
			
			int matrizCongelados[2][3] = 
			{
			{1, 2, 3},
			{picole.quantidadeInt, sorvete.quantidadeInt, iogurte.quantidadeInt}
			};
			
			for(i = 0; i < 2; ++i)
			{
				for(j = 0; j < 3; ++j)
				{
					if(i == 0)
					{
						switch(j)
						{
							case 0:
							{
								printf("Item: Picolés (R$2,50)   ");
							}break;
							
							case 1:
							{
								printf("Sorvetes (R$12,00)   ");
							}break;
							
							case 2:
							{
								printf("Iogurtes (R$3,50)   ");
							}break;
						}
					}
					else if(i == 1 && j == 0)
					{
						printf("Quant.:\t   %d", matrizCongelados[1][0]);
					}
					else
					{
						printf("\t\t      %d", matrizCongelados[i][j]);
					}
				}
				printf("\n\n");
			}
			
			printf("Qual item você vai querer adicionar no carrinho:\n1 - Picolés\n2 - Sorvetes\n3 - Iogurtes\n");
			scanf("%d", &selecao);
			
			switch(selecao)
			{
				case 1:
				{
					printf("\nDigite a quantidade que você vai querer comprar: ");
					scanf("%d", &quantidade);
					
				}break;
				
				case 2:
				{
					printf("\nDigite a quantidade que você vai querer comprar: ");
					scanf("%d", &quantidade);
					
				}break;
				
				case 3:
				{
					printf("\nDigite a quantidade que você vai querer comprar: ");
					scanf("%d", &quantidade);
					
				}break;
			}
			
		}break;
		
		case 6://bebidas: suco em caixa, guaraná, energy drink
		{
			produtos suco;
			produtos guarana;
			produtos energyDrink;
			
			suco.preco = 5.25;
			suco.quantidadeInt = 27;

			guarana.preco = 7.40;
			guarana.quantidadeInt = 23;

			energyDrink.preco = 3.50;
			energyDrink.quantidadeInt = 25;

			int matrizBebidas[2][3] = 
			{
			{1, 2, 3},
			{suco.quantidadeInt, guarana.quantidadeInt, energyDrink.quantidadeInt}
			};
			
			for(i = 0; i < 2; ++i)
			{
				for(j = 0; j < 3; ++j)
				{
					if(i == 0)
					{
						switch(j)
						{
							case 0:
							{
								printf("Item: Suco de caixa (R$5,25)   ");
							}break;
							
							case 1:
							{
								printf("Guaraná 2L (R$7,40)   ");
							}break;
							
							case 2:
							{
								printf("Energy Drink (R$3,50)   ");
							}break;
						}
					}
					else if(i == 1 && j == 0)
					{
						printf("Quant.:\t   %d", matrizBebidas[1][0]);
					}
					else
					{
						printf("\t\t\t   %d", matrizBebidas[i][j]);
					}
				}
				printf("\n\n");
			}
			
			printf("Qual item você vai querer adicionar no carrinho:\n1 - Suco de caixa\n2 - Guaraná\n3 - Energy Drink\n");
			scanf("%d", &selecao);
			
			switch(selecao)
			{
				case 1:
				{
					printf("\nDigite a quantidade que você vai querer comprar: ");
					scanf("%d", &quantidade);
					
				}break;
				
				case 2:
				{
					printf("\nDigite a quantidade que você vai querer comprar: ");
					scanf("%d", &quantidade);
					
				}break;
				
				case 3:
				{
					printf("\nDigite a quantidade que você vai querer comprar: ");
					scanf("%d", &quantidade);
					
				}break;
			}
			
		}break;
		
		case 7://bebidas alcoólicas: cerveja, vinho, licor
		{
			produtos cerveja;
			produtos vinho;
			produtos licor;
			
			cerveja.preco = 6.30;
			cerveja.quantidadeInt = 24;
	
			vinho.preco = 13.50;
			vinho.quantidadeInt = 10;
	
			licor.preco = 20;
			licor.quantidadeInt = 4;
	
			int matrizAlcool[2][3] = 
			{
			{1, 2, 3},
			{cerveja.quantidadeInt, vinho.quantidadeInt, licor.quantidadeInt}
			};
			
			for(i = 0; i < 2; ++i)
			{
				for(j = 0; j < 3; ++j)
				{
					if(i == 0)
					{
						switch(j)
						{
							case 0:
							{
								printf("Item: Cerveja (R$6,30)   ");
							}break;
							
							case 1:
							{
								printf("Vinho (R$13,50)   ");
							}break;
							
							case 2:
							{
								printf("Licor (R$20,00)   ");
							}break;
						}
					}
					else if(i == 1 && j == 0)
					{
						printf("Quant.:\t   %d", matrizAlcool[1][0]);
					}
					else
					{
						printf("\t\t     %d", matrizAlcool[i][j]);
					}
				}
				printf("\n\n");
			}
			
			printf("Qual item você vai querer adicionar no carrinho:\n1 - Cerveja\n2 - Vinho\n3 - Licor\n");
			scanf("%d", &selecao);
			
			switch(selecao)
			{
				case 1:
				{
					printf("\nDigite a quantidade que você vai querer comprar: ");
					scanf("%d", &quantidade);
					
				}break;
				
				case 2:
				{
					printf("\nDigite a quantidade que você vai querer comprar: ");
					scanf("%d", &quantidade);
					
				}break;
				
				case 3:
				{
					printf("\nDigite a quantidade que você vai querer comprar: ");
					scanf("%d", &quantidade);
					
				}break;
			}
			
		}break;
		
		case 8://pão francês, sonho, empada
		{
			produtos paoFrances;
			produtos sonho;
			produtos empada;
			
			paoFrances.preco = 4;
			paoFrances.quantidadeInt = 35;

			sonho.preco = 7.30;
			sonho.quantidadeInt = 13;

			empada.preco = 3;
			empada.quantidadeInt = 10;

			int matrizPanificadora[2][3] = 
			{
			{1, 2, 3},
			{paoFrances.quantidadeInt, sonho.quantidadeInt, empada.quantidadeInt}
			};
			
			for(i = 0; i < 2; ++i)
			{
				for(j = 0; j < 3; ++j)
				{
					if(i == 0)
					{
						switch(j)
						{
							case 0:
							{
								printf("Item: Pão Francês (R$4,00)   ");
							}break;
							
							case 1:
							{
								printf("Sonho (R$7,30)   ");
							}break;
							
							case 2:
							{
								printf("Empada (R$3,00)   ");
							}break;
						}
					}
					else if(i == 1 && j == 0)
					{
						printf("Quant.:\t   %d   ", matrizPanificadora[1][0]);
					}
					else
					{
						printf("\t\t     %d", matrizPanificadora[i][j]);
					}
				}
				printf("\n\n");
			}
			
			printf("Qual item você vai querer adicionar no carrinho:\n1 - Pão Francês\n2 - Sonho\n3 - Empada\n");
			scanf("%d", &selecao);
			
			switch(selecao)
			{
				case 1:
				{
					printf("\nDigite a quantidade que você vai querer comprar: ");
					scanf("%d", &quantidade);
					
				}break;
				
				case 2:
				{
					printf("\nDigite a quantidade que você vai querer comprar: ");
					scanf("%d", &quantidade);
					
				}break;
				
				case 3:
				{
					printf("\nDigite a quantidade que você vai querer comprar: ");
					scanf("%d", &quantidade);
					
				}break;
			}
			
		}break;
	}
	
	
	return 0;
}