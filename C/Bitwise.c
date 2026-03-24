#include <stdio.h>

int main(int argc, char ** argv){
	int x = 9;
	int y = 5;
	int result;
	result = y^((x^y)&-(x<y));
	if (x < y)
		result = x;
	else 
		result = y;
	printf("The smallest number is %d\n", result);
	return 0;
}
