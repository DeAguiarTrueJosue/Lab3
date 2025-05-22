#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct GameItem
{
	char name[50];
	int power;
	int rarity;
	char type[20];
};

void DisplayItems(GameItem items[], int size) {
	for (int i = 0; i < size; i++)
	{
		printf("The item %s", items[i].name);
		printf(" has a power of %i and a rarity of %i, being of the type: %s", items[i].power, items[i].rarity, items[i].type);
		printf("\n");
	}
}

GameItem FindTheMostPowerful(GameItem items[], int size) {
	int strongestIndex = 0;
	for (int i = 1; i < size; i++)
	{
		if (items[i].power > items[strongestIndex].power)
		{
			strongestIndex = i;
		}
	}
	return items[strongestIndex];
}

float AvarageRarity(GameItem items[], int size) {
	float avarage = 0;
	for (int i = 0; i < size; i++)
	{
		avarage += items[i].rarity;
	}
	return avarage / size;
}

int main() {

	GameItem inventory[5] = {};

	strcpy_s(inventory[0].name, "Golden berry");
	inventory[0].power = 1;
	inventory[0].rarity = 4;
	strcpy_s(inventory[0].type, "Food");

	strcpy_s(inventory[1].name, "Excalibur");
	inventory[1].power = 50;
	inventory[1].rarity = 5;
	strcpy_s(inventory[1].type, "Weapon");

	strcpy_s(inventory[2].name, "Enchanted bow");
	inventory[2].power = 35;
	inventory[2].rarity = 3;
	strcpy_s(inventory[2].type, "Weapon");

	strcpy_s(inventory[3].name, "Birch wood");
	inventory[3].power = 5;
	inventory[3].rarity = 1;
	strcpy_s(inventory[3].type, "Material");

	strcpy_s(inventory[4].name, "Fire arrow");
	inventory[4].power = 15;
	inventory[4].rarity = 2;
	strcpy_s(inventory[4].type, "Weapon");

	DisplayItems(inventory, 5);

	GameItem strongest = FindTheMostPowerful(inventory, 5);

	float avarage = AvarageRarity(inventory, 5);

	printf("\nThe strongest item you have has %i power.\nIt is the %s", strongest.power, strongest.name);
	printf("\n\nThe avarage of the rarity of your items is %.1f", avarage);

	return 0;
}