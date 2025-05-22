#include <stdio.h>
#include <stdlib.h>

void DecimalToBase(int decimal, int base)
{
	char hexa[64] = "";
	int size = 0;
	int nextValue = 0;

	for (int i = decimal; i > 0; i /= base)
	{
		nextValue = i % base;
		if (nextValue > 9)
		{
			nextValue += 'A' - 10;
		}
		else {
			nextValue += '0';
		}
		for (int i = size; i > 0; i--)
		{
			hexa[i] = hexa[i - 1];
		}
		hexa[0] = nextValue;
		size++;
	}

	printf("%s", hexa);

	printf("\n");
}

int main() {

	int number, base = 0;


	do
	{
		system("cls");
		printf("For what base would you like to convert youy number?\n2 - 16: ");
		scanf_s("%i", &base);
	} while (base > 16 || base < 2);

	printf("\nWhat number would you like to convert?\n");
	scanf_s("%i", &number);

	DecimalToBase(number, base);

	return 0;
}