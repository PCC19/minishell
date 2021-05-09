/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_caps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <cpereira@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 15:20:26 by cpereira          #+#    #+#             */
/*   Updated: 2021/05/09 06:32:37 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void sighandler(int signum)
{
	if (signum == 18)
		printf("Ctrl = C\n");

	if (signum == 2)
		exit (0);
	if (signum == 3)
	{
		printf("Ctrl = a\n");
		exit (0);
	}
	//printf("signal %d\n",signum);
	printf("Caught signal %d, coming out...\n", signum);
}

void config_term(t_v *v)
{
	char ret[2048];
	tgetent(ret, getenv("TERM"));
	tcgetattr(0,&v->old);
	tcgetattr(0,&v->term);
	signal( SIGINT, sighandler );
	v->term.c_lflag &= ~(ECHO);
	v->term.c_lflag &= ~(ICANON);
	v->term.c_lflag &= ~(ISIG);
	v->term.c_cc[VMIN] = 1;
    v->term.c_cc[VTIME] = 0;
	tcsetattr(0,TCSANOW,&v->term);
}

int my_termprint(int c)
{
	return write(1, &c, 1);
}


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
