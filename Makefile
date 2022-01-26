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

INC = -Iincludes/ -Ilibft/includes/

PS_DIR = src/push_swap
CHK_DIR = src/checker
CMN_DIR = src/common

OBJ_DIR = objs
PS_O_DIR = $(OBJ_DIR)/push_swap
CHK_O_DIR = $(OBJ_DIR)/checker
CMN_O_DIR = $(OBJ_DIR)/common

PS_OBJ = $(addprefix $(PS_O_DIR)/,$(PUSH_SWAP_SRC:.c=.o))
CHK_OBJ = $(addprefix $(CHK_O_DIR)/,$(CHECKER_SRC:.c=.o))
CMN_OBJ = $(addprefix $(CMN_O_DIR)/,$(COMMON_SRC:.c=.o))

LIBFT_DIR = libft
LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(PS_OBJ) $(CHK_OBJ) $(CMN_OBJ)
	@$(CC) $(FLAGS) -o push_swap $(PS_OBJ) $(CMN_OBJ) $(LIBFT)
	@$(CC) $(FLAGS) -o checker $(CHK_OBJ) $(CMN_OBJ) $(LIBFT)

$(LIBFT):
	@make --no-print-directory -C $(LIBFT_DIR)

$(PS_O_DIR)/%.o: $(PS_DIR)/%.c
	@mkdir -p $(PS_O_DIR)
	@$(CC) $(FLAGS) $(INC) -o $@ -c $<

$(CHK_O_DIR)/%.o: $(CHK_DIR)/%.c
	@mkdir -p $(CHK_O_DIR)
	@$(CC) $(FLAGS) $(INC) -o $@ -c $<

$(CMN_O_DIR)/%.o: $(CMN_DIR)/%.c
	@mkdir -p $(CMN_O_DIR)
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