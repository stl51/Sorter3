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
pthread_mutex_t countlock=PTHREAD_MUTEX_INITIALIZER;

int main(int argc, char **argv){
	//SERVE'S UP BIG KAHUNA!
	
	int server_sock;
	int client_sock;
	
	struct sockaddr_in address;
	
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
	
	//create thread pool if desired
	
	
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
		
		if (num_of_thread < MAX_NUM_THREAD)
		{
		
		//get a tid...somehow
		// replace socket of a tid with the client socket
		//	tid_pool[i].socketfd = client_sock;
		
		//use tid to create a thread which calls the helper method
			pthread_create(&tid_pool[i].tid, NULL, service, (void *)i);
			
		//keep track of number of threads	
			pthread_mutex_lock(&countlock);
			num_of_thread++;
			pthread_mutex_unlock(&counttlock);
			
		//allow thread to detach so join isn't required
		//	pthread_detach(tid_pool[i].tid);
		}	
		
		
	}
	
	close(server_sock);
	return 0;
}
