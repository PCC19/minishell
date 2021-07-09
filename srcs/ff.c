/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ff.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <cpereira@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 18:15:35 by user42            #+#    #+#             */
/*   Updated: 2021/07/09 23:38:09 by pcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ff(char *str, int *k)
{
	(*k)++;
	while (str[*k] == SPC && str[*k] != 0)
		(*k)++;
}

void	ff_until_char(char *str, int *k, char *delimiters)
{
	while (!ft_is_in(str[*k], delimiters) && str[*k] != 0)
		(*k)++;
}
