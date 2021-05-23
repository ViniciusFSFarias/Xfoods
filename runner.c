#include <stdio.h>
#include <stdlib.h>

#define MAX_ITENS 45
#define MAX_STRING 32

typedef struct {
    char nome[ MAX_STRING ];
    int categoria;
    int estoque;
    int adquirido;
    float preco;
} Produto;

void red() { printf("\033[0;31m"); }
void green() { printf("\033[0;32m"); }
void blue() { printf("\033[0;34m"); }
void cyan() { printf("\033[0;36m"); }
void yellow() { printf("\033[0;33m"); }
void reset() { printf("\033[0m"); }

int main( ) {

    // Esta parte do código carrega a lista de produtos.txt
    FILE *filePointer = fopen( "produtos.txt", "rt" );
    if ( filePointer == NULL ) {
        red(); printf( "Error while opening file.\n" ); reset();
        return 1;
    }
    int i = 0, j = 0, totalTipos = 0;
    fscanf( filePointer, "%d", &totalTipos );
    int itensPorTipo[ totalTipos ];
    Produto p[ totalTipos ][ MAX_ITENS ];
    char tipo[ MAX_ITENS ][ MAX_STRING ];
    for ( i = 0; i < totalTipos; i++ ) {
        fscanf( filePointer, "%s %d", tipo[ i ], &itensPorTipo[ i ] );
        for ( j = 0; j < itensPorTipo[ i ]; j++ ) {
            fscanf( filePointer, "%s %d %f", p[ i ][ j ].nome,
                &p[ i ][ j ].estoque, &p[ i ][ j ].preco );
           p[ i ][ j ].categoria = i; p[ i ][ j ].adquirido = 0;
        }
    }
    fclose( filePointer );

    // variáveis do carrinho de compras
    int itensCarrinho = 0;
    float totalAPagar = 0.0f;

    // menu principal de escolha
    int choice = -1;
    while ( choice ) {
        yellow(); printf( "MENU DE PRODUTOS:\n" ); reset();
        for ( i = 0; i < totalTipos; i++ ) {
            printf( "%d. %s\n", i + 1, tipo[ i ] );
        }
        printf( "0. SAIR\n" );
        printf( "Total de itens no seu carrinho = %d\n", itensCarrinho );
        green(); printf( "Valor total a pagar: %.2f\n", totalAPagar ); reset();
        yellow(); printf( "SUA ESCOLHA: " ); reset();
        scanf( "%d", &choice );
        if ( 0 <= choice && choice <= totalTipos ) {
            if ( choice == 0 ) {
                yellow(); printf( "OBRIGADO PELA PREFERÊNCIA!\n" ); reset();
                return 0;
            }
            int itemChoice = -1;
            while ( itemChoice ) {
                printf( "MENU DE %s:\n", tipo[ choice - 1 ] );
                for ( j = 0; j < itensPorTipo[ choice - 1 ]; j++ ) {
                    printf( "%d. %s (estoque = %d, preço unitário = %.2f)\n",
                        j + 1, p[ choice - 1 ][ j ].nome,
                        p[ choice - 1][ j ].estoque, p[ choice - 1 ][ j ].preco );
                }
                printf( "0. RETORNAR AO MENU PRINCIPAL\n" );
                printf( "Total de itens no seu carrinho = %d\n", itensCarrinho );
                if ( itensCarrinho > 0 ) {
                    cyan(); printf( "CARRINHO = [ " );
                    int alreadyPrintedSomething = 0;
                    for ( i = 0; i < totalTipos; i++ ) {
                        for ( j = 0; j < itensPorTipo[ i ]; j++ ) {
                            if ( p[ i ][ j ].adquirido > 0 ) {
                                if ( alreadyPrintedSomething ) {
                                    printf( ", " );
                                }
                                printf( "%s = %d ($%.2f)", p[ i ][ j ].nome, p[ i ][ j ].adquirido,
                                    p[ i ][ j ].adquirido * p[ i ][ j ].preco );
                                alreadyPrintedSomething = 1;
                            }
                        }
                    }
                    printf( " ]\n" ); reset();
                }
                yellow(); printf( "COMPRAR QUAL ITEM? " ); reset();
                scanf( "%d", &itemChoice );
                if ( 1 <= itemChoice && itemChoice <= itensPorTipo[ choice - 1 ] ) {
                    printf( "Quantas unidades de %s? ", p[ choice - 1 ][ itemChoice - 1 ].nome );
                    int unidades = 0;
                    scanf( "%d", &unidades );
                    if ( unidades > p[ choice - 1 ][ itemChoice - 1 ].estoque ) {
                        red(); printf( "Erro: falta de estoque!\n" ); reset();
                    }
                    else {
                        if ( itensCarrinho + unidades > MAX_ITENS ) {
                            red(); printf( "Erro: limite excedido de itens no carrinho!\n" ); reset();
                        }
                        else {
                            itensCarrinho += unidades;
                            p[ choice - 1 ][ itemChoice - 1 ].adquirido += unidades;
                            p[ choice - 1 ][ itemChoice - 1 ].estoque -= unidades;
                            totalAPagar += unidades * p[ choice - 1 ][ itemChoice - 1 ].preco;
                        }
                    }
                }
                else {
                    if ( itemChoice != 0 ) { 
                        red(); printf( "ITEM INVÁLIDO!\n" ); reset();
                    }
                }
            }
        }
        else {
            red(); printf( "ESCOLHA INVÁLIDA!\n" ); reset();
        }
    }
    blue(); printf( "FIM\n" ); reset();
    return 0;
}
