/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bye.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <cpereira@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 03:31:30 by user42            #+#    #+#             */
/*   Updated: 2021/06/03 21:28:39 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	bye(t_v *v)
{
	int	i;

	printf("exit\n");
	tcsetattr(0, TCSANOW, &v->old);
	u_free_array_bi(v->env);
	u_free_array_bi(v->path);
	i = 0;
	while (i < 50 && i < v->qtd_hist)
	{
		free(v->hist[i]);
		i++;
	}
	free(v->prompt);
	free(v->curr_comand);
	ft_bzero(v->ret2, ft_strlen(v->ret2));
	free(v->ret2);
	exit(0);
	if (v->flag_exit == 1)
		u_free_array_bi(v->cmd.cmd_args);
}

void	free_array(void **array)
{
	unsigned int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

