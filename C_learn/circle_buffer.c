#include <stdint.h>
#include <stdio.h>


typedef struct circle_buf{
	uint32_t r;
	uint32_t w;
	uint32_t len;
	uint8_t *buf;
}*p_circle_buf;

void circle_init(p_circle_buf pCircleBuf,uint32_t len,uint8_t *buf)
{
	pCircleBuf->r = pCircleBuf->w = 0;
	pCircleBuf->len = len;
	pCircleBuf->buf = buf;
}

int circle_write(p_circle_buf pCircleBuf,uint8_t Val)
{
	uint32_t next_w;
	next_w = pCircleBuf->w + 1;
	if(next_w == pCircleBuf->len)
		next_w = 0;
	if(pCircleBuf->r != next_w)
	{
		pCircleBuf->buf[pCircleBuf->w]  =Val;
		pCircleBuf->w = next_w;
		return 0;
	}
	else
	{
		return -1;
	}
}
int circle_read(p_circle_buf pCircleBuf,uint8_t *pVal)
{
	if(pCircleBuf->r != pCircleBuf->w)
	{
		*pVal = pCircleBuf->buf[pCircleBuf->r];
		pCircleBuf->r++;
		
		if(pCircleBuf->r == pCircleBuf->len)
			pCircleBuf->r = 0;
		return 0;
	}
	else
	{
		return -1;
	}
}

static uint8_t data_buf[100];
static circle_buf key_bufs;
int main()
{
	uint8_t key_val = 0;
	circle_init(&key_bufs,100,data_buf);
	
	for(int i=0;i<10;i++){
		circle_write(&key_bufs, i+1);
		printf("w = %d\n",key_bufs.w);
	}
	
	for(int i=0;i<10;i++){
		if(0 == circle_read(&key_bufs,&key_val)){
			//TODO
			
			printf("circle_buf -> key_val = %d\n",key_val);
			printf("r = %d\n",key_bufs.r);
		}
	}
	return 0;
}
