#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
char *gr;
struct street{
    char name[50];
    char point[1000];
};
int forminput(int a,int b,int c)
{

    struct street *s;
    
    char buffer[20]; 
    int x,y,ns,nl;
    unsigned char *buf1,*buf2,*buf3,*buf4;
    int fd = -1,i=0,j=0,k=0,l=0,m=0,n=0; 
    char buf[30];
    
    if ((fd = open("/dev/urandom", O_RDONLY)) < 0)
    {
	perror("open()");
	return 0;
    } 	
   buf1 = (unsigned char *)malloc(10*sizeof(unsigned char));
   buf2 = (unsigned char *)malloc(10*sizeof(unsigned char));
   buf3 = (unsigned char *)malloc(100*sizeof(unsigned char));
   buf4 = (unsigned char *)malloc(100*sizeof(unsigned char));
   	  
	ns=read(fd,buf1,1);
	ns=buf1[0]%(a-2+1)+2;//number of street	
  	//printf("Number of Street=%d\n",ns);
	s=(struct street*)malloc(ns*sizeof(struct street));	
	k=-1*c;	
	strcpy(gr,"");	
	for(l=0;l<ns;l++)
	{       strcpy(s[l].point," "); 
		strcpy(s[l].name,"a \"Street");  
		nl=read(fd,buf2,1); 
		nl=buf2[0]%(b-1+1)+1;//number of line	
   	//	printf("For street number %d Number of Line segments=%d\n",l,nl);
		/*Number of points*/
				
		sprintf(buffer, "%d", l);;
		strcat(s[l].name,buffer);
		strcat(s[l].name,"\"");		
		for(j=1;j<=nl+1;j++)

		{
			
		
			x=read(fd,buf3,1);
			y=read(fd,buf4,1);
			x=buf3[0]%(c-k+1)+k;
			y=buf4[0]%(c-k+1)+k;
			//printf("Cordinate for linesegment %d =(%d,%d)\n",j,x,y);
			strcat(s[l].point,"(");
			sprintf(buffer, "%d", x);
			strcat(s[l].point,buffer);
			strcat(s[l].point,",");
			sprintf(buffer, "%d", y);
			strcat(s[l].point,buffer);
			strcat(s[l].point,") ");
			
				
		}//printf("%s%s\n",s[l].name,s[l].point);
		strcat(gr,s[l].name);
		strcat(gr,s[l].point);
		strcat(gr,"\n");

	}
	strcat(gr,"g");
	strcat(gr,"\n");
	strcat(gr,"r");
	strcat(gr,"\n");

	
free(buf1);
free(buf2);
free(buf3);
free(buf4);
free(s);
return 1;

}

int main(int argc, char **argv)
{
	int fd1,t;
	if ((fd1 = open("/dev/urandom", O_RDONLY)) < 0)
	    {
		perror("open()");
		return 0;
    	   } 	
    	unsigned char *buf;
	buf=(unsigned char*)malloc(10*sizeof(unsigned char*));
	t=read(fd1,buf,1);
	t=buf[0]%(atoi(argv[3])-5+1)+5;
	if(argc<3){fprintf(stderr,"Error: RGEN did not get enough input\n");exit(1);}
	int i;
	int ns,nl,p,r;
	ns=atoi(argv[1]);
	nl=atoi(argv[2]);
	p=atoi(argv[4]);
	for(i=0;i<10;i++)
	{	gr=(char *)malloc((ns*1000)*sizeof(char));
		if(i=3)exit(1);
	
	r=forminput(ns,nl,p);
	fprintf(stdout,"%s",gr);
	fflush(stdout);
	free(gr);sleep(t);
	}
        
    return 0;
}
