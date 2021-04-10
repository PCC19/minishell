/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_out_red.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 01:57:38 by user42            #+#    #+#             */
/*   Updated: 2021/04/10 19:10:39 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse_out_red(t_v *v, int *k)
{
	char	file_redir[MIL];
	int		flags;

	//printf("outred:\n");
	if (v->expandido[*k] == '>')
	{
		flags = O_RDWR | O_CREAT | O_TRUNC;
		printf("flags1: %d\n", flags);
		ft_bzero(file_redir, MIL);
		(*k)++;
		if (v->expandido[*k] == '>')
		{
			(*k)++;
			flags = O_RDWR | O_CREAT | O_APPEND;
			printf("flags2: %d\n", flags);
		}
		while (v->expandido[*k] == ' ' && v->expandido[*k] != 0)
			(*k)++;
		copy_until(file_redir, &v->expandido[*k], " <>", k);
		//printf("file_o_redir: %s\n", file_redir);
		//close(v->cmd.fd_out);
		v->cmd.fd_out = open(file_redir, flags);
	}	
}
