NAME    =   push_swap
# Paths
SRC_DIR = src
INCLUDE_DIR = includes
LIBFT_DIR = libft
OBJ_DIR = obj
# Libft
LIBFT   =   $(LIBFT_DIR)/libft.a
LIBFT_INCLUDE   = -I$(LIBFT_DIR)/include
# Source files
SRC     =   $(SRC_DIR)/main.c\
            $(SRC_DIR)/push_swap.c\
            $(SRC_DIR)/stack_manager.c\
            $(SRC_DIR)/init.c\
            $(SRC_DIR)/push_swap_utils.c\
            $(SRC_DIR)/arg_check.c\
            $(SRC_DIR)/stack_moves.c\
            $(SRC_DIR)/algorithm_utils.c\
            $(SRC_DIR)/ranks.c
# Objects
OBJ     =   $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
# Compiling rules
CC      =   cc
CFLAGS  =   -Wall -Wextra -Werror
# Includes
INCLUDES = -I$(INCLUDE_DIR) $(LIBFT_INCLUDE)
# Building commands:
all: $(NAME)
$(NAME): $(OBJ) $(LIBFT)
    $(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LIBFT) -o $(NAME)
$(LIBFT):
    @$(MAKE) -C $(LIBFT_DIR)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
    $(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
$(OBJ_DIR):
    mkdir -p $(OBJ_DIR)
clean:
    rm -f $(OBJ)
    @$(MAKE) -C $(LIBFT_DIR) clean
fclean: clean
    rm -f $(NAME)
    @$(MAKE) -C $(LIBFT_DIR) fclean
re: fclean all
.PHONY: all clean fclean re