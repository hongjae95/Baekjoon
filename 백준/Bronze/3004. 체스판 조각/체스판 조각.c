#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{    
	int n = 0;

	scanf("%d", &n);

	if (n % 2 == 0) // 짝수
	{
		printf("%d", ((n / 2) + 1) * ((n / 2) + 1));
	}
	else
		printf("%d", ((n / 2) + 1) * (n-(n/2) +1));

	return 0;
}
