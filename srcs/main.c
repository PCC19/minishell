# include <unistd.h>
# include <stdio.h>
# include "minishell.h"
# include "libft.h"

int main(int argc, char **argv, char **envp)
{
/*	int pid ;
	pid = fork( );
	if ( pid == 0 ) {
		execl ( "/bin/ls","-al", "/media/sf_minishell", NULL ) ;
		printf ( "Child: After exec( )\n") ; }
	else
		printf ( "Parent process\n" ) ;
*/

// Declaracao de variaveis
	int		i;
	t_list	*lista_env;
	t_list	*a;

// Inicializa lista
	lista_env = ft_lstnew(envp[0]);

// Le variaveis de ambiente

// Printa
	printf("argc: %d\n", argc);
	printf("argv: %s\n", argv[0]);
	printf("===================\n");
	i = 1;
	while(envp[i])
	{
		//printf("%s\n", envp[i]);
		a = ft_lstnew(envp[i]);
		ft_lstadd_back(&lista_env, a);
		i++;
	}

// Adiciona variavel
// Printa lista
	u_print_list(lista_env);
// Destroi list
	u_free_list(lista_env);	

}
