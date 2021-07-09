/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_line_to_array_bi.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 20:18:15 by user42            #+#    #+#             */
/*   Updated: 2021/07/09 20:48:09 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_line_to_array_bi(t_v *v, char *src)
{
	int		len_arr;
	int		i;
	char	**new;
	char	**aux;

	len_arr = 0;
	while (v->cmd.heredoc[len_arr])
		len_arr++;
	new = (char **)safe_malloc((len_arr + 2) * sizeof(char *));
	i = 0;
	while (v->cmd.heredoc[i] != 0)
	{
		new[i] = ft_strdup(v->cmd.heredoc[i]);
		i++;
	}
	new[i] = ft_strdup(src);
	new[i + 1] = NULL;
	aux = v->cmd.heredoc;
	v->cmd.heredoc = new;
	u_free_array_bi(aux);
}
