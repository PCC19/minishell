/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_in_red.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <cpereira@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 23:58:59 by user42            #+#    #+#             */
/*   Updated: 2021/07/08 17:55:37 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse_in_red(t_v *v, int *k, int in)
{
	char	file_redir[MIL];

	ft_bzero(file_redir, MIL);
	ff(v->expanded, k);
	if (v->expanded[*k] == '<')
	{
		// trata <<
		v->flag_heredoc = 1;
		copy_until(v->eof, v->expanded, " <>", k);
		handle_heredoc(v);
	}
	else
	{
		copy_until(file_redir, v->expanded, " <>", k);
		v->cmd.fd_in_red = open(file_redir, O_RDONLY | O_CREAT);
		dup2(v->cmd.fd_in_red, in);
		close(v->cmd.fd_in_red);
	}
	ff_until_char(v->expanded, k, " <>\"\'");
//		printf("inred |%s|\t|%c|\t|%d|\n",v->expanded, v->expanded[*k], *k);
}
