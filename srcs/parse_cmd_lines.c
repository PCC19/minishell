/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_lines.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <cpereira@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 00:41:53 by user42            #+#    #+#             */
/*   Updated: 2021/05/26 03:24:52 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/minishell.h"

int	parse_cmd_lines(t_v *v, char *linha)
{
	char	**aux;
	char	*s;
	int		n;
	int		p;
	int		i;
	int		z;
	pid_t	pidf;

	//init_cmd_args(v);
	aux = ft_split3(linha, ';');
	n = ft_count_lines(aux);
	//v->cmd_lines = (char **)malloc(sizeof(char *) * (n + 1));
	v->cmd_lines = (char **)safe_malloc(sizeof(char *) * (n + 1));
	i = 0;
	p = 0;
	z = 0;
	while(aux[i] && v->flag_exit == 0)
	{
		init_cmd_args(v);
		if (ft_strlen(aux[i]) > 0)
		{
			check_n_free(v->curr_comand);
			v->curr_comand = ft_strdup(aux[i]);
			s = ft_strdup(aux[i]);
			v->cmd_lines[i] = ft_strtrim(s, " ");
			parse_pipelines(v, v->cmd_lines[p]);
			u_free_array_bi(v->pipelines);
			free(s);
			p++;

			if (v->cmd.ret_status == -1)
			{
				write_error(v);
				free(v->curr_comand);
				ft_bzero(v->ret,2048);
				pidf = getpid();
				kill(pidf, SIGKILL);
			}

		}
		i++;
	}
	v->cmd_lines[p] = 0;
	while (z < p )
	{
		free(v->cmd_lines[z]);
		z++;
	}
	free(v->cmd_lines);
	u_free_array_bi(aux);
	return (0);
}
