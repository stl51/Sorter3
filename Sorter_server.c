#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Sorter_server.h"
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

#include <sys/socket.h>
#include <netinet/in.h>

#include <pthread.h>

pthread_mutex_t insertlock=PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t protaglock=PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t pathlock=PTHREAD_MUTEX_INITIALIZER;

int main(int argc, char** argv) {

	int sortby;

	if (strcmp("-c", argv[1]) != 0) {
		printf("ERROR: Invalid Value Type\n");
		return 0;
	}
	sortby = 0;
	if (strcmp("color", argv[2]) == 0) {
		sortby = 1;
	}
	else if (strcmp("director_name", argv[2]) == 0) {
		sortby = 2;
	}
	else if (strcmp("num_critic_for_reviews", argv[2]) == 0) {
		sortby = 3;
	}
	else if (strcmp("duration", argv[2]) == 0) {
		sortby = 4;
	}
	else if (strcmp("director_facebook_likes", argv[2]) == 0) {
		sortby = 5;
	}
	else if (strcmp("actor_3_facebook_likes", argv[2]) == 0) {
		sortby = 6;
	}
	else if (strcmp("actor_2_name", argv[2]) == 0) {
		sortby = 7;
	}
	else if (strcmp("actor_1_facebook_likes", argv[2]) == 0) {
		sortby = 8;
	}
	else if (strcmp("gross", argv[2]) == 0) {
		sortby = 9;
	}
	else if (strcmp("genres", argv[2]) == 0) {
		sortby = 10;
	}
	else if (strcmp("actor_1_name", argv[2]) == 0) {
		sortby = 11;
	}
	else if (strcmp("movie_title", argv[2]) == 0) {
		sortby = 12;
	}
	else if (strcmp("num_voted_users", argv[2]) == 0) {
		sortby = 13;
	}
	else if (strcmp("cast_total_facebook_likes", argv[2]) == 0) {
		sortby = 14;
	}
	else if (strcmp("actor_3_name", argv[2]) == 0) {
		sortby = 15;
	}
	else if (strcmp("facenumber_in_poster", argv[2]) == 0) {
		sortby = 16;
	}
	else if (strcmp("plot_keywords", argv[2]) == 0) {
		sortby = 17;
	}
	else if (strcmp("movie_imdb_link", argv[2]) == 0) {
		sortby = 18;
	}
	else if (strcmp("num_user_for_reviews", argv[2]) == 0) {
		sortby = 19;
	}
	else if (strcmp("language", argv[2]) == 0) {
		sortby = 20;
	}
	else if (strcmp("country", argv[2]) == 0) {
		sortby = 21;
	}
	else if (strcmp("content_rating", argv[2]) == 0) {
		sortby = 22;
	}
	else if (strcmp("budget", argv[2]) == 0) {
		sortby = 23;
	}
	else if (strcmp("title_year", argv[2]) == 0) {
		sortby = 24;
	}
	else if (strcmp("actor_2_facebook_likes", argv[2]) == 0) {
		sortby = 25;
	}
	else if (strcmp("imdb_score", argv[2]) == 0) {
		sortby = 26;
	}
	else if (strcmp("aspect_ratio", argv[2]) == 0) {
		sortby = 27;
	}
	else if (strcmp("movie_facebook_likes", argv[2]) == 0) {
		sortby = 28;
	}
	if (sortby == 0) {
		printf("ERROR: Invalid Category For Sorting\n");
		return 1;
	}
	//vvv  set these to the default of current directory  vvv
	char src_dir[4096];	//source directory
	char dest_dir[4096];	//destination directory
	char orig_dir[4096]; //starting directory
	/*src_dir = (char*)malloc(sizeof(char) * 4096);
	dest_dir = (char*)malloc(sizeof(char) * 4096);
	orig_dir = (char*)malloc(sizeof(char) * 4096);*/
	getcwd(src_dir, sizeof(src_dir));
	getcwd(dest_dir, sizeof(dest_dir));
	getcwd(orig_dir, sizeof(orig_dir));
	if((argc==6)||(argc==8)){
			printf("ERROR: Incorrect number of arguments\n");
			return 1;
	}
	if(argc==5){
	
			if (strcmp("-d", argv[3]) == 0) {
				if (argv[4] != NULL) {
					strcpy(src_dir, argv[4]);
				}
				else {
					printf("ERROR: Missing input directory name\n");
					return 1;
				}
			}
			else if (strcmp("-o", argv[3]) == 0) {
				if (argv[4] != NULL) {
					strcat(dest_dir, argv[4]);
				}
				else {
					printf("ERROR: Missing output directory name\n");
					return 1;
				}
			}
	}
	if(argc==7)	{
		if (strcmp("-o", argv[5]) == 0) {
			if (argv[6] != NULL) {
				strcpy(dest_dir, argv[6]);
			}
			else {
				printf("ERROR: Missing output directory name\n");
				return 1;
			}
		}
	}
	//check if directories are valid:
	DIR* src_folder = opendir(src_dir);
	if (src_folder) {
		//closedir(src_folder);
	}
	else {
		printf("ERROR: Invalid input directory\n");
		return 1;
	}

	DIR* dest_folder = opendir(dest_dir);
	if (dest_folder) {
		//closedir(dest_folder);
	}
	else {
		printf("ERROR: Invalid output directory\n");
		return 1;
	}

	//int total;
	printf("Initial TID: %d\n", (int)pthread_self());
	printf("TIDs of all threads: ");
	
	char pathway[4096];
	getcwd(pathway,sizeof(pathway));
	strcat(pathway,"/");
	strcat(pathway,src_dir);
	
	thread_arg * arg = (thread_arg*)malloc(sizeof(thread_arg));
	arg->dir_check = src_folder;
	arg->sortby = sortby;
	strcpy(arg->dest_dir, dest_dir);
	strcpy(arg->pathway, pathway);
	film_arg* res;
	res = run_thru((void*)arg);
	int size = ((film_arg*)res)->amount;
	film** array = ((film_arg*)res)->film_list;
	//total = ((film_arg*)res)->threads;
	printf("\ntotal number of threads: %d\n", ((film_arg*)res)->threads+1);

	char* nfilename = (char*)malloc(sizeof(char) * 100);
	//memcpy(nfilename, filename, strlen(filename) - 4);
	//nfilename[strlen(filename) - 4] = '\0';
	//nfilename = strcpy(nfilename, filename);
	nfilename = strcpy(nfilename, "AllFiles-sorted-");
	nfilename = strcat(nfilename, argv[2]);
	nfilename = strcat(nfilename, ".csv");
	//make a new file and write to that file the sorted array

	chdir(dest_dir);
	FILE* nfile = fopen(nfilename, "w");
	int b;
	for (b = 0; b<size; b++) {
		fprintf(nfile, "%s,%s,%d,%d,%d,%d,%s,%d,%d,%s,%s,%s,%d,%d,%s,%d,%s,%s,%d,%s,%s,%s,%d,%d,%d,%f,%f,%d\n", array[b]->color, array[b]->director_name, array[b]->num_critic_for_reviews, array[b]->duration, array[b]->director_facebook_likes, array[b]->actor_3_facebook_likes, array[b]->actor_2_name, array[b]->actor_1_facebook_likes, array[b]->gross, array[b]->genres, array[b]->actor_1_name, array[b]->movie_title, array[b]->num_voted_users, array[b]->cast_total_facebook_likes, array[b]->actor_3_name, array[b]->facenumber_in_poster, array[b]->plot_keywords, array[b]->movie_imdb_link, array[b]->num_user_for_reviews, array[b]->language, array[b]->country, array[b]->content_rating, array[b]->budget, array[b]->title_year, array[b]->actor_2_facebook_likes, array[b]->imdb_score, array[b]->aspect_ratio, array[b]->movie_facebook_likes);
	}
	fclose(nfile);

	return 0;
}


