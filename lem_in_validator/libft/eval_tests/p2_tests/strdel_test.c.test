#include "../libft.h"
#include <stdlib.h>
#include <stdio.h>

int		strdel_test(void)
{
	int tests_passed = 0;

	char *str1 = malloc(sizeof(char) * 10);
	char *str2 = NULL;

	ft_strdel(&str1);
	if  (str1 == NULL)
		tests_passed++;
	else
		printf("\nERROR: str1 != NULL");

	ft_strdel(&str2);
	tests_passed++;

	if (tests_passed == 2)
	{
		printf("\tOK, check for leaks\n");
		return (1);
	}
	return (0);
}