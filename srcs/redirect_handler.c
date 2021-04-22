/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 01:52:30 by user42            #+#    #+#             */
/*   Updated: 2021/04/22 01:59:32 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	redirect_handler(t_v *v, int in, int out)
{
	int	k;

	k = 0;
	while (v->expandido[k] != 0)
	{
		if (v->expandido[k] == '<')
			parse_in_red(v, &k, in);
		else if (v->expandido[k] == '>')
			parse_out_red(v, &k, out);
		else if (v->expandido[k] == SPC)
			ff(v->expandido, &k);
		else
			parse_cmd_args(v, &k);
	}
}
