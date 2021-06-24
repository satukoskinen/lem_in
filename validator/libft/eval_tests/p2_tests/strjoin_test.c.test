#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../libft.h"

int     strjoin_test(void)
{
    int tests_passed = 0;

    char *str = ft_strjoin("first one", " second one");
    if (strcmp(str, "first one second one") == 0)
        tests_passed++;
    else
        printf("\nERROR: strcmp(str, 'first one second one') != 0\n%s)", str);
    free(str);

    str = ft_strjoin("first one", "");
    if (strcmp(str, "first one") == 0)
        tests_passed++;
    else
        printf("\nERROR: strcmp(str, 'first one') != 0\n%s)", str);
    free(str);

    str = ft_strjoin("", "");
    if (strcmp(str, "") == 0)
        tests_passed++;
    else
        printf("\nERROR: strcmp(str, '') != 0\n%s)", str);
    free(str);

    if (tests_passed == 3)
    {
        printf("\tOK\n");
        return (1);
    }
    return (0);
}