###############################################################################
#
#	Makefile
#
###############################################################################

NAME		=	libarr.a

SRC_DIR		=	src/
INC_DIR		=	inc/
OBJ_DIR		=	obj/
DEP_DIR		=	.deps/

CC			=	gcc
CFLAGS 		=	-O3 -Wall -Wextra -Werror -fPIC
DFLAGS		=	-Wunreachable-code -Wconversion -Wpedantic -Wtype-limits
CPPFLAGS	=	-I $(INC_DIR)
DEPFLAGS	=	-MT $@ -MMD -MP -MF $(DEP_DIR)$*.d
COMPILE.c	=	$(CC) $(DEPFLAGS) $(CFLAGS) $(CPPFLAGS) -c

SRC_BASE	=	arr_add.c \
				arr_add_first.c \
				arr_add_last.c \
				arr_add_mult.c \
				arr_new.c \
				arr_put.c \
				arr_free.c \
				arr_del.c \
				arr_del_first.c \
				arr_del_last.c \
				arr_get.c \
				arr_get_first.c \
				arr_get_last.c \
				arr_iter.c \
				arr_iter_range.c \
				arr_join.c \
				arr_join_mult.c \
				arr_take.c \
				arr_take_first.c \
				arr_take_last.c \
				arr_search.c \
				arr_find.c \
				arr_find_by.c \
				arr_parse.c \
				arr_null.c \
				arr_copy.c \
				arr_rotate.c \
				arr_print.c \
				arr_sort.c \

SRC			=	$(addprefix $(SRC_DIR), $(SRC_BASE))
OBJ			=	$(addprefix $(OBJ_DIR), $(SRC_BASE:.c=.o))

all:
				@$(MAKE) -j $(NAME)

$(NAME): $(OBJ)

				@echo "\\n\033[32;1mARRAY FUNCTIONS COMPILED\033[0m \\n"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(DEP_DIR)%.d | $(OBJ_DIR) $(DEP_DIR)
				@$(COMPILE.c) $< -o $@
				@echo $@

$(OBJ_DIR):
				@mkdir -p $@

$(DEP_DIR):
				@mkdir -p $@

DEPFILES = $(addprefix $(DEP_DIR), $(SRC_BASE:.c=.d))
$(DEPFILES):

clean:
				@rm -rf $(OBJ_DIR) $(DEP_DIR)

fclean: clean
				@rm -rf $(NAME);

re: fclean all

.PHONY: all fclean clean re

include $(wildcard $(DEPFILES))
