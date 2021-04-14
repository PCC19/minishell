# include <unistd.h>
# include <stdio.h>
# include <curses.h>
#include <term.h>
#include <termcap.h>
# include "minishell.h"
# include "libft.h"
# include "get_next_line.h"

int my_termprint(int c){
	return write(1, &c, 1);
}

	t_v v;
//int main(int argc, char **argv, char **envp)
int	main(void)
{

////char **envp = __environ;
////*	int pid ;
///	pid = fork( );
///	if ( pid == 0 ) {
///		execl ( "/bin/ls","-al", "/media/sf_minishell", NULL ) ;
///		printf ( "Child: After exec( )\n") ; }
///	else
///		printf ( "Parent process\n" ) ;
///*/
///
// ===============================================================
///// Declaracao de variaveis
///	int		i;
///	t_dlist	*lista_env;
/////	t_list	*a;
///
///// Inicializa lista
///	lista_env = ft_dlst_create(envp[0]);
///
///// Le variaveis de ambiente
///
///// Printa
///	//printf("argc: %d\n", argc);
///	//printf("argv: %s\n", argv[0]);
///	printf("===================\n");
///	i = 1;
///	while(envp[i])
///	{
///		//printf("%s\n", envp[i]);
///		//a = ft_lstnew(envp[i]);
///		//ft_lstadd_back(&lista_env, a);
///		//ft_lstadd_back_p(&lista_env, envp[i]);
///		ft_dlst_add(&lista_env, envp[i]);
///
///		
///		i++;
///	}
///
///// Adiciona variavel
///// Printa lista
///	u_print_dlist(lista_env);
/////	ft_lstiter(lista_env, &prints);
///// Destroi list
///	u_free_dlist(lista_env);	
///	
///	char	*linha;
///	t_dlist	*command_lines;
///	int		flag;
///
///
///	get_next_line(0, &linha);
///	command_lines = ft_dlst_create(linha);
///
///	flag = 1;
///	while (flag)
///	{
///		get_next_line(0,&linha);
///		ft_dlst_add(&command_lines, linha);
///		printf("lido: %s\n", linha);
///		flag = ft_strncmp(linha, "q", 1);
///		free(linha);
///	}
///	printf("FIM DA LEITURA\n");
///	printf("=========================\n");
///	printf("HISTORY:\n");
///	//u_print_dlist(command_lines);
///	//u_free_dlist(command_lines);
// ===============================================================

//	initscr();
//	addstr("Goodbye, cruel C programming!");
//	refresh();
//	getch();
//	endwin();
// ===============================================================
/*
	char *ret2;
	int l;
	char **ret_split;
	//char **var_ambiente;
	char *pasta_atual;
	//char **env = __environ;


    char ret[2048];
    tgetent(ret, getenv("TERM"));

	struct termios term;
	tcgetattr(0,&term);

	term.c_lflag &= ~(ECHO);
	term.c_lflag &= ~(ICANON);
	term.c_cc[VMIN] = 1;
    term.c_cc[VTIME] = 0;
	tcsetattr(0,TCSANOW,&term);

	//teste();
	printf("Hello World!\n");
//	printf ("env = %s av = %s ac = %d\n", env[1],av[0],ac);
	printf ("Bem vindo ao MINISHEL2L\n");

	ret2  = ft_strdup("");
	ret_split = ft_split(ret,' ');
	//var_ambiente = get_export(env,ret_split);
	pasta_atual = ft_strdup("teste");

	printf("t = %s\n",key_backspace);


	tputs(save_cursor,1,my_termprint);
	while (1)
	{
		l = read (0,ret,100);
		if (!ft_strncmp("\e[A",ret,3))
		{
			tputs(restore_cursor,1,my_termprint);
			tputs(tigetstr("ed"),1,my_termprint);
			write (1,"cima\n",4);
		}
		else if (!ft_strncmp("\e[B",ret,3))
		{
			tputs(restore_cursor,1,my_termprint);
			tputs(tigetstr("ed"),1,my_termprint);
			write (1,"baixo\n",5);
		}
		else if (!ft_strncmp("\e[C",ret,3))
		{
			tputs(restore_cursor,1,my_termprint);
			tputs(tigetstr("ed"),1,my_termprint);
			write (1,"dir\n",3);
		}
		else if (!ft_strncmp("\e[D",ret,3))
		{
			tputs(restore_cursor,1,my_termprint);
			tputs(tigetstr("ed"),1,my_termprint);
			write (1,"esq\n",3);
		}
		if (!ft_strncmp("\n",ret,1))
		{
			tputs(save_cursor,1,my_termprint);
			printf("COMANDO !\n");
			//execulta_comando (ret2,var_ambiente);
			ret2 = ft_strdup("");
		}
		else
		{
			ret2 = ft_strjoin(ret2,ret);
			write (1,ret,l);
		}

	}	
	return (0);
*/
// ===============================================================
	char *s;
	(void) s;
	(void) v;

	/*printf("aaaaaaaaa\n");
	int fd = open("teste", O_CREAT | O_RDWR | O_APPEND);
	printf("fd arq %d\n",fd);
	
	
	char lido[4];
	int pp[2];
	pipe(pp);

		ft_bzero(lido,4);
	
		// salva stds
		int save_in = dup(STDIN_FILENO);
		int save_out = dup(STDOUT_FILENO);

		write(STDOUT_FILENO, "aaa\n", 4);

		write(pp[IN], "bbb", 4);		// escreve na entrada do pipe
		read(pp[OUT], &lido, 4);		// le da saida do pipe
		printf("lido: |%s|\n", lido);	// escreve na tela
		
		dup2(pp[IN], STDOUT_FILENO);	// JOGA STDOUT PARA ENTRADA DO PIPE
		dup2(pp[OUT], STDIN_FILENO);	// FAZ STDIN LER DA SAIDA DO PIPE

		// As proximas linhas fazer o papel 
		// do comando que sera executado
		// que le de um lugar e esreve em outro
		write(STDOUT_FILENO, "ccc", 4);		// escreve remapeado para pipe
		read(STDIN_FILENO, &lido, 4);		// le remapeado do pipe
		printf("lido1: |%s|\n", lido);		// vai para pipe (nao pra tela !)

		// restaura
		dup2(save_in, STDIN_FILENO);
		dup2(save_out, STDOUT_FILENO);

		printf("lido2: |%s|\n", lido);	// IMPRIME NORMAL NA TELA


	close(fd);
	exit(0);
}*/

	init_env(&v, __environ);
	u_print_array_bi(v.env);

	//char *str = "0\"\'1$TERM 3\'\"; >a1 <a2 abc  > a3 < a4 | aa arg1 arg2 | a ; b >b1 <b2 >b3 <b4 | bb arg1 arg2 | b ; x; y   ; z";
//	char *str = " >a1 <a2 abc  > a3 < a4 | aa arg1 arg2 ;z";
	char *str = " abc > a1| aa arg1 arg2 ;z";
	//char *str = "0\"\'1$TERM 3\'\"; a>a1 <a2 > a3 < a4 | a ; b >b1 <b2 >>b3 <b4 | z";

	printf("%s\n",str);
	parse_cmd_lines(&v, str);
	u_print_array_bi(v.cmd_lines);


	//char *a = "0\"\'1$DISPLAY 3\'\" \'\"4$DISPLAY 67\"\' 8$PAGER>0 abc def";
	////char *a = "$PAGER \'$PAGER\' \"$PAGER\" \'\"$PAGER\"\' \"\'$PAGER\'\"";
	////char *a = "1224    56899 $PAGER> eita";
	//parse_s(&v,a);
	//printf("\n");
	//printf("expandido: %s\n", v.expandido);
	
	
	
	//free(v.expandido);
	u_free_array_bi(v.env);

	u_free_array_bi(v.cmd_lines);
	return (0);
}



// GRAMATICA
// aaaaaaaa ; bbbbbbbb
// aaa | aaa | aaa  ; bbb | bbb | bbb
// a >a1 <a2 > a3 < a4 | aa arg1 arg2 | a ; b >b1 <b2 >b3 <b4 | bb arg1 arg2 | b
