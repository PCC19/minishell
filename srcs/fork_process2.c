/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_process2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 00:37:25 by user42            #+#    #+#             */
/*   Updated: 2021/06/11 00:59:09 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	fork_process2(t_v *v)
{

	int		i;
	char	*command;
	char	*aux;
	int		r;


		u_print_struct_cmd(v); // LINHA DE DEBUG

	//caminho absoluto
		// se existe executa
	if (is_abs_path(v->cmd.cmd_args[0]))
	{
		r = exec_cmd3(v->cmd.filename, &v->cmd.cmd_args[0], v);
		return (r);
	}
	else //sem caminho
	{
		r = exec_cmd3(v->cmd.filename, &v->cmd.cmd_args[0], v);
		//se existe executa
		if (r > 0)
			return (r);
		else // se nao existe
		{
			//se nao tem path: erro
			if (v->path[0] == NULL)
				return (-1);
			else
			//se tem path busca no path
			{
				r = -1;
				i = 0;

				if (v->cmd.cmd_args[1] != NULL )
					if (v->cmd.cmd_args[1][0] == '~' && v->cmd.cmd_args[1][1] != '~')
						v->cmd.cmd_args[1] = (ft_strjoin(loc_var("HOME",v),&v->cmd.cmd_args[1][1]));

					//		printf("cmd_args[0]: |%s|\n", v->cmd.cmd_args[0]);
					//		printf("cmd_args[1]: |%s|\n", v->cmd.cmd_args[1]);

				//v->cmd.cmd_args[0] = get_last_path(v->cmd.cmd_args[0]);
				v->cmd.cmd_args[0] = get_last_path2(v->cmd.cmd_args[0]);

				//		printf("cmd_args[0]: |%s|\n", v->cmd.cmd_args[0]);
				//		printf("cmd_args[1]: |%s|\n", v->cmd.cmd_args[1]);

				while (v->path[i] != NULL && r != 0)
				{
					printf("%d , %s\t",i,v->path[i]);
					aux = ft_strdup(v->path[i]);
					command = ft_strjoin(aux, "/");
					free(aux);
					aux = command;
					command = ft_strjoin(aux, v->cmd.cmd_args[0]);
//						printf("command: |%s|\n", command);
//						printf("cmd_args[0]: |%s|\n", v->cmd.cmd_args[0]);
//						printf("cmd_args[1]: |%s|\n", v->cmd.cmd_args[1]);
					r = exec_cmd3(command, &v->cmd.cmd_args[0], v);
						printf("r: %d\n", r);
					free(aux);
					free(command);
					i++;
				}
				return (r);
			}
		}
	}
}
