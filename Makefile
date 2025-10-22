
NAME        := push_swap
CC          := cc
CFLAGS      := -Wall -Wextra -Werror
RM          := rm -f
INCLUDES    := -Iincludes -Ift_printf
SRC_DIR     := src
OBJ_DIR     := obj
PRINTF_DIR  := ft_printf

PRINTF_LIB  := $(PRINTF_DIR)/libftprintf.a

SRCS := main.c \
        push_swap.c \
        ft_split.c \
        string_utils.c \
        error_handling.c \
        init_stack_a.c \
        init_nodes_a.c \
        init_nodes_b.c \
        push_operations.c \
        swap_operations.c \
        rotation_operations.c \
        reverse_rotation_operations.c \
        sort_stacks_turk.c \
        sort_three_stack.c \
        stack_utils.c \
        stack_utils_extra.c

SRC_FILES := $(addprefix $(SRC_DIR)/, $(SRCS))
OBJ_FILES := $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(PRINTF_LIB) $(OBJ_FILES)
	@$(CC) $(CFLAGS) $(OBJ_FILES) $(PRINTF_LIB) -o $(NAME)
	@echo "✅ push_swap compiled successfully!"

$(PRINTF_LIB):
	@$(MAKE) -C $(PRINTF_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@$(MAKE) -C $(PRINTF_DIR) clean
	@$(RM) -r $(OBJ_DIR)
	@echo "Object files cleaned."

fclean: clean
	@$(MAKE) -C $(PRINTF_DIR) fclean
	@$(RM) $(NAME)
	@echo "All cleaned, including executable."

re: fclean all

.PHONY: all clean fclean re
