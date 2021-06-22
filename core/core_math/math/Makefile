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

SRC_BASE	=	math_abs.c \
				math_ceil.c \
				math_cos.c \
				math_dcnt.c \
				math_dgr.c \
				math_fabs.c \
				math_fac.c \
				math_flabs.c \
				math_floor.c \
				math_fsign.c \
				math_intlen.c \
				math_ipow.c \
				math_log.c \
				math_modf.c \
				math_modl.c \
				math_nextprime.c \
				math_pow.c \
				math_prime.c \
				math_primefac.c \
				math_rad.c \
				math_roundl.c \
				math_sign.c \
				math_sin.c \
				math_sqrt.c \

SRC			=	$(addprefix $(SRC_DIR), $(SRC_BASE))
OBJ			=	$(addprefix $(OBJ_DIR), $(SRC_BASE:.c=.o))

all:
				@$(MAKE) -j $(NAME)

$(NAME): $(OBJ)

				@echo "\\n\033[32;1mMATH FUNCTIONS COMPILED\033[0m \\n"

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