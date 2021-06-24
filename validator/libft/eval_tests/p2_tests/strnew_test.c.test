#include "../libft.h"
#include <stdlib.h>
#include <stdio.h>

int		strnew_test(void)
{
	int tests_passed = 0;

	char *str1 = ft_strnew(10);
	char str2[10] = {'\0'};

	if (memcmp(str1, str2, 10) == 0)
		tests_passed++;
	else
	{
		printf("\nERROR: memcmp(str1, str2) != 0");
	}
	free(str1);
	if ((str1 = ft_strnew(-1)) == NULL)
		tests_passed++;
	else
	{
		printf("\nERROR: ft_strnew(-1) != NULL");
	}
	free(str1);
	if (tests_passed == 2)
	{
		printf("\tOK\n");
		return (1);
	}
	return (0);
}