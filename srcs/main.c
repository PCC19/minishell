# include <unistd.h>
# include <stdio.h>
# include <curses.h>
#include <term.h>
#include <termcap.h>
# include "minishell.h"
# include "libft.h"
# include "get_next_line.h"

int	main(void)
{
	t_v v;
	pid_t pid = getpid();
	printf("pid: %d\n", pid);

	char *s = NULL;
	(void) s;
	(void) v;

	init_env(&v, __environ);
		//printf("Antes\n");
		//u_print_array_bi(&v, v.env);
	init_path(&v);	

	//char *str = "0\"\'1$TERM 3\'\"; >a1 <a2 abc  > a3 < a4 | aa arg1 arg2 | a ; b >b1 <b2 >b3 <b4 | bb arg1 arg2 | b ; x; y   ; z";
	//char str[] = "xx yy |  >a1 <a2 abc  >a3 < a4 | aa arg1 arg2; z > a5";
	//char str[] = "pwd ; pwd a";
	//char str[] = "cd srcs | pwd >> arq";
	//char str[] = "echo \'asd\'     \"djfjdkf\" $PWD \"$PWD\" \'$PWD\'";
	//char str[] = "echo \'asd\'  $PWD \"$PWD\" \'$PWD\'; lixo a b c";
	//char str[] = "export a=234; export b=567";
	//char str[] = "export a=234; export b=567; unset a";
	//char str[] = "env; export a=234; export b=567; unset a; env";
	//char str[] = "env; export a=234; export b=567; unset a; ls -la | grep mini";
	//char str[] = "echo \"ls -la";
	//char str[] = "ls -la | grep a | grep k";
	char str[] = "echo $?; ls -la | grep a | grep k; echo $?";

	printf("%s\n",str);
	v.flag_exit = 0;
	create_prompt(&v);
	// CODIGO PRINCIPAL ========
	parse_cmd_lines(&v, str);
	// =========================

	u_free_array_bi(v.env);
	u_free_array_bi(v.cmd_lines);
	u_free_array_bi(v.path);
	free(v.prompt);
	return (0);
}

// GRAMATICA
// aaaaaaaa ; bbbbbbbb
// aaa | aaa | aaa  ; bbb | bbb | bbb
// a >a1 <a2 > a3 < a4 | aa arg1 arg2 | a ; b >b1 <b2 >b3 <b4 | bb arg1 arg2 | b
