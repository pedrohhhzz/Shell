#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>




int main(int argc, char *argv[]) {
	
	char texto_digitado[200];
	int sair = 0;
	int status;
	char *comando;
	char *parametros[10];
	int contador;
	char *parametro;
	pid_t pid;
	
	
	printf("\n Bem vindo\n\n");
	printf("\n para sair digite: sair");
	
	do{
		
		printf("\n>");
		scanf("%[^\n]%*c", texto_digitado);
		contador = 0;
		
		
		if (strcmp(texto_digitado, "sair") == 0 ){
			sair = 1;
		}
		
		else{
			
			pid = fork();
			
			if(pid != 0){
				
				waitpid(pid, status, 0);
			}
			
			else{
				
				comando = (char *) strtok(texto_digitado, " ");
				parametros[0] = comando;
				
			do{
				parametro = strtok(NULL, " ");
				parametros[++contador] = parametro;
			} while(parametro != NULL);	
			
			
			parametros[++contador] = NULL;
			
			execvp(comando, parametros);
			sair = 1;
			
			
				
			}
			
			
		}
		
	}while (!sair);

	
	
	
	return 0;
}
