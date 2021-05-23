#include <stdio.h>
#include <stdlib.h>

#define MAX_ITENS_CARRINHO 45
#define MAX_STRING_LENGTH 32

typedef struct {
    char nome[ MAX_STRING_LENGTH ];
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
    FILE *filePointer;
    filePointer = fopen( "produtos.txt", "rt" );
    if ( filePointer == NULL ) {
        red(); printf( "Error while opening file.\n" ); reset();
        return 1;
    }
    int i = 0, j = 0, totalTipos = 0;
    fscanf( filePointer, "%d", &totalTipos );
    int itensPorTipo[ totalTipos ];
    Produto produto[ totalTipos ][ MAX_ITENS_CARRINHO ];
    char tipo[ MAX_ITENS_CARRINHO ][ MAX_STRING_LENGTH ];
    for ( i = 0; i < totalTipos; i++ ) {
        fscanf( filePointer, "%s %d", tipo[ i ], &itensPorTipo[ i ] );
        for ( j = 0; j < itensPorTipo[ i ]; j++ ) {
            fscanf( filePointer, "%s %d %f", produto[ i ][ j ].nome,
                &produto[ i ][ j ].estoque, &produto[ i ][ j ].preco );
           produto[ i ][ j ].categoria = i;
           produto[ i ][ j ].adquirido = 0;
        }
    }
    fclose( filePointer );

    // variáveis do carrinho de compras
    int totalItensCarrinho = 0;
    float totalAPagar = 0.0f;

    // menu principal de escolha
    int menuEscolha = -1;
    while ( menuEscolha ) {
        yellow(); printf( "MENU DE PRODUTOS:\n" ); reset();
        for ( i = 0; i < totalTipos; i++ ) {
            printf( "%d. %s\n", i + 1, tipo[ i ] );
        }
        printf( "0. SAIR\n" );
        printf( "Total de itens no seu carrinho = %d\n", totalItensCarrinho );
        green(); printf( "Valor total a pagar: %.2f\n", totalAPagar ); reset();
        yellow(); printf( "SUA ESCOLHA: " ); reset();
        scanf( "%d", &menuEscolha );
        if ( 0 <= menuEscolha && menuEscolha <= totalTipos ) {
            if ( menuEscolha == 0 ) {
                yellow(); printf( "OBRIGADO PELA PREFERÊNCIA!\n" ); reset();
                return 0;
            }
            int menuItemEscolha = -1;
            while ( menuItemEscolha ) {
                printf( "MENU DE %s:\n", tipo[ menuEscolha - 1 ] );
                for ( j = 0; j < itensPorTipo[ menuEscolha - 1 ]; j++ ) {
                    printf( "%d. %s (estoque = %d, preço unitário = %.2f)\n",
                        j + 1, produto[ menuEscolha - 1 ][ j ].nome,
                        produto[ menuEscolha - 1][ j ].estoque, produto[ menuEscolha - 1 ][ j ].preco );
                }
                printf( "0. RETORNAR AO MENU PRINCIPAL\n" );
                printf( "Total de itens no seu carrinho = %d\n", totalItensCarrinho );
                if ( totalItensCarrinho > 0 ) {
                    cyan(); printf( "CARRINHO = [ " );
                    int alreadyPrintedSomething = 0;
                    for ( i = 0; i < totalTipos; i++ ) {
                        for ( j = 0; j < itensPorTipo[ i ]; j++ ) {
                            if ( produto[ i ][ j ].adquirido > 0 ) {
                                if ( alreadyPrintedSomething ) {
                                    printf( ", " );
                                }
                                printf( "%s = %d ($%.2f)", produto[ i ][ j ].nome,
                                    produto[ i ][ j ].adquirido,
                                    produto[ i ][ j ].adquirido * produto[ i ][ j ].preco );
                                alreadyPrintedSomething = 1;
                            }
                        }
                    }
                    printf( " ]\n" ); reset();
                }
                yellow(); printf( "COMPRAR QUAL ITEM? " ); reset();
                scanf( "%d", &menuItemEscolha );
                if ( 1 <= menuItemEscolha && menuItemEscolha <= itensPorTipo[ menuEscolha - 1 ] ) {
                    printf( "Quantas unidades de %s? ", produto[ menuEscolha - 1 ][ menuItemEscolha - 1 ].nome );
                    int unidades = 0;
                    scanf( "%d", &unidades );
                    if ( unidades > produto[ menuEscolha - 1 ][ menuItemEscolha - 1 ].estoque ) {
                        red(); printf( "Erro: falta de estoque!\n" ); reset();
                    }
                    else {
                        if ( totalItensCarrinho + unidades > MAX_ITENS_CARRINHO ) {
                            red(); printf( "Erro: limite excedido de itens no carrinho!\n" ); reset();
                        }
                        else {
                            totalItensCarrinho += unidades;
                            produto[ menuEscolha - 1 ][ menuItemEscolha - 1 ].adquirido += unidades;
                            produto[ menuEscolha - 1 ][ menuItemEscolha - 1 ].estoque -= unidades;
                            totalAPagar += unidades * produto[ menuEscolha - 1 ][ menuItemEscolha - 1 ].preco;
                        }
                    }
                }
                else {
                    if ( menuItemEscolha != 0 ) { 
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
