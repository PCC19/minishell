/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pipelines.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 03:47:00 by user42            #+#    #+#             */
/*   Updated: 2021/04/13 17:46:01 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

int	parse_pipelines(t_v *v, char *linha)
{
	char	**aux;
	char	*s;
	int		n;
	int		i;

	aux = ft_split(linha, '|');
	n = ft_conta_linhas(aux);
	v->pipelines = (char **)malloc(sizeof(char *) * (n + 1));
	i = 0;
	while(aux[i])
	{
		s = ft_strdup(aux[i]);
		v->pipelines[i] = ft_strtrim(s, " "); // PRECISA DESTA LINHA ???
		printf("\n\n\npipeline : |%s|\n", v->pipelines[i]);
		parse_s(v, v->pipelines[i]);
		parse_redirects(v);
		// SALVA STDS
		v->cmd.save_in = dup(STDIN_FILENO);
		v->cmd.save_out = dup(STDOUT_FILENO);
		// Cria Pipes (mesmo que nao sejam usados)
		pipe(v->cmd.pipe_ant);
		pipe(v->cmd.pipe_pos);
		// MAPEIA STDS
		// se eh primeiro
		if (i == 0)
		{
			// STDIN = STDIN ou redirect se houver
			if (v->cmd.fd_in_red == -1)
				dup2(v->cmd.save_in, STDIN_FILENO);
			else
				dup2(v->cmd.fd_in_red, STDIN_FILENO);	// FAZ STDIN LER DA SAIDA DO PIPE
			// STDOUT = entrada do pipe_pos ou redirect se houver
			if (v->cmd.fd_out_red == -1)
				dup2(v->cmd.pipe_pos[IN], STDOUT_FILENO);
			else
				dup2(v->cmd.save_out, STDOUT_FILENO);
			dprintf(v->cmd.save_out,"stdin: %d\t\t stdout: %d\n", STDIN_FILENO, STDOUT_FILENO);
		}
		// se eh meio
		if (i > 0)
		{
			// pipe_ant = pipe_pos
			v->cmd.pipe_ant[IN] = v->cmd.pipe_pos[IN];
			v->cmd.pipe_ant[OUT] = v->cmd.pipe_pos[OUT];
			// STDIN = saida do pipe ant ou redirect se houver
			if (v->cmd.fd_in_red == -1)
				dup2(v->cmd.pipe_ant[OUT], STDIN_FILENO);
			else
				dup2(v->cmd.fd_in_red, STDIN_FILENO);	// FAZ STDIN LER DA SAIDA DO PIPE
			// STDOUT = entrada do pipe_pos ou redirect se houver
			if (v->cmd.fd_out_red == -1)
				dup2(v->cmd.pipe_pos[IN], STDOUT_FILENO);
			else
				dup2(v->cmd.fd_out_red, STDOUT_FILENO);
			dprintf(v->cmd.save_out,"stdin: %d\t\t stdout: %d\n", STDIN_FILENO, STDOUT_FILENO);
		}
		// se eh ultimo
		if (i == n - 1)
		{
			// pipe_ant = pipe_pos
			v->cmd.pipe_ant[IN] = v->cmd.pipe_pos[IN];
			v->cmd.pipe_ant[OUT] = v->cmd.pipe_pos[OUT];
			// STDIN = saida do pipe ant ou redirect se houver
			if (v->cmd.fd_in_red == -1)
				dup2(v->cmd.pipe_ant[OUT], STDIN_FILENO);
			else
				dup2(v->cmd.fd_in_red, STDIN_FILENO);	// FAZ STDIN LER DA SAIDA DO PIPE
			// STDOUT = STDOUT ou redirect se houver
			if (v->cmd.fd_out_red == -1)
				dup2(v->cmd.save_out, STDOUT_FILENO);
			else
				dup2(v->cmd.fd_out_red, STDOUT_FILENO);
			dprintf(v->cmd.save_out,"stdin: %d\t\t stdout: %d\n", STDIN_FILENO, STDOUT_FILENO);
		}
		// EXECUTA COMANDO
			// io
			char teste_str[10];
			ft_bzero(teste_str,10);
			scanf("%s", teste_str);
			printf("%s\n", teste_str);
		// RESTAURA STDS
		dup2(v->cmd.save_in, STDIN_FILENO);
		dup2(v->cmd.save_out, STDOUT_FILENO);
/*
	// EXECUCAO DO COMANDO
	
		// TESTE DOS REDIRECTS (PODE APAGAR)
		char teste_str[MIL] = "teste\n";
		//
		//int n = 5;
		////read(v->cmd.fd_in, teste_str, n);
		////teste_str[n] = 0;
		//write(v->cmd.fd_out, teste_str, n + 1);
		//debug("teste");
	
		// salva stds
		int save_in = dup(STDIN_FILENO);
		int save_out = dup(STDOUT_FILENO);

		// duplica
		dup2(v->cmd.fd_in_red, 0);
		dup2(v->cmd.fd_out_red, 1);

		// io
		scanf("%s", teste_str);
		printf("%s\n", teste_str);

		// restaura
		dup2(save_in, 0);
		dup2(save_out,1);

		if (v->cmd.fd_in_red > 1)
		{
			debug("closing fd %d",v->cmd.fd_in_red);
			close(v->cmd.fd_in_red);
		}		
		if(v->cmd.fd_out_red > 1)
		{
			debug("closing fd %d",v->cmd.fd_out_red);
			close(v->cmd.fd_out_red);
		}
	// FIM EXECUCAO DO COMANDO
*/

		// frees	
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
