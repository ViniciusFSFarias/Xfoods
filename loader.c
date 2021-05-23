#include <stdio.h>

typedef struct {
    char nome[ 32 ];
    int quantidade;
    float preco;
} Produto;

int main( ) {
    FILE *filePointer;
    filePointer = fopen( "produtos.txt", "rt" );
    if ( filePointer == NULL ) {
        printf( "Error while opening file.\n" );
        return 1;
    }
    int i = 0, j = 0, totalTipos = 0;
    fscanf( filePointer, "%d", &totalTipos );
    Produto produto[ totalTipos ][ 45 ];
    char tipo[ 45 ][ 32 ];
    for ( i = 0; i < totalTipos; i++ ) {
        int quantidadeProdutosDesteTipo = 0;
        fscanf( filePointer, "%s %d", tipo[ i ], &quantidadeProdutosDesteTipo );
        printf( "tipo de produto = %s, ", tipo[ i ] );
        printf( "quantidade de produtos deste tipo = %d\n", quantidadeProdutosDesteTipo );
        for ( j = 0; j < quantidadeProdutosDesteTipo; j++ ) {
            fscanf( filePointer, "%s %d %f", produto[ i ][ j ].nome,
                &produto[ i ][ j ].quantidade, &produto[ i ][ j ].preco );
            printf( "%s %d %f\n", produto[ i ][ j ].nome, produto[ i ][ j ].quantidade, produto[ i ][ j ].preco );
        }
    }
    fclose( filePointer );
    return 0;
}
