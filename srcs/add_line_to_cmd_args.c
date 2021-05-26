/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_line_to_cmd_args.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 00:15:06 by user42            #+#    #+#             */
/*   Updated: 2021/05/26 01:47:59 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_line_to_cmd_args(t_v *v, char *src)
{
	int		len_arr;
	int		i;
	char	**new;
	char	**aux;

		len_arr = 0;
		while (v->cmd.cmd_args[len_arr])
			len_arr++;
		new = (char **)safe_malloc((len_arr + 2) * sizeof(char *));
		i = 0;
		while (v->cmd.cmd_args[i] != 0)
		{
			new[i] = ft_strdup(v->cmd.cmd_args[i]);
			i++;
		}
		new[i] = ft_strdup(src);
		new[i + 1] = NULL;
		aux = v->cmd.cmd_args;
		v->cmd.cmd_args = new;
		u_free_array_bi(aux);
}
