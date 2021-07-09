/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pipelines.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <cpereira@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 03:47:00 by user42            #+#    #+#             */
/*   Updated: 2021/07/09 21:48:42 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	prepare_for_execution(t_v *v, int i, int n)
{
	int pipe_aux[2];

	parse_s(v, v->pipelines[i]);
	redirect_handler(v, i, n);
	if (v->cmd.fn == NULL && v->cmd.cmd_args[0] != NULL)
		v->cmd.fn = ft_strdup(v->cmd.cmd_args[0]);
	// print heredoc no fd in
		// cria um pipe
		// printa na entrada deste pipe
		// Faz redirects
		pipe(pipe_aux);
//		dup2(pipe_aux[PIPE_OUT], v->cmd.fd_out);
		v->cmd.fd_in_red = pipe_aux[PIPE_IN];
		dup2(v->cmd.fd_in_red, v->cmd.fd_in);
		close(v->cmd.fd_in_red);
	fd_handler(v->cmd.fd_in, v->cmd.fd_out);
		u_print_array_bi_fd(v, v->cmd.heredoc, pipe_aux[PIPE_OUT]);
		//ft_putstr_fd(v->cmd.heredoc[0],pipe_aux[PIPE_IN]);
	check_n_free(v->curr_comand);
	v->curr_comand = ft_strdup(v->cmd.fn);
		// mapeia a saida deste pipe como fd in do comando

		// executa comando

		// close pipe novo
}

int	parse_pipelines(t_v *v, char *linha, int i, int n)
{
	char	**aux;
	char	*s;

	aux = ft_split3(linha, '|');
	n = remov_quots(1, aux);
	v->pipelines = (char **)safe_malloc(sizeof(char *) * (n + 1));
	init_struct_cmd(v);
	while (aux[i] && v->flag_exit == 0)
	{
		init_cmd_args(v);
		s = ft_strdup(aux[i]);
		v->pipelines[i] = ft_strtrim(s, " ");
		prepare_for_execution(v, i, n);
			u_print_struct_cmd(v);
		if (v->flag_perm_denied == 0)
			execute_command(v);
		dups_clear(v, s);
		i++;
	}
	close_fds(v, i);
	u_free_array_bi(aux);
	return (0);
}

void	dups_clear(t_v *v, char *s)
{
	v->flag_perm_denied = 0;
	close(v->cmd.fd_out);
	if (v->cmd.fd_in != 0)
		close(v->cmd.fd_in);
	v->cmd.fd_in = v->cmd.pipe[PIPE_OUT];
	dup2(v->cmd.save_in, STDIN_FILENO);
	dup2(v->cmd.save_out, STDOUT_FILENO);
	cleaning(v, s);
	verify_ret(v);
}

void	cleaning(t_v *v, char *s)
{
	free(v->cmd.fn);
	v->cmd.fn = NULL;
	free(v->expanded);
	v->expanded = NULL;
	free(s);
	s = NULL;
	u_free_array_bi(v->cmd.cmd_args);
	u_free_array_bi(v->cmd.heredoc);
}

void	verify_ret(t_v *v)
{
	pid_t	pidf;

	if (v->cmd.ret_status == -1)
	{
		write_error(v);
		free(v->curr_comand);
		ft_bzero(v->ret, 2048);
		pidf = getpid();
		kill(pidf, SIGKILL);
	}
}
