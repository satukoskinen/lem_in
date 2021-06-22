
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/01 00:14:29 by jkoskela          #+#    #+#              #
#    Updated: 2021/03/18 02:30:56 by julius           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libcstr.a

CC			=	gcc
FLAGS 		=	-O3 -Wall -Wextra -Werror -fPIC

SRC_DIR		=	src/
INC_DIR		=	inc/
OBJ_DIR		=	obj/


SRC_BASE	=	s_appendc.c \
				s_cat.c \
				s_cdup.c \
				s_chr.c \
				s_clr.c \
				s_cmp.c \
				s_copy.c \
				s_cpy.c \
				s_csub.c \
				s_ctoc.c \
				s_cut.c \
				s_del.c \
				s_dup.c \
				s_equ.c \
				s_fill.c \
				s_find_first.c \
				s_iter.c \
				s_iteri.c \
				s_join.c \
				s_join_free.c \
				s_lcat.c \
				s_lcpy.c \
				s_len.c \
				s_lenc.c \
				s_map.c \
				s_mapi.c \
				s_ncat.c \
				s_ncmp.c \
				s_ncpy.c \
				s_ndup.c \
				s_nequ.c \
				s_new.c \
				s_newc.c \
				s_nstr.c \
				s_rchr.c \
				s_rev.c \
				s_split.c \
				s_str.c \
				s_sub.c \
				s_sum.c \
				s_swp.c \
				s_trim.c \
				s_readline.c \
				s_toi.c \

SRC			=	$(addprefix $(SRC_DIR), $(SRC_BASE))
OBJ			=	$(addprefix $(OBJ_DIR), $(SRC_BASE:.c=.o))
DIR			=	$(sort $(dir $(OBJ)))

all:
				@$(MAKE) -j $(NAME)

$(NAME): $(OBJ) Makefile

				@echo "\\n\033[32;1mCSTRING FUNCTIONS COMPILED\033[0m \\n"

$(DIR):
				@mkdir -p $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.c Makefile | $(DIR)
				@$(CC) $(FLAGS) -c $< -o $@ -I $(INC_DIR)
				@echo $@

clean:
				@rm -rf $(OBJ_DIR);


fclean: clean
				@rm -rf $(NAME);

re: fclean
				@$(MAKE) -j $(NAME)

.PHONY: fclean clean re
