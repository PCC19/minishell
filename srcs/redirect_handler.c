/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <cpereira@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 01:52:30 by user42            #+#    #+#             */
/*   Updated: 2021/07/07 16:57:57 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	redirect_handler(t_v *v, int i, int n)
{
	int	k;

	pipe(v->cmd.pipe);
	v->cmd.fd_out = v->cmd.pipe[PIPE_IN];
	k = 0;
	parse_block(v); // nome da nova funcao. Retirar var k deste codigo.
//	while (v->expanded[k] != 0)
//	{
//		if (v->expanded[k] == '\"')
//			parse_quote_in_redirect(v, &k, "\"");
//		else if (v->expanded[k] == '\'')
//			parse_quote_in_redirect(v, &k, "\'");
//		else if (v->expanded[k] == '<')
//			parse_in_red(v, &k, v->cmd.fd_in);
//		else if (v->expanded[k] == '>')
//			parse_out_red(v, &k, v->cmd.fd_out);
//		else if (v->expanded[k] == SPC)
//			ff(v->expanded, &k);
//		else
//			parse_cmd_args(v, &k);
//	}
	if (i == 0 && v->cmd.fd_in_red == -1)
		v->cmd.fd_in = STDIN_FILENO;
	if (i == (n - 1) && v->cmd.fd_out_red == -1)
		v->cmd.fd_out = STDOUT_FILENO;
}
