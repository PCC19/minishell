/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_com.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 00:12:59 by user42            #+#    #+#             */
/*   Updated: 2021/05/07 01:11:05 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_com(t_v *v)
{
	int		i;
	char	*command;
	char	*aux;
	int		r;

	r = -1;
	i = 0;
	while (v->path[i] != NULL)
	{
		aux = ft_strdup(v->path[i]);
		command = ft_strjoin(aux, "/");
		free(aux);
		aux = command;
		command = ft_strjoin(aux, v->cmd.cmd_args[0]);
		r = execve(command, &v->cmd.cmd_args[0], v->env);
		free(aux);
		free(command);
		i++;
	}
	return (r);
}
