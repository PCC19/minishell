/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 18:08:52 by user42            #+#    #+#             */
/*   Updated: 2021/04/10 21:18:03 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse_redirects(t_v *v)
{
	int	k;

	parse_cmd_args(v, &k);
//    para cada redirect 
	//printf("corte: |%s|\n", v->expandido + k);
	while (v->expandido[k] != 0)
	{
		parse_in_red(v, &k);
		parse_out_red(v, &k);
		k++;
	}
	//printf("     fd: in->%d out->%d\n", v->cmd.fd_in, v->cmd.fd_out);
	u_print_struct_cmd(v);
	// TESTE DOS REDIRECTS (PODE APAGAR)
	/*char teste_str[MIL] = "teste\n";
	int n = 5;
	read(v->cmd.fd_in, teste_str, n);
	teste_str[n] = 0;
	write(v->cmd.fd_out, teste_str, n + 1);
	if (v->cmd.fd_in > 1)
		close(v->cmd.fd_in);
	if(v->cmd.fd_out > 1)
		close(v->cmd.fd_out);
	*/
}
