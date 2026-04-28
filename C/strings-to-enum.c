#include <stdio.h>
#include <string.h>

typedef enum{
	Red, 
	Green,
	Yellow
}Color;

int main(){
	char color[10];
	int found = 0;
	printf("enter a color(Red, Green, Yellow ): ");
	scanf("%9s", color);
	Color col;
	if(strcmp(color, "Red") == 0){
		col = Red;
		found = 1;
		}
		
	else if(strcmp(color, "Green") == 0){
		col = Green;
		found = 1;
		}
		
	else if(strcmp(color, "Yellow") == 0){
		col = Yellow;
		found = 1;
		}
		
	else{
		printf("error");
		return 1;
	}
		
	if (found){
		printf("Enum value assigned: %d\n", col);
	}
	return 0;
}
