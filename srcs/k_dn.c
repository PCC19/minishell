/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_dn.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 18:41:18 by user42            #+#    #+#             */
/*   Updated: 2021/05/10 18:51:33 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	k_dn(t_v *v)
{
	tputs(restore_cursor,1,my_termprint);
	tputs(tigetstr("ed"),1,my_termprint);
	v->ret2 = ft_strdup(v->hist[v->posic_hist]);
	ft_putstr_fd(v->ret2,1);
	if (v->posic_hist >= v->qtd_hist - 1)
		v->posic_hist = v->qtd_hist - 1;
	else
		v->posic_hist ++;
}
