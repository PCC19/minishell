/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 18:08:52 by user42            #+#    #+#             */
/*   Updated: 2021/04/09 19:19:56 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse_redirects(t_v *v)
{
	int	k;
	char *cmdeargs;
	char *aux;

	aux = ft_calloc(1000,sizeof(char));

	printf("=====================\n");
// Parse do cmd 
	//vai para o primeiro redirect 
	k = 0;
	printf("vexp: |%s|\n", v->expandido);
	while (!(ft_is_in(v->expandido[k], "><"))
			&& k < (int)ft_strlen(v->expandido))
		k++;
	//ate la pode guardar como comando + arg (checar com execc tem que receber) 
	ft_memcpy(aux, v->expandido, k);
	cmdeargs = ft_strtrim(aux, " ");
	printf("cmdargs; |%s|\n", cmdeargs);
//    para cada redirect 
	printf("corte: |%s|\n", v->expandido + k);
	while (v->expandido[k] != 0)
	{
		// se for <
			// abre arquivo
			// seta fd

		// se for >
			// se prox for > tb

		// else
			// eh so >	

	}

/*
Precisa de estrutura para guardar 
    cmd + args 
    fd in 
    fd out 
    status de retorno 
*/
	free(cmdeargs);
	free(aux);
}
