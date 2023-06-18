#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

/**
 * copyTobase - copy bases in one base
 * @b: main base
 * @b1: base
 * @b2: base
 */
void copyTobase(char *b, char *b1, char *b2)
{
	int j;

	for (j = 0; j < (int)strlen(b1); j++)
		b[j] = b1[j];

	for (j = 0; j < (int)strlen(b2); j++)
		b[j + strlen(b1)] = b2[j];
	b[64] = '\0';
}

/**
 * main - keygen for crackme5
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 (success) | 1 (failed)
 */
int main(int argc, char **argv)
{
	int len, sum = 0, i, var;
	char *ptr = argv[1], base[65], key[6];
	char *base1 = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU";
	char *base2 = "+4mjW6fxqZeF3Qa1rPhdKIouk";

	if (argc != 2)
		return (1);

	copyTobase(base, base1, base2);
	len = strlen(ptr);
	key[0] = base[(len ^ 59) & 63];
	for (i = 0; i < len; i++)
		sum += ptr[i];
	key[1] = base[(sum ^ 79) & 63];
	for (i = 0, sum = 1; i < len; i++)
		sum *= ptr[i];
	key[2] = base[(sum ^ 85) & 63];
	for (i = 0, sum = 0; i < len; i++)
		if (sum <= ptr[i])
			sum = ptr[i];
	srand(sum ^ 14);
	var = rand();
	key[3] = base[var & 63];
	for (i = 0, var = 0; i < len; i++)
		var += ptr[i] * ptr[i];
	key[4] = base[(var ^ 239) & 63];
	for (i = 0, var = 0; i < ptr[0]; i++)
		var = rand();
	key[5] = base[(var ^ 229) & 63];
	for (i = 0; i < 6; i++)
		printf("%c", key[i]);
	printf("\n");
	return (0);
}
