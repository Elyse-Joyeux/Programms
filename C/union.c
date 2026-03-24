#include <stdio.h>

union MyUnion{
	int i;
	char c;
	float f;

} u1,u2, u3;

int main(){
	printf("U1 data input: \n");
	printf("\nI: ");scanf("%d", &u1.i);
	printf("\nC: ");scanf(" %c", &u1.c);
	printf("\nF: ");scanf("%f", &u1.f);
	
	printf("U2 data input: \n");
	printf("\nI: ");scanf("%d", &u2.i);
	printf("\nC: ");scanf(" %c", &u2.c);
	printf("\nF: ");scanf("%f", &u2.f);
	
	printf("U3 data input: \n");
	printf("\nI: ");scanf("%d", &u3.i);
	printf("\nC: ");scanf(" %c", &u3.c);
	printf("\nF: ");scanf("%f", &u3.f);
	
	printf("U1 data input: \n");
	printf("\nI: %d", u1.i);
	printf("\nC: %c",u1.c);
	printf("\nF: %f",u1.f);
	
	printf("U2 data input: \n");
	printf("\nI: %d", u2.i);
	printf("\nC: %c",u2.c);
	printf("\nF: %f",u2.f);
	
	printf("U3 data input: \n");
	printf("\nI: %d", u3.i);
	printf("\nC: %c",u3.c);
	printf("\nF: %f",u3.f);
	
	
	printf("\nThe size of any union is %zu", sizeof(u1));
	
	return 0;
}
