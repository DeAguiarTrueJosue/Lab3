#include <stdio.h>
#include <stdlib.h>
#include <string>

struct Command
{
	char action[20] = "\0";
	char target[50] = "\0";
	char parameters[3][20] = { "\0", "\0", "\0" };
};

int CompareBothCase(const char* number1, const char* number2) {
	int ca, cb;
	do {
		ca = *(unsigned char*)number1;
		cb = *(unsigned char*)number2;
		ca = tolower(ca);
		cb = tolower(cb);
		number1++;
		number2++;
	} while (ca == cb && ca != '\0');
	return ca - cb;
}

void toLower(char* a) {
	int ca;
	do {
		ca = *(unsigned char*)a;
		ca = tolower(ca);
		*a = ca;
		a++;
	} while (ca != '\0');
}

void Actions(Command* toDo)
{
	if (CompareBothCase(toDo->action, "Move") == 0)
	{
		printf("You moved to the %s", toDo->target);
		for (int i = 0; i < 3; i++)
		{
			if (toDo->parameters[i][0] != '\0')
			{
				printf(" %s", toDo->parameters[i]);
			}
		}
		printf("!\n");
	}
	else if (CompareBothCase(toDo->action, "Attack") == 0)
	{
		printf("You atatcked the %s", toDo->target);
		for (int i = 0; i < 3; i++)
		{
			if (toDo->parameters[i][0] != '\0')
			{
				printf(" %s", toDo->parameters[i]);
			}
		}
		printf("!\n");
	}
	else if (CompareBothCase(toDo->action, "Heal") == 0)
	{
		printf("You healed the %s", toDo->target);
		for (int i = 0; i < 3; i++)
		{
			if (toDo->parameters[i][0] != '\0')
			{
				printf(" %s", toDo->parameters[i]);
			}
		}
		printf("!\n");
	}
	else if (CompareBothCase(toDo->action, "Poop") == 0)
	{
		printf("I pooped myself");
		printf("!\n");
	}
}

void ParseCommand(char command[130], Command* toDo) {
	int moment = 0;
	char miniCommand[50] = {};
	char index = 0;
	for (int i = 0; i < 130; i++)
	{
		if (command[i] != ' ' && command[i] != '\0')
		{
			miniCommand[index] = command[i];
			index++;
		}
		else
		{
			switch (moment)
			{
			case 0:
				strcpy_s(toDo->action, miniCommand);
				toDo->action[index] = '\0';
				moment++;
				index = 0;
				break;
			case 1:
				strcpy_s(toDo->target, miniCommand);
				toDo->target[index] = '\0';
				moment++;
				index = 0;
				break;
			case 2:
				strcpy_s(toDo->parameters[0], miniCommand);
				toDo->parameters[0][index] = '\0';
				moment++;
				index = 0;
				break;
			case 3:
				strcpy_s(toDo->parameters[1], miniCommand);
				toDo->parameters[1][index] = '\0';
				moment++;
				index = 0;
				break;
			case 4:
				strcpy_s(toDo->parameters[2], miniCommand);
				toDo->parameters[2][index] = '\0';
				moment++;
				index = 0;
				break;
			default:
				break;
			}
			if (command[i] == '\0')
			{
				break;
			}
		}
	}
}

int main() {

	Command toDo;

	char command[130];

	printf("Tell me what you wanna do:\n");
	scanf_s(" %[^\n]s", command, 130);

	ParseCommand(command, &toDo);

	toLower(toDo.target);
	toLower(toDo.parameters[0]);
	toLower(toDo.parameters[1]);
	toLower(toDo.parameters[2]);

	Actions(&toDo);

	printf("Tell me what you wanna do:\n");
	scanf_s(" %[^\n]s", command, 130);

	ParseCommand(command, &toDo);

	toLower(toDo.target);
	toLower(toDo.parameters[0]);
	toLower(toDo.parameters[1]);
	toLower(toDo.parameters[2]);

	Actions(&toDo);

	printf("Tell me what you wanna do:\n");
	scanf_s(" %[^\n]s", command, 130);

	ParseCommand(command, &toDo);

	toLower(toDo.target);
	toLower(toDo.parameters[0]);
	toLower(toDo.parameters[1]);
	toLower(toDo.parameters[2]);

	Actions(&toDo);

	return 0;
}