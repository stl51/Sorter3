#include <stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<dirent.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h> 
//#include"mergesort.h"
//#include"sorter.h"


int filenumber=0;

pthread_t threadHandles[255];
int threadIndex = -1;

pthread_mutex_t lock;
pthread_mutex_t lock2;
pthread_mutex_t lock3;

char *b;


int totalcount;

 typedef struct thread_data{

	int indent;
	int port;
	const char* name;
	const char* column;
	const char* output;
	const char* server;

} tdata;


typedef struct thread_data2{
	char* name;
	char* path;
	int port;
	const char* server;
	
	
} fdata;

char * iscolumn(char *col){

	if(strcmp(col, "color")==0){
		b="00";
	}
	else if(strcmp(col,"director_name")==0){
		b="01";
	}
	else if(strcmp(col,"num_critic_for_reviews")==0){
                b="02";
        }
	else if(strcmp(col,"duration")==0){
                b="03";
        }
	else if(strcmp(col,"director_facebook_likes")==0){
                b="04";
        }
	else if(strcmp(col,"actor_3_facebook_likes")==0){
                b="05";
        }
	else if(strcmp(col,"actor_2_name")==0){
                b="06";
        }
	else if(strcmp(col,"actor_1_facebook_likes")==0){
                b="07";
        }
	else if(strcmp(col,"gross")==0){
                b="08";
        }
	else if(strcmp(col,"genres")==0){
                b="09";
        }
	else if(strcmp(col,"actor_1_name")==0){
                b="10";
        }
	else if(strcmp(col,"movie_title")==0){
                b="11";
        }
	else if(strcmp(col,"num_voted_users")==0){
                b="12";
        }
	else if(strcmp(col,"cast_total_facebook_likes")==0){
                b="13";
        }
	else if(strcmp(col,"actor_3_name")==0){
                b="14";
        }
	else if(strcmp(col,"facenumber_in_poster")==0){
                b="15";
        }
	else if(strcmp(col,"plot_keywords")==0){
                b="16";
        }
	else if(strcmp(col,"movie_imdb_link")==0){
                b="17";
        }
	else if(strcmp(col,"num_user_for_reviews")==0){
                b="18";
        }
	else if(strcmp(col,"language")==0){
                b="19";
        }
	else if(strcmp(col,"country")==0){
                b="20";
        }
	else if(strcmp(col,"content_rating")==0){
                b="21";
        }
	else if(strcmp(col,"budget")==0){
                b="22";
        }
	else if(strcmp(col,"title_year")==0){
                b="23";
        }
	else if(strcmp(col,"actor_2_facebook_likes")==0){
                b="24";
        }
	else if(strcmp(col,"imdb_score")==0){
                b="25";
        }
	else if(strcmp(col,"aspect_ratio")==0){
                b="26";
        }
	else if(strcmp(col,"movie_facebook_likes")==0){
                b="27";
        }
	else{
	b="0";
	}

return b;

}
//replace control characters in file

int replace_character(FILE* input){

	int count=0;
	
    if (input == NULL) {
		return 0; /* if file not found quit */
	}

    char current_char = 0;
    char to_replace = '\n'; /* get the character to be replaced */
    char replacement = '@'; 

    while ((current_char  = fgetc(input)) != EOF) {
			
		count++; 
        if (current_char == to_replace) 
        {
            fseek(input, ftell(input) - 1, SEEK_SET); 
			
            fprintf(input, "%c", replacement); 
        }
    }

   fprintf(input, "~");

    fclose(input);
	
	return count;// +3 for column and tilde
	
}


//thread to sort files

