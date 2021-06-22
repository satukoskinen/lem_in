###############################################################################
#
#	Makefile
#
###############################################################################

NAME		=	libgraph.a

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

SRC_BASE	=	parr_add.c \
				parr_add_first.c \
				parr_add_last.c \
				parr_add_mult.c \
				parr_new.c \
				parr_assign.c \
				parr_free.c \
				parr_del.c \
				parr_del_first.c \
				parr_del_last.c \
				parr_get.c \
				parr_get_first.c \
				parr_get_last.c \
				parr_iter.c \
				parr_join.c \
				parr_read_file.c \
				parr_write_file.c \
				parr_split.c \
				parr_take.c \
				parr_take_first.c \
				parr_take_last.c \
				parr_search.c \
				parr_find.c \
				parr_parse.c \
				parr_write.c \
				parr_null.c \
				parr_grow.c \
				parr_copy.c \
				parr_dup.c \
				parr_rotate.c \

SRC			=	$(addprefix $(SRC_DIR), $(SRC_BASE))
OBJ			=	$(addprefix $(OBJ_DIR), $(SRC_BASE:.c=.o))

all:
				@$(MAKE) -j $(NAME)

$(NAME): $(OBJ)

				@echo "\\n\033[32;1mPARRAY FUNCTIONS COMPILED\033[0m \\n"

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