#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int isint(char* num)
{
	for (int i = 0; i < strlen(num); ++i)
	{
		if (!isdigit(num[i]))
		{
			return 0;
		}
	}
	return 1;
}

int sum(int num1, int num2)
{
	return num1 + num2;
}

int dif(int num1, int num2)
{
	return num1 - num2;
}

int rem(int num1, int num2)
{
	return num1 * num2;
}

int prod(int num1, int num2)
{
	return num1 % num2;
}

int main(int argc, char** argv)
{
	if (argc % 3 != 0 || argc < 4)
	{
		printf("Введено некорректное кол-во аргументов");
		return 0;
	}
	if (strcmp(argv[argc - 2], "-k") != 0)
	{
		printf("Введен неверный флаг");
		return 0;
	}
	if (!isint(argv[argc - 1]))
	{
		printf("Введен неверный ключ");
		return 0;
	}
	int* arr = (int*)calloc(argc / 3 - 1, sizeof(int));
	for (int i = 1; i < argc - 4; i += 3)
	{
		char* arg1 = argv[i];
		char* arg2 = argv[i + 1];
		char* arg3 = argv[i + 2];
		if (!isint(arg1) || !isint(arg3))
		{
			printf("Введено некорректное число\n");
			free(arr);
			return 0;
		}
		if (strcmp(arg2, "+") != 0 && strcmp(arg2, "-") != 0 && strcmp(arg2, "*") != 0 && strcmp(arg2, "%") != 0)
		{
			printf("Введён некорректный знак\n");
			free(arr);
			return 0;
		}	
		if (strcmp(arg2, "+") == 0)
		{
			arr[(i - 1) / 3] = sum(atoi(arg1), atoi(arg3));
		}
		else if (strcmp(arg2, "-") == 0)
		{
			arr[(i - 1) / 3] = dif(atoi(arg1), atoi(arg3));
		}
		else if (strcmp(arg2, "*") == 0)
		{
			arr[(i - 1) / 3] = rem(atoi(arg1), atoi(arg3));
		}
		else
		{
			arr[(i - 1) / 3] = prod(atoi(arg1), atoi(arg3));
		}
	}
	char* str = (char*)calloc(argc / 3 - 1, sizeof(char));
	for (int i = 0; i < argc / 3 - 1; ++i)
	{
		printf("Ответ №%i: %i\n", i + 1, arr[i]);
		str[i] = (char)(arr[i] - atoi((argv[argc - 1])));
	}
	printf("Результирующая строка: ");
	for (int i = 0; i < argc / 3 - 1; ++i)
	{
		printf("%c", str[i]);
	}
	printf("\n");
}
