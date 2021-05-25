/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <cpereira@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 22:33:13 by user42            #+#    #+#             */
/*   Updated: 2021/05/25 02:18:29 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		parse_s(t_v *v, char *linha)
{
	int						i;
	int						j;

	v->expanded = (char*)ft_calloc(MIL, sizeof(char));
	i = 0;
	j = 0;
	while (linha[i] != 0)
	{
		if (ft_is_in(linha[i], "$") &&
			(state == NORMAL || state == DOUBLE_QUOTE))
			expand(v, &linha[i], &i, &j);
		else
		{
			ft_memcpy(&v->expanded[j], &linha[i], 2);
			j++;
		}
		i++;
	}
	return (0);
}
