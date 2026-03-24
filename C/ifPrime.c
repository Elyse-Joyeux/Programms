#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main()
{
	bool isPrime = true;
	int num;

	printf("enter number: ");
	scanf("%d", &num);

	if (num <= 1)
	{
		isPrime = false;
	}
	int limit = (int)(sqrt(num));
	for (int i = 2; i <= limit; i++)
	{
		if (num % i == 0)
		{
			isPrime = false;
			break;
		}
	}

	if (isPrime)
		printf("\nthe entered number is prime!");
	else
		printf("the entered number is not prime");
	return 0;
}
