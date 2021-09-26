#include<stdio.h>

typedef unsigned char uint8_t;

float get_humidity_data(uint8_t arr[2])
{
	int val = 0;
	uint8_t *pBuf = (uint8_t*)&val;
	
	float result=0.0;
	pBuf[0] = arr[1];
	pBuf[1] = arr[0];
	
	if(val<4096)
	{
		val=val;
	}
	else
	{
		val=val-65536;
	}
	result = (float)val/10; //保留小数存储最终湿度值

	return result;
}

int main(void)
{
	
	//低字节序 
//	uint8_t sDec[4] = {0xFF,0x9B};
	uint8_t sDec[2] = {0x00,0xEB};
	float humidity;
	
	humidity = get_humidity_data(sDec);

	printf("\r\nresult=%.1f\r\n",humidity);
	return 0;

 } 
