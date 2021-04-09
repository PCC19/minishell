NAME = minishell

LIBFT = ./libft/libft.a

SDIR =	./srcs/
ODIR =	./objs/

SRCS =	$(SDIR)main.c\
		$(SDIR)get_next_line.c\
		$(SDIR)get_next_line_utils.c\
		$(SDIR)u_print_list.c\
		$(SDIR)u_free_list.c\
		$(SDIR)parse_cmd_lines.c\
		$(SDIR)free_matrizes.c\
		$(SDIR)u_free_array_bi.c\
		$(SDIR)ft_conta_linhas.c\
		$(SDIR)parse_pipelines.c\
		$(SDIR)u_print_array_bi.c\
		$(SDIR)parse_s.c\
		$(SDIR)init_env.c\
		$(SDIR)expande.c\
		$(SDIR)parse_redirects.c\
		$(SDIR)parse_cmd_args.c



		
OBJS =	$(patsubst $(SDIR)%.c, $(ODIR)%.o, $(SRCS))		

CC = clang
HEADERS = -I./includes -I./libft
C_FLAGS = -Wall -Werror -Wextra -g
C_SANIT = -fsanitize=address
L_FLAGS = -L ./libft -lft -lncurses

$(NAME):	$(OBJS) $(LIBFT) $(MLX)
	$(CC) $(OBJS) $(C_FLAGS) $(C_SANIT) $(HEADERS) $(L_FLAGS) -o $(NAME)
	#$(CC) $(OBJS) $(C_FLAGS) $(HEADERS) $(L_FLAGS) -o $(NAME)
	echo CONCLUIDO
	./minishell

$(ODIR)%.o: $(SDIR)%.c
		mkdir -p $(ODIR)
		$(CC) $(C_FLAGS) $(HEADERS) -c $< -o $@

$(LIBFT):
	make re -C ./libft

all: minishell

clean:
	make clean -C ./libft
	rm -f $(OBJS)
	rmdir $(ODIR)

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME)

re: fclean all

run:
	./minishell
