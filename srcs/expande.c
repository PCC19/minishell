/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expande.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 00:42:52 by user42            #+#    #+#             */
/*   Updated: 2021/04/09 17:53:32 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pega_conteudo_var(t_v *v, char **substr, int q)
{
	*substr = ft_strchr(v->env[q], '=');
	if (ft_strlen(*substr) > 0)
		(*substr)++;
}

void	expande(t_v *v, char *linha, int *i, int *j)
{
	int		k;
	int		q;
	char	*substr;

	linha++;
	substr = 0;
	k = 0;
	while (!(ft_is_in(linha[k], " \'\"><")) && k < (int)ft_strlen(linha))
		k++;
	q = -1;
	while (v->env[++q] != 0)
	{
		if (!ft_strncmp(linha, v->env[q], k))
			pega_conteudo_var(v, &substr, q);
	}
	ft_memcpy(&v->expandido[(*j)], substr, ft_strlen(substr));
	(*j) = (*j) + ft_strlen(substr);
	(*i) = (*i) + k;
}
