/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_in_red.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 23:58:59 by user42            #+#    #+#             */
/*   Updated: 2021/04/22 02:26:20 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse_in_red(t_v *v, int *k, int in)
{
	char file_redir[MIL];

	printf("parse_in_red:\n");
	ft_bzero(file_redir, MIL);
	ff(v->expandido, k);
	copy_until(file_redir, v->expandido, " <>", k);
	printf("file_redir: %s\n", file_redir);
	v->cmd.fd_in_red = open(file_redir, O_RDONLY | O_CREAT);
	dup2(v->cmd.fd_in_red, in);
	close(v->cmd.fd_in_red);

}
