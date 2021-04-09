/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 01:19:17 by user42            #+#    #+#             */
/*   Updated: 2021/04/09 03:24:15 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include "libft.h"
# include "get_next_line.h"
# include <string.h>

typedef enum	e_estado_parse_s
{
				NORMAL,
				SINGLE_QUOTE,
				DOUBLE_QUOTE
}				t_estado_parse_s;


typedef struct	s_v{
	char **cmd_lines;
	char **pipelines;
	char **cmd;
	char *expandido;
	char **env;
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



