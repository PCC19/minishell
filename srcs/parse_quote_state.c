/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_quote_state.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 03:06:54 by user42            #+#    #+#             */
/*   Updated: 2021/05/25 04:11:27 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_state_parse_s	parse_quote_state(char *s, int k)
{
	int	i;
	t_state_parse_s	state;

	state = NORMAL;
	i = 0;
	while(i <= k)
	{
		parse_dq(s[i], &k, &state);
		parse_sq(s[i], &k, &state);
		i++;
	}
	printf("k %d i %d c; %c state: %d\n",k ,i-1, s[i-1], state);
	printf("saiu\n");
	return (state);
}
