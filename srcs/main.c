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
	/*int fd = open("arq", O_CREAT | O_RDWR);
	char *buf = "steste";
	write(fd, buf, 6);
	close(fd);
	exit(0);
*/


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
	//char *str = " abc > a1| aa arg1 arg2 ;z";
	//char *str = "echo \" teste | ola\" > arq | echo | lixo";
	char *str = "echo \" teste | ola\" >arq1 > arq2 <arq3 <arq4 | echo";
	//char *str = "0\"\'1$TERM 3\'\"; a>a1 <a2 > a3 < a4 | a ; b >b1 <b2 >>b3 <b4 | z";

	//char **ss;

	//printf("%s\n",str);
	//ss = ft_split2(str,'|');
	//u_print_array_bi(ss);
	//exit(0);
	

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
