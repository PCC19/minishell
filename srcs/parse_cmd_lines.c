/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_lines.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 00:41:53 by user42            #+#    #+#             */
/*   Updated: 2021/05/02 00:55:28 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

int	parse_cmd_lines(t_v *v, char *linha)
{
	char	**aux;
	char	*s;
	int		n;

	v->cmd = (t_cmd){0};
	aux = ft_split3(linha, ';');
		//u_print_array_bi(v, aux);
	n = ft_conta_linhas(aux);
	v->cmd_lines = (char **)malloc(sizeof(char *) * (n + 1));
	int i = 0;
	while(aux[i] && v->flag_exit == 0)
	{
		s = ft_strdup(aux[i]);
		v->cmd_lines[i] = ft_strtrim(s, " ");
		printf("===============================\n");
		printf("parsing pipelines ... \n");
		printf("===============================\n");
		parse_pipelines(v, v->cmd_lines[i]);
		u_free_array_bi(v->pipelines);
		free(s);
		i++;
	}
	v->cmd_lines[i] = 0;
	u_free_array_bi(aux);
	return (0);
}
