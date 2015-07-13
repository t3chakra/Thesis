#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <assert.h>
#define INF 1000
int **cost;
int init(int v);
int shortestpath(int **cost, int src, int tar,int v);
void graph(int x,int y);
char** split(char* str_edge, const char delimeter);

int main()
{
	int i,c,v,flag,v1,v2,src,tar,graphcount=0;
	char** tokens;
	char* token; 
	char** edge;
	char buffer[2500];	
	while(fgets(buffer,sizeof buffer,stdin)!=NULL)
	
	{	flag=0;
		
		if(feof(stdin))		
			break;
		switch(buffer[0])
		{
			case 'V':
				if(graphcount>1){for(i=0;i<graphcount;i++)free(cost[i]);free(cost);}
				tokens=split(buffer,' ');
				v=atoi(*(tokens+1));
				if(v<0){printf("Error: Number of total Vertices can not be negative\n");graphcount=0;}
				else if(v==0){printf("Error: There will be no graph with 0 vertices\n");graphcount=0;}
				else
				{	graphcount=init(v);}
				free(tokens);				
				continue;
			case 'E':
				v1=v2=0;				
				tokens = split(buffer, ' ');
			        if (tokens)
    				{
					token=*(tokens+1);
					for(i=0;i<strlen(token);i++)
					{
						if(token[i]=='-')
						{
						  printf("Error: Negetive vertex is not possible for edge\n");
							flag=1;free(tokens);free(token);
							break;
						}
						if(token[i]=='{'||token[i]=='<')
						{
							token[i]='0';
						}

					}
				        if(flag!=1)
					{
						token[i-2]='\0';
						tokens=split(token,'>');
							
						if(tokens)
						{
        						for (i = 0; *(tokens + i); i++)
        						{
            							token=*(tokens + i);
								if(token[0]==',')token[0]='0';
            							edge=split(token,',');
								if(edge)							
								{
									v1=atoi(*(edge+0));
									v2=atoi(*(edge+1));
								
									if(v1>(v-1)||v2>(v-1))
									{
										printf("Error: The vertex you have given for edge does not exist\n");
			          
										break;
									}
									else
										graph(v1,v2);
							 	}
		
								free(token);
								free(edge);
							}
						}
        					free(tokens);
					}
  				}				
				continue;			
			case 's':
				src=tar=0;
				tokens=split(buffer,' ');
				src=atoi(*(tokens+1));
				tar=atoi(*(tokens+2));
				if(src>v||tar>v||src<0||tar<0) 
					printf("Error: Vertex you have given for shortest path does not exist  \n");				
				else
					c=shortestpath(cost,src,tar,v);
				free(tokens);
				continue;


		}

         }				
		
	
return 0;
}
/*Forming graph with edge*/
void graph(int x,int y)
{
	cost[x][y]=cost[y][x]=1;
}
/*Forming initial empty adjacency matrix*/
int init(int v)
{	
	int i,j;
	// first allocate memory for pointer to each row
	cost = (int**) malloc(v * sizeof(int*));
        // then allocate memory for each row
	for(i = 0; i < v; i++)
    		cost[i] = (int*) malloc(v * sizeof(int));	   
    	for(i=0;i< v;i++)
    		for(j=0;j< v;j++)
     			cost[i][j] = INF;
   
	return v;
}
/* Using Dijkstra's Algorithm in C take some help from Author:Pramesh Pudasaini from the link http://www.codewithc.com/dijkstras-algorithm-in-c-program-source-code/ for psedudo code and use it according to this program requirement*/
/*Find shortest path*/
int shortestpath(int **cost,int src,int tar,int v)
{
    int *dist,*prev,*selected,i,m,min,start,d,j;
    int *path;
    dist=(int*) malloc (v * sizeof(int));
    prev=(int*) malloc (v * sizeof(int));
    selected=(int*) malloc (v * sizeof(int));
    path=(int*) malloc (v * sizeof(int));
    d=0;
    for(i=0;i<v;i++){selected[i]=0;path[i]=0;}
    	
    for(i=0;i< v;i++)
    {
        dist[i] = INF; 
        prev[i] = -1;  
    }
    start = src;
    selected[start]=1;
    dist[start] = 0;
    while(selected[tar]==0)
    {
        min = INF;
        m = 0;
        for(i=0;i< v;i++)
        {
            d = dist[start] +cost[start][i]; 
            if(d< dist[i]&&selected[i]==0)
            {
                dist[i] = d; 
                prev[i] = start;
            }
            if(min>dist[i] && selected[i]==0)
            {
                min = dist[i];
                m = i;
            }
        }
        start = m;
        selected[start] = 1;
	if(i==v && min==INF)break;
	
    }
   start = tar;
    
    j = 0;
    
    while(start != -1 && min!=INF )
    {
    	path[j]=start;
        start = prev[start];
	j++;

    }
    if(j!=0){
    		for(i=j-1;i>=0;i--)
		{
			printf("%d",path[i]);
			if(i!=0)printf("-");
        	}
     }
    else
	{
		printf("Error: No Shortest Path Exist between input Vertices");
	}
  	printf("\n");

	free(dist);free(path);free(prev);free(selected);
 	return 1;   
}

/*Acknowledgement: http://stackoverflow.com/questions/9210528/split-string-with-delimiters-in-c Author : Matt for this  function and use it as my assignment requirement*/

/*For spliting the edge input..*/
char** split(char* str_edge, const char delimeter)
{
    char** result    = 0;
    size_t count     = 0;
    char* tmp        = str_edge;
    char* last_comma = 0;
    char delim[2];
    delim[0] = delimeter;
    delim[1] = 0;

    /* Count how many elements will be extracted. */
    while (*tmp)
    {
        if (delimeter == *tmp)
        {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }

    /* Add space for trailing token. */
    count += last_comma < (str_edge + strlen(str_edge) - 1);

    /* Add space for terminating null string so caller
       knows where the list of returned strings ends. */
    count++;

    result = malloc(sizeof(char*) * count);

    if (result)
    {
        size_t idx  = 0;
        char* token = strtok(str_edge, delim);

        while (token)
        {
            assert(idx < count);
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
        }
        assert(idx == count - 1);
        *(result + idx) = 0;
    }

    return result;
}
