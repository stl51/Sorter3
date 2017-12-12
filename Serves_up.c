#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>
#include "Sorter_server.h"

#define PORT 26925
int status = 1; // for server running status
int num_of_thread = 0; // currently created num of threads
int array_size=128;
pthread_mutex_t countlock=PTHREAD_MUTEX_INITIALIZER;
film** master;
int master_size;

typedef struct tid_socket{
	pthread_t tid;
	int socketfd;
	
}tid_socket;

tid_socket* tid_pool;
	
void init_tid_pool()
{
	tid_pool=(tid_socket*)malloc(sizeof(tid_socket)*array_size);
	for(int i = 0; i < array_size; i++)
	{
		tid_pool[i].socketfd = -1;
	}
	
	pthread_mutex_lock(&countlock);
	num_of_thread++;
	pthread_mutex_unlock(&countlock);
}


/* return the index of available tid in pool */
int get_tid()
{
	if(num_of_thread==array_size){
			array_size = array_size * 2;
			tids = (tid_socket*)realloc(tids, sizeof(tid_socket)*array_size);
		}
		
	pthread_mutex_lock(&countlock);
		num_of_thread++;
	pthread_mutex_unlock(&countlock);
	
	return num_of_thread;
	
	//return -1;
}

void * service(void *args)
{
	// this is the socket for our server 
	// to talk to client
	int index = (int)args;//gunna have to fix this
	int client_socket = tid_pool[index].socketfd;
	// define two buffers, receive and send
	char send_buf*;
	char recv_buf*;
	recv_buf=(char*)malloc(sizeof(char)*1024);
	/* STEP 5: receive data */
	// use read system call to read data 
	//read(client_socket, recv_buf, 256);
	
	while((n=read(client_socket,recv_buf,sizeof(recv_buf)-1))>0){//when this exits we've read the whole thing
		recv_buf[n]=0;
		if(){	//check if EOF?
			
		}
		
		if(){	//check if sort request or dump request
			//if sort
			//shift buffer to collect input file for sorting the array
			
			//else if dump
			//edit send_buf
			write(client_socket, send_buf, sizeof(send_buf)-1);
		}
	}

	//if sort
	film_arg* ret = process_buff(recv_buf, sortby);
	master_size += ret->amount;
	master = merge_sorted(master, ret->film_list, master_size-(ret->amount),ret->amount, sortby);

	//if dump
	int b;
	//make sure send_buf is big enough, using master_size somehow
	for (b = 0; b<master_size; b++) {
		sprintf(send_buf, "%s,%s,%d,%d,%d,%d,%s,%d,%d,%s,%s,%s,%d,%d,%s,%d,%s,%s,%d,%s,%s,%s,%d,%d,%d,%f,%f,%d\n", master[b]->color, master[b]->director_name, master[b]->num_critic_for_reviews, master[b]->duration, master[b]->director_facebook_likes, master[b]->actor_3_facebook_likes, master[b]->actor_2_name, master[b]->actor_1_facebook_likes, master[b]->gross, master[b]->genres, master[b]->actor_1_name, master[b]->movie_title, master[b]->num_voted_users, master[b]->cast_total_facebook_likes, master[b]->actor_3_name, master[b]->facenumber_in_poster, master[b]->plot_keywords, master[b]->movie_imdb_link, master[b]->num_user_for_reviews, master[b]->language, master[b]->country, master[b]->content_rating, master[b]->budget, master[b]->title_year, master[b]->actor_2_facebook_likes, master[b]->imdb_score, master[b]->aspect_ratio, master[b]->movie_facebook_likes);
	}
	
//	write(client_socket, send_buf, sizeof(send_buf)-1);
	close(client_socket);
//		release_tid(index);
//	num_of_thread--;
}




int main(int argc, char **argv){
	
	
	int server_sock;
	int client_sock;
	
	//creation of the master array below
	master = (film**)malloc(sizeof(film*));
	master_size = 0;


	struct sockaddr_in address;
	//pthread_t * tids = (pthread_t*)malloc(sizeof(pthread_t) * 1);
	
	//setup of server socket
	if ((server_sock = socket(AF_INET, SOCK_STREAM, 0)) <= 0)
	{
		// print error message with perror()
		perror("ERROR:Issue during setup of server socket\n");
		// exit your server
		exit(EXIT_FAILURE);
	}
	
	address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(PORT);
	
	
	//bind to address
	if (bind(server_sock, (struct sockaddr*)&address, sizeof(address)) < 0)
	{
		// perror() report error message
		perror("ERROR:Issue during the binding to an address\n");
		// close socket
		close(server_sock);
		// exit your program
		exit(EXIT_FAILURE);
	}
	
	if (listen(server_sock, 0) < 0)
	{
		// perror() report error message
		perror("ERROR:Issue during while performing listen\n");
		// close socket
		close(server_sock);
		// exit your program
		exit(EXIT_FAILURE);
	}
	
	
	init_tid_pool();
	
	while (status)	{
		
		client_sock = accept(server_sock, NULL, NULL);	//potentially change args here
		// check if accept() is successful or not
		if (client_sock < 0)
		{
			// perror() report error message
			perror("ERROR:Issue while accepting client socket\n");
			// close socket
			close(server_sock);
			// exit your program
			exit(EXIT_FAILURE);
		}
		
//		if (num_of_thread < MAX_NUM_THREAD)
//		{
		
		//get a tid...somehow
		
		//keep track of number of threads	
		//	pthread_mutex_lock(&countlock);
		//	num_of_thread++;
		//	pthread_mutex_unlock(&counttlock);
		// replace socket of a tid with the client socket
		//	if (num_of_thread > array_size) {
		//		array_size = array_size * 2;
		//		tids = (pthread_t*)realloc(tids, sizeof(pthread_t)*array_size);
		//	}
			int i = get_tid();
			tid_pool[i].socketfd = client_sock;
			pthread_create(&tid_pool[i].tid, NULL, service, (void *)i);
	//		tid_pool[i].socketfd = client_sock;
	//		tids[spawns - 1].
		
		//use tid to create a thread which calls the helper method
	//	pthread_create(&(tids[spawns - 1]), 0, (void*) run_thru, (void*) arg);
	//		pthread_create(&(tidpool[spawns - 1]) NULL, service, (void *)i);
			

			
		//allow thread to detach so join isn't required
		//	pthread_detach(tid_pool[i].tid);
//		}	
		
		
	}
	
	close(server_sock);
	return 0;
}


film_arg* merge_sorted(film** arrayA, film** arrayB, int mid, int k, int col) {//returns a new sorted array. Please modify so it returns a struct that also contains the size of the array (mid+k)
																			   //array = already created but empty array to place films into, mid = sizeof A, k = sizeof B, col = sortby


	film_arg* final = (film_arg*)malloc(sizeof(film_arg));
	final->amount = mid + k;
	final->film_list = (film**)malloc(sizeof(film*)*(mid + k));
	int z;
	for (z = 0; z < final->amount; z++) {
		(final->film_list)[z] = (film*)malloc(sizeof(film));
	}
	film** array = final->film_list;


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
