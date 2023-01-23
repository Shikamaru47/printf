#include "main.h"

/**
 * get_flag - Calculates active flag
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter.
 * Return: flag:
 */
int get_flag(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int j, index;
	int flag = 0;
	const char flag_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int flag_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (index = *i + 1; format[index] != '\0'; index++)
	{
		for (j = 0; flag_CH[j] != '\0'; j++)
			if (format[index] == flag_CH[j])
			{
				flag |= flag_ARR[j];
				break;
			}

		if (flag_CH[j] == 0)
			break;
	}

	*i = index - 1;

	return (flag);
}
