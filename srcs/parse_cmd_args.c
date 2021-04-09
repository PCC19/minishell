/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 23:06:16 by user42            #+#    #+#             */
/*   Updated: 2021/04/09 23:59:55 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse_cmd_args(t_v *v, int *k)
{
	char *cmdeargs;
	char aux[MIL];

	ft_bzero(aux, MIL);

	printf("------- parse_cmd_args ---------------\n");
	*k = 0;
	printf("vexp: |%s|\n", v->expandido);
	while (!(ft_is_in(v->expandido[*k], "><"))
			&& *k < (int)ft_strlen(v->expandido))
		(*k)++;
	//ate la pode guardar como comando + arg (checar com execc tem que receber) 
	ft_memcpy(aux, v->expandido, *k);
	cmdeargs = ft_strtrim(aux, " ");
	v->cmd.cmd_args = ft_split(cmdeargs, ' ');
	v->cmd.filename = ft_strdup(v->cmd.cmd_args[0]);
	printf("cmd_args:\n");
	u_print_array_bi(v->cmd.cmd_args);
	printf("filename: %s\n", v->cmd.filename);
	printf("---------------------------------\n");
	free(cmdeargs);
}
