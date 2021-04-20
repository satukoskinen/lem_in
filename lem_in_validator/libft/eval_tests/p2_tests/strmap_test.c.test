#include "../libft.h"
#include <stdlib.h>
#include <stdio.h>

char    ft_map(char c)
{
    return (c + 1);
}

int     strmap_test(void)
{
    int tests_passed = 0;

    char *str1;
    char *str2 = malloc(sizeof(char) * 10);
    str1 = ft_strmap("abcdefghi", ft_map);
    str2 = strcpy(str2, "bcdefghij");

    if (strcmp(str1, str2) == 0)
        tests_passed++;
    else
        printf("\nERROR: strcmp(str1, str2) != 0\n%s\n%s", str1, str2);

    free(str1);
    free(str2);
    if (tests_passed == 1)
    {
        printf("\tOK\n");
        return (1);
    }
    return (0);
}