/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_in_red.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 23:58:59 by user42            #+#    #+#             */
/*   Updated: 2021/04/13 02:19:14 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse_in_red(t_v *v, int *k)
{
	char file_redir[MIL];

	//printf("in_red in  k: %d\t|%s|\n", *k, &v->expandido[*k]);
	ft_bzero(file_redir, MIL);
	ff(v->expandido, k);
	copy_until(file_redir, v->expandido, " <>", k);
	v->cmd.fd_in_red = open(file_redir, O_RDWR | O_CREAT);
	//printf("file_redir |%s|\n", file_redir);
	//printf("in_red out k: %d\t|%s|\n", *k, &v->expandido[*k]);
}
