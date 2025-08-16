.SILENT:

NAME		= parser

SRC_DIR		= src
OBJ_DIR		= obj
INC_DIR		= include

SRCS		= main.c \
			  $(SRC_DIR)/ft_atoi.c \
			  $(SRC_DIR)/ft_itoa.c \
			  $(SRC_DIR)/ft_strchr.c \
			  $(SRC_DIR)/ft_strcmp.c \
			  $(SRC_DIR)/ft_strlen.c \
			  $(SRC_DIR)/ft_strncpy.c \
			  $(SRC_DIR)/key_value.c \
			  $(SRC_DIR)/num_writer.c \
			  $(SRC_DIR)/parser.c \
			  $(SRC_DIR)/writer.c

OBJS		= $(SRCS:%.c=$(OBJ_DIR)/%.o)

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
INCLUDES	= -I$(INC_DIR)

GREEN		= \033[0;32m
RED			= \033[0;31m
BLUE		= \033[0;34m
NC			= \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	echo "$(GREEN)✓ $(NAME) compiled successfully$(NC)"

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	echo "$(BLUE)Compiling: $<$(NC)"

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)/$(SRC_DIR)

clean:
	rm -rf $(OBJ_DIR)
	echo "$(RED)Object files cleaned$(NC)"

fclean: clean
	rm -f $(NAME)
	echo "$(RED)$(NAME) removed$(NC)"

re: fclean all

.PHONY: all clean fclean re

$(OBJS): | $(OBJ_DIR)