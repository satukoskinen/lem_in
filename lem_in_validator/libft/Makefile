NAME = libft.a

OBJ_DIR = obj
SRC_DIRS = array list math mem get_next_line printf/src puts str
DEP_DIR = .deps

ARR_SRC = $(addprefix array/, \
	array_add.c \
	array_del.c \
	array_get.c \
	array_indexof.c \
	array_insert.c \
	array_is_empty.c \
	array_new.c \
	array_remove.c \
	array_size.c \
)

LIST_SRC = $(addprefix list/, \
	ft_lstadd.c \
	ft_lstdel.c \
	ft_lstdelone.c \
	ft_lstiter.c \
	ft_lstmap.c \
	ft_lstnew.c \
	ft_lstpushback.c \
	ft_lstsize.c \
)

MATH_SRC = $(addprefix math/, \
	ft_abs.c \
	ft_dpow.c \
	ft_fabs.c \
	ft_isnan.c \
	ft_isnegative.c \
	ft_isneginf.c \
	ft_isposinf.c \
	ft_modf.c \
	ft_power.c \
	ft_uintmax_pow.c \
	ft_atoi.c \
	ft_atoll.c \
	ft_atoi_base.c \
	ft_sqrt.c \
)

MEM_SRC = $(addprefix mem/, \
	ft_bzero.c \
	ft_calloc.c \
	ft_memalloc.c \
	ft_memccpy.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memdel.c \
	ft_memmove.c \
	ft_memset.c \
	ft_realloc.c \
)

PUTS_SRC = $(addprefix puts/, \
	ft_putchar_fd.c \
	ft_putchar.c \
	ft_putnbr_fd.c \
	ft_putnbr.c \
	ft_putstr_fd.c \
	ft_putstr.c \
)

STR_SRC = $(addprefix str/, \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_isspace.c \
	ft_strcat.c \
	ft_strchr.c \
	ft_strcmp.c \
	ft_strcpy.c \
	ft_strdel.c \
	ft_strdup.c \
	ft_striter.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strlen.c \
	ft_strncat.c \
	ft_strncmp.c \
	ft_strncpy.c \
	ft_strnew.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strsplit.c \
	ft_strstr.c \
	ft_strsub.c \
	ft_strtrim.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_intmax_itoa_base.c \
	ft_uintmax_itoa_base.c \
	ft_itoa_base.c \
	ft_itoa.c \
)

GNL_SRC = $(addprefix get_next_line/, \
	get_next_line.c \
	remainder.c \
)

PRINTF_SRC = $(addprefix printf/src/, \
	ft_asprintf.c \
	ft_dprintf.c \
	ft_printf.c \
	ft_vasprintf.c \
	conversion_specs.c \
	dtoa.c \
	parse_chars.c \
	parse_doubles.c \
	parse_pointers.c \
	parse_signed_integers.c \
	parse_unsigned_integers.c \
	parse_helpers.c \
	parser.c \
	round_double.c \
)

SRC = $(ARR_SRC) \
	$(LIST_SRC) \
	$(MATH_SRC) \
	$(MEM_SRC) \
	$(STR_SRC) \
	$(PUTS_SRC) \
	$(GNL_SRC) \
	$(PRINTF_SRC)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address
CPPFLAGS = -I . -I printf -I array -I get_next_line
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEP_DIR)/$*.d
COMPILE.c = $(CC) $(DEPFLAGS) $(CFLAGS) $(CPPFLAGS) -c

.PHONY: all re clean fclean

all: $(NAME)

$(NAME): $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
	@echo "Create $@"
	@ar rc $@ $^

$(OBJ_DIR)/%.o: %.c $(DEP_DIR)/%.d | $(DEP_DIR) $(OBJ_DIR)
	@echo "Compile $<"
	@$(COMPILE.c) -o $@ $<

$(DEP_DIR): ; @mkdir -p $(addprefix $@/, $(SRC_DIRS))

$(OBJ_DIR): ; @mkdir -p $(addprefix $@/, $(SRC_DIRS))

DEPFILES = $(addprefix $(DEP_DIR)/, $(SRC:.c=.d))
$(DEPFILES):

clean:
	@rm -rf $(OBJ_DIR) $(DEP_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

include $(wildcard $(DEPFILES))