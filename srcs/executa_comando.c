/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executa_comando.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 23:22:10 by user42            #+#    #+#             */
/*   Updated: 2021/04/29 23:23:36 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	executa_comando(t_v *v)
{
	if (ft_strncmp(v->cmd.filename, "pwd",3) == 0)
		get_pwd(v);
	else if (ft_strncmp(v->cmd.filename, "cd",2) == 0)
		get_cd(v);
}
