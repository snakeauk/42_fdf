NAME		=	fdf
BONUS		=	fdf_bonus

CC			=	cc
CFLAGS		=	-g# -Wall -Wextra -Werror
RM			=	rm -rf

LIBFT		=	libft
LIBFT_A		=	$(LIBFT).a
LIBFT_DIR	=	./$(LIBFT)

MLX			=	minilibx

SRCS_DIR	=	./srcs
MAN_DIR		=	$(SRCS_DIR)/mandatory
BONUS_DIR	=	$(SRCS_DIR)/bonus
SRCS		=	$(wildcard $(SRCS_DIR)/*.c)
MAN_SRCS	=	$(wildcard $(MAN_DIR)/*.c)
BONUS_SRCS	=	$(wildcard $(BONUS_DIR)/*.c)

OBJS_DIR	=	./objs
OBJS		=	$(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)
MAN_OBJS	=	$(MAN_SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)
BONUS_OBJS	=	$(BONUS_SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Darwin)
	OS_DIR		=	$(LIBFT_DIR)/mac
	MLX_DIR		=	$(MLX)_macos
	MLX_A		=	$(MLX_DIR)/libmlx.a
	MFLAGS		=	-framework OpenGL -framework AppKit
else
	OS_DIR		=	$(LIBFT_DIR)/linux
	MLX_DIR		=	$(MLX)-linux
	MLX_A		=	$(MLX_DIR)/libmlx_Linux.a
	MFLAGS		=	-lXext -lX11 -lm -lz
endif

INCLUDES	=	-I ./includes -I $(LIBFT_DIR)/includes -I $(OS_DIR)/includes -I $(MLX_DIR)

RESET		=	\033[0m
BOLD		=	\033[1m
LIGHT_BLUE	=	\033[94m

MAKEFLAGS	+=	--no-print-directory

all: $(LIBFT_A) $(MLX_A) $(OBJS_DIR) $(OBJS) $(MAN_OBJS) $(NAME)

$(NAME):
	@echo "$(BOLD)$(LIGHT_BLUE)Compile $(NAME)...$(RESET)"
	@echo "$(BOLD)$(LIGHT_BLUE)Compile now...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) $(MAN_OBJS) $(MLX_A) $(LIBFT_DIR)/$(LIBFT_A) $(INCLUDES) $(MFLAGS) -o $(NAME)
	@echo "$(BOLD)$(LIGHT_BLUE)Compile $(NAME) Complete!$(RESET)"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)/mandatory $(OBJS_DIR)/bonus
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJS_DIR)/mandatory:
	@mkdir -p $(OBJS_DIR)/mandatory

$(OBJS_DIR)/bonus:
	@mkdir -p $(OBJS_DIR)/bonus

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(LIBFT_A):
	@$(MAKE) -C $(LIBFT_DIR)

$(MLX_A):
	@echo "$(BOLD)$(LIGHT_BLUE)Create $(MLX)...$(RESET)"
	@$(MAKE) -C $(MLX_DIR)

clean:
	@echo "$(BOLD)$(LIGHT_BLUE)Cleaning $(NAME)...$(RESET)"
	@$(MAKE) clean -C $(LIBFT_DIR)
	@$(RM) $(OBJS) $(BONUS_OBJS)
	@$(RM) -r $(OBJS_DIR)
	@echo "$(BOLD)$(LIGHT_BLUE)Cleaning $(NAME) Complete!$(RESET)"

fclean:
	@echo "$(BOLD)$(LIGHT_BLUE)ALL Cleaning $(NAME)...$(RESET)"
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@$(MAKE) clean -C $(MLX_DIR)
	@$(RM) $(OBJS) $(BONUS_OBJS) $(NAME) $(BONUS)
	@$(RM) -r $(OBJS_DIR)
	@echo "$(BOLD)$(LIGHT_BLUE)ALL Cleaning $(NAME) Complete!$(RESET)"

bonus: $(LIBFT_A) $(MLX_A) $(OBJS) $(BONUS_OBJS) $(BONUS)

$(BONUS):
	@echo "$(BOLD)$(LIGHT_BLUE)Compile $(BONUS)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) $(BONUS_OBJS) $(MLX_A) $(LIBFT_DIR)/$(LIBFT_A) $(INCLUDES) $(MFLAGS) -o $(BONUS)
	@echo "$(BOLD)$(LIGHT_BLUE)Compile $(BONUS) Complete!$(RESET)"


re: fclean all

.PHONY: all clean fclean re bonus