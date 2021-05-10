/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_up.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 18:39:31 by user42            #+#    #+#             */
/*   Updated: 2021/05/10 18:51:30 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	k_up(t_v *v)
{
	tputs(restore_cursor,1,my_termprint);
	tputs(tigetstr("ed"),1,my_termprint); //kL
	v->ret2 = ft_strdup(v->hist[v->posic_hist]);
	ft_putstr_fd(v->ret2,1);
	if (v->posic_hist <= 0)
		v->posic_hist = 0;
	else
		v->posic_hist --;
}
