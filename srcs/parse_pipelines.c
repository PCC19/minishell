/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pipelines.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 03:47:00 by user42            #+#    #+#             */
/*   Updated: 2021/04/14 19:07:28 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

void	executa_comando_1(t_v *v)
{
	char teste_str[10];
	// io
	ft_bzero(teste_str,10);
	
	read(v->cmd.fd_in, &teste_str, 5);
	write(v->cmd.fd_out, &teste_str, 5);
	
	//close(v->cmd.fd_in);
	//close(v->cmd.fd_out);

}

void	executa_comando_2(t_v *v)
{
	char teste_str[10];
	// io
	ft_bzero(teste_str,10);
	
	//// SALVA STDS
	v->cmd.save_in = dup(STDIN_FILENO);
	v->cmd.save_out = dup(STDOUT_FILENO);
	printf("save_in: %d\t\t save_out: %d\n", v->cmd.save_in, v->cmd.save_out);

	// REDIRECIONA FDS
	dup2(v->cmd.fd_out, STDOUT_FILENO);	// JOGA STDOUT PARA ENTRADA DO PIPE
	dup2(v->cmd.fd_in, STDIN_FILENO);	// FAZ STDIN LER DA SAIDA DO PIPE
	
	// Excuta o comando
	scanf("%s", teste_str);
	printf("%s\n", teste_str);

	close (v->cmd.fd_out);
	close (v->cmd.fd_in);
	close(STDIN_FILENO);
	close(STDOUT_FILENO);

	// restaura fds	
	dup2(v->cmd.save_in, STDIN_FILENO);
	dup2(v->cmd.save_out, STDOUT_FILENO);

}


int	parse_pipelines(t_v *v, char *linha)
{
	char	**aux;
	char	*s;
	int		n;
	int		i;

	aux = ft_split(linha, '|');
	n = ft_conta_linhas(aux);
	v->pipelines = (char **)malloc(sizeof(char *) * (n + 1));
	//// SALVA STDS
	//v->cmd.save_in = dup(STDIN_FILENO);
	//v->cmd.save_out = dup(STDOUT_FILENO);
	//printf("save_in: %d\t\t save_out: %d\n", v->cmd.save_in, v->cmd.save_out);

	// Cria Pipes (mesmo que nao sejam usados)
	int aaa = 10;
	pipe(v->cmd.pipe_ant);
	pipe(v->cmd.pipe_pos);
	fcntl(v->cmd.pipe_ant[IN], F_SETFL, O_NONBLOCK);
	fcntl(v->cmd.pipe_ant[OUT], F_SETFL, O_NONBLOCK);
	fcntl(v->cmd.pipe_pos[IN], F_SETFL, O_NONBLOCK);
	fcntl(v->cmd.pipe_pos[OUT], F_SETFL, O_NONBLOCK);

	dprintf(1,"pipe_ant[in]:%d\t\tpipe_ant[out]:%d\n", v->cmd.pipe_ant[IN], v->cmd.pipe_ant[OUT]); 
	dprintf(1,"pipe_pos[in]:%d\t\tpipe_pos[out]:%d\n", v->cmd.pipe_pos[IN], v->cmd.pipe_pos[OUT]); 
	dprintf(1, "aaa %d\n", aaa);

	i = 0;
	while(aux[i])
	{
		s = ft_strdup(aux[i]);
		v->pipelines[i] = ft_strtrim(s, " "); // PRECISA DESTA LINHA ???
		printf("\n\n\npipeline : |%s|\n", v->pipelines[i]);
		parse_s(v, v->pipelines[i]);
		parse_redirects(v);
		// MAPEIA STDS
		// se eh primeiro
		if (i == 0)
		{
			printf("PRIMEIRO\n");
			dprintf(1,"pipe_ant[in]:%d\t\tpipe_ant[out]:%d\n", v->cmd.pipe_ant[IN], v->cmd.pipe_ant[OUT]); 
			dprintf(1,"pipe_pos[in]:%d\t\tpipe_pos[out]:%d\n", v->cmd.pipe_pos[IN], v->cmd.pipe_pos[OUT]); 
			dprintf(1, "aaa %d\n", aaa);
			// STDIN = STDIN ou redirect se houver
			if (v->cmd.fd_in_red == -1)
				v->cmd.fd_in = STDIN_FILENO;
			else
				v->cmd.fd_in = v->cmd.fd_in_red;
			// STDOUT = entrada do pipe_pos ou redirect se houver
			if (v->cmd.fd_out_red == -1)
				v->cmd.fd_out = v->cmd.pipe_pos[IN];
			else
				v->cmd.fd_out = v->cmd.fd_out_red;
			if (i == n - 1)
				v->cmd.fd_out = STDOUT_FILENO;
			dprintf(1, "1o fd_in: %d\t\t fd_out: %d\n", v->cmd.fd_in, v->cmd.fd_out);
		}
		else
		{
		// se eh meio
			if (i > 0)
			{
				printf("MEIO\n");
				// pipe_ant = pipe_pos
				v->cmd.pipe_ant[IN] = v->cmd.pipe_pos[IN];
				v->cmd.pipe_ant[OUT] = v->cmd.pipe_pos[OUT];
				// STDIN = saida do pipe ant ou redirect se houver
				if (v->cmd.fd_in_red == -1)
					v->cmd.fd_in = v->cmd.pipe_ant[OUT];
				else
					v->cmd.fd_in = v->cmd.fd_in_red;	// FAZ STDIN LER DA SAIDA DO PIPE
				// STDOUT = entrada do pipe_pos ou redirect se houver
				if (v->cmd.fd_out_red == -1)
					v->cmd.fd_out = v->cmd.pipe_pos[IN];
				else
					v->cmd.fd_out = v->cmd.fd_out_red;
				dprintf(v->cmd.save_out,"me fd_in: %d\t\t fd_out: %d\n", v->cmd.fd_in, v->cmd.fd_out);
			}
			// se eh ultimo
			if (i == n - 1)
			{
				printf("ULTIMO\n");
				// pipe_ant = pipe_pos
				v->cmd.pipe_ant[IN] = v->cmd.pipe_pos[IN];
				v->cmd.pipe_ant[OUT] = v->cmd.pipe_pos[OUT];
				// STDIN = saida do pipe ant ou redirect se houver
				if (v->cmd.fd_in_red == -1)
					v->cmd.fd_in = v->cmd.pipe_ant[OUT];
				else
					v->cmd.fd_in = v->cmd.fd_in_red;	// FAZ STDIN LER DA SAIDA DO PIPE
				// STDOUT = STDOUT ou redirect se houver
				if (v->cmd.fd_out_red == -1)
					v->cmd.fd_out = STDOUT_FILENO;
				else
					v->cmd.fd_out = v->cmd.fd_out_red;
				dprintf(v->cmd.save_out,"ul  fd_in: %d\t\t fd_out: %d\n", v->cmd.fd_in, v->cmd.fd_out);
			}
		}
		u_print_struct_cmd(v);
		// EXECUTA COMANDO
		executa_comando_2(v);
		//// RESTAURA STDS
		//dup2(v->cmd.save_in, STDIN_FILENO);
		//dup2(v->cmd.save_out, STDOUT_FILENO);
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
