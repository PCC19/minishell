/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 17:40:43 by user42            #+#    #+#             */
/*   Updated: 2021/07/08 18:27:53 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_heredoc(t_v *v)
{
	char *line;

	// pega string eof
		printf("flag_heredoc: %d\n", v->flag_heredoc);
		printf("eof: |%s|\n", v->eof);
	line = readline(">");
		printf("line: |%s|\n", line);
	free(line);



}
