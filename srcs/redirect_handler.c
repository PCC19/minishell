/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 01:52:30 by user42            #+#    #+#             */
/*   Updated: 2021/05/26 00:49:51 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	redirect_handler(t_v *v, int i, int n)
{
	int	k;

	k = 0;
	while (v->expanded[k] != 0)
	{
		printf("v->expanded: |%s|\n", v->expanded);
		if (v->expanded[k] == '\"')
			parse_quote_in_redirect(v, &k, "\"");
		else if (v->expanded[k] == '\'')
			parse_quote_in_redirect(v, &k, "\'");
		else if (v->expanded[k] == '<') 
			parse_in_red(v, &k, v->cmd.fd_in);
		else if (v->expanded[k] == '>')
			parse_out_red(v, &k, v->cmd.fd_out);
		else if (v->expanded[k] == SPC)
			ff(v->expanded, &k);
		else
		{
			printf("parse_cmd_args\n");
			parse_cmd_args(v, &k);
			}
	}
	if (i == 0 && v->cmd.fd_in_red == -1)
		v->cmd.fd_in = STDIN_FILENO;
	if (i == (n - 1) && v->cmd.fd_out_red == -1)
		v->cmd.fd_out = STDOUT_FILENO;
}
