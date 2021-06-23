###############################################################################
#
# \authors Satu Koskinen
#
# \brief Add a new element to the beginning of a dynamic array.
#
# If the array is not sufficiently big a new memory area double the
# alloc_size of the previous one is allocated.
#
# \param dst Destination array.
# \param elem Element to be added.
# \return 1 on success 0 on failure.
#
###############################################################################

NAME		=	libstr.a

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

SRC_BASE	=	hstr_assign.c \
				hstr_range.c \
				hstr_write.c \
				str_join.c \
				str_from_s.c \
				str_chr.c \
				str_cpy.c \
				str_ncpy.c \
				str_new.c \
				str_write.c \
				str_rev.c \
				str_free.c \
				str_toi.c \
				str_toi_base.c \
				str_tof.c \
				page_new.c \
				page_get.c \
				page_read_file.c \
				page_write_file.c \
				page_print.c \
				page_free.c \


SRC			=	$(addprefix $(SRC_DIR), $(SRC_BASE))
OBJ			=	$(addprefix $(OBJ_DIR), $(SRC_BASE:.c=.o))

all:
				@$(MAKE) -j $(NAME)

$(NAME): $(OBJ)

				@echo "\\n\033[32;1mSTRING FUNCTIONS COMPILED\033[0m \\n"

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
