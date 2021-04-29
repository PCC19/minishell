/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 22:19:37 by user42            #+#    #+#             */
/*   Updated: 2021/04/29 23:06:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_pwd (t_v *v)
{
	long	size;
	char	*buf;

	size = MIL;
	buf = NULL;
	if (v->cmd.cmd_args[1] == NULL)
		buf = getcwd(buf, (size_t)size);
	else
		buf = ft_strdup("pwd : too many arguments");
	ft_putstr_fd(buf, v->cmd.fd_out);
	ft_putstr_fd("\n", v->cmd.fd_out);
	free(buf);
	return (0);
}
