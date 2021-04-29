NAME = lem_in

OBJ_DIR = obj
SRC_DIR = src
SRC_SUBDIRS = graph
DEP_DIR = .deps
LIBFT_DIR = libft

LIBFT = $(LIBFT_DIR)/libft.a

GRAPH_SRC = $(addprefix src/graph/, \
	graph_new.c \
	graph_add_vertex.c \
	graph_add_edge.c \
	graph_del.c \
	graph_print.c \
	graph_get_edge.c \
	graph_get_vertex.c \
)

SRC = $(GRAPH_SRC) $(addprefix src/, \
	main.c \
	parse_input.c \
	parse_line.c \
	process_graph.c \
	get_shortest_paths.c \
	get_max_flow_paths.c \
	find_shortest_path.c \
	find_all_simple_paths.c \
	max_flow_edmonds_karp.c \
	optimize_path_use.c \
	move_ants.c \
	path_helpers.c \
	get_path_combinations.c \
)

OBJ = $(subst $(SRC_DIR), $(OBJ_DIR), $(SRC:.c=.o))

CC = gcc
#CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
CFLAGS = -Wall -Wextra -Werror -Wpedantic -Wtype-limits \
                -Wunreachable-code -Wpadded -Wshadow -fPIC -Wconversion
CPPFLAGS = -I . -I src -I src/graph -I libft -I libft/array
LDLIBS = -lft
LDFLAGS = -L libft -fsanitize=address
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEP_DIR)/$*.d
COMPILE.c = $(CC) $(DEPFLAGS) $(CFLAGS) $(CPPFLAGS) -c

.PHONY: all re clean fclean

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@echo "Link $@"
	@$(CC) $(CFLAGS) -o $@ $(OBJ) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(DEP_DIR) $(OBJ_DIR)
	@echo "Compile $<"
	@$(COMPILE.c) -o $@ $<

$(DEP_DIR): ; @mkdir -p $(addprefix $@/, $(SRC_SUBDIRS))

$(OBJ_DIR): ; @mkdir -p $(addprefix $@/, $(SRC_SUBDIRS))

$(LIBFT): $(LIBFT_DIR)
	@$(MAKE) -C libft

DEPFILES = $(subst $(SRC_DIR), $(DEP_DIR), $(SRC:.c=.d))
$(DEPFILES):

clean:
	@rm -rf $(OBJ_DIR) $(DEP_DIR)
	@$(MAKE) -C libft clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C libft fclean

re: fclean all

include $(wildcard $(DEPFILES))