void * sortfunc(void* threadarg2){			

	char * name;
	char * path;
	const char * serveradd;
	int port; 
	int buffer_size;

	
	fdata* data;
	
	data = (fdata *) threadarg2;
	
	name = data->name;
	path = data->path;
	serveradd = data->server;
	port = data->port;
	
	
   int sockfd; //declare a socket 
   struct sockaddr_in address; //socket struct
   struct hostent *server; //host struct
   
   server = gethostbyname(serveradd); 
   
   if (server == NULL){
		fprintf(stderr, "ERROR, NO SUCH HOST\n");
		exit(0);
	}
   
   memset(&address, 0, sizeof(address));
   
    address.sin_family = AF_INET;
	
	address.sin_port = htons(port);
	
	bcopy((char*)server->h_addr,
			(char*)&address.sin_addr.s_addr,
			server->h_length);
			
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0)
	{
		//perror() report error message
		perror("sock");
		//exit your program
		exit(EXIT_FAILURE);
	}
	
	//printf("socket created");	
	
	
	FILE* f;
	//char* newfp;
	
	int c=0;
	char val;
	
	char * filename = name;
	
	int length=strlen(filename);
	
	if(strncmp(filename + length - 4, ".csv", 4) == 0){
					f=fopen(path, "r+");
						if(f==NULL){
						printf("error in opening file");}
						else{
						
							while(fscanf(f,"%c",&val)!=EOF){
								if(val=='\n'){
								break;}
								if(val==','){
								++c;}
							}
							fflush(stdout);
							if(c==27){ 	
							
								fflush(stdout);
								printf("%lu\n",(unsigned long)pthread_self());
								fflush(stdout);
					
								rewind(f);	
								buffer_size = replace_character(f) + 1;
							//	printf("after replace character");
								char buffer[buffer_size];
								char columnbuff[buffer_size + 2];
							//	memset(columnbuff, 0, buffer_size + 3);
								f=fopen(path, "r"); 
								//int len;
								//printf("before connect");
								fflush(stdout);	
								if (connect(sockfd, (struct sockaddr*)&address, sizeof(address)) < 0){
								// perror() report error message
								perror("connect");
								// close socket
								close(sockfd);
								// exit your program
								exit(EXIT_FAILURE);
								
								}
								
							//	printf("file socket created");
								/*len=send(sockfd, buffer, sizeof(buffer), 0);
								if(len<0){
									printf("error sending buffer_size");
								}*/ 
							
								strcpy(columnbuff, b);
								rewind(f);	
									
								//fscanf(f, "%s", buffer);
							
								fread(buffer, buffer_size, 1, f);
								
								
								
								strcat(columnbuff,buffer);
							//	fwrite(columnbuff, buffer_size+3, 1, stdout);	
								write(sockfd, columnbuff, buffer_size+3);
								
								fclose(f);
								
								fflush(stdout);
								printf("-----------buffer--------:\n");
								fflush(stdout);
								fwrite(columnbuff, buffer_size+2, 1, stdout);	
								fflush(stdout);
								printf("\nbuffer size: %d\n",(buffer_size + 2));
								fflush(stdout);
								
								//fflush(stdout);
								//printf("-------buffer sent---------:%s\n",columnbuff);
								//fflush(stdout);
								
								//printf("before close");
								
								//printf("after close");
							
							}
								
								
							else{
								
								fclose(f);}
							
						}   
							
				}
				 close(sockfd);

				pthread_exit(NULL);
	
	
}


//thread to sort files

