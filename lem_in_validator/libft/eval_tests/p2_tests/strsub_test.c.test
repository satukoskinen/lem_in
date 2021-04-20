#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../libft.h"

int     strsub_test(void)
{
    int tests_passed = 0;

    char *str = ft_strsub("grab the substring", 9, 3);
    if (strcmp(str, "sub") == 0)
        tests_passed++;
    else
        printf("\nERROR: strcmp(str, 'sub') != 0\n%s)", str);

    free(str);
    str = ft_strsub("grab the substring", 0, 1);
    if (strcmp(str, "g") == 0)
        tests_passed++;
    else
        printf("\nERROR: strcmp(str, 'g') != 0\n%s)", str);

    free(str);
    str = ft_strsub("grab the substring", 1, 0);
    if (strcmp(str, "") == 0)
        tests_passed++;
    else
        printf("\nERROR: strcmp(str, '') != 0\n%s)", str);

    free(str);
    str = ft_strsub("grab the \0substring", 10, 3);
    if (strcmp(str, "sub") == 0)
        tests_passed++;
    else
        printf("\nERROR: strcmp(str, 'sub') != 0\n%s)", str);

    free(str);
    if (tests_passed == 4)
    {
        printf("\tOK\n");
        return (1);
    }
    return (0);
}