#include "inc/core.h"

typedef struct s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

t_list	*list_new(void *data)
{
	t_list	*out;

	out = malloc(sizeof(t_list));
	if (!out)
		return (NULL);
	out->data = data;
	out->next = NULL;
	return (out);
}

t_ssize	list_add_last(t_list **src, void *data)
{
	t_list	*ptr;

	ptr = *src;
	if (*src == NULL)
	{
		*src = list_new(data);
		if (*src == NULL)
			return (CR_FAIL);
	}
	else
	{
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = list_new(data);
	}
	return (CR_SUCCESS);
}

t_ssize	list_add_first(t_list **src, void *data)
{
	t_list	*ptr;

	ptr = list_new(data);
	if (!ptr)
		return (CR_FAIL);
	ptr->next = *src;
	*src = ptr;
	return (CR_SUCCESS);
}

void	list_iter(t_list *src, void (*f)(void **data))
{
	while (src)
	{
		f(&src->data);
		src = src->next;
	}
}

void	*list_get_last(t_list *src)
{
	if (!src->next)
		return (src->data);
	return (list_get_last(src->next));
}

void	*list_get_first(t_list *src)
{
	return (src->data);
}

void lprint(void **data)
{
	print("%s\n", *data);
}

/* See https:// www.geeksforgeeks.org/?p=3622 for details of this
function */
t_list	*list_sort_merge(t_list *a, t_list *b, t_ssize (*f)(void *, void *))
{
    t_list	*result = NULL;
 
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);
    if (f(a->data, b->data) > 0)
	{
        result = a;
        result->next = list_sort_merge(a->next, b, f);
    }
    else
	{
        result = b;
        result->next = list_sort_merge(a, b->next, f);
    }
    return (result);
}
 
void list_sort_split(t_list *src, t_list **a, t_list **b)
{
    t_list *fast;
    t_list *slow;
    
	slow = src;
    fast = src->next;
    while (fast != NULL)
	{
        fast = fast->next;
        if (fast != NULL)
		{
            slow = slow->next;
            fast = fast->next;
        }
    } 
    *a = src;
    *b = slow->next;
    slow->next = NULL;
}

void list_sort(t_list **src, t_ssize (*f)(void *, void *))
{
    t_list *head = *src;
    t_list *a;
    t_list *b;
 
    if ((head == NULL) || (head->next == NULL))
        return ;
 
    list_sort_split(head, &a, &b);
    list_sort(&a, f);
    list_sort(&b, f);
    *src = list_sort_merge(a, b, f);
}

t_ssize	cmp(void *a, void *b)
{
	return (s_cmp(a, b));
}

int	main(void)
{
	char *str = "FIRST NODE";
	char *str2 = "SECOND NODE";
	char *str3 = "THIRD NODE";
	t_list	*lst;

	lst = NULL;
	list_add_last(&lst, str);
	list_add_last(&lst, str2);
	list_add_first(&lst, str3);
	/*char *ret = list_get_first(lst);*/
	/*print("%s\n", ret);*/
	list_sort(&lst, cmp);
	list_iter(lst, lprint);
}
