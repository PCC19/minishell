/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_print_array_bi.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <cpereira@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 22:11:16 by user42            #+#    #+#             */
/*   Updated: 2021/07/09 20:52:36 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	u_print_array_bi(t_v *v, char **s)
{
	int	i;

	(void) v;
	if (s != NULL)
	{
		i = 0;
		while (s[i] != 0)
		{
			printf("%s\n", (s[i]));
			i++;
		}
	}
}

void	u_print_array_bi_fd(t_v *v, char **s, int fd)
{
	int	i;

	(void) v;
	if (s != NULL)
	{
		i = 0;
		while (s[i] != 0)
		{
			dprintf(fd, "%s\n", (s[i]));
			i++;
		}
	}
}
