/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_term.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 17:25:26 by user42            #+#    #+#             */
/*   Updated: 2021/05/10 17:25:36 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int verify_term(t_v *v, char *ret)
{
	if (!ft_strncmp("\e[A",ret,3)) // cima
	{
		tputs(restore_cursor,1,my_termprint);
		tputs(tigetstr("ed"),1,my_termprint); //kL
		v->ret2 = ft_strdup(v->hist[v->posic_hist]);
		ft_putstr_fd(v->ret2,1);
		if (v->posic_hist <= 0)
			v->posic_hist = 0;
		else
			v->posic_hist --;
		ret[0] = 0;
		return (1);
	}
	if (!ft_strncmp("\e[B",ret,3)) // baixo
	{
		tputs(restore_cursor,1,my_termprint);
		tputs(tigetstr("ed"),1,my_termprint);
		v->ret2 = ft_strdup(v->hist[v->posic_hist]);
		ft_putstr_fd(v->ret2,1);
		if (v->posic_hist >= v->qtd_hist - 1)
			v->posic_hist = v->qtd_hist - 1;
		else
			v->posic_hist ++;
		ret[0] = 0;
		return (1);
	}
	if (!ft_strncmp("\e[C",ret,3)) //  direita
	{
		tputs(restore_cursor,1,my_termprint);
		tputs(tigetstr("ri"),1,my_termprint); // ed
		//ft_putstr_fd("cc",1);
		//ft_bzero(ret,2048);
		//ret2 = ft_strdup("");
		//write (1,"dir\n",3);
		ret[0] = 0;
		return (1);
	}
	else if (!ft_strncmp("\e[D",ret,3)) //  esquerda
	{
		tputs(restore_cursor,1,my_termprint);
		tputs(tigetstr("le"),5,my_termprint); // ed
		ret[0] = 0;
		return (1);
	}
	if (ret[0] == 127) //backspace
	{
		tputs(restore_cursor,1,my_termprint);
		tputs(tigetstr("ed"),1,my_termprint);
		//tputs(tigetstr("kD"),1,my_termprint);
		v->ret2[ft_strlen(v->ret2)-1] = 0;
		ft_putstr_fd(v->ret2,1);
		return (1);
	}
	if (ret[0] == 3) // CTRL+C
	{
		ft_bzero(v->ret2, 2048);
		ft_bzero(v->ret, 2048);
		ft_putstr_fd("\n", 1);
		ft_putstr_fd(v->prompt1,1);
		tputs(save_cursor,1,my_termprint);

	}
	if (ret[0] == 4) // CTRL +D
		exit_msh(v);
	return (0);



}
