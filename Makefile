NAME		=	fdf

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
MLX_FLAG	=	-lXext -lX11
RM			=	rm -rf

LIB			=	libft
LIB_A		=	lib.a

LIB_DIR		=	./lib


SRCS_DIR	=	./srcs
SRCS		=	$(wildcard $(SRCS_DIR)/*.c)
OBJS		=	$(SRCS:.c=.o)

BONUS		=	./srcs/test_bonus
BONUS_SRCS	=	$(wildcard $(SRCS_DIR)/*.c)
BONUS_OBJS	=	$(BONUS_SRCS:.c=.o)

RESET		=	\033[0m
BOLD		=	\033[1m
DIM			=	\033[2m
UNDERLINE	=	\033[4m
BLINK		=	\033[5m
INVERT		=	\033[7m
LIGHT_BLUE	=	\033[94m
YELLOW		=	\033[93m


MLX_NAME    =	libmlx
MLX_DIR		=	./minilibx-linux
MLX_A	    =	$(MLX_DIR)/$(MLX_NAME).a
MLX_FLAGS   += 	-L./lib -L$(MLX_DIR)/obj

INCLUDES	=	-I ./includes -I $(LIB_DIR)/includes -I $(MLX_DIR)

MAKEFLAGS	+=	--no-print-directory

all: $(NAME)

$(NAME): libft minilibx $(OBJS)
	@$(MAKE) -C $(MLX_DIR)
	@echo "$(BOLD)$(LIGHT_BLUE)Compile $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(MLX_FLAG) $(INCLUDES) $(OBJS) $(LIB_DIR)/$(LIB_A) $(MLX_A) -lm -o $(NAME)
	@echo "$(BOLD)$(LIGHT_BLUE)Compile $(NAME) Complete!$(RESET)"

.c.o:
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

libft:
	@echo "$(BOLD)$(LIGHT_BLUE)Compile $(LIB)...$(RESET)"
	@$(MAKE) -C $(LIB_DIR)

minilibx:
	@echo "$(BOLD)$(LIGHT_BLUE)Compile $(MLX_NAME)...$(RESET)"
	@$(MAKE) -C $(MLX_DIR)

clean:
	@echo "$(BOLD)$(LIGHT_BLUE)Cleaning $(NAME)...$(RESET)"
	@$(MAKE) clean -C $(LIB_DIR)
	@$(RM) $(OBJS) $(BONUS_OBJS)
	@echo "$(BOLD)$(LIGHT_BLUE)Cleaning $(NAME) Complete!$(RESET)"

fclean:
	@echo "$(BOLD)$(LIGHT_BLUE)ALL Cleaning $(NAME)...$(RESET)"
	@$(MAKE) fclean -C $(LIB_DIR)
	@$(MAKE) clean -C $(MLX_DIR)
	@$(RM) $(OBJS) $(BONUS_OBJS)
	@$(RM) $(NAME) $(BONUS)
	@echo "$(BOLD)$(LIGHT_BLUE)ALL Cleaning $(NAME) Complete!$(RESET)"

bonus: fclean $(BONUS_OBJS) $(OBJS)
	@echo "$(BOLD)$(LIGHT_BLUE)Compile $(BONUS)...$(RESET)"
	@$(MAKE) -C $(LIB_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) $(BONUS_OBJS) $(LIB_DIR)/$(LIB) -o $(BONUS)
	@echo "$(BOLD)$(LIGHT_BLUE)Compile $(BONUS) Complete!$(RESET)"

re: fclean all

.PHONY: all clean fclean re bonus