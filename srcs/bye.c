/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bye.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 03:31:30 by user42            #+#    #+#             */
/*   Updated: 2021/05/14 03:37:15 by user42           ###   ########.fr       */
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
	//free(v->prompt);
	exit(0);
}
