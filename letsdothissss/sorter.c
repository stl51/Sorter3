#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include"mergesort.h"
#include"sorter.h"

struct node* dequeue(struct queue *q)
{
    // If queue is empty, return NULL.
    if (q->front == NULL)
       return NULL;
 
    // Store previous front and move front one node ahead
    struct node *temp = q->front;
    q->front = q->front->next;
 
    // If front becomes NULL, then change rear also as NULL
    if (q->front == NULL)
       q->rear = NULL;
    return temp;
}

char *trim(char *str){
 
 char *temp;

  while(isspace((unsigned char)*str)) str++;

  if(*str == 0){  
    return str;
  }

  temp = str + strlen(str) - 1;
  while(temp > str && isspace((unsigned char)*temp)) temp--;
  
  *(temp+1) = 0;

  return str;
}

void tokenizer(char* str){ 

int c=0;
int i=0;
int p=0;
int y=0;
int z=0;

char end='\0';

for(i=0; i<strlen(str); ++i){

 if(str[i]==','){

  ++c;                 

  char *temp=(char*)malloc(sizeof(char*)*c);

	for(z=0; z<c-1; ++z){
    temp[z]=str[y];
    ++y;}

   temp[z+1]=end;
   temp = trim(temp);
   final[p]=temp;
   ++p;
   c=0;
   ++y; 
 }

 
 else if(str[i]=='\"'){
	++y;
  do{
  ++c;
  ++i;
   }while(str[i]!='\"');

 ++c;

 char *temp=(char*)malloc(sizeof(char*)*c);

	for(z=0; z<c-2; ++z){
   temp[z]=str[y];
    ++y;}

   temp[z+1]=end;
   final[p]=temp;
   ++i;
   y+=2;
   ++p;
   c=0;	 
 
 }
 
 else{
 ++c;
 }
}

++c;

char *temp=(char*)malloc(sizeof(char*)*c);

for(z=0; z<c-1; ++z){
temp[z]=str[y];
 ++y;
}

temp[z+1]=end;
temp = trim(temp);
final[p]=temp;

}


void initialize1(imdb *list,int count){

list[count].color = final[0];
list[count].director_name = final[1];
list[count].num_critic_for_reviews = final[2];
list[count].duration = final[3];
list[count].director_facebook_likes = final[4];
list[count].actor_3_facebook_likes= final[5];
list[count].actor_2_name= final[6];
list[count].actor_1_facebook_likes= final[7];
list[count].gross= final[8];
list[count].genres= final[9];
list[count].actor_1_name= final[10];
list[count].movie_title= final[11];
list[count].num_voted_users= final[12];
list[count].cast_total_facebook_likes= final[13];
list[count].actor_3_name= final[14];
list[count].facenumber_in_poster= final[15];
list[count].plot_keywords= final[16];
list[count].movie_imdb_link= final[17];;
list[count].num_user_for_reviews= final[18];
list[count].language= final[19];
list[count].country= final[20];
list[count].content_rating= final[21];
list[count].budget= final[22];
list[count].title_year= final[23];
list[count].actor_2_facebook_likes= final[24];
list[count].imdb_score= final[25];
list[count].aspect_ratio= final[26];
list[count].movie_facebook_likes= final[27];

} 


void printlist(imdb *list,int count, FILE* fp){

fprintf(fp,"%s,",list[count].color);
fprintf(fp,"%s,",list[count].director_name);
fprintf(fp,"%s,",list[count].num_critic_for_reviews);
fprintf(fp,"%s,",list[count].duration);
fprintf(fp,"%s,",list[count].director_facebook_likes);
fprintf(fp,"%s,",list[count].actor_3_facebook_likes);
fprintf(fp,"%s,",list[count].actor_2_name);
fprintf(fp,"%s,",list[count].actor_1_facebook_likes);
fprintf(fp,"%s,",list[count].gross);
fprintf(fp,"%s,",list[count].genres);
fprintf(fp,"%s,",list[count].actor_1_name);
fprintf(fp,"%s,",list[count].movie_title);
fprintf(fp,"%s,",list[count].num_voted_users);
fprintf(fp,"%s,",list[count].cast_total_facebook_likes);
fprintf(fp,"%s,",list[count].actor_3_name);
fprintf(fp,"%s,",list[count].facenumber_in_poster);
fprintf(fp,"%s,",list[count].plot_keywords);
fprintf(fp,"%s,",list[count].movie_imdb_link);
fprintf(fp,"%s,",list[count].num_user_for_reviews);
fprintf(fp,"%s,",list[count].language);
fprintf(fp,"%s,",list[count].country);
fprintf(fp,"%s,",list[count].content_rating);
fprintf(fp,"%s,",list[count].budget);
fprintf(fp,"%s,",list[count].title_year);
fprintf(fp,"%s,",list[count].actor_2_facebook_likes);
fprintf(fp,"%s,",list[count].imdb_score);
fprintf(fp,"%s,",list[count].aspect_ratio);
fprintf(fp,"%s",list[count].movie_facebook_likes);



} 

