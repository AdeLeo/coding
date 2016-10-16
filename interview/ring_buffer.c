#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    unsigned char *bufBase;
    int bufLen;
    int writeldx;
    int readldx;
    int dataLen;
}RING_BUFFER;

int ringBuf_write(RING_BUFFER *pRingBuf, unsigned char *pSrcBuf, int len)
{
    
}

int ringBuf_read(RING_BUFFER *pRingBuf, unsigned char *pDstBuf, int len)
{

}
