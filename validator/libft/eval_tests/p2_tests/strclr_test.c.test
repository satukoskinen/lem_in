#include "../libft.h"
#include <stdlib.h>
#include <stdio.h>

int		strclr_test(void)
{
	int tests_passed = 0;

    char *str1 = malloc(sizeof(char) * 100);
    char str2[100] = {'\0'};

    for (int i = 0; i < 100; i++)
        str1[i] = 'x';

    ft_strclr(str1);

    if (memcmp(str1, str2, 100) == 0)
        tests_passed++;
    else
        printf("\nERROR: memcmp(str1, str2, 100) != 0");

    free(str1);
    str1 = NULL;

    ft_strclr(str1);
    tests_passed++;

	if (tests_passed == 2)
	{
		printf("\tOK\n");
		return (1);
	}
	return (0);
}