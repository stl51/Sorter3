#ifndef SORTER_H_H
#define SORTER_H_H

struct node
{
    char* file;
    struct node *next;
};
 
struct queue
{
    struct node *front, *rear;
};
 
struct queue* dataq;
 
char *final[28]; 

char *dummy[8000]; 

struct node* dequeue(struct queue *q);
char *trim(char *str);
void tokenizer(char* str);
void initialize1(imdb *list,int count);
void printlist(imdb *list,int count, FILE* fp);
void sorter(struct queue* dataq,const char* column, FILE *f, char* filename, const char* output);

#endif