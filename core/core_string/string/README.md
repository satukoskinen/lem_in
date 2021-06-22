# String

This string implementation provides an optional string handling workflow for
the C language. It is based on dynamic resizable strings which carry the
length of the string with them. With this approach we can gain significant
speed increases in certain areas at the expense of memory usage. It also
integrates with the core library memory tracking functionality.

Normally c-styled strings are char pointers that hold a string of bytes and
in the end a null terminator which effectively determines the size of the string.
This approach is very memory efficient and stems from a time when memory
was a bigger bottleneck than today. What we sacrifice is speed and
usability.

Positives:

-	With dynamically resizable memory blocks we gain much better performance
	when handling huge amounts of text in methods such as string joining

-	We never have to call strlen to determine the length of the string or
	create additional temporary variables for passing around lengths.

-	We can compare and copy strings much faster by calling rawcpy instead
	of iterating untill a null terminator.

-	We provide opaque string handlers which, when used correctly, can vastly
	decrease the amount of allocation in a program.

Negatives:

-	Will use more memory. Length information is saved in the string struct itself
	and allocations are dynamic, so one string will use up more memory.

-	Will allocate memory when used with string literals.

-	For very basic use can be more convoluted and add complexity.

There are many alterantive approcahes for making convenient modern strings for
C, such as saving the length in the string itself before the start, tracking space
reserves when pre-allocated data is assigned etc. In this library however we
wanted to take the most explicit and easy to understand approach in our opinion,
which doesn't try to do everything but rather improve on certain specific domains.

## Strings

The string struct consists of a resizable memory block `raw`
and a length `len`. A string is stored in `raw` and is NULL terminated.
The memory block migth have a bigger size, but `len` represents the
active bytes in the string.

```c

typedef struct	s_str
{
	t_raw	raw;
	t_size	len;
}				t_str;

```

## String handle

```c

typedef t_hraw	t_hstr;

```

## Page