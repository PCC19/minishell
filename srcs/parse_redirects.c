/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 18:27:17 by user42            #+#    #+#             */
/*   Updated: 2021/04/14 00:13:59 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse_redirects(t_v *v)
{
	int	k;

	init_struct_cmd(v);
	k = 0;
	while (v->expandido[k] != 0)
	{
		if (v->expandido[k] == '<')
			parse_in_red(v, &k);
		else if (v->expandido[k] == '>')
			parse_out_red(v, &k);
		else if (v->expandido[k] == SPC)
			ff(v->expandido, &k);
		else
			parse_cmd_args(v, &k);
	}
	//u_print_struct_cmd(v);
}
