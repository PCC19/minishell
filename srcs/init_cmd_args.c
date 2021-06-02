/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 17:41:58 by user42            #+#    #+#             */
/*   Updated: 2021/06/02 17:47:41 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_cmd_args(t_v *v)
{
	v->cmd = (t_cmd){0};
	v->cmd.cmd_args = (char **)safe_malloc((0 + 1) * sizeof(char *));
	v->cmd.cmd_args[0] = NULL;
	//v->cmd.cmd_args[0] = ft_strdup("paulo");
	//v->cmd.cmd_args[1] = ft_strdup("cunha");
	v->cmd.cmd_args[0] = NULL;
}