void * dirfunc(void * threadarg){
	
	//pthread_t tid;
	//pthread_t tid2;
	
	int indent;
	const char * newname;
	const char * column;
	const char * output;
	const char* server;
	int port;

	
	//int counter=0;
	
	tdata* data;
	
	data = (tdata *) threadarg;
	indent = data->indent;
	newname = data->name;
	column = data->column;
	output = data->output;
	server = data->server;
	port = data->port; 

	
    DIR *dir;
    struct dirent *entry;
    int s;
    int len;
    int len2=1;
	int ret;
    const char *slash="/";
	
	
	ret=chdir(newname);

	
	if(ret<0){
	
	fflush(stdout);
	printf("Input directory doesn't exist\n");
	fflush(stdout);
	pthread_exit(NULL);
	}
	
	
    if (!(dir = opendir("."))){
		
		printf("exit here\n");
		fflush(stdout);
       pthread_exit(NULL);
	}
	
	//pthread_t *arr=(pthread_t *)malloc(sizeof(pthread_t)*100);
    int tcount=0;
	
	
    while ((entry=readdir(dir))!= NULL) {
		
		

        if (entry->d_type == DT_DIR) {
		
            char path[1024];
			
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0){
				//if(c==1){
				//pthread_mutex_lock(&lock3);
				//c=0;
				continue;
				//}
				
			}
                
            snprintf(path, sizeof(path), "%s/%s", newname, entry->d_name);
			
			
			
            len=strlen(newname); 
           
            s=strlen(entry->d_name)+2; 
            char *result=(char *)malloc(sizeof(char)*(len+ s+len2));
            strcpy(result,newname);
            strcat(result,slash);
            strcat(result,entry->d_name);  
		
			//initializing directory thread
			
			tdata * mydata = (tdata*)malloc(sizeof(tdata));
			
			mydata->indent = indent + 2;
			mydata->column = column;
			mydata->name = result; 
			mydata->output = output; 
			mydata->server = server; 
			mydata->port = port; 
			
			//lock around thread count
            pthread_mutex_lock(&lock);
            
			threadIndex++;
     
			pthread_mutex_unlock(&lock);
			
			//creating directory thread 
			
			if( pthread_create(&threadHandles[threadIndex], NULL, dirfunc, (void*)mydata)){
	
				fflush(stdout);
				printf("error in creating thread");
			
			}
			
			pthread_join(threadHandles[threadIndex], NULL);
			
			//tcount++;
        } 
		
		else {
			
			len=strlen(newname);
            s=strlen(entry->d_name)+2;
            char *resultfile=(char *)malloc(sizeof(char)*(len+ s+len2));
            strcpy(resultfile,newname);
            strcat(resultfile,slash);
            strcat(resultfile,entry->d_name);

		
			//initializing file thread strcut 
			
			fdata * mydata2 = (fdata*)malloc(sizeof(fdata));
			
			
			mydata2->name = entry->d_name;
			mydata2->path = resultfile; 
			mydata2->server = server;
			mydata2->port = port;
			
			
			//lock around threadcount
			
            pthread_mutex_lock(&lock2);
			
			threadIndex++;
			
            pthread_mutex_unlock(&lock2);
			
			
			//creating file thread 
			
			if( pthread_create(&threadHandles[threadIndex], NULL, sortfunc, (void*)mydata2) ) {
				printf("error in creating thread");
				
			}
			
			pthread_join(threadHandles[threadIndex], NULL);
			
			tcount++;
				
			} 

		} 
		
	
    closedir(dir);

pthread_exit(NULL);

}

//-----------------------//--------MAIN-------//------------------// 

