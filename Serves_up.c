#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

#define PORT 26925
int status = 1; // for server running status
int num_of_thread = 0; // currently created num of threads
int array_size=128;
pthread_mutex_t countlock=PTHREAD_MUTEX_INITIALIZER;

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
	int index = (int)args;
	int client_socket = tid_pool[index].socketfd;
	// define two buffers, receive and send
	char send_buf*;
	char recv_buf*;
	recv_buf=(char*)malloc(sizeof(char)*1024);
	/* STEP 5: receive data */
	// use read system call to read data 
	//read(client_socket, recv_buf, 256);
	
	while((n=read(client_socket,recv_buf,sizeof(recv_buf)-1))>0){
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
	
	
//	write(client_socket, send_buf, sizeof(send_buf)-1);
	close(client_socket);
//		release_tid(index);
//	num_of_thread--;
}




int main(int argc, char **argv){
	
	
	int server_sock;
	int client_sock;
	
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
