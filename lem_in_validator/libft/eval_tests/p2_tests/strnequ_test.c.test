#include <stdio.h>
#include "../libft.h"

int strnequ_test(void)
{
    int tests_passed = 0;

    if (ft_strnequ("hello world \t", "hello world \t", 20) == 1 && strncmp("hello world \t", "hello world \t", 20) == 0)
        tests_passed++;
    else
        printf("\nERROR: ");
    
    if (ft_strnequ("\200", "\0", 1) == 0 && strncmp("\200", "\0", 1) > 0)
        tests_passed++;
    else
        printf("\nERROR: ");
    
    if (ft_strnequ("\200", "\0", 0) == 1 && strncmp("\200", "\0", 0) == 0)
        tests_passed++;
    else
        printf("\nERROR: ");

    if (ft_strnequ("", "\0", 1) == 1 && strncmp("", "\0", 1) == 0)
        tests_passed++;
    else
        printf("\nERROR: ");

    if (ft_strnequ("test\0 test", "test", 10) == 1 && strncmp("test\0 test", "test", 10) == 0)
        tests_passed++;
    else
        printf("\nERROR: ");

    if (ft_strnequ("abcd", "abcde", 4) == 1 && strncmp("abcd", "abcde", 4) == 0)
        tests_passed++;
    else
        printf("\nERROR: ");

    if (tests_passed == 6)
    {
        printf("\tOK\n");
        return (1);
    }
    return (0);
} 