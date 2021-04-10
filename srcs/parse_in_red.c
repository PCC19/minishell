/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_in_red.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 23:58:59 by user42            #+#    #+#             */
/*   Updated: 2021/04/10 18:44:39 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse_in_red(t_v *v, int *k)
{
	char file_redir[MIL];

	//printf("inred:\n");
	if (v->expandido[*k] == '<')
	{
		ft_bzero(file_redir, MIL);
		(*k)++;
		while (v->expandido[*k] == ' ' && v->expandido[*k] != 0)
			(*k)++;
		copy_until(file_redir, &v->expandido[*k], " <>", k);
		//printf("file_redir: %s\n", file_redir);
		//close(v->cmd.fd_in);
		v->cmd.fd_in = open(file_redir, O_RDWR | O_CREAT);
	}	
}
