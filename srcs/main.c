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
	char *aux;
	(void) aux;

	init_env(&v, __environ);
		//printf("Antes\n");
		//u_print_array_bi(&v, v.env);
	init_path(&v);
	init_hist(&v, "teste");

	reset_flags(&v);
	config_term(&v);

	v.cmd.ret_status = EXIT_SUCCESS;
	v.r_command = 0;

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
	//char str[] = "echo $?; ls -la | grep a | grep k; echo $?";
	char str[] = "ls";

	add_hist2(&v, "echo cezar | sed \"s/cezar/angelica/\"");
	add_hist2(&v, "echo cezar | sed \'s/cezar/angelica/\' | sed \'s/angelica/42/\"'");
	add_hist2(&v, "echo cezar | sed s/cezar/angelica/ | sed s/angelica/42/");
	add_hist2(&v, "echo daniel | sed \"s/cezar/angelica/\"");


	ft_putstr_fd("Bem vindo ao MINISHELL CPEREIRA & PCUNHA\n",1);
	v.prompt = ft_strdup("cezar-paulo >");
	ft_putstr_fd(v.prompt,1);
	tputs(tigetstr("ce"),1,my_termprint); // ed
	tputs(save_cursor,1,my_termprint);

	char ret[2048];
	v.ret2 = ft_strdup("");
	v.posic_string = 0;

	while (1)
	{
		ft_bzero(ret,2048);
		read (0,ret,100);

		//printf("letra = %d\n",ret[0]);

		if (!verify_term(&v,ret))
		{
			if (!ft_strncmp("\n",ret,1))
			{
				v.posic_hist = v.qtd_hist;
				v.posic_string = 0;

				add_hist2(&v,v.ret2);

				v.flag_exit = 0;
				//create_prompt(&v);
				// CODIGO PRINCIPAL ========
				ft_putstr_fd("\n",1);
					printf("ret2: |%s\\n", v.ret2);
				parse_cmd_lines(&v, v.ret2);
				if (v.flag_exit == 1)
					bye(&v);
				// =========================

				//printf(" -- ret = %d \n",v.cmd.ret_status);
				if (v.cmd.ret_status == -1)
				{
					ft_putstr_fd("bash : ",1);
					ft_putstr_fd(v.ret2,1);
					ft_putstr_fd(" : command not found\n",1);
				}

				//v.r_comando = execulta_comando (v.ret2,&v);
				ft_bzero(v.ret2,2048);
				ft_bzero(v.ret,2048);

				ft_putstr_fd(v.prompt,1);
				tputs(save_cursor,1,my_termprint);
			}
			else
			{
				if (v.posic_string == (int)ft_strlen(v.ret2))
					v.ret2 = ft_strjoin(v.ret2,ret);
				else
					v.ret2[v.posic_string] = ret[0];
				v.posic_string++;	
				ft_putstr_fd(ret,1);
			}
			if (v.r_command == 3)
			{
				u_free_array_bi(&v.ret2);
				bye(&v);
			}
		}
	}
	return (0);




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
