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
    if(dataLen == bufLen)
        return -1;

    if(writeldx + len < bufLen)
    {
        strncpy((pRingBuf->bufBase)+writeldx, pSrcBuf, len);
        writeldx += len;
    }
    else
    {
        strncpy((pRingBuf->bufBase)+writeldx, pSrcBuf, bufLen - writeldx);
        strncpy((pRingBuf->bufBase), pSrcBuf+bufLen-writeldx, len - bufLen + writeldx);
        writeldx = len - bufLen + writeldx;
    }

    dataLen += len;
    
    return len;
}

int ringBuf_read(RING_BUFFER *pRingBuf, unsigned char *pDstBuf, int len)
{
    if(dataLen == 0)
        return -1;

    if(readldx + len < bufLen)
    {
        strncpy((pRingBuf->bufBase)+readldx, pDstBuf, len);
        readldx += len;
    }
    else if(dataLen - len < 0)
    {
        int i = 0;
        while(dataLen - i)
        {
            
        }
    }
    else
    {
        strncpy((pRingBuf->bufBase)+readldx, pDstBuf, bufLen - readldx);
        strncpy((pRingBuf->bufBase), pDstBuf+bufLen-readldx, len - bufLen + readldx);
        readldx = len - bufLen + readldx;
    }

    dataLen -= len;
    
    return len;

}
