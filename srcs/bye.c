/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bye.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <cpereira@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 03:31:30 by user42            #+#    #+#             */
/*   Updated: 2021/07/11 20:23:49 by pcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	bye(t_v *v)
{
	int	i;

	printf("exit\n");
	tcsetattr(0, TCSAFLUSH, &v->old);
	u_free_array_bi(v->env);
	u_free_array_bi(v->path);
	i = 0;
	while (i < 500 && i < v->qtd_hist)
	{
		free(v->hist[i]);
		i++;
	}
	free(v->prompt);
	free(v->curr_comand);
	ft_bzero(v->ret2, ft_strlen(v->ret2));
	free(v->ret2);
	exit(0);
}

void	free_array(void **array)
{
	unsigned int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

void	check_n_free(void *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}
