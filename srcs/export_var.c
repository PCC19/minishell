/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 21:06:58 by user42            #+#    #+#             */
/*   Updated: 2021/05/01 22:07:08 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	export_var(t_v *v)
{
	int		len_arr;
	int		i;
	char	**new;
	char	**aux;

	if (v->cmd.cmd_args[1] != 0)
	{
		exc_var(v);
		len_arr = 0;
		while (v->env[len_arr])
			len_arr++;
		new = (char **)malloc((len_arr + 2) * sizeof(char *));
		i = 0;
		while (v->env[i] != 0)
		{
			new[i] = ft_strdup(v->env[i]);
			i++;
		}
		new[i] = ft_strdup(v->cmd.cmd_args[1]);
		new[i + 1] = NULL;
		aux = v->env;
		v->env = new;
		u_free_array_bi(aux);
	}
	u_print_array_bi(v, v->env);
}