film_arg * run_thru(void* arg) {
	printf("%d,", (int)pthread_self());
	DIR* folder = ((thread_arg*)arg)->dir_check;
	int sortby = ((thread_arg*)arg)->sortby;
    char dest_dir[1024]; 
	strcpy(dest_dir, ((thread_arg*)arg)->dest_dir);
	char pathway[1024];
	strcpy(pathway, ((thread_arg*)arg)->pathway);

	//printf("PIDS of all child processes: ");

	int spawns = 0;
	pthread_t * tids = (pthread_t*)malloc(sizeof(pthread_t) * 1);//array of all threads this thread creates
	int array_size = 1;
	void * status;

	//pthread_mutex_lock(&protaglock);

	struct dirent* protag;	//protag is the file/directory in focus
//	protag = readdir(folder);
//	while (protag != NULL) {
	while(1){
		
		pthread_mutex_lock(&protaglock);
		protag = readdir(folder);
		if(protag==NULL){
            pthread_mutex_unlock(&protaglock);
			break;
		}
		char swing[1024];
		strcpy(swing, protag->d_name);
		pthread_mutex_unlock(&protaglock);
//		protag = readdir(folder);
		//lock above
	
		
		
		DIR* dir_check = opendir(swing);
		pthread_mutex_lock(&pathlock);
		if(dir_check==NULL){
			if(pathway[strlen(pathway)-1] != '/'){
				strcat(pathway,"/");
			}
			strcat(pathway,swing);
			dir_check=opendir(pathway);
		}
		if (dir_check != NULL) { 
			//protag is a folder, fork and handle
			if (!strcmp(swing, ".") || !strcmp(swing,"..")) {
				pthread_mutex_unlock(&pathlock);
                continue;
			}
			spawns++;
			if (spawns > array_size) {
				array_size = array_size * 2;
				tids = (pthread_t*)realloc(tids, sizeof(pthread_t)*array_size);
			}
			thread_arg * arg = (thread_arg*)malloc(sizeof(thread_arg));
			arg->dir_check = dir_check;
			arg->sortby = sortby;
			strcpy(arg->dest_dir, dest_dir);
			strcpy(arg->pathway, pathway);
			pthread_create(&(tids[spawns - 1]), 0, (void*) run_thru, (void*) arg);//need a struct to hold all args
			
        }
		else {
            //protag is a file, fork and handle
			spawns++;
			if (spawns > array_size) {
				array_size = array_size * 2;
				tids = (pthread_t*)realloc(tids, sizeof(pthread_t)*array_size);
			}
			FILE* ofile = fopen(pathway, "r");

			char* dir_path = (char*)malloc(sizeof(char) * 4096);
			dir_path = (char*)memcpy(dir_path, pathway, sizeof(char)*(strlen(pathway) - strlen(swing)));
			dir_path[strlen(pathway) - strlen(swing)] = '\0';
			sortcsv_arg * args = (sortcsv_arg*)malloc(sizeof(sortcsv_arg));
			args->ofile = ofile;
			args->sortby = sortby;
            pthread_create(&(tids[spawns - 1]), 0, (void*) sort_csv, (void*) args);//see line 225
			
		}
        pathway[strlen(pathway)-strlen(swing)] = '\0';
		pthread_mutex_unlock(&pathlock);
	}
	
	pthread_mutex_lock(&insertlock);
    int i = 0;
	film_arg * a = (film_arg*)malloc(sizeof(film_arg));
	a->film_list = (film**)malloc(sizeof(film*));
	a->amount = 0;
	a->threads = spawns;
	while (i < spawns) {
		pthread_join(tids[i], &status);//status needs to be a void *, then casted into a film_arg* to be merged
		film_arg* b = (film_arg*)status;
		int t = b->threads + a->threads;
		a = insert_film(a->film_list, b->film_list, a->amount, b->amount, sortby);
		a->threads = t;
		//add function that contains merge_sorted here
		
		//total = total + WEXITSTATUS(status);
		i++;
	}
	pthread_mutex_unlock(&insertlock);
	//total = total + spawns;
	//printf("\ntotal number of child processes: %d\n", total);

	closedir(folder);
	return a;
}

