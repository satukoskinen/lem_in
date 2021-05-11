NAME = lem_in

OBJ_DIR = obj
SRC_DIR = src
DEP_DIR = .deps
CORE_DIR = core

CORE = $(CORE_DIR)/libcore.a

SRC = $(addprefix src/, \
	main.c \
	lem_parse_input.c \
	lem_parse_line.c \
	lem_parse_room.c \
	lem_parse_link.c \
	lem_parse_utils.c \
	lem_transform_vertex_disjoint.c \
	lem_init_graph.c \
	lem_init_edge_attributes.c \
	lem_init_node_attributes.c \
	lem_find_node.c \
	lem_compare_nodes.c \
	lem_get_edge.c \
	lem_edge_remaining_capacity.c \
	lem_process_graph.c \
	lem_find_max_flow_paths.c \
	lem_save_max_flow_paths.c \
	lem_optimise_path_use.c \
	lem_move_ants.c \
	lem_print_ants_per_path.c \
	lem_print_edge.c \
	lem_print_node.c \
	lem_print_path_combinations.c \
	lem_print_path.c \
	lem_print_string.c \
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
