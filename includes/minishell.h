/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 01:19:17 by user42            #+#    #+#             */
/*   Updated: 2021/04/09 23:58:00 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include "libft.h"
# include "get_next_line.h"
# include <string.h>
# include <fcntl.h>


# define MIL 1000

typedef enum	e_estado_parse_s
{
				NORMAL,
				SINGLE_QUOTE,
				DOUBLE_QUOTE
}				t_estado_parse_s;

typedef struct	s_cmd{
	char *filename;
	char **cmd_args; // filename eh o arg[0];
	int	fd_in;
	int	fd_out;
}				t_cmd;

typedef struct	s_v{
	char	**cmd_lines;
	char	**pipelines;
	char	*expandido;
	char	**env;
	t_cmd	cmd;
}				t_v;





void	u_print_list(t_list *list);
void	u_print_dlist(t_dlist *list);
void	prints(void *s);
void	u_free_list(t_list *list);
void	u_free_dlist(t_dlist *list);
void	prints(void *s);
int		parse_cmd_lines(t_v *v, char *linha);
int		free_matrizes(char **s);
int		ft_conta_linhas(char **s);
void	u_free_array_bi(char **s);
int		parse_pipelines(t_v *v, char *linha);
void	u_print_array_bi(char **s);
int		parse_s(t_v *v, char *linha);
void	init_env(t_v *v, char **envp);
void	expande(t_v *v, char *linha, int *i, int *j);
void	parse_redirects(t_v *v);
void	parse_cmd_args(t_v *v, int *k);
