
// check if numbers form a pythagorean triple
#include<stdio.h>

int main(){
	int n1, n2,n3;
	printf("enter first number: ");
	scanf("%d", &n1);
	printf("\nenter second number: ");
	scanf("%d", &n2);
	printf("\nenter third number: ");
	scanf("%d", &n3);
	int largest = n1;
	
	if(n2 > largest) largest = n2;
	if(n3 > largest) largest = n3;
	
	if(largest == n1){
		int largeCalc = largest * largest;
		if((largeCalc == n2*n2 + n3*n3)){
			printf("this is a pythagorean triple!");
		}
		else
		printf("the provided numbers do not form a pythagorean triple");
	}
			
	else if(largest == n2){
		int largeCalc = largest * largest;
		if((largeCalc == n1*n1 + n3*n3)){
			printf("this is a pythagorean triple!");
		}
		else
		printf("the provided numbers do not form a pythagorean triple");
	}
		
	else if(largest == n3){
		int largeCalc = largest * largest;
		if((largeCalc == n1*n1 + n2*n2)){
			printf("this is a pythagorean triple!");
		}
		else
		printf("the provided numbers do not form a pythagorean triple");
	}
			
	
	return 0;
}




