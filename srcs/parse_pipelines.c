/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pipelines.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 03:47:00 by user42            #+#    #+#             */
/*   Updated: 2021/04/22 02:16:40 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

void	executa_comando_1(t_v *v)
{
	(void) v;
	char teste_str[10];
	ft_bzero(teste_str,10);
	
	read(STDIN_FILENO, &teste_str, 5);
	write(STDOUT_FILENO, &teste_str, 5);
}

void	executa_comando_2(t_v *v)
{
	(void) v;
	char teste_str[10];
	ft_bzero(teste_str,10);
	
	scanf("%s", teste_str);
	printf("%s\n", teste_str);
}

int	parse_pipelines(t_v *v, char *linha)
{
	char	**aux;
	char	*s;
	int		n;
	int		i;

	aux = ft_split2(linha, '|');
	n = ft_conta_linhas(aux);
	v->pipelines = (char **)malloc(sizeof(char *) * (n + 1));
	init_struct_cmd(v);

	//// SALVA STDS
	v->cmd.save_in = dup(STDIN_FILENO);
	v->cmd.save_out = dup(STDOUT_FILENO);

	v->cmd.fd_in = STDIN_FILENO;

	i = 0;
	while(aux[i])
	{
		s = ft_strdup(aux[i]);
		v->pipelines[i] = ft_strtrim(s, " "); // PRECISA DESTA LINHA ???
		printf("\n\n\npipeline : |%s|\n", v->pipelines[i]);
		parse_s(v, v->pipelines[i]);

		// cria pipe
		pipe(v->cmd.pipe);
		// Mapeia stdout para entrada do pipe
		v->cmd.fd_out = v->cmd.pipe[PIPE_IN];
		redirect_handler(v, v->cmd.fd_in, v->cmd.fd_out);
			u_print_struct_cmd(v);

		fd_handler(v->cmd.fd_in, v->cmd.fd_out);

		// EXECUTA
		dprintf(v->cmd.save_in, "\nExecutando comando ... \n\n");
		executa_comando_2(v);

		// Close stdout e fds e remapeia entrada do proximo !
		close(v->cmd.fd_out);
		if (v->cmd.fd_in != 0)
			close(v->cmd.fd_in);
		v->cmd.fd_in = v->cmd.pipe[PIPE_OUT];
		// restaura fds	
		dup2(v->cmd.save_in, STDIN_FILENO);
		dup2(v->cmd.save_out, STDOUT_FILENO);
		close(v->cmd.save_in);
		close(v->cmd.save_out);
		printf("Apos restaura fds\n");
		u_print_struct_cmd(v);
		// FIM LOOP
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
