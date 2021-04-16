/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 18:10:38 by user42            #+#    #+#             */
/*   Updated: 2021/04/14 22:41:51 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_struct_cmd(t_v *v)
{
	//printf("init_struct\n");
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
	//v->cmd.fd_in_red = STDIN_FILENO;
	//v->cmd.fd_out_red = STDOUT_FILENO;
	v->cmd.fd_in_red = -1;
	v->cmd.fd_out_red = -1;
	//v->cmd.pipe_ant[IN] = -1;
	//v->cmd.pipe_ant[OUT] = -1;
	//v->cmd.pipe_pos[IN] = -1;
	//v->cmd.pipe_pos[OUT] = -1;
	v->cmd.fd_in = -1;
	v->cmd.fd_out = -1;
	v->cmd.ret_status = 0;
}
