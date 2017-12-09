/*****
*
*	Define structures and function prototypes for your sorter
*
*
*
******/

//Suggestion: define a struct that mirrors a record (row) of the data set
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pthread.h>

struct film{
		char* color;
		char* director_name;
		int num_critic_for_reviews;
		int duration;
		int director_facebook_likes;
		int actor_3_facebook_likes;
		char* actor_2_name;
		int actor_1_facebook_likes;
		int gross;
		char* genres;
		char* actor_1_name;
		char* movie_title;		
		int num_voted_users;
		int cast_total_facebook_likes;
		char* actor_3_name;		
		int facenumber_in_poster;
		char* plot_keywords;
		char* movie_imdb_link;
		int num_user_for_reviews;
		char* language;
		char* country;
		char* content_rating;
		int budget;
		int title_year;
		int actor_2_facebook_likes;	
		double imdb_score;
		double aspect_ratio;
		int movie_facebook_likes;
};
typedef struct film film;

struct thread_arg{
	//&(tids[spawns - 1]), 0, run_thru, dir_check, sortby, dest_dir, pathway
	DIR* dir_check;
	int sortby;
	char dest_dir[1024];
	char pathway[1024];
	
};
typedef struct thread_arg thread_arg;

struct sortcsv_arg{
	//ofile, sortby, dir_path
	FILE* ofile;
	int sortby;
    char dir_path[1024];
	
};
typedef struct sortcsv_arg sortcsv_arg;

struct film_arg{
		film** film_list;
		int amount;
		int threads;
};
typedef struct film_arg film_arg;

//Suggestion: prototype a mergesort function
film** mergesort(film** array, int size, int col);//pointer to unsorted array, size of array, column to sort by

//LOCKSMITH:

//pthread_mutex_t insertlock=PTHREAD_MUTEX_INITIALIZER;


//pthread_mutex_t protaglock=PTHREAD_MUTEX_INITIALIZER;


//pthread_mutex_t pathlock=PTHREAD_MUTEX_INITIALIZER;




void free_strings(film** array, int len);//free string pointers for each struct when freeing an array
film* filmcpy(film* filmA, film* filmB);//copy a film struct function
film* replace_NULL_w_empty(film* f);//self explanitory
char* strtok_fix (char* str, char const * delim);//a fix to strtok to include nulls
film_arg * sort_csv(void * arg);
film_arg * run_thru(void* arg);
film_arg* insert_film(film** arrayA, film** arrayB, int mid, int k, int col);
film_arg* merge_sorted(film** arrayA, film** arrayB, int mid, int k, int col);
