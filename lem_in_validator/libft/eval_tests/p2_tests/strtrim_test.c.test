#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../libft.h"

int     strtrim_test(void)
{
    int tests_passed = 0;

    char *str = ft_strtrim(" \n\t \n  \ttrim this string\t \n \t\t  ");
    if (strcmp(str, "trim this string") == 0)
        tests_passed++;
    else
        printf("\nERROR 1: strcmp(str, 'trim this string') != 0\n|%s|", str);
    free(str);

    str = ft_strtrim("trim this string");
    if (strcmp(str, "trim this string") == 0)
        tests_passed++;
    else
        printf("\nERROR 2: strcmp(str, 'trim this string') != 0\n|%s|", str);
    free(str);

    str = ft_strtrim("");
    if (strcmp(str, "") == 0)
        tests_passed++;
    else
        printf("\nERROR 3: strcmp(str, '') != 0\n|%s|", str);
    free(str);

    str = ft_strtrim("\t\n ");
    if (strcmp(str, "") == 0)
        tests_passed++;
    else
        printf("\nERROR 4: strcmp(str, '') != 0\n|%s|", str);
    free(str);

    if (tests_passed == 4)
    {
        printf("\tOK\n");
        return (1);
    }
    return (0);
}