#include "../libft.h"
#include <stdio.h>

int     strequ_test(void)
{
    int tests_passed = 0;

    if (ft_strequ("hello world \t", "hello world \t") == 1 && strcmp("hello world \t", "hello world \t") == 0)
        tests_passed++;
    else
        printf("\nERROR");

    if (ft_strequ("\200", "\0") == 0 && strcmp("\200", "\0") > 0)
        tests_passed++;
    else
        printf("\nERROR");

    if (ft_strequ("", "\0") == 1 && strcmp("", "\0") == 0)
        tests_passed++;
    else
        printf("\nERROR");

    if (ft_strequ("test\0 test", "test") == 1 && strcmp("test\0 test", "test") == 0)
        tests_passed++;
    else
        printf("\nERROR");

    if (ft_strequ("abcd", "abcde") == 0 && strcmp("abcd", "abcde") < 0)
        tests_passed++;
    else
        printf("\nERROR");

    if (tests_passed == 5)
    {
        printf("\tOK\n");
        return (1);
    }    
    return (0);
}