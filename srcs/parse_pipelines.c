/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pipelines.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 03:47:00 by user42            #+#    #+#             */
/*   Updated: 2021/04/13 04:03:41 by user42           ###   ########.fr       */
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
		// MAPEIA STDS
		// se eh primeiro
			// cria pipe posterior
			// STDIN = STDIN ou redirect se houver
			// STDOUT = entrada do pipe_pos ou redirect se houver
		// se eh meio
			// pipe_ant = pipe_pos
			// STDIN = saida do pipe ant ou redirect se houver
			// STDOUT = entrada do pipe_pos ou redirect se houver
		// se eh ultimo
			// pipe ant = pipe_pos
			// STDIN =  eh saida do pipe_ant ou redirect se houver
			// STDOUT = STDOUT ou redirect se houver
		// EXECUTA COMANDO
		// RESTAURA STDS

	// se eh 

/*Aaaaaa |1  bbbbb |2 cccccc  |3 dddd 
Cria 2 pipes (anterior e posterior) 
Anterior = vazio 
Posteiror = 1 
Se eh 1o: 
 Le do stdin (sujeito a redir) 
 Escreve no in do pipe1 (sujeito a redir) 
Se eh 2o, 
 Anteiror = 1 
 Posterior = 2 
 Le out do pipe 1 
 Escrev no in do pipe 2 
Se eh 3o, 
 Anterior = 2 
 Posteiror = 3 
 Le out do pipe 2 
 Escreve no in do pipe 3 
Se eh ult 
 Anterior =3 
 Posteiror = vazio 
*/
	// EXECUCAO DO COMANDO
	
		// TESTE DOS REDIRECTS (PODE APAGAR)
		char teste_str[MIL] = "teste\n";
		/*
		int n = 5;
		//read(v->cmd.fd_in, teste_str, n);
		//teste_str[n] = 0;
		write(v->cmd.fd_out, teste_str, n + 1);
		debug("teste");
		*/
	

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

