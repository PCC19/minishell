/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_block.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 16:58:13 by user42            #+#    #+#             */
/*   Updated: 2021/07/08 17:38:24 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse_block(t_v *v)
{
	int k;

	k = 0;
	while (v->expanded[k] != 0)
	{
		if (v->expanded[k] == ' ')
			ff(v->expanded, &k);
		else if (v->expanded[k] == '\"')
			parse_quote_in_redirect(v, &k, "\"");
		else if (v->expanded[k] == '\'')
			parse_quote_in_redirect(v, &k, "\'");
		else if (v->expanded[k] == '<')
			parse_in_red(v, &k, v->cmd.fd_in);
		else if (v->expanded[k] == '>')
			parse_out_red(v, &k, v->cmd.fd_out);
		else
			parse_cmd_args(v, &k);
	}
}
/*
 |   >a   > b <c  cmd    arg >>d "xxxx"  'zzzz' arg arg|



ff (vai ate 1o nao-espaco)
3 se for > (adicionar mov cursor)
	se proximo for >
		processa >>
	senao
		processa >

se for <
	se proximo for <
		5 processa <<
	senao
		4 processa < (adicionar mov cursor)

se for " ou '
	2 processa aspas
		copia da aspa de abertura ate proxima aspa
		adiciona ao cmd_args
		deixa cursor apos ult aspa

se for char
	1 processa char
		copia ate ult char que nao seja spc / quotes / < / >
		deixa cursor no prox char (inc + ff)
	
=====================================
ok1) REFATORAR PASE: Mudar parse (andamento do cursor etc)
	usar rotina de acionar ao array_bi
		DEBUGAR: printar char de saida de cada parse
		NOTA: hardcode no main de > < no primeiro char

2) HEREDOC
	2a) Alterar parse existente
		seta flag
		pega string de eof

	2b) Rotina do readline
		cria pipe
		faz redirect do pipe temporario
		printa no pipe temp

	2c) Apos comando
		fechar pipe temporario
	
Restauracao dos fds segue normal


*/

