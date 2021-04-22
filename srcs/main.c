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
	//char *str = "echo \" teste | ola\" | alfa ; beta";
	char *str = "alfa | beta";

	scanf("%s\n", s);
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
