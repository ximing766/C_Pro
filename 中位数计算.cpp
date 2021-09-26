#include<stdio.h>

// 获得三个数中的中间数
int getSecond(int a,int b,int c){
    int max = a > b ? a : b;
    max = max > c ? max : c;
    int min = a < b ? a: b;
    min = min < c ? min : c;
    int second = a + b + c - max - min;
    return second;
}


float get_mean_humidity(float humi_arr[9],int i)
{
	float a=humi_arr[i],b=humi_arr[i+1],c=humi_arr[i+2];
	float max = a>b?a:b;
	max = max>c?max:c;
	float min = a<b?a:b;
	min = min<c?min:c;
	float mean_humidity1 = a+b+c-max-min;
	
	return mean_humidity1;
}



int main(void)
{
	float test[9]={1.2,2.3,1.5,1.1,2.2,3.3,6.6,5.5,7.7};
	
	int a =-1,b=-1,c=2;
	int result;
	result = getSecond(a,b,c);
	
	float test_val;
	test_val = get_mean_humidity(test,6);
	printf("test_val=%.1f",test_val);

	
	return 0;
 } 
