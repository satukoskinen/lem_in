#ifndef TYPES_H
# define TYPES_H

///////////////////////////////////////////////////////////////////////////////
///
/// \brief Typedefs for the core library.
///
/// \authors Julius Koskela
///
///////////////////////////////////////////////////////////////////////////////

# include <string.h>
# include <unistd.h>

/// Standard redef ////////////////////////////////////////////////////////////

typedef unsigned char		t_byte;
typedef unsigned long long	t_size;
typedef long long			t_ssize;
typedef signed char			t_int8;
typedef short int			t_int16;
typedef int					t_int32;
typedef long long int		t_int64;
typedef unsigned char		t_uint8;
typedef unsigned short int	t_uint16;
typedef unsigned int		t_uint32;
typedef unsigned long long	t_uint64;

/// Boolean ///////////////////////////////////////////////////////////////////

typedef enum e_bool
{
	FALSE,
	TRUE
}				t_bool;

/// Memory ////////////////////////////////////////////////////////////////////

typedef struct s_raw
{
	t_byte		*data;
	t_size		size;
}				t_raw;

typedef t_raw				t_hraw;

/// Array /////////////////////////////////////////////////////////////////////

typedef struct s_array
{
	t_raw		raw;
	t_size		len;
	t_size		elem_size;
}				t_array;

/// Pointer Array /////////////////////////////////////////////////////////////

typedef struct s_parray
{
	void		**data;
	t_size		len;
	t_size		size;
}				t_parray;

/// String ////////////////////////////////////////////////////////////////////

typedef struct s_str
{
	t_raw	raw;
	t_size	len;
}				t_str;

typedef t_hraw				t_hstr;

typedef t_array				t_page;

/// Map ///////////////////////////////////////////////////////////////////////

typedef struct s_map_node
{
	const char	*key;
	void		*data;
}				t_map_node;

typedef struct s_map
{
	t_map_node	*node;
	t_size		capacity;
	t_size		count;
	double		load_factor;
	t_uint64	(*hash)(const char *);
	t_uint64	(*probe)(t_uint64);
	t_uint64	(*resize)(t_uint64);
}				t_map;

/// Graph /////////////////////////////////////////////////////////////////////

typedef t_map				t_graph;
typedef t_parray			t_edges;
typedef t_parray			t_nodes;

typedef struct s_graph_node
{
	const char	*key;
	t_edges		in;
	t_edges		out;
	t_bool		valid;
	void		*attr;
}				t_graph_node;

typedef struct s_graph_edge
{
	t_graph_node	*u;
	t_graph_node	*v;
	t_bool			valid;
	void			*attr;
}					t_graph_edge;

/// Linear Algebra ////////////////////////////////////////////////////////////

typedef struct s_vec
{
	double		*v;
}				t_vec;

typedef struct s_vec4
{
	double		v[4];
}				t_vec4;

typedef struct s_vec3
{
	double		v[3];
}				t_vec3;

typedef struct s_vec2
{
	double		v[2];
}				t_vec2;

typedef struct s_mat
{
	double		*m;
}				t_mat;

typedef struct s_mat4
{
	double		m[16];
}				t_mat4;

typedef struct s_mat3
{
	double		m[9];
}				t_mat3;

typedef struct s_mat2
{
	double		m[4];
}				t_mat2;

typedef t_vec4				t_quat;

#endif
