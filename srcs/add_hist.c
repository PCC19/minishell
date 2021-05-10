/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_hist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 17:13:36 by user42            #+#    #+#             */
/*   Updated: 2021/05/10 17:39:33 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_hist(t_v *all, char *ret)
{
	all->hist[all->qtd_hist] = malloc((2048 + 1) * sizeof(char *));
	ft_memcpy(all->hist[all->qtd_hist], ret, ft_strlen(ret));
	all->hist[all->qtd_hist][ft_strlen (ret)] = '\0';
	all->posic_hist = all->qtd_hist;
	all->qtd_hist++;
}
