#include <stdio.h>
#include <stdlib.h>
#include "../libft.h"

int     itoa_test(void)
{
    int tests_passed = 0;

    char *str = ft_itoa(0);
    if (strcmp(str, "0") == 0)
        tests_passed++;
    else
        printf("\nERROR 1: strcmp(str, '0') != 0\n%s", str);
    free(str);

    str = ft_itoa(-1);
    if (strcmp(str, "-1") == 0)
        tests_passed++;
    else
        printf("\nERROR 2: strcmp(str, '-1') != 0\n%s", str);
    free(str);

    str = ft_itoa(42);
    if (strcmp(str, "42") == 0)
        tests_passed++;
    else
        printf("\nERROR 3: strcmp(str, '42') != 0\n%s", str);
    free(str);

    str = ft_itoa(4000);
    if (strcmp(str, "4000") == 0)
        tests_passed++;
    else
        printf("\nERROR 4: strcmp(str, '4000') != 0\n%s", str);
    free(str);

    str = ft_itoa(2147483647);
    if (strcmp(str, "2147483647") == 0)
        tests_passed++;
    else
        printf("\nERROR 5: strcmp(str, '2147483647') != 0\n%s", str);
    free(str);

    str = ft_itoa(-2147483648);
    if (strcmp(str, "-2147483648") == 0)
        tests_passed++;
    else
        printf("\nERROR 6: strcmp(str, '-2147483648') != 0\n%s", str);
    free(str);

    if (tests_passed == 6)
    {
        printf("\tOK\n");
        return (1);
    }
    return (0);
}