NAME = lem_in

OBJ_DIR = obj
SRC_DIR = src
DEP_DIR = .deps
CORE_DIR = core

CORE = $(CORE_DIR)/libcore.a

SRC = $(addprefix src/, \
	main.c \
	parse_input.c \
	parse_line.c \
	parse_room.c \
	parse_link.c \
	parse_utils.c \
	lem_transform_vertex_disjoint.c \
	print_utils.c \
	graph_utils.c \
	max_flow_edmonds_karp.c \
	save_max_flow_paths.c \
	optimise_path_use.c \
	move_ants.c \
)

OBJ = $(subst $(SRC_DIR), $(OBJ_DIR), $(SRC:.c=.o))

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror #-fsanitize=address
#CFLAGS = -g -Wall -Wextra -Werror -Wpedantic -Wtype-limits -Wunused \
                -Wunreachable-code -Wshadow -fPIC -Wconversion
CPPFLAGS = -I . -I core
LDLIBS = -lcore -lm
LDFLAGS = -L core #-fsanitize=address
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEP_DIR)/$*.d
COMPILE.c = $(CC) $(DEPFLAGS) $(CFLAGS) $(CPPFLAGS) -c

.PHONY: all re clean fclean

all: $(NAME)

$(NAME): $(CORE) $(OBJ)
	@echo "Link $@"
	@$(CC) $(CFLAGS) -o $@ $(OBJ) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(DEP_DIR) $(OBJ_DIR)
	@echo "Compile $<"
	@$(COMPILE.c) -o $@ $<

$(DEP_DIR): ; @mkdir -p $@

$(OBJ_DIR): ; @mkdir -p $@

$(CORE): $(CORE_DIR)
	@$(MAKE) -C core

DEPFILES = $(subst $(SRC_DIR), $(DEP_DIR), $(SRC:.c=.d))
$(DEPFILES):

clean:
	@rm -rf $(OBJ_DIR) $(DEP_DIR)
	@$(MAKE) -C core clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C core fclean

re: fclean all

include $(wildcard $(DEPFILES))
