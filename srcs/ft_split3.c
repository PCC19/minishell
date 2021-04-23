/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 02:21:52 by user42            #+#    #+#             */
/*   Updated: 2021/04/23 02:32:35 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"
#include <stdlib.h>
#include "minishell.h"


int		ft_count_words(char const *s, char c)
{
	int i;
	int	count;
	t_estado_parse_s		estado;

	count = 1;
	estado = NORMAL;
	i = 0;
	while (s[i] != 0)
	{
		if (s[i] == c && estado == NORMAL);
			count++;
		i++;
		parse_sq(s[i], &i, &estado);
		parse_dq(s[i], &i, &estado);
	}
	return (count);
}


char	**ft_split3(char const *s, char c)
{


}

