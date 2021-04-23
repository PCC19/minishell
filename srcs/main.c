# include <unistd.h>
# include <stdio.h>
# include <curses.h>
#include <term.h>
#include <termcap.h>
# include "minishell.h"
# include "libft.h"
# include "get_next_line.h"

//int main(int argc, char **argv, char **envp)
int	main(void)
{
	t_v v;
	pid_t pid = getpid();
	printf("pid: %d\n", pid);

	char *s = NULL;
	(void) s;
	(void) v;

	init_env(&v, __environ);
	//u_print_array_bi(v.env);

	//char *str = "0\"\'1$TERM 3\'\"; >a1 <a2 abc  > a3 < a4 | aa arg1 arg2 | a ; b >b1 <b2 >b3 <b4 | bb arg1 arg2 | b ; x; y   ; z";
//	char *str = " >a1 <a2 abc  > a3 < a4 | aa arg1 arg2 ;z";
	//char *str = " abc > a1| aa arg1 arg2 ;z";
	//char *str = "echo \" teste | ola\" > arq | echo | lixo";
	//char *str = "0\"\'1$TERM 3\'\"; a>a1 <a2 > a3 < a4 | a ; b >b1 <b2 >>b3 <b4 | z";
	char *str = "echo \" teste | ola\" | alfa $TERM ; aa | bb | cc ; xx | yy";
	//char *str = "alfa 1 2 | beta a b  ; gamma x y | delta q q q q";



	/*char **aux = ft_split3(str, '|');
	printf("aux[0]: %s\n", aux[0]);
	u_print_array_bi(&v, aux);
	u_free_array_bi(aux);
	u_free_array_bi(v.env);
	exit (0);
*/


	printf("%s\n",str);
	parse_cmd_lines(&v, str);
	//u_print_array_bi(v.cmd_lines);


	u_free_array_bi(v.env);
	u_free_array_bi(v.cmd_lines);
	return (0);
}
//expandido
//cmd
	// filename
	// cmd_args




// GRAMATICA
// aaaaaaaa ; bbbbbbbb
// aaa | aaa | aaa  ; bbb | bbb | bbb
// a >a1 <a2 > a3 < a4 | aa arg1 arg2 | a ; b >b1 <b2 >b3 <b4 | bb arg1 arg2 | b
