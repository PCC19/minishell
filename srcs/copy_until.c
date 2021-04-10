/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_until.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 00:13:47 by user42            #+#    #+#             */
/*   Updated: 2021/04/10 01:17:30 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	copy_until(char *dest, char *source, char *delimiters, int *k)
{
	int i;

	//printf("source: |%s|\n", source);
	//printf("k in: %d\n", *k);
	i = 0;
	while (!(ft_is_in(source[i], delimiters)) && (i) < (int)ft_strlen(source))
		i++;
	//printf("     i: %d\n", i);
	ft_memcpy(dest, &source[0], i);
	//printf("dest  : |%s|\n", dest);
	*k+=i;
	//printf("k out: %d\n", *k);
}
