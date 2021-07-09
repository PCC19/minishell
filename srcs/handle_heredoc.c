/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 17:40:43 by user42            #+#    #+#             */
/*   Updated: 2021/07/09 21:49:10 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_heredoc(t_v *v)
{
	char *line;

	// pega string eof
//		printf("flag_heredoc: %d\n", v->flag_heredoc);
//		printf("eof: |%s|\n", v->eof);
		// Cria pipe
		// Primeira linha
	line = readline(">");
	printf("%s\n", line);
	add_line_to_array_bi(v, line);
		// Demais linhas
	while (ft_strncmp(line, v->eof, ft_strlen(v->eof)))
	{
		free(line);
		line = readline(">");
		printf("%s\n", line);
		add_line_to_array_bi(v, line);
	}
	free(line);
}
