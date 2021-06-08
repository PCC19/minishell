/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_last_path2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 00:15:46 by user42            #+#    #+#             */
/*   Updated: 2021/06/09 00:27:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *get_last_path2(char *str)
{
	char	**split_str;
	int		i;

	split_str = ft_split3(str, '/');
	i = 0;
	while (split_str[i])
		i++;
	if (i>0)
		i--;

	free(str);
	str = ft_strdup(split_str[i]);
	return (str);
}
