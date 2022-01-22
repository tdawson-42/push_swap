NAME = push_swap

CC = gcc
FLAGS = -Wall -Werror -Wextra

PUSH_SWAP_SRC = push_swap.c \
				lis.c \
				shortest_path.c

CHECKER_SRC = checker.c

COMMON_SRC = error_check.c \
			print.c \
			stack_operations.c \
			stack_utils.c \
			utils.c

SRC = $(PUSH_SWAP_SRC) $(CHECKER_SRC) $(COMMON_SRC)

INC = -Ilibft/includes/

OBJ_DIR = objs
PUSH_SWAP_OBJ = $(addprefix $(OBJ_DIR)/,$(PUSH_SWAP_SRC:.c=.o))
CHECKER_OBJ = $(addprefix $(OBJ_DIR)/,$(CHECKER_SRC:.c=.o))
COMMON_OBJ = $(addprefix $(OBJ_DIR)/,$(COMMON_SRC:.c=.o))
OBJ = $(PUSH_SWAP_OBJ) $(CHECKER_OBJ) $(COMMON_OBJ)

LIBFT_DIR = libft
LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJ)
	@$(CC) $(FLAGS) -o push_swap $(PUSH_SWAP_OBJ) $(COMMON_OBJ) $(LIBFT)
	@$(CC) $(FLAGS) -o checker $(CHECKER_OBJ) $(COMMON_OBJ) $(LIBFT)

$(LIBFT):
	@make --no-print-directory -C $(LIBFT_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c
	@$(CC) $(FLAGS) $(INC) -o $@ -c $<

clean:
	@make clean --no-print-directory -C $(LIBFT_DIR)
	@/bin/rm -rf $(OBJ_DIR)

fclean: clean
	@make fclean --no-print-directory -C $(LIBFT_DIR)
	@/bin/rm -f checker
	@/bin/rm -f push_swap

re: fclean all

.PHONY: all clear fclean re