void sorter(struct queue* dataq, const char* column, FILE *f, char* filename, const char* output){

char str[1000];  int count=1; int k; int restartcount=0;

//queue parameters, 
FILE* tempfp; struct node *tempn=NULL;

while(dataq->front!=NULL){
	
	
tempn = dequeue(dataq);

tempfp = fopen(tempn->file,"r"); 

while(fscanf(tempfp,"%[^@]%*c", str) !=EOF){
	
	
if(restartcount==0){
	restartcount++;
	continue;
}

restartcount++;

dummy[count-1] = strdup(str);


count++;

} 

restartcount=0;

fclose(tempfp);

}



//else{
	
//while(fscanf(f,"%[^\n]%*c", str) !=EOF){

//dummy[count-1] = strdup(str);


//count++;

//} 
	
//}


count=count-1; 

imdb* list; 
list=(imdb*)malloc(count*sizeof(imdb)); 

char*temp;

for(k=0; k < count; k++){

temp = dummy[k];

tokenizer(temp);

initialize1(list,k);

} 

if((strcmp("color",column))==0){
	MergeSortColor(list,count);
}
else if((strcmp("director_name",column))==0){
	
	MergeSortDirector(list,count);
}
else if((strcmp("num_critic_for_reviews",column))==0){
	MergeSortNumCritic(list,count);
}
else if((strcmp("duration",column))==0){
	MergeSortDur(list,count);
}
else if((strcmp("director_facebook_likes",column))==0){
	MergeSortDirLike(list,count);
}
else if((strcmp("actor_3_facebook_likes",column))==0){
	MergeSortActor3Like(list,count);
}
else if((strcmp("actor_2_name",column))==0){
	MergeSortActor2(list,count);
}
else if((strcmp("actor_1_facebook_likes",column))==0){
	MergeSortActor1Like(list,count);
}
else if((strcmp("gross",column))==0){
	MergeSortGross(list,count);
}
else if((strcmp("genres",column))==0){
	MergeSortGenre(list,count);
}
else if((strcmp("actor_1_name",column))==0){
	MergeSortActor1(list,count);
}
else if((strcmp("movie_title",column))==0){
	MergeSortMovieTitle(list,count);
}
else if((strcmp("num_voted_users",column))==0){
	MergeSortVote(list,count);
}
else if((strcmp("cast_total_facebook_likes",column))==0){
	MergeSortCastLike(list,count);
}
else if((strcmp("actor_3_name",column))==0){
	MergeSortActor3(list,count);
}
else if((strcmp("facenumber_in_poster",column))==0){
	MergeSortPoster(list,count);
}
else if((strcmp("plot_keywords",column))==0){
	MergeSortPlot(list,count);
}
else if((strcmp("movie_imdb_link",column))==0){
	MergeSortLink(list,count);
}
else if((strcmp("num_user_for_reviews",column))==0){
	MergeSortReview(list,count);
}
else if((strcmp("language",column))==0){
	MergeSortLang(list,count);
}
else if((strcmp("country",column))==0){
	MergeSortCountry(list,count);
}
else if((strcmp("content_rating",column))==0){
	MergeSortRating(list,count);
}
else if((strcmp("budget",column))==0){
	MergeSortBudget(list,count);
}
else if((strcmp("title_year",column))==0){
	MergeSortYear(list,count);
}
else if((strcmp("actor_2_facebook_likes",column))==0){
	MergeSortActor2Like(list,count);
}
else if((strcmp("imdb_score",column))==0){
	MergeSortScore(list,count);
}
else if((strcmp("aspect_ratio",column))==0){
	MergeSortAspect(list,count);
}
else if((strcmp("movie_facebook_likes",column))==0){
	MergeSortMovieLike(list,count);
}
else{
	printf("error\n");
}


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
                     char* newtitle= (char*)malloc(sizeof(char)*(strlen(output)+1+tlen+8+strlen(column)+4));
                     strcpy(newtitle, output);
                     strcat(newtitle, slash);
                     strcat(newtitle, title);
                     strcat(newtitle,sorted);
                     strcat(newtitle,column);
                     strcat(newtitle,csv);





int i = mkdir(output,0777);
if(i<0){
fp = fopen(newtitle, "w");
}
else{
fp = fopen(newtitle, "w");
}

fprintf(fp,"color,director_name,num_critic_for_reviews,duration,director_facebook_likes,actor_3_facebook_likes,actor_2_name,actor_1_facebook_likes,gross,genres,actor_1_name,movie_title,num_voted_users,cast_total_facebook_likes,actor_3_name,facenumber_in_poster,plot_keywords,movie_imdb_link,num_user_for_reviews,language,country,content_rating,budget,title_year,actor_2_facebook_likes,imdb_score,aspect_ratio,movie_facebook_likes\n");


for(k=0; k < count; k++){
printlist(list,k,fp);
fprintf(fp,"@");
}

rewind(fp);

//fflush(stdout);

return;

}


