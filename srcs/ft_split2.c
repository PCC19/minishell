/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 17:11:47 by user42            #+#    #+#             */
/*   Updated: 2021/04/19 00:40:05 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include "minishell.h"

int		ft_conta_palavras2(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

char	*malloc_palavra2(char const *s, char c)
{
	char	*palavra;
	int		i;

	i = 0;
	while (s[i] && !(s[i] == c))
		i++;
	palavra = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (s[i] && !(s[i] == c))
	{
		palavra[i] = s[i];
		i++;
	}
	palavra[i] = '\0';
	return (palavra);
}

char	**init_array(char const *s, char c)
{
	char	**out;
	int		i;

	if (s == NULL)
		return (NULL);
	out = (char **)malloc(sizeof(char *) * (ft_conta_palavras2(s, c) + 1));
	i = 0;
	while (i < ft_conta_palavras2(s, c) + 1)
	{
		out[i] = (char*)malloc(MIL);
		ft_bzero(out[i], MIL);
		i++;
	}
	return (out);
}

char	**ft_split2(char const *s, char c)
{
	char					**out;
	int						i;
	int						j;
	int						k;
	t_estado_parse_s		estado;

	i = 0;
	j = 0;
	k = 0;
	estado = NORMAL;
	out = init_array(s, c);
	while (s[i] != 0)
	{
		if ((s[i] == c && estado == NORMAL) || s[i] == 0)
		{
			out[j++][k] = 0;
			k = 0;
		}
		else
			out[j][k++] = s[i];
		parse_sq(s[++i], &i, &estado);
		parse_dq(s[i], &i, &estado);
	}
	out[++j] = 0;
	return (out);
}
