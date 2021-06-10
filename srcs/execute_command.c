/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <cpereira@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 01:11:30 by user42            #+#    #+#             */
/*   Updated: 2021/06/10 21:36:41 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_command(t_v *v)
{
	printf("a: %d\n", v->cmd.ret_status);
	if (ft_strncmp(v->cmd.filename, "pwd", 3) == 0
		&& ft_strlen(v->cmd.filename) == 3)
		get_pwd(v);
	else if (ft_strncmp(v->cmd.filename, "cd", 2) == 0
		&& ft_strlen(v->cmd.filename) == 2)
		get_cd(v);
	else if (ft_strncmp(v->cmd.filename, "echo", 4) == 0
		&& ft_strlen(v->cmd.filename) == 4)
		get_echo(v);
	else if (ft_strncmp(v->cmd.filename, "export", 6) == 0
		&& ft_strlen(v->cmd.filename) == 6)
		export_var(v);
	else if (ft_strncmp(v->cmd.filename, "unset", 5) == 0
		&& ft_strlen(v->cmd.filename) == 5)
		exc_var(v);
	else if (ft_strncmp(v->cmd.filename, "env", 3) == 0
		&& ft_strlen(v->cmd.filename) == 3)
		get_env(v);
	else if (ft_strncmp(v->cmd.filename, "exit", 4) == 0
		&& ft_strlen(v->cmd.filename) == 4)
		exit_msh(v);
	else
		if (v->ret_last == 0)
			v->cmd.ret_status = fork_process(v);
	printf("d: %d\n", v->cmd.ret_status);
}

char	**alocate_new(t_v *v)
{
	int		i;
	char	**new;

	i = 0;
	while (v->env[i])
		i++;
	new = (char **)safe_malloc((i + 1) * sizeof(char *));
	return (new);
}

void	exc_var(t_v *v)
{
	int		i;
	int		k;
	char	**new;
	char	**aux;
	char	*var;

	if (v->cmd.cmd_args[1] != 0)
	{
		var = get_var(v);
		new = alocate_new(v);
		i = 0;
		k = 0;
		while (v->env[i] != 0)
		{
			if (ft_strncmp(v->env[i], var, ft_strlen(var)) != 0)
				new[k++] = ft_strdup(v->env[i]);
			i++;
		}
		new[k] = NULL;
		aux = v->env;
		v->env = new;
		// se variavel a ser excluia eh path, reseta path na struct
		if (ft_strncmp(var, "PATH",4) == 0)
			reset_vpath(v);
		u_free_array_bi(aux);
		free(var);
		free_array((void*)v->path);
		init_path(v);
		set_return_status(v, EXIT_SUCCESS);
	}
}

int	exec_com(t_v *v)
{
	int		i;
	char	*command;
	char	*aux;
	int		r;

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

	while (v->path[i] != NULL)
	{
		//printf("%d , %s\n",i,v->path[i]);
		aux = ft_strdup(v->path[i]);
		command = ft_strjoin(aux, "/");
		free(aux);
		aux = command;
		command = ft_strjoin(aux, v->cmd.cmd_args[0]);
//			printf("command: |%s|\n", command);
//			printf("cmd_args[0]: |%s|\n", v->cmd.cmd_args[0]);
//			printf("cmd_args[1]: |%s|\n", v->cmd.cmd_args[1]);
		r = execve(command, &v->cmd.cmd_args[0], v->env);
//			printf("r: %d\n", r);
		free(aux);
		free(command);
		i++;
	}
	return (r);
}
