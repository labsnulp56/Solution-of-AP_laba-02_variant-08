#include <stdio.h>

#define MAX 50

char* Input(void);
char* DivideSentence(char* user_string);
int MyStrlen(char *str);
int MyPow(int base, int exp);
char * mystrtok(char * str, const char * delim);

int main()
{
	system("color F1");
	Input();
	system("pause");
	return 0;
}

char* Input(void)
{
	puts("input string");
	puts("+-+-+-+-+-+-+");
	char hex[MAX];
	gets_s(hex, MAX);
	DivideSentence(hex);
	return hex;
}

char* DivideSentence(char* user_string)
{
	const char *limits = " ,.;()-";     
	char *pw;							
	pw = mystrtok(user_string, limits);
	while (pw != NULL)				    
	{
		printf("| %s", pw);				
		convertion(pw, MyStrlen(pw));
		pw = mystrtok(NULL, limits);
	}
	return(user_string);
}

int convertion(char* hex, int lenth)
{

	char* ptr = hex;
	int localLenth = lenth - 1, val;
	register i = 0;
	long long decimal = 0, place = 1;
	for (i = 0; (*(ptr + i)) != '\0'; i++)
	{
		if ((*(ptr + i)) >= '0' && (*(ptr + i)) <= '9')
		{
			val = (*(ptr + i)) - 48;
		}
		else if ((*(ptr + i)) >= 'a' && (*(ptr + i)) <= 'f')
		{
			val = (*(ptr + i)) - 97 + 10;
		}
		else if ((*(ptr + i)) >= 'A' && (*(ptr + i)) <= 'F')
		{
			val = (*(ptr + i)) - 65 + 10;
		}
		else
		{
			printf("%s", " -> is incorrect |\n");
			return -1;
		}
		decimal += val * MyPow(16, localLenth);
		localLenth--;

	}
	printf(" = %d |\n", decimal);
}

int MyStrlen(char *str)
{
	int len = 0;
	int i;

	for (i = 0; str[i] != 0; i++)
	{
		len++;
	}
	return(len);
}

int MyPow(int base, int exp)
{
	int result = 1;
	for (;;)
	{
		if (exp & 1)
			result *= base;
		exp >>= 1;
		if (!exp)
			break;
		base *= base;
	}
	return result;
}

char * mystrtok(char * str, const char * delim)
{
	static char * last = 0;
	if (str) last = str;
	if ((last == 0) || (*last == 0)) return 0;
	char * c = last;
	while (strchr(delim, *c)) ++c;
	if (*c == 0) return 0;
	char * start = c;
	while (*c && (strchr(delim, *c) == 0)) ++c;
	if (*c == 0)
	{
		last = c;
		return start;
	}
	*c = 0;
	last = c + 1;
	return start;
}

