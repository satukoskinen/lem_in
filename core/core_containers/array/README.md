# Dynamic Array

A multi-purpose dynamic array implementation for the C language.

A dynamic array is an array which grows automatically without the need to
explicitly reallocate and copy data over. This implementation provieds
functionality to create and manipulate a dynamic array in an efficient
manner. This implementation emulates the functionality of a C++ std::vector.

## Design

-   Dynamic resizing. Doubles the size of the array when maximum size
    is reached.
-   Datatype agnostic. When creating the array user specifies an element size
    for the array (preferrably using the sizeof operator).
-   Data is kept straight in memory for fast iteration. This is not a pointer
    array, all the data is in the array itself avoiding fragmentation.
-   Provides get and add methods, but also let's user typecast the arrays data
    portion and iterate it directly for maximum performance.

## Typedefs

```c

typedef struct s_array
{
    t_raw  raw;
    t_size len;
    t_size elem_size;
} t_array;

```

`raw` is a resizable memory container. `len` refers to the number of active
elements in the array. Each element is of size `elem_size` defined when creating
a new array.

```c
t_array a = arr_new(1, sizeof(int));
```

Above would create an array of length 1 of elemets the size of `int` (4 bytes).

## Functions

These are general descriptions about the functions in the library and their
intended usage. For a detailed description refer to the source-code file
of each function.

### General

```c
t_array     arr_new(t_size len, t_size elem_size);
t_ssize     arr_free(t_array *src);
t_ssize     arr_null(t_array *src);
```

`arr_new` is the only function that allocates memory that has to be freed by the
user. In case of an error a null array might be returned. To check if an array
is null, function `arr_null` can be used.

### Manipulating the Elements

```c

void        *arr_get(t_array *src, t_size index);
void        *arr_get_first(t_array *src);
void        *arr_get_last(t_array *src);
void        *arr_take(void *dst, t_array *src, t_size index);
void        *arr_take_first(void *dst, t_array *src);
void        *arr_take_last(void *dst, t_array *src);
t_ssize     arr_add(t_array *src, void *node, t_size index);
t_ssize     arr_add_first(t_array *src, void *node);
t_ssize     arr_add_last(t_array *src, void *node);
t_ssize     arr_add_mult(t_array *src, t_size count, ...);
t_ssize     arr_put(t_array *dst, void *src, t_size size);
t_ssize     arr_del(t_array *src, t_size index);
t_ssize     arr_del_first(t_array *src);
t_ssize     arr_del_last(t_array *src);
t_ssize     arr_find(t_array *src, void *key);
t_ssize     arr_search(t_array *src, t_array *key);
t_ssize     arr_copy(t_array *dst, t_array *src);
t_ssize     arr_join(t_array *dst, t_array *src);
t_ssize     arr_join_mult(t_array *dst, t_size count, ...);
t_ssize     arr_rotate(t_array *arr, t_ssize steps);

```

This group of functions is used to manipulate elements in the array. Find
differs from search such that find matches one element whereas search matches
all elements in the array `key`. Get means getting a pointer to an element,
whereas take gets the element and deletes it (called pop in some
implementations).

### Manipulating the Array

```c

void        arr_print(t_array *src, char *format);
t_ssize     arr_iter(t_array *src,
                t_ssize (*f)(void *, t_size));
t_ssize     arr_iter_range(t_array *src, t_size start, t_size end,
                t_ssize (*f)(void *, t_size));
t_ssize     arr_find_by(t_array *arr, const void *key,
                t_ssize (*f)(const void *, const void *));
t_ssize     arr_parse(t_array *dst, t_array *src,
                t_ssize (*f)(t_array *, void *));
void        arr_sort(t_array *src,
                t_ssize (*f)(void *, void *));
```

This group of functions is used to manipulte or iterate the array in various
ways. Also contains `arr_print` a printf style formatted printing for built-in
datatypes.

-------------------------------------------------------------------------------
