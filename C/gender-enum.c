#include <stdio.h>

typedef enum{
	Male,
	Female, 
	Other
}Gender;

int main(){
	int n;
	printf("Enter a number: ");
	scanf("%d", &n);
	Gender gender = (Gender)n;
	
	switch(gender){
		case Male:
			printf("Male");
			break;
		case Female:
			printf("Female");
			break;
		case Other:
			printf("Other");
			break;
		default:
			printf("Invalid Choice");
		
	}
	return 0;
}
