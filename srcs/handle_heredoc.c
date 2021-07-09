/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 17:40:43 by user42            #+#    #+#             */
/*   Updated: 2021/07/09 23:38:39 by pcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_heredoc(t_v *v, int fd_temp)
{
	char	*line;

	line = readline(">");
	ft_putstr_fd(line, 1);
	ft_putstr_fd("\n", 1);
	if (ft_strncmp(line, v->eof, ft_strlen(v->eof)))
	{
		ft_putstr_fd(line, fd_temp);
		ft_putstr_fd("\n", fd_temp);
	}
	while (ft_strncmp(line, v->eof, ft_strlen(v->eof)))
	{
		free(line);
		line = readline(">");
		ft_putstr_fd(line, 1);
		ft_putstr_fd("\n", 1);
		if (ft_strncmp(line, v->eof, ft_strlen(v->eof)))
		{
			ft_putstr_fd(line, fd_temp);
			ft_putstr_fd("\n", fd_temp);
		}
	}
	free(line);
}

void	rm_file(void)
{
	char		**cmd;
	pid_t		child_pid;
	int			status;

	child_pid = fork();
	if (child_pid == 0)
	{
		cmd = (char **)safe_malloc(sizeof(char *) * (4 + 1));
		cmd[0] = ft_strdup("/bin/rm");
		cmd[1] = ft_strdup("-rf");
		cmd[2] = ft_strdup("./zzzz");
		cmd[3] = NULL;
		execve(cmd[0], cmd, NULL);
		free(cmd[0]);
		free(cmd[1]);
		free(cmd[2]);
		free(cmd[3]);
		free(cmd);
		exit(0);
	}
	else
		waitpid(child_pid, &status, 0);
}
