/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_print_struct_cmd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 17:52:20 by user42            #+#    #+#             */
/*   Updated: 2021/04/14 00:13:07 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	u_print_struct_cmd(t_v *v)
{
	printf("__________________________________________\n");
	printf("   STRUCT CMD    \n");
	printf("filename:\t\t|%s|\n", v->cmd.filename);
	printf("cmd_args;\n");
	u_print_array_bi(v->cmd.cmd_args);
	printf("fd_in_red: %d\t\t fd_out_red: %d\n", v->cmd.fd_in_red, v->cmd.fd_out_red);
	printf("pipe_ant[in]: %d\t\t pipe_ant[out]: %d\n", v->cmd.pipe_ant[IN], v->cmd.pipe_ant[OUT]);
	printf("pipe_pos[in]: %d\t\t pipe_pos[out]: %d\n", v->cmd.pipe_pos[IN], v->cmd.pipe_pos[OUT]);
	printf("fd_in: %d\t\t fd_out: %d\n", v->cmd.fd_in, v->cmd.fd_out);
	printf("ret_status:\t\t %d\n",v->cmd.ret_status);
	printf("__________________________________________\n");
}
