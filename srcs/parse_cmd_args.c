/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 23:06:16 by user42            #+#    #+#             */
/*   Updated: 2021/05/26 01:17:52 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse_cmd_args(t_v *v, int *k)
{
	char	*cmdeargs;
	char	aux[MIL];
	char	**temp;
	int		i;

	ft_bzero(aux, MIL);
	copy_until(aux, v->expanded, "<>", k);
	cmdeargs = ft_strtrim(aux, " ");
	//v->cmd.cmd_args = ft_split3(cmdeargs, ' ');
	temp = ft_split3(cmdeargs, ' ');
	// trocar linha acima por um loop onde acrescenta cada linha na matriz existente
	i = 0;
	while(temp[i])
	{
		add_line_to_cmd_args(v, temp[i]);
		i++;
	}
		//u_print_array_bi(v, v->cmd.cmd_args);
	v->cmd.filename = ft_strdup(v->cmd.cmd_args[0]);
	free(cmdeargs);
}
