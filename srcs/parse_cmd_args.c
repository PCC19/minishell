/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 23:06:16 by user42            #+#    #+#             */
/*   Updated: 2021/04/18 22:47:11 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse_cmd_args(t_v *v, int *k)
{
	char *cmdeargs;
	char aux[MIL];

	ft_bzero(aux, MIL);
	//printf("in_parse_args  k: %d\t|%s|\n", *k, &v->expandido[*k]);
	copy_until(aux, v->expandido, "<>", k);
	//printf("aux: |%s|\n", aux);
	cmdeargs = ft_strtrim(aux, " ");
	v->cmd.cmd_args = ft_split2(cmdeargs, ' ');
	v->cmd.filename = ft_strdup(v->cmd.cmd_args[0]);
	u_print_array_bi(v->cmd.cmd_args);
	//printf("out_parse_args k: %d\t|%s|\n", *k, &v->expandido[*k]);
	//printf("filename: %s\n", v->cmd.filename);
	free(cmdeargs);
}
