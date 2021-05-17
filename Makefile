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
		$(SDIR)u_free_array_bi.c\
		$(SDIR)ft_count_lines.c\
		$(SDIR)parse_pipelines.c\
		$(SDIR)u_print_array_bi.c\
		$(SDIR)parse_s.c\
		$(SDIR)init_env.c\
		$(SDIR)expand.c\
		$(SDIR)parse_cmd_args.c\
		$(SDIR)copy_until.c\
		$(SDIR)parse_in_red.c\
		$(SDIR)parse_out_red.c\
		$(SDIR)u_print_struct_cmd.c\
		$(SDIR)init_struct_cmd.c\
		$(SDIR)ff.c\
		$(SDIR)ft_split3.c\
		$(SDIR)parse_sq.c\
		$(SDIR)parse_dq.c\
		$(SDIR)fd_handler.c\
		$(SDIR)redirect_handler.c\
		$(SDIR)execute_command.c\
		$(SDIR)get_pwd.c\
		$(SDIR)get_cd.c\
		$(SDIR)update_env_var.c\
		$(SDIR)loc_var.c\
		$(SDIR)create_prompt.c\
		$(SDIR)get_echo.c\
		$(SDIR)export_var.c\
		$(SDIR)get_var.c\
		$(SDIR)exc_var.c\
		$(SDIR)get_env.c\
		$(SDIR)exit_msh.c\
		$(SDIR)fork_process.c\
		$(SDIR)init_path.c\
		$(SDIR)exec_com.c\
		$(SDIR)set_return_status.c\
		$(SDIR)count_split.c\
		$(SDIR)reset_flags.c\
		$(SDIR)update_folder.c\
		$(SDIR)add_hist.c\
		$(SDIR)verify_term.c\
		$(SDIR)my_termprint.c\
		$(SDIR)sighandler.c\
		$(SDIR)config_term.c\
		$(SDIR)k_up.c\
		$(SDIR)k_dn.c\
		$(SDIR)k_right.c\
		$(SDIR)k_left.c\
		$(SDIR)k_bspace.c\
		$(SDIR)k_ctrl_c.c\
		$(SDIR)bye.c

OBJS =	$(patsubst $(SDIR)%.c, $(ODIR)%.o, $(SRCS))		

CC = clang
HEADERS = -I./includes -I./libft
C_FLAGS = -Wall -Werror -Wextra -g
C_SANIT = -fsanitize=address
L_FLAGS = -L ./libft -lft -lncurses -ltermcap

$(NAME):	$(OBJS) $(LIBFT)
	$(CC) $(OBJS) $(C_FLAGS) $(C_SANIT) $(HEADERS) $(L_FLAGS) -o $(NAME)
	#$(CC) $(OBJS) $(C_FLAGS) $(HEADERS) $(L_FLAGS) -o $(NAME)
	echo CONCLUIDO
	#./minishell
	#valgrind --leak-check=full --track-origins=yes ,/minishell


$(ODIR)%.o: $(SDIR)%.c
		mkdir -p $(ODIR)
		$(CC) $(C_FLAGS) $(HEADERS) -c $< -o $@

$(LIBFT):
	make re -C ./libft

all: minishell

clean:
	make clean -C ./libft
	rm -rf $(ODIR)
	#rm -f $(OBJS)
	#rmdir $(ODIR)

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME)

re: fclean all

run:
	./minishell

val:	$(OBJS) $(LIBFT)
	$(CC) $(OBJS) $(C_FLAGS) $(HEADERS) $(L_FLAGS) -o $(NAME)
	echo CONCLUIDO
	#./minishell
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./minishell
