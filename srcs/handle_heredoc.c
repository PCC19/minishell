/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 17:40:43 by user42            #+#    #+#             */
/*   Updated: 2021/07/10 17:23:46 by pcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_heredoc(t_v *v, int fd_temp)
{
	char	*line;

	line = readline("> ");
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
		line = readline("> ");
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
	unlink ("./zzzz");
}
