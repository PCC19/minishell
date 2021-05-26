/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 01:37:54 by user42            #+#    #+#             */
/*   Updated: 2021/05/26 01:46:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_cmd_args(t_v *v)
{
	v->cmd = (t_cmd){0};
	v->cmd.cmd_args = (char **)safe_malloc((0 + 1) * sizeof(char *));
	//v->cmd.cmd_args[0] = ft_strdup("paulo");
	//v->cmd.cmd_args[1] = ft_strdup("cunha");
	v->cmd.cmd_args[0] = NULL;
}