film_arg* insert_film(film** arrayA, film** arrayB, int mid, int k, int col) {

	film_arg* final;

	//pthread_mutex_lock(&insertlock);

		final=merge_sorted(arrayA,arrayB,mid,k,col);
		
	//pthread_mutex_unlock(&insertlock);
	
	return final;
	
}	



film_arg* merge_sorted(film** arrayA, film** arrayB, int mid, int k, int col) {//returns a new sorted array. Please modify so it returns a struct that also contains the size of the array (mid+k)
	//array = already created but empty array to place films into, mid = sizeof A, k = sizeof B, col = sortby


	film_arg* final=(film_arg*)malloc(sizeof(film_arg));
	final->amount=mid+k;
	final->film_list=(film**)malloc(sizeof(film*)*(mid+k));
	int z;
	for (z = 0; z < final->amount; z++) {
		(final->film_list)[z] = (film*)malloc(sizeof(film));
	}
	film** array=final->film_list;
	
	
	int i = 0; int j = 0; int a = 0;
	while (i<mid && j<k) {
		//depending on what column we're sorting by, do things
		if (col == 1 || col == 2 || col == 7 || col == 10 || col == 11 || col == 12 || col == 15 || col == 17 || col == 18 || col == 20 || col == 21 || col == 22) {
			//sort by string, first being NULL
			switch (col) {
			case(1): {//color
				if (arrayA[i]->color == NULL) {
					array[a] = filmcpy(arrayA[i], array[a]);
					i++;
					break;
				}
				else if (arrayB[j]->color == NULL) {
					array[a] = filmcpy(arrayB[j], array[a]);
					j++;
					break;
				}
				if (strcmp(arrayA[i]->color, arrayB[j]->color) > 0) {//arrayA's val is greater
					array[a] = filmcpy(arrayB[j], array[a]);
					j++;
					break;
				}
				else {//arrayA's val is less or equal
					array[a] = filmcpy(arrayA[i], array[a]);
					i++;
					break;
				}
			}
			case(2): {//director_name//
				if (arrayA[i]->director_name == NULL) {
					array[a] = filmcpy(arrayA[i], array[a]);
					i++;
					break;
				}
				else if (arrayB[j]->director_name == NULL) {
					array[a] = filmcpy(arrayB[j], array[a]);
					j++;
					break;
				}
				if (strcmp(arrayA[i]->director_name, arrayB[j]->director_name) > 0) {//arrayA's val is greater
					array[a] = filmcpy(arrayB[j], array[a]);
					j++;
					break;
				}
				else {//arrayA's val is less or equal
					array[a] = filmcpy(arrayA[i], array[a]);
					i++;
					break;
				}
			}
			case(7): {//actor_2_name
				if (arrayA[i]->actor_2_name == NULL) {
					array[a] = filmcpy(arrayA[i], array[a]);
					i++;
					break;
				}
				else if (arrayB[j]->actor_2_name == NULL) {
					array[a] = filmcpy(arrayB[j], array[a]);
					j++;
					break;
				}
				if (strcmp(arrayA[i]->actor_2_name, arrayB[j]->actor_2_name) > 0) {//arrayA's val is greater
					array[a] = filmcpy(arrayB[j], array[a]);
					j++;
					break;
				}
				else {//arrayA's val is less or equal
					array[a] = filmcpy(arrayA[i], array[a]);
					i++;
					break;
				}
			}
			case(10): {//genres
				if (arrayA[i]->genres == NULL) {
					array[a] = filmcpy(arrayA[i], array[a]);
					i++;
					break;
				}
				else if (arrayB[j]->genres == NULL) {
					array[a] = filmcpy(arrayB[j], array[a]);
					j++;
					break;
				}
				if (strcmp(arrayA[i]->genres, arrayB[j]->genres) > 0) {//arrayA's val is greater
					array[a] = filmcpy(arrayB[j], array[a]);
					j++;
					break;
				}
				else {//arrayA's val is less or equal
					array[a] = filmcpy(arrayA[i], array[a]);
					i++;
					break;
				}
			}
			case(11): {//actor_1_name
				if (arrayA[i]->actor_1_name == NULL) {
					array[a] = filmcpy(arrayA[i], array[a]);
					i++;
					break;
				}
				else if (arrayB[j]->actor_1_name == NULL) {
					array[a] = filmcpy(arrayB[j], array[a]);
					j++;
					break;
				}
				if (strcmp(arrayA[i]->actor_1_name, arrayB[j]->actor_1_name) > 0) {//arrayA's val is greater
					array[a] = filmcpy(arrayB[j], array[a]);
					j++;
					break;
				}
				else {//arrayA's val is less or equal
					array[a] = filmcpy(arrayA[i], array[a]);
					i++;
					break;
				}
			}
			case(12): {//movie_title
				if (arrayA[i]->movie_title == NULL) {
					array[a] = filmcpy(arrayA[i], array[a]);
					i++;
					break;
				}
				else if (arrayB[j]->movie_title == NULL) {
					array[a] = filmcpy(arrayB[j], array[a]);
					j++;
					break;
				}
				if (strcmp(arrayA[i]->movie_title, arrayB[j]->movie_title) > 0) {//arrayA's val is greater
					array[a] = filmcpy(arrayB[j], array[a]);
					j++;
					break;
				}
				else {//arrayA's val is less or equal
					array[a] = filmcpy(arrayA[i], array[a]);
					i++;
					break;
				}
			}
			case(15): {//actor_3_name
				if (arrayA[i]->actor_3_name == NULL) {
					array[a] = filmcpy(arrayA[i], array[a]);
					i++;
					break;
				}
				else if (arrayB[j]->actor_3_name == NULL) {
					array[a] = filmcpy(arrayB[j], array[a]);
					j++;
					break;
				}
				if (strcmp(arrayA[i]->actor_3_name, arrayB[j]->actor_3_name) > 0) {//arrayA's val is greater
					array[a] = filmcpy(arrayB[j], array[a]);
					j++;
					break;
				}
				else {//arrayA's val is less or equal
					array[a] = filmcpy(arrayA[i], array[a]);
					i++;
					break;
				}
			}
			case(17): {//plot_keywords
				if (arrayA[i]->plot_keywords == NULL) {
					array[a] = filmcpy(arrayA[i], array[a]);
					i++;
					break;
				}
				else if (arrayB[j]->plot_keywords == NULL) {
					array[a] = filmcpy(arrayB[j], array[a]);
					j++;
					break;
				}
				if (strcmp(arrayA[i]->plot_keywords, arrayB[j]->plot_keywords) > 0) {//arrayA's val is greater
					array[a] = filmcpy(arrayB[j], array[a]);
					j++;
					break;
				}
				else {//arrayA's val is less or equal
					array[a] = filmcpy(arrayA[i], array[a]);
					i++;
					break;
				}
			}
			case(18): {//move_imdb_link
				if (arrayA[i]->movie_imdb_link == NULL) {
					array[a] = filmcpy(arrayA[i], array[a]);
					i++;
					break;
				}
				else if (arrayB[j]->movie_imdb_link == NULL) {
					array[a] = filmcpy(arrayB[j], array[a]);
					j++;
					break;
				}
				if (strcmp(arrayA[i]->movie_imdb_link, arrayB[j]->movie_imdb_link) > 0) {//arrayA's val is greater
					array[a] = filmcpy(arrayB[j], array[a]);
					j++;
					break;
				}
				else {//arrayA's val is less or equal
					array[a] = filmcpy(arrayA[i], array[a]);
					i++;
					break;
				}
			}
			case(20): {//language
				if (arrayA[i]->language == NULL) {
					array[a] = filmcpy(arrayA[i], array[a]);
					i++;
					break;
				}
				else if (arrayB[j]->language == NULL) {
					array[a] = filmcpy(arrayB[j], array[a]);
					j++;
					break;
				}
				if (strcmp(arrayA[i]->language, arrayB[j]->language) > 0) {//arrayA's val is greater
					array[a] = filmcpy(arrayB[j], array[a]);
					j++;
					break;
				}
				else {//arrayA's val is less or equal
					array[a] = filmcpy(arrayA[i], array[a]);
					i++;
					break;
				}
			}
			case(21): {//country
				if (arrayA[i]->country == NULL) {
					array[a] = filmcpy(arrayA[i], array[a]);
					i++;
					break;
				}
				else if (arrayB[j]->country == NULL) {
					array[a] = filmcpy(arrayB[j], array[a]);
					j++;
					break;
				}
				if (strcmp(arrayA[i]->country, arrayB[j]->country) > 0) {//arrayA's val is greater
					array[a] = filmcpy(arrayB[j], array[a]);
					j++;
					break;
				}
				else {//arrayA's val is less or equal
					array[a] = filmcpy(arrayA[i], array[a]);
					i++;
					break;
				}
			}
			case(22): {//content_rating
				if (arrayA[i]->content_rating == NULL) {
					array[a] = filmcpy(arrayA[i], array[a]);
					i++;
					break;
				}
				else if (arrayB[j]->content_rating == NULL) {
					array[a] = filmcpy(arrayB[j], array[a]);
					j++;
					break;
				}
				if (strcmp(arrayA[i]->content_rating, arrayB[j]->content_rating) > 0) {//arrayA's val is greater
					array[a] = filmcpy(arrayB[j], array[a]);
					j++;
					break;
				}
				else {//arrayA's val is less or equal
					array[a] = filmcpy(arrayA[i], array[a]);
					i++;
					break;
				}
			}
			}
		}
		else {
			switch (col) {
			case(3): {//num_critic_for_reviews
				if (arrayA[i]->num_critic_for_reviews > arrayB[j]->num_critic_for_reviews) {
					array[a] = filmcpy(arrayB[j], array[a]);
					j++;
					break;
				}
				else {
					array[a] = filmcpy(arrayA[i], array[a]);
					i++;
					break;
				}
			}
			case(4): {//duration
				if (arrayA[i]->duration > arrayB[j]->duration) {
					array[a] = filmcpy(arrayB[j], array[a]);
					j++;
					break;
				}
				else {
					array[a] = filmcpy(arrayA[i], array[a]);
					i++;
					break;
				}
			}
			case(5): {//director_facebook_likes
				if (arrayA[i]->director_facebook_likes > arrayB[j]->director_facebook_likes) {
					array[a] = filmcpy(arrayB[j], array[a]);
					j++;
					break;
				}
				else {
					array[a] = filmcpy(arrayA[i], array[a]);
					i++;
					break;
				}
			}
			case(6): {//actor_3_facebook_likes
				if (arrayA[i]->actor_3_facebook_likes > arrayB[j]->actor_3_facebook_likes) {
					array[a] = filmcpy(arrayB[j], array[a]);
					j++;
					break;
				}
				else {
					array[a] = filmcpy(arrayA[i], array[a]);
					i++;
					break;
				}
			}
			case(8): {//actor_1_facebook_likes
				if (arrayA[i]->actor_1_facebook_likes > arrayB[j]->actor_1_facebook_likes) {
					array[a] = filmcpy(arrayB[j], array[a]);
					j++;
					break;
				}
				else {
					array[a] = filmcpy(arrayA[i], array[a]);
					i++;
					break;
				}
			}
			case(9): {//gross
				if (arrayA[i]->gross > arrayB[j]->gross) {
					array[a] = filmcpy(arrayB[j], array[a]);
					j++;
					break;
				}
				else {
					array[a] = filmcpy(arrayA[i], array[a]);
					i++;
					break;
				}
			}
			case(13): {//num_voted_users
				if (arrayA[i]->num_voted_users > arrayB[j]->num_voted_users) {
					array[a] = filmcpy(arrayB[j], array[a]);
					j++;
					break;
				}
				else {
					array[a] = filmcpy(arrayA[i], array[a]);
					i++;
					break;
				}
			}
			case(14): {//cast_total_facebook_likes
				if (arrayA[i]->cast_total_facebook_likes > arrayB[j]->cast_total_facebook_likes) {
					array[a] = filmcpy(arrayB[j], array[a]);
					j++;
					break;
				}
				else {
					array[a] = filmcpy(arrayA[i], array[a]);
					i++;
					break;
				}
			}
			case(16): {//facenumber_in_poster
				if (arrayA[i]->facenumber_in_poster > arrayB[j]->facenumber_in_poster) {
					array[a] = filmcpy(arrayB[j], array[a]);
					j++;
					break;
				}
				else {
					array[a] = filmcpy(arrayA[i], array[a]);
					i++;
					break;
				}
			}
			case(19): {//num_user_for_reviews
				if (arrayA[i]->num_user_for_reviews > arrayB[j]->num_user_for_reviews) {
					array[a] = filmcpy(arrayB[j], array[a]);
					j++;
					break;
				}
				else {
					array[a] = filmcpy(arrayA[i], array[a]);
					i++;
					break;
				}
			}
			case(23): {//budget
				if (arrayA[i]->budget > arrayB[j]->budget) {
					array[a] = filmcpy(arrayB[j], array[a]);
					j++;
					break;
				}
				else {
					array[a] = filmcpy(arrayA[i], array[a]);
					i++;
					break;
				}
			}
			case(24): {//title_year
				if (arrayA[i]->title_year > arrayB[j]->title_year) {
					array[a] = filmcpy(arrayB[j], array[a]);
					j++;
					break;
				}
				else {
					array[a] = filmcpy(arrayA[i], array[a]);
					i++;
					break;
				}
			}
			case(25): {//actor_2_facebook_likes
				if (arrayA[i]->actor_2_facebook_likes > arrayB[j]->actor_2_facebook_likes) {
					array[a] = filmcpy(arrayB[j], array[a]);
					j++;
					break;
				}
				else {
					array[a] = filmcpy(arrayA[i], array[a]);
					i++;
					break;
				}
			}
			case(26): {//imdb_score
				if (arrayA[i]->imdb_score > arrayB[j]->imdb_score) {
					array[a] = filmcpy(arrayB[j], array[a]);
					j++;
					break;
				}
				else {
					array[a] = filmcpy(arrayA[i], array[a]);
					i++;
					break;
				}
			}
			case(27): {//aspect_ratio
				if (arrayA[i]->aspect_ratio > arrayB[j]->aspect_ratio) {
					array[a] = filmcpy(arrayB[j], array[a]);
					j++;
					break;
				}
				else {
					array[a] = filmcpy(arrayA[i], array[a]);
					i++;
					break;
				}
			}
			case(28): {//movie_facebook_likes
				if (arrayA[i]->movie_facebook_likes > arrayB[j]->movie_facebook_likes) {
					array[a] = filmcpy(arrayB[j], array[a]);
					j++;
					break;
				}
				else {
					array[a] = filmcpy(arrayA[i], array[a]);
					i++;
					break;
				}
			}
			}
		}
		a++;
	}//end of while loop
	if (i == mid) {//arrayA caught up to end
		while (j<k) {
			array[a] = filmcpy(arrayB[j], array[a]);
			j++; a++;
		}
	}
	else if (j == k) {
		while (i<mid) {
			array[a] = filmcpy(arrayA[i], array[a]);
			i++; a++;
		}
	}

	free_strings(arrayA, mid);
	free_strings(arrayB, k);
	free(arrayA);
	free(arrayB);
	
	return final;
	
}
