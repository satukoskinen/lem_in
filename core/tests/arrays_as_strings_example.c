
#include "../inc/core.h"
# define STR str_new
# define DEL str_del
# define PRINT str_print

typedef t_array t_str;

void	str_print(t_str src)
{
	write(1, src.data, src.len);
}

t_str	str_cpy(t_str dst, t_str src)
{
	arr_copy(&dst, &src);
	return (dst);
}

t_str	str_new(char *src)
{
	t_str	out;
	t_size	len;

	len = 0;
	if (!src)
		len = 1;
	else
		while (src[len] != '\0')
			len++;
	out = arr(len, sizeof(char));
	arr_put(&out, src, len);
	return (out);
}

void	str_del(t_str src)
{
	arr_free(&src);
}

t_str	str_join(t_str dst, t_str src)
{
	arr_join(&dst, &src);
	return (dst);
}

int		str_chr(t_str src, char key)
{
	return (arr_find(&src, &key));
}

int		str_str(t_str src, t_str key)
{
	return (arr_search(&src, &key));
}

int main(int argc, char **argv)
{
	t_str str1 = str_new(NULL);
	t_str str2 = str_new("first ");
	t_str str3 = str_new("second ");
	t_str str4 = str_new("third ");
	t_str str5 = str_new("fourth ");
	t_str str6 = str_new("fifth");

	arr_join_mult(&str1, 5,
					&str2,
					&str3,
					&str4,
					&str5,
					&str6);
	PRINT(str1);
	char c = 's';
	printf("\nFirst occurence of s: %d\n", str_chr(str1, c));
	printf("\nFirst char of third: %d\n", str_str(str1, str4));
	DEL(str1);
	DEL(str2);
	DEL(str3);
	DEL(str4);
	DEL(str5);
	DEL(str6);
}

