/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 18:10:38 by user42            #+#    #+#             */
/*   Updated: 2021/04/11 18:12:59 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_struct_cmd(t_v *v)
{
	printf("init_struct\n");
	//v->cmd = (t_cmd){0};
	/*if (v->cmd.filename != NULL)
	{
		free(v->cmd.filename);
		v->cmd.filename = NULL;
	}
	if (v->cmd.cmd_args != NULL)
	{
		u_free_array_bi(v->cmd.cmd_args);
		v->cmd.cmd_args = NULL;
	}
	*/
	v->cmd.filename = 0;
	v->cmd.cmd_args = 0;
	v->cmd.fd_in = STDIN_FILENO;
	v->cmd.fd_out = STDOUT_FILENO;
	v->cmd.ret_status = 0;
}
