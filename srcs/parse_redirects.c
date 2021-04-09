/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 18:08:52 by user42            #+#    #+#             */
/*   Updated: 2021/04/09 18:42:44 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse_redirects(t_v *v)
{
	int	k;
	char *cmdeargs;

	cmdeargs = ft_calloc(1000,sizeof(char));

// Parse do cmd 
	//vai para o primeiro redirect 
	k = 0;
	while (!(ft_is_in(*v->expandido, "><")) && k < (int)ft_strlen(v->expandido))
		k++;
	//ate la pode guardar como comando + arg (checar com execc tem que receber) 
	ft_memcpy(cmdeargs, v->expandido, k);
	printf("cmdargs; |%s|\n", cmdeargs);
	free(cmdeargs);
/*    para cada redirect 
       open arquivo criando 
        seta os fds com dups 

Precisa de estrutura para guardar 
    cmd + args 
    fd in 
    fd out 
    status de retorno 
*/
}
