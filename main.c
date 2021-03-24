# include <unistd.h>
# include <stdio.h>

int main( )
{
	int pid ;
	pid = fork( );
	if ( pid == 0 ) {
		execl ( "/bin/ls","-al", "/media/sf_minishell", NULL ) ;
		printf ( "Child: After exec( )\n") ; }
	else
		printf ( "Parent process\n" ) ;
}
