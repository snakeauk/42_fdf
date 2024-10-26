NAME		=	fdf

CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror
MLX_FLAG	=	-framework OpenGL -framework AppKit

RM			=	rm -rf

INCLUDE		=	-I ./includes -I $(LIB_DIR)/includes -I $(MLX_DIR)/

LIB_DIR		=	./lib
LIB			=	lib.a

MLX_DIR		=	./minilibx
MLX			=	libmlx.a


SRCS_DIR    =	srcs
KEYBOAD		=	$(SRCS_DIR)/keyboard

SRCS        =	$(SRCS_DIR)/fdf.c \
				$(SRCS_DIR)/map.c \
				$(SRCS_DIR)/control.c \
				$(SRCS_DIR)/keyboard.c \
				$(SRCS_DIR)/mouse.c \
				$(SRCS_DIR)/draw.c \
				$(SRCS_DIR)/project.c \
				$(SRCS_DIR)/line.c \
				$(SRCS_DIR)/ft_utils.c 


OBJS_DIR	=	objs
OBJS		=	$(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)
OBJS_VIM	=	$(SRCS_VIM=$(OBJS_DIR)/%.o)
OBJS_GAME	=	$(SRCS_GAME=$(OBJS_DIR)/%.o)

MAKEFLAGS	+=	--no-print-directory

RESET		=	\033[0m
BOLD		=	\033[1m
DIM			=	\033[2m
UNDERLINE	=	\033[4m
BLINK		=	\033[5m
INVERT		=	\033[7m
LIGHT_BLUE	=	\033[94m
YELLOW		=	\033[93m

all:	$(NAME)

$(NAME): mlx libft $(OBJS)
	@$(MAKE) -C $(MLX_DIR)
	@echo "$(BOLD)$(LIGHT_BLUE)Compile $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) $(LIB_DIR)/$(LIB) $(MLX_DIR)/$(MLX) -lm -o $(NAME) $(MLX_FLAG)
	@echo "$(BOLD)$(LIGHT_BLUE)Compile $(NAME) Complete!$(RESET)"

libft:
	@echo "$(BOLD)$(LIGHT_BLUE)Making $(LIB)...$(RESET)"
	@$(MAKE) -C $(LIB_DIR)

mlx:
	@echo "$(BOLD)$(LIGHT_BLUE)Making $(MLX)...$(RESET)"
	@$(MAKE) -C $(MLX_DIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	@echo "$(BOLD)$(LIGHT_BLUE)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	@echo "$(BOLD)$(LIGHT_BLUE)Cleaning $(NAME)...$(RESET)"
	@$(MAKE) clean -C $(LIB_DIR)
	@$(RM) $(MLX_DIR)/*.o
	@$(RM) $(OBJS_DIR)
	@echo "$(BOLD)$(LIGHT_BLUE)Cleaning $(NAME) Complete!$(RESET)"

fclean:
	@echo "$(BOLD)$(LIGHT_BLUE)ALL Cleaning $(NAME)...$(RESET)"
	@$(MAKE) fclean -C $(LIB_DIR)
	@echo "$(BOLD)$(LIGHT_BLUE)ALL Cleaning $(MLX_DIR)...$(RESET)"
	@$(MAKE) clean -C $(MLX_DIR)
	@echo "$(BOLD)$(LIGHT_BLUE)ALL Cleaning $(OBJS_DIR)...$(RESET)"
	@$(RM) $(OBJS_DIR) $(NAME)
	@echo "$(BOLD)$(LIGHT_BLUE)ALL Cleaning $(NAME) Complete!$(RESET)"

re: fclean all

.PHONY: all clean fclean re bonus