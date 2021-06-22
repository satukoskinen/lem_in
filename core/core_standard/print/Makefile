NAME = libprint.a

OBJ_DIR = obj
SRC_DIR = src
DEP_DIR = .deps

MATH_SRC = $(addprefix sub/, \
	_dpow.c \
	_abs.c \
	_fabs.c \
	_modf.c \
	_uintmax_pow.c \
)

MEM_SRC = $(addprefix sub/, \
	_realloc.c \
)

STR_SRC = $(addprefix sub/, \
	_atoi.c \
	_intmax_itoa_base.c \
	_uintmax_itoa_base.c \
)

OTHER_SRC = $(addprefix sub/, \
	_vasprint.c \
	_get_conversion_specs.c \
	_conv_char.c \
	_conv_double.c \
	_conv_pointer.c \
	_conv_int.c \
	_conv_uint.c \
	parse_helpers.c \
	_parse.c \
	_dtoa.c \
	_round_double.c \
	_rounds_half_to_even.c \
	_failure.c \
)

PRINT_SRC = \
	print.c \
	print_file.c \
	print_fd.c \
	format.c

SRC = $(addprefix src/, \
	$(MATH_SRC) \
	$(MEM_SRC) \
	$(STR_SRC) \
	$(OTHER_SRC) \
	$(PRINT_SRC) \
)

CC = gcc
CFLAGS = -O3 -Wall -Wextra -Werror  #-fsanitize=address
CPPFLAGS = -I . -I ../inc -I inc
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEP_DIR)/$*.d
COMPILE.c = $(CC) $(DEPFLAGS) $(CFLAGS) $(CPPFLAGS) -c

.PHONY: all re clean fclean

all: $(NAME)

$(NAME): $(subst $(SRC_DIR), $(OBJ_DIR), $(SRC:.c=.o))
	@echo "\\n\033[32;1mPRINT FUNCTIONS COMPILED\033[0m \\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/sub/%.c | $(OBJ_DIR) $(DEP_DIR)
	@$(COMPILE.c) -o $@ $<

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR) $(DEP_DIR)
	@$(COMPILE.c) -o $@ $<
	@echo $@

$(OBJ_DIR): ; @mkdir -p $@/sub

$(DEP_DIR): ; @mkdir -p $@/sub

DEPFILES = $(addprefix $(DEP_DIR)/, $(SRC:.c=.d))
$(DEPFILES):

clean:
	@rm -rf $(OBJ_DIR) $(DEP_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

include $(wildcard $(DEPFILES))
