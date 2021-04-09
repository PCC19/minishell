/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pipelines.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 03:47:00 by user42            #+#    #+#             */
/*   Updated: 2021/04/09 23:51:39 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

int	parse_pipelines(t_v *v, char *linha)
{
	char	**aux;
	char	*s;
	int		n;

	aux = ft_split(linha, '|');
	n = ft_conta_linhas(aux);
	v->pipelines = (char **)malloc(sizeof(char *) * (n + 1));
	int i = 0;
	while(aux[i])
	{
		s = ft_strdup(aux[i]);
		v->pipelines[i] = ft_strtrim(s, " ");
		printf("pipeline : |%s|\n", v->pipelines[i]);
		parse_s(v, v->pipelines[i]);
		parse_redirects(v);
			// faz pipe para proximo se houver
		u_free_array_bi(v->cmd.cmd_args);
		free(v->cmd.filename);
		free(v->expandido);
		free(s);
		i++;
	}
	v->pipelines[i] = 0;
	u_free_array_bi(aux);
	return (0);
}

