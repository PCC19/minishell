/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_out_red.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 01:57:38 by user42            #+#    #+#             */
/*   Updated: 2021/04/13 02:17:27 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse_out_red(t_v *v, int *k)
{
	char	file_redir[MIL];
	int		flags;

	//printf("out_red in  k: %d\t|%s|\n", *k, &v->expandido[*k]);
	flags = O_RDWR | O_CREAT | O_TRUNC;
	ft_bzero(file_redir, MIL);
	ff(v->expandido, k);
	//printf("out_red in  k: %d\t|%s|\n", *k, &v->expandido[*k]);
	if (v->expandido[*k] == '>')
	{
		ff(v->expandido, k);
		flags = O_RDWR | O_CREAT | O_APPEND;
	}
	copy_until(file_redir, v->expandido, " <>", k);
	//printf("file_redir |%s|\n", file_redir);
	v->cmd.fd_out_red = open(file_redir, flags);
	//printf("out_red out k: %d\t|%s|\n", *k, &v->expandido[*k]);
}
