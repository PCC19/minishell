/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 18:08:52 by user42            #+#    #+#             */
/*   Updated: 2021/04/09 23:58:35 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse_redirects(t_v *v)
{
	int	k;

	parse_cmd_args(v, &k);
//    para cada redirect 
	printf("corte: |%s|\n", v->expandido + k);
	while (v->expandido[k] != 0)
	{
		break;
		// se for <
			// abre arquivo
			// seta fd

		// se for >
			// se prox for > tb append senao trunca
	}

/*
Precisa de estrutura para guardar 
    cmd + args 
    fd in 
    fd out 
    status de retorno 
*/
}
