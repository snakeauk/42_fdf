NAME		=	test
BONUS		=	bonus

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf

LIBFT		=	libft
LIBFT_A		=	$(LIBFT).a
LIBFT_DIR	=	./$(LIBFT)

MLX			=	minilibx

SRCS_DIR	=	./srcs
SRCS		=	$(wildcard $(SRCS_DIR)/*.c)
OBJS		=	$(SRCS:.c=.o)

BONUS_DIR	=	./srcs/test_bonus
BONUS_SRCS	=	$(wildcard $(SRCS_DIR)/*.c $(BONUS_DIR)/*.c)
BONUS_OBJS	=	$(BONUS_SRCS:.c=.o)


UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Darwin)
	OS_DIR		=	$(LIBFT_DIR)/mac
	MLX_DIR		=	$(MLX)
	MLX_A		=	$(MLX_DIR)/libmlx.a
else
	OS_DIR		=	$(LIBFT_DIR)/linux
	MLX_DIR		=	$(MLX)-linux
	MLX_A		=	$(MLX_DIR)/libmlx_Linux.a
endif

INCLUDES	=	-I ./includes -I $(LIBFT_DIR)/includes -I $(OS_DIR)/includes -I $(MLX_DIR)
MLX_INCLUDES=	-lXext -lXext -lX11 -lm -lz

RESET		=	\033[0m
BOLD		=	\033[1m
DIM			=	\033[2m
UNDERLINE	=	\033[4m
BLINK		=	\033[5m
INVERT		=	\033[7m
LIGHT_BLUE	=	\033[94m
YELLOW		=	\033[93m

MAKEFLAGS	+=	--no-print-directory

all: $(NAME)

$(NAME): $(LIBFT_A) $(MLX_A) $(OBJS)
	@echo "$(BOLD)$(LIGHT_BLUE)Compile $(NAME)...$(RESET)"
	@echo "$(BOLD)$(LIGHT_BLUE)Create $(LIBFT)...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR)
	@echo "$(BOLD)$(LIGHT_BLUE)Compile now...$(RESET)"
	@$(CC) $(CFLAG) $(OBJS) $(MLX_A) $(LIBFT_DIR)/$(LIBFT_A) $(INCLUDES) $(MLX_INCLUDES) -o $(NAME)
	@echo "$(BOLD)$(LIGHT_BLUE)Compile $(NAME) Complete!$(RESET)"

.c.o:
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT_A):
	@echo "$(BOLD)$(LIGHT_BLUE)Create $(MLX)...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR)

$(MLX_A):
	@echo "$(BOLD)$(LIGHT_BLUE)Create $(MLX)...$(RESET)"
	@$(MAKE) -C $(MLX_DIR)

clean:
	@echo "$(BOLD)$(LIGHT_BLUE)Cleaning $(NAME)...$(RESET)"
	@$(MAKE) clean -C $(LIBFT_DIR)
	@$(RM) $(OBJS) $(BONUS_OBJS)
	@echo "$(BOLD)$(LIGHT_BLUE)Cleaning $(NAME) Complete!$(RESET)"

fclean:
	@echo "$(BOLD)$(LIGHT_BLUE)ALL Cleaning $(NAME)...$(RESET)"
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@$(MAKE) clean -C $(MLX_DIR)
	@$(RM) $(OBJS) $(BONUS_OBJS) $(NAME) $(BONUS)
	@echo "$(BOLD)$(LIGHT_BLUE)ALL Cleaning $(NAME) Complete!$(RESET)"

bonus: fclean $(LIBFT_A) $(MLX_A) $(BONUS_OBJS) $(OBJS)
	@echo "$(BOLD)$(LIGHT_BLUE)Compile $(BONUS)...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR)
	@$(CC) $(CFLAG) $(INCLUDES) $(BONUS_OBJS) $(LIBFT_DIR)/$(LIBFT_A) -o $(BONUS)
	@echo "$(BOLD)$(LIGHT_BLUE)Compile $(BONUS) Complete!$(RESET)"

re: fclean all

.PHONY: all clean fclean re bonus