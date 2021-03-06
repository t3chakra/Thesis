/*JOY BABA LOKNATH..JOY SHREE GANESHA..JOY SHREE KRISHNA*/
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
void usage(char *progName)
{
    if (progName != NULL)
    {
        fprintf(stderr,
                "Correct usage: %s [-s] <int> [-n] <int> -l <int>\n",
                progName);
    }
}
static void
child_handler(int sig)
{
exit(1);
}

/* Establish handler. */


int main(int argc, char *argv[])
{
    char opt;
    char s[10],n[10],l[10],c[10];
    strcpy(s,"");
    strcpy(n,"");strcpy(l,"");strcpy(c,"");
    int pid1,pid2,pid3,pid4;
    int ch1[2],ch2[2],ch3[2],ch4[2];
    if (pipe(ch1) < 0){fprintf(stderr, "pipe for rgen did not open :\n");
fflush(stderr);return 0;}
    if (pipe(ch2) < 0){fprintf(stderr, "pipe for ch2 did not open :\n");
fflush(stderr);return 0;}
    if (pipe(ch3) < 0){fprintf(stderr, "pipe for ch2 did not open :\n");
fflush(stderr);return 0;}
    if (pipe(ch4) < 0){fprintf(stderr, "pipe for ch2 did not open :\n");
fflush(stderr);return 0;}
    
    while((opt = getopt(argc, argv, "s:n:l:c:")) != -1)
    {
        switch(opt)
        {
           
           case 'n':
                fprintf(stdout, "option n seen.\n");
                strcat(n,optarg);
                fprintf(stdout, "option value: %s\n", n);
                break;
            case 's':
                fprintf(stdout, "option s seen.\n");
                strcat(s,optarg);
                fprintf(stdout, "option value: %s\n", s);
                break;
            case 'l':
                fprintf(stdout, "option l seen.\n");
                strcat(l,optarg);
                fprintf(stdout, "option value: %s\n", l);
                break;
            case 'c':
                fprintf(stdout, "option c seen.\n");
                strcat(c,optarg);
                fprintf(stdout, "option value: %s\n",c);
                break;
            default:
                fprintf(stderr, "Error: invalid option.\n");
                usage(argv[0]);
                break;
        }


    }
        /* creating child process for */
        pid1=fork();
        if(pid1==0)
        {
                
                 
                close(ch1[0]); 

                    if(dup2(ch1[1], STDOUT_FILENO) < 0) {fprintf(stderr,"dup2(child1)"); return 0;}
                    if (execl("./rgen","./rgen",s,n,l,c,(char *)NULL) < 0){fprintf(stderr,"error opening rgen in inexecl\n"); fflush(stderr);return 0;}
			struct sigaction sa;
		sigemptyset(&sa.sa_mask);
		sa.sa_flags = 0;
		sa.sa_handler = child_handler;

		sigaction(SIGCHLD, &sa, NULL);

                
        }
        else
        {
                pid2=fork();
                /* 2nd Child Process*/
                if(pid2==0)
                {                
                        close(ch1[1]);
                        close(ch2[0]);
                        
                        if(dup2(ch1[0], STDIN_FILENO) < 0) {fprintf(stderr,"dup2(2nd childprocess)");fflush(stderr); return 0;}
                        if(dup2(ch2[1], STDOUT_FILENO) < 0) {fprintf(stderr,"dup2(2nd childprocess)");fflush(stderr); return 0;}
                        
                        if (execl("./a1.py","./a1.py", (char *)NULL) < 0){fprintf(stderr,"error opening python inexecl\n"); fflush(stderr);return 0;}
                        
                }
                else
                {
                        
                        pid3=fork();
                        if(pid3==0)
                        {
                                close(ch2[1]);
                                
                                if(dup2(ch2[0], STDIN_FILENO) < 0) {fprintf(stderr,"dup2(3rdchid)");fflush(stderr); return 0;}
                                //if(dup2(ch3[0], STDIN_FILENO) < 0) {fprintf(stderr,"dup2(3rdchid)");fflush(stderr); return 0;}
                                if (execl("./check","./check", (char *)NULL) < 0){fprintf(stderr,"eoor3 inexecl\n"); fflush(stderr);return 0;}

                        
                        }
                        else{//parent
                                close(ch2[0]);
                                if(dup2(ch2[1], STDOUT_FILENO) < 0) {fprintf(stderr,"dup2(3rdchid)");fflush(stderr); return 0;}                                
                                char spath[1000];
                                while(1){fgets(spath,sizeof spath,stdin);//fflush(stdin);
                                fprintf(stdout,"%s",spath);
                                fflush(stdout);}
                                
                                //fprintf(stdout,"parent\n");
                                //fflush(stdout);
                        
                        }
                }

                                
        
                

        }

    return 0;
}

