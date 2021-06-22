/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parr_usage.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/23 21:26:54 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/core.h"

//-----------------------------------------------------------------------------
// An example user type which has a mix of different type of data including
// pointers so that direct copying of the struct by size won't work since only
// the string pointers would be duplicated, but not the contents which can vary
// in size.

typedef struct	s_person
{
	char		*firstname;
	char		*lastname;
	int			age;
}				t_person;

//-----------------------------------------------------------------------------
// These are printing functions for the different kinds of data we might be
// printing. We pass these functions into the parr_iter function which iterates
// over the array and executes the function on each array rawber. We return the
// iterator, but we could also return -1 or CR_STOP to CR_STOP the loop.

int				print_string(void **data, t_size i)
{
	char		*ptr;

	ptr = *data;
	if (ptr)
		printf("[%zu] %s\n", i, ptr);
	else
		printf("\nNULL\n");
	return (i);
}

int				print_person(void **data, t_size i)
{
	t_person	*ptr;

	ptr = *data;
	if (ptr)
		printf("[%zu] %-10s	%-10s	%d\n", i, ptr->firstname, ptr->lastname, ptr->age);
	else
		printf("Person not found!\n");
	return (i);
}

//-----------------------------------------------------------------------------
// These are different search functions we could use. These functions can be
// used with the parr_search function by passing them as a parameter. CR_search will
// pass the key value passed as a parameter into parr_search, into the user defined
// function in which it can be used to match some data in the rawber value
// passed as a parameter. The function will iterate the whole array and put any
// pointer returned from the function into the destination array.

void			*match_lastname(void *key, void *val)
{
	char		*key_cast;
	t_person	*val_cast;

	key_cast = key;
	val_cast = val;
	if (s_cmp(val_cast->lastname, key_cast) == 0)
		return ((void *)val_cast);
	return (NULL);
}

void			*match_firstname(void *key, void *val)
{
	char		*key_cast;
	t_person	*val_cast;

	key_cast = key;
	val_cast = val;
	if (s_cmp(val_cast->firstname, key_cast) == 0)
		return ((void *)val_cast);
	return (NULL);
}

//-----------------------------------------------------------------------------
// This is an example of a parse function. The parr_parse function passes the
// destination array and a rawber from the source array. User can define how
// that data is parsed and add that data into the destination array on each
// iteration. User can return CR_STOP or -1 to indicate the loop should CR_STOP.

int				deserialize(t_parray *dst, void *data)
{
	t_person	*person;
	char		**words;

	if (!(person = (t_person *)malloc(sizeof(t_person))))
		return (CR_STOP);
	words = s_split((char *)data, ',');
	person->firstname = words[0];
	person->lastname = words[1];
	person->age = atoi(words[2]);
	free(words[2]);
	free(words);
	parr_add_last(dst, person);
	return (CR_CONTINUE);
}

//-----------------------------------------------------------------------------
// Here are examples of deallocators. these would be passed into parr_iterate.

int				deallocate_string(void **rawber, t_size i)
{
	char		*str;

	printf("[%zu] String deallocated!\n", i);
	str = *rawber;
	free(str);
	return (i);
}

int				deallocate_person(void **rawber, t_size i)
{
	t_person	*person;

	if (!*rawber)
		return (CR_STOP);
	person = *rawber;
	printf("[%zu] Person deallocated!\n", i);
	free(person->firstname);
	free(person->lastname);
	free(person);
	return (i);
}

//-----------------------------------------------------------------------------
// This is an example of a function we'd pass into the write function. We can
// use this to duplicate or write data in different manners from src to dst on
// each iteration.

int				serialize(void **dst, void *src)
{
	char		*dst_cast;
	t_person	*src_cast;

	src_cast = src;
	dst_cast = malloc(sizeof(char) * 100);
	sprintf(dst_cast, "%s,%s,%d", src_cast->firstname, src_cast->lastname, src_cast->age);
	*dst = dst_cast;
	return (CR_CONTINUE);
}

//-----------------------------------------------------------------------------
// Main method

int				main(int argc, char **argv)
{
	t_parray		source;
	t_parray		people;
	t_parray		results;
	t_parray		duplicate;

	if (argc != 3)
		return (-1);

	// Allocate arrays
	source = parr(1);
	people = parr(1);
	results = parr(1);
	duplicate = parr(1);

	// Read a file to source array
	parr_read_file(&source, argv[1]);
	parr_rotate(&source, -1);
	parr_iterate(&source, print_string);

	// Parse source array
	parr_parse(&people, &source, deserialize);

	// Search from parsed array (returns a list of all results)
	parr_search(&results, &people, "Skywalker", match_lastname);

	// Duplicate results array
	parr_write(&duplicate, &results, serialize);

	// Write array to a file. We can use CR_APPEND, CR_PREPEND or CR_WRITE flags to
	// signify where in the file we want to write. As the last parameter we
	// could pass a function pointer or the CR_STRING macro to indicate we want
	// the function to interpet each rawber as a string.
	parr_write_file(argv[2], &duplicate, CR_WRITE, CR_STRING);

	// Deallocate allocated array rawbers
	parr_iterate(&source, deallocate_string);
	parr_iterate(&people, deallocate_person);
	parr_iterate(&duplicate, deallocate_string);

	// Deallocate arrays
	parr_free(&source);
	parr_free(&people);
	parr_free(&results);
	parr_free(&duplicate);
}
