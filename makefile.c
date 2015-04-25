#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int makeFile( char *fileName, int size )
{
    FILE *fp;
    char *pData;

    /* メモリを確保する */
    pData = malloc( size );
    if( pData == NULL )
    {
        /* 確保失敗 */
        return 1;
    }

    fp = fopen( fileName, "wb" );
    if( fp == NULL )
    {
        /* ファイルオープン失敗 */
        return 1;
    }
    /* ファイルに空白(0x20)を書き込む */
    memset( pData, 0x20, size );
    fwrite( pData, size, 1, fp );
    fclose( fp );

    /* メモリを解放する */
    free( pData );
    return 0;
}

main() {
    makeFile("a.txt", 100000000);
}
