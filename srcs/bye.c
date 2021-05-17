/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bye.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 03:31:30 by user42            #+#    #+#             */
/*   Updated: 2021/05/18 01:25:59 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	bye(t_v *v)
{
	printf("Logouts\n");
	tcsetattr(0, TCSANOW, &v->old);
	u_free_array_bi(v->env);
	u_free_array_bi(v->cmd_lines);
	u_free_array_bi(v->path);
	printf("ret2:\n|%s|\n",v->ret2);
	printf("hist:\n");
	u_print_array_bi(v, v->hist);

	u_free_array_bi(v->hist);
	//free(v->prompt);
	exit(0);
}
