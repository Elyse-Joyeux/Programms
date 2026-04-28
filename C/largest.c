#include<stdio.h>

int main(){
	int num = 1;
	int x = 74;
	int y = 37;
	int z = 12;
	int largest = num;
	
	if(x > largest) largest = x;
	if(y > largest) largest = y;
	if(z > largest) largest = z;
	printf("The largest number is %d", largest);
	
	return 0;
}