int main(int argc, char **argv) {

//char* cwd = (char*)malloc(sizeof(char)*256);
char cwd[256];
int sizerel;
int sizerel1;
int finallen;
int finallen1;
char *column;
//int tempport;
pthread_t t;
getcwd(cwd, sizeof(cwd));
tdata* arg=(tdata *)malloc(sizeof(tdata));

char* str= "dump";

int buffer_size=strlen(str);


b=iscolumn(argv[2]);
if(strlen(b)==1){ 
	printf("incorrect column name");
	exit(0);
}

if(argc!=7 && argc!=9 && argc!=11){
	printf("incorrect number of parameters");
	exit(0);
} 

column=argv[2];
arg->column=argv[2];
arg->server=argv[4];
arg->port=atoi(argv[6]);
//tempport = atoi(argv[6]);
//printf("port number: %d\n",arg->port);


//-------send column info------//

/*int sockfd3; //declare a socket 
struct sockaddr_in address3; //socket struct
struct hostent *server3; //host struct
   
server3 = gethostbyname(argv[4]); 
   
   if (server3 == NULL){
		fprintf(stderr, "ERROR, NO SUCH HOST\n");
		exit(0);
	}
   
    memset(&address3, 0, sizeof(address3));
   
    address3.sin_family = AF_INET;
	
	address3.sin_port = htons(tempport);
	
	bcopy((char*)server3->h_addr,
			(char*)&address3.sin_addr.s_addr,
			server3->h_length);
			
	sockfd3 = socket(AF_INET, SOCK_STREAM, 0);
	
	if (sockfd3 < 0)
	{
		//perror() report error message
		perror("sock");
		//exit your program
		exit(EXIT_FAILURE);
	}


	printf("1st socket created");
	
	int buffer_size=2;
	char buffer[buffer_size]; 
	
//	int len;
								
	if (connect(sockfd3, (struct sockaddr*)&address3, sizeof(address3)) < 0){
	// perror() report error message
		perror("connect");
	// close socket
		close(sockfd3);
	// exit your program
		exit(EXIT_FAILURE);
								
		}
								
	//len=send(sockfd3, buffer, sizeof(buffer), 0);
	
//	if(len<0){
//	printf("error sending column");
//	}
								
	stpcpy(buffer,num);
								
	write(sockfd3, buffer, buffer_size);

        close(sockfd3);
*/

//----------thread creation-------------//


if(argc==7){	
	arg->name=cwd;
	arg->output=cwd;

pthread_create(&t, NULL, dirfunc, (void *)arg );

} // if  7 parameters


else if(argc==9){

	sizerel=strlen(argv[8])-1;
        finallen=sizerel+sizeof(cwd);
        char *finalpath=(char *)malloc(sizeof(finallen));
	int i;
	if(strcmp(argv[7],"-d")==0){

		if(argv[8][0]=='.'){
           		if(strlen(argv[8])>2){ // if relative path is > 2
             			for(i=0; i<strlen(cwd); ++i){
                			finalpath[i]=cwd[i];
             			}
            			int k=i;
             			for(i=1; i<sizerel+1; ++i){
                			finalpath[k]=argv[8][i];
                			++k;
             			}
				arg->name=finalpath;
				arg->output=cwd;
				pthread_create(&t, NULL, dirfunc, (void *)arg );

			}

			else{ // if relative path is < 2
				arg->name=cwd;
				arg->output=cwd;
				pthread_create(&t, NULL, dirfunc, (void *)arg );
			}
		} // end if relative path
		else{ 
			arg->name=argv[8];
			arg->output=cwd;
			pthread_create(&t, NULL, dirfunc, (void *)arg );
		}

	} // end if input dir
	else if(strcmp(argv[7],"-o")==0){
	
		if(argv[8][0]=='.'){
                        if(strlen(argv[8])>2){ // if relative path is > 2
                                for(i=0; i<strlen(cwd); ++i){
                                        finalpath[i]=cwd[i];
                                }
                                int k=i;
                                for(i=1; i<sizerel+1; ++i){
                                        finalpath[k]=argv[8][i];
                                        ++k;
                                }
                                arg->name=cwd;
                                arg->output=finalpath;
								pthread_create(&t, NULL, dirfunc, (void *)arg );
			}

                        else{ // if relative path is < 2
                                arg->name=cwd;
                                arg->output=cwd;
								pthread_create(&t, NULL, dirfunc, (void *)arg );
                        }
                } // end if relative path
                else{
                        arg->name=cwd;
                        arg->output=argv[8];
						pthread_create(&t, NULL, dirfunc, (void *)arg );
                }


	}
	else{
		printf("incorrect parameter indication");
		exit(0);
	}
	

} // if 9 parameters

else{
	
	  sizerel=strlen(argv[8])-1;
          finallen=sizerel+sizeof(cwd);
          char *finalpath=(char *)malloc(sizeof(finallen));
          int i=0;
 	  sizerel1=strlen(argv[10])-1;
          finallen1=sizerel1+sizeof(cwd);
          char *finalpath1=(char *)malloc(sizeof(finallen1));		
	  int j=0;

	  if(strcmp(argv[7],"-d")!=0){
		printf("incorrect parameter type");
		exit(0);
	 }
	 if(strcmp(argv[9],"-o")!=0){
		printf("incorrect parameter type");
		exit(0);
	 }

	  if(argv[8][0]=='.'){ // if d is relative
         	if(strlen(argv[8])>2){ // if d is relative and is > 2
            		for(i=0; i<strlen(cwd); ++i){
               			finalpath[i]=cwd[i];
            		}
            		int k=i;
            		for(i=1; i<sizerel+1; ++i){
               			finalpath[k]=argv[8][i];
               			++k;
            		}
              		if(argv[10][0]=='.'){ // if d is relative and is >2 and output is relative
                 		if(strlen(argv[10])>2){ // if d is relative and is >2 and output is relative and >2
                    			for(j=0; i<strlen(cwd); ++j){
                      				finalpath1[j]=cwd[j];
                    			}
                    			int k=j;
                   			for(j=1; j<sizerel1+1; ++j){
                      				finalpath1[k]=argv[10][j];
                      				++k;
                    			}
             				 arg->name=finalpath;
             				 arg->output=finalpath1;
							 pthread_create(&t, NULL, dirfunc, (void *)arg );
				}
				else{
					arg->name=finalpath;
					arg->output=cwd;
					pthread_create(&t, NULL, dirfunc, (void *)arg );
				
				}
			}
			else{ // if d is relative and output is not relative
				arg->name=finalpath;
				arg->output=argv[10];
				pthread_create(&t, NULL, dirfunc, (void *)arg );
			}
		}
		else{ // if d is relative but < 2 (cwd)	
			if(argv[10][0]=='.'){ // if d is relative and is >2 and output is relative
                                if(strlen(argv[10])>2){ // if d is relative and is >2 and output is relative and >2
                                        for(j=0; i<strlen(cwd); ++j){
                                                finalpath1[j]=cwd[j];
                                        }
                                        int k=j;
                                        for(j=1; j<sizerel1+1; ++j){
                                                finalpath1[k]=argv[10][j];
                                                ++k;    
                                        }
                                         arg->name=cwd;
                                         arg->output=finalpath1;
                                         pthread_create(&t, NULL, dirfunc, (void *)arg );
                                }
                                else{   
                                        arg->name=cwd;
                                        arg->output=cwd;
										pthread_create(&t, NULL, dirfunc, (void *)arg );
                                }
                        }
                        else{ // if d is relative and output is not relative
                                arg->name=finalpath;
                                arg->output=argv[10];
								pthread_create(&t, NULL, dirfunc, (void *)arg );
                        }
                }
	}// if d is relative
	
	else{ // d is not relative

		if(argv[10][0]=='.'){ // if d is not relative and is >2 and output is relative
                                if(strlen(argv[10])>2){ // if d is not relative and is >2 and output is relative and >2
                                        for(j=0; i<strlen(cwd); ++j){
                                                finalpath1[j]=cwd[j];
                                        }
                                        int k=j;
                                        for(j=1; j<sizerel1+1; ++j){
                                                finalpath1[k]=argv[10][j];
                                                ++k;
                                        }
                                         arg->name=argv[8];
                                         arg->output=finalpath1;
                                         pthread_create(&t, NULL, dirfunc, (void *)arg );
                                }
                                else{
                                        arg->name=argv[8];
                                        arg->output=cwd;
										pthread_create(&t, NULL, dirfunc, (void *)arg );
                                }
                }
                else{ // if d is not relative  and output is not relative
                                arg->name=argv[8];
                                arg->output=argv[10];
								pthread_create(&t, NULL, dirfunc, (void *)arg );
               }

	}

} // if 11 parameters


fflush(stdout);
printf("thread struct\n");
fflush(stdout);
printf("---------------------------------\n");
fflush(stdout);
printf("input directory is %s \n", arg->name);
fflush(stdout);
printf("output directory is %s \n", arg->output);
fflush(stdout);

  
  if(pthread_join(t, NULL)) {

printf("Error joining thread\n");
return 2;

}

fflush(stdout);
printf("threads joined successfully\n");
fflush(stdout);

 pthread_mutex_destroy(&lock);
pthread_mutex_destroy(&lock2);


//---------------------phase 2: final request ------------------------// 

int sockfd2; //declare a socket 
struct sockaddr_in address; //socket struct
struct hostent *server2; //host struct
   
server2 = gethostbyname(argv[4]); 
   
   if (server2 == NULL){
		fprintf(stderr, "ERROR, NO SUCH HOST\n");
		exit(0);
	}
   
   memset(&address, 0, sizeof(address));
   
    address.sin_family = AF_INET;
	
	address.sin_port = htons(arg->port);
	
	bcopy((char*)server2->h_addr,
			(char*)&address.sin_addr.s_addr,
			server2->h_length);
			
	sockfd2 = socket(AF_INET, SOCK_STREAM, 0);
	
	if (sockfd2 < 0)
	{
		//perror() report error message
		perror("sock");
		//exit your program
		exit(EXIT_FAILURE);
	}
	
	fflush(stdout);
	printf("last socket created\n");
	fflush(stdout);
	
	int n; char fbuff[256]; 
	const char* filename="Allfiles.csv";
	FILE *fp;

		     int tlen=strlen(filename)-3;
                     char title[tlen];
                     int x;
                     for(x=0; x<tlen-1; ++x){
                        title[x]=filename[x];
                     }
                     title[x]='\0';
                     const char *sorted= "-sorted-";
                     const char *csv= ".csv";
                     const char *slash="/";
                     char newtitle[strlen(arg->output)+1+tlen+8+strlen(column)+4];
                     strcpy(newtitle, arg->output);
                     strcat(newtitle, slash);
                     strcat(newtitle, title);
                     strcat(newtitle,sorted);
                     strcat(newtitle,column);
                     strcat(newtitle,csv);
                     //printf("%s", newtitle);


fp = fopen(newtitle, "w");

fprintf(fp,"color,director_name,num_critic_for_reviews,duration,director_facebook_likes,actor_3_facebook_likes,actor_2_name,actor_1_facebook_likes,gross,genres,actor_1_name,movie_title,num_voted_users,cast_total_facebook_likes,actor_3_name,facenumber_in_poster,plot_keywords,movie_imdb_link,num_user_for_reviews,language,country,content_rating,budget,title_year,actor_2_facebook_likes,imdb_score,aspect_ratio,movie_facebook_likes\n");

fprintf(fp,"\n"); 

fclose(fp);

if (connect(sockfd2, (struct sockaddr*)&address, sizeof(address)) < 0){
								// perror() report error message
								perror("connect");
								// close socket
								close(sockfd2);
								// exit your program
								exit(EXIT_FAILURE);
								
								}
								
								
fflush(stdout);
printf("after last socket connected\n");
fflush(stdout);

memset(fbuff, 0, 4);

strcpy(fbuff, "dump");

write(sockfd2, fbuff, buffer_size);

fflush(stdout);
printf("-----------dump buffer--------:\n");
fflush(stdout);
fwrite(fbuff, buffer_size, 1, stdout);	
fflush(stdout);


sleep(5);

fflush(stdout);
printf("bRUH waKE UP\n");
fflush(stdout);

fp = fopen(newtitle, "a");

int readbuffsize=1024;
char readbuff[readbuffsize];


while((n = read(sockfd2, readbuff, sizeof(readbuff))) > 0){
	printf("uhhhh\n");
	fflush(stdout);
  	fwrite(readbuff, sizeof(readbuff), 1, fp); 
}

fclose(fp);

close(sockfd2);


return 0;

}


