#include <stdio.h>
#include <stdlib.h>
#include "Sorter_thread.h"
#include <string.h>
#include <pthread.h>

film** mergesort(film** array, int size, int col){//pointer to unsorted array, size of array, column to sort by
	if(size == 1){
		return array;
	}
	 int mid = size>>1;//find midpoint
	 //allocate 2 arrays
	 film** arrayA = (film**) malloc(sizeof(film*)*mid);
	 film** arrayB = (film**) malloc(sizeof(film*)*(size-mid));
	 
	 int i=0; int k=0;
	 
	 for(i=0; i<mid; i++){//loop for filling arrayA, mid is size of A
		 //printf("%d\n", i);
		 //if (i==5043){
			 //printf("here!\n");
		 //}
		 arrayA[i] = (film*) malloc(sizeof(film));
		 array[i] = replace_NULL_w_empty(array[i]);
		 arrayA[i] = replace_NULL_w_empty(arrayA[i]);
		 arrayA[i] = filmcpy(array[i], arrayA[i]);
	 }
	 for(k=0; i<size; i++){//loop for filling arrayB, final k is size of B
		 //printf("%d\n", i);
		 //if (i==5043){
			 //printf("here!\n");
		 //}
		 arrayB[k] = (film*) malloc(sizeof(film));
		 array[i] = replace_NULL_w_empty(array[i]);
		 arrayB[k] = replace_NULL_w_empty(arrayB[k]);
		 arrayB[k] = filmcpy(array[i], arrayB[k]);
		 
		 k++;
	 }
	 //IN CASE MEMORY PROBLEMS
	 //free_strings(array, size);
	 //free(array);
	 
	 arrayA = mergesort(arrayA, mid, col);
	 arrayB = mergesort(arrayB, k, col);
	 
	 //array = (film*) malloc(sizeof(film)*size);
	 //for(i=0; i<size; i++){
		 //array[i] = replace_NULL_w_empty(array[i]);
	 //}
	 
	 i=0; int j=0; int a=0;
	 while(i<mid && j<k){
		 //depending on what column we're sorting by, do things
		 if(col == 1 || col == 2 || col == 7 || col == 10 || col == 11 || col == 12 || col == 15 || col == 17 || col == 18 || col == 20 || col == 21 || col == 22){
			 //sort by string, first being NULL
			 switch(col){
				 case(1):{//color
					 if(arrayA[i]->color == NULL){
						 array[a] = filmcpy(arrayA[i],array[a]);
						 i++;
						 break;
					 }else if (arrayB[j]->color == NULL){
						 array[a] = filmcpy(arrayB[j],array[a]);
						 j++;
						 break;
					 }
					 if(strcmp(arrayA[i]->color, arrayB[j]->color) > 0){//arrayA's val is greater
						 array[a] = filmcpy(arrayB[j],array[a]);
						 j++;
						 break;
					 }else{//arrayA's val is less or equal
						 array[a] = filmcpy(arrayA[i],array[a]);
						 i++;
						 break;
					 }
				 }
				 case(2):{//director_name//
					 if(arrayA[i]->director_name == NULL){
						 array[a] = filmcpy(arrayA[i],array[a]);
						 i++;
						 break;
					 }else if (arrayB[j]->director_name == NULL){
						 array[a] = filmcpy(arrayB[j],array[a]);
						 j++;
						 break;
					 }
					 if(strcmp(arrayA[i]->director_name, arrayB[j]->director_name) > 0){//arrayA's val is greater
						 array[a] = filmcpy(arrayB[j],array[a]);
						 j++;
						 break;
					 }else{//arrayA's val is less or equal
						 array[a] = filmcpy(arrayA[i],array[a]);
						 i++;
						 break;
					 }
				 }
				 case(7):{//actor_2_name
					 if(arrayA[i]->actor_2_name == NULL){
						 array[a] = filmcpy(arrayA[i],array[a]);
						 i++;
						 break;
					 }else if (arrayB[j]->actor_2_name == NULL){
						 array[a] = filmcpy(arrayB[j],array[a]);
						 j++;
						 break;
					 }
					 if(strcmp(arrayA[i]->actor_2_name, arrayB[j]->actor_2_name) > 0){//arrayA's val is greater
						 array[a] = filmcpy(arrayB[j],array[a]);
						 j++;
						 break;
					 }else{//arrayA's val is less or equal
						 array[a] = filmcpy(arrayA[i],array[a]);
						 i++;
						 break;
					 }
				 }
				 case(10):{//genres
					 if(arrayA[i]->genres == NULL){
						 array[a] = filmcpy(arrayA[i],array[a]);
						 i++;
						 break;
					 }else if (arrayB[j]->genres == NULL){
						 array[a] = filmcpy(arrayB[j],array[a]);
						 j++;
						 break;
					 }
					 if(strcmp(arrayA[i]->genres, arrayB[j]->genres) > 0){//arrayA's val is greater
						 array[a] = filmcpy(arrayB[j],array[a]);
						 j++;
						 break;
					 }else{//arrayA's val is less or equal
						 array[a] = filmcpy(arrayA[i],array[a]);
						 i++;
						 break;
					 }
				 }
				 case(11):{//actor_1_name
					 if(arrayA[i]->actor_1_name == NULL){
						 array[a] = filmcpy(arrayA[i],array[a]);
						 i++;
						 break;
					 }else if (arrayB[j]->actor_1_name == NULL){
						 array[a] = filmcpy(arrayB[j],array[a]);
						 j++;
						 break;
					 }
					 if(strcmp(arrayA[i]->actor_1_name, arrayB[j]->actor_1_name) > 0){//arrayA's val is greater
						 array[a] = filmcpy(arrayB[j],array[a]);
						 j++;
						 break;
					 }else{//arrayA's val is less or equal
						 array[a] = filmcpy(arrayA[i],array[a]);
						 i++;
						 break;
					 }
				 }
				 case(12):{//movie_title
					 if(arrayA[i]->movie_title == NULL){
						 array[a] = filmcpy(arrayA[i],array[a]);
						 i++;
						 break;
					 }else if (arrayB[j]->movie_title == NULL){
						 array[a] = filmcpy(arrayB[j],array[a]);
						 j++;
						 break;
					 }
					 if(strcmp(arrayA[i]->movie_title, arrayB[j]->movie_title) > 0){//arrayA's val is greater
						 array[a] = filmcpy(arrayB[j],array[a]);
						 j++;
						 break;
					 }else{//arrayA's val is less or equal
						 array[a] = filmcpy(arrayA[i],array[a]);
						 i++;
						 break;
					 }
				 }
				 case(15):{//actor_3_name
					 if(arrayA[i]->actor_3_name == NULL){
						 array[a] = filmcpy(arrayA[i],array[a]);
						 i++;
						 break;
					 }else if (arrayB[j]->actor_3_name == NULL){
						 array[a] = filmcpy(arrayB[j],array[a]);
						 j++;
						 break;
					 }
					 if(strcmp(arrayA[i]->actor_3_name, arrayB[j]->actor_3_name) > 0){//arrayA's val is greater
						 array[a] = filmcpy(arrayB[j],array[a]);
						 j++;
						 break;
					 }else{//arrayA's val is less or equal
						 array[a] = filmcpy(arrayA[i],array[a]);
						 i++;
						 break;
					 }
				 }
				 case(17):{//plot_keywords
					 if(arrayA[i]->plot_keywords == NULL){
						 array[a] = filmcpy(arrayA[i],array[a]);
						 i++;
						 break;
					 }else if (arrayB[j]->plot_keywords == NULL){
						 array[a] = filmcpy(arrayB[j],array[a]);
						 j++;
						 break;
					 }
					 if(strcmp(arrayA[i]->plot_keywords, arrayB[j]->plot_keywords) > 0){//arrayA's val is greater
						 array[a] = filmcpy(arrayB[j],array[a]);
						 j++;
						 break;
					 }else{//arrayA's val is less or equal
						 array[a] = filmcpy(arrayA[i],array[a]);
						 i++;
						 break;
					 }
				 }
				 case(18):{//move_imdb_link
					 if(arrayA[i]->movie_imdb_link == NULL){
						 array[a] = filmcpy(arrayA[i],array[a]);
						 i++;
						 break;
					 }else if (arrayB[j]->movie_imdb_link == NULL){
						 array[a] = filmcpy(arrayB[j],array[a]);
						 j++;
						 break;
					 }
					 if(strcmp(arrayA[i]->movie_imdb_link, arrayB[j]->movie_imdb_link) > 0){//arrayA's val is greater
						 array[a] = filmcpy(arrayB[j],array[a]);
						 j++;
						 break;
					 }else{//arrayA's val is less or equal
						 array[a] = filmcpy(arrayA[i],array[a]);
						 i++;
						 break;
					 }
				 }
				 case(20):{//language
					 if(arrayA[i]->language == NULL){
						 array[a] = filmcpy(arrayA[i],array[a]);
						 i++;
						 break;
					 }else if (arrayB[j]->language == NULL){
						 array[a] = filmcpy(arrayB[j],array[a]);
						 j++;
						 break;
					 }
					 if(strcmp(arrayA[i]->language, arrayB[j]->language) > 0){//arrayA's val is greater
						 array[a] = filmcpy(arrayB[j],array[a]);
						 j++;
						 break;
					 }else{//arrayA's val is less or equal
						 array[a] = filmcpy(arrayA[i],array[a]);
						 i++;
						 break;
					 }
				 }
				 case(21):{//country
					 if(arrayA[i]->country == NULL){
						 array[a] = filmcpy(arrayA[i],array[a]);
						 i++;
						 break;
					 }else if (arrayB[j]->country == NULL){
						 array[a] = filmcpy(arrayB[j],array[a]);
						 j++;
						 break;
					 }
					 if(strcmp(arrayA[i]->country, arrayB[j]->country) > 0){//arrayA's val is greater
						 array[a] = filmcpy(arrayB[j],array[a]);
						 j++;
						 break;
					 }else{//arrayA's val is less or equal
						 array[a] = filmcpy(arrayA[i],array[a]);
						 i++;
						 break;
					 }
				 }
				 case(22):{//content_rating
					 if(arrayA[i]->content_rating == NULL){
						 array[a] = filmcpy(arrayA[i],array[a]);
						 i++;
						 break;
					 }else if (arrayB[j]->content_rating == NULL){
						 array[a] = filmcpy(arrayB[j],array[a]);
						 j++;
						 break;
					 }
					 if(strcmp(arrayA[i]->content_rating, arrayB[j]->content_rating) > 0){//arrayA's val is greater
						 array[a] = filmcpy(arrayB[j],array[a]);
						 j++;
						 break;
					 }else{//arrayA's val is less or equal
						 array[a] = filmcpy(arrayA[i],array[a]);
						 i++;
						 break;
					 }
				 }
			 }
		 }else{
			 switch(col){
				 case(3):{//num_critic_for_reviews
					 if(arrayA[i]->num_critic_for_reviews > arrayB[j]->num_critic_for_reviews){
						 array[a] = filmcpy(arrayB[j],array[a]);
						 j++;
						 break;
					 }else{
						 array[a] = filmcpy(arrayA[i],array[a]);
						 i++;
						 break;
					 }
				 }
				 case(4):{//duration
					 if(arrayA[i]->duration > arrayB[j]->duration){
						 array[a] = filmcpy(arrayB[j],array[a]);
						 j++;
						 break;
					 }else{
						 array[a] = filmcpy(arrayA[i],array[a]);
						 i++;
						 break;
					 }
				 }
				 case(5):{//director_facebook_likes
					 if(arrayA[i]->director_facebook_likes > arrayB[j]->director_facebook_likes){
						 array[a] = filmcpy(arrayB[j],array[a]);
						 j++;
						 break;
					 }else{
						 array[a] = filmcpy(arrayA[i],array[a]);
						 i++;
						 break;
					 }
				 }
				 case(6):{//actor_3_facebook_likes
					 if(arrayA[i]->actor_3_facebook_likes > arrayB[j]->actor_3_facebook_likes){
						 array[a] = filmcpy(arrayB[j],array[a]);
						 j++;
						 break;
					 }else{
						 array[a] = filmcpy(arrayA[i],array[a]);
						 i++;
						 break;
					 }
				 }
				 case(8):{//actor_1_facebook_likes
					 if(arrayA[i]->actor_1_facebook_likes > arrayB[j]->actor_1_facebook_likes){
						 array[a] = filmcpy(arrayB[j],array[a]);
						 j++;
						 break;
					 }else{
						 array[a] = filmcpy(arrayA[i],array[a]);
						 i++;
						 break;
					 }
				 }
				 case(9):{//gross
					 if(arrayA[i]->gross > arrayB[j]->gross){
						 array[a] = filmcpy(arrayB[j],array[a]);
						 j++;
						 break;
					 }else{
						 array[a] = filmcpy(arrayA[i],array[a]);
						 i++;
						 break;
					 }
				 }
				 case(13):{//num_voted_users
					 if(arrayA[i]->num_voted_users > arrayB[j]->num_voted_users){
						 array[a] = filmcpy(arrayB[j],array[a]);
						 j++;
						 break;
					 }else{
						 array[a] = filmcpy(arrayA[i],array[a]);
						 i++;
						 break;
					 }
				 }
				 case(14):{//cast_total_facebook_likes
					 if(arrayA[i]->cast_total_facebook_likes > arrayB[j]->cast_total_facebook_likes){
						 array[a] = filmcpy(arrayB[j],array[a]);
						 j++;
						 break;
					 }else{
						 array[a] = filmcpy(arrayA[i],array[a]);
						 i++;
						 break;
					 }
				 }
				 case(16):{//facenumber_in_poster
					 if(arrayA[i]->facenumber_in_poster > arrayB[j]->facenumber_in_poster){
						 array[a] = filmcpy(arrayB[j],array[a]);
						 j++;
						 break;
					 }else{
						 array[a] = filmcpy(arrayA[i],array[a]);
						 i++;
						 break;
					 }
				 }
				 case(19):{//num_user_for_reviews
					 if(arrayA[i]->num_user_for_reviews > arrayB[j]->num_user_for_reviews){
						 array[a] = filmcpy(arrayB[j],array[a]);
						 j++;
						 break;
					 }else{
						 array[a] = filmcpy(arrayA[i],array[a]);
						 i++;
						 break;
					 }
				 }
				 case(23):{//budget
					 if(arrayA[i]->budget > arrayB[j]->budget){
						 array[a] = filmcpy(arrayB[j],array[a]);
						 j++;
						 break;
					 }else{
						 array[a] = filmcpy(arrayA[i],array[a]);
						 i++;
						 break;
					 }
				 }
				 case(24):{//title_year
					 if(arrayA[i]->title_year > arrayB[j]->title_year){
						 array[a] = filmcpy(arrayB[j],array[a]);
						 j++;
						 break;
					 }else{
						 array[a] = filmcpy(arrayA[i],array[a]);
						 i++;
						 break;
					 }
				 }
				 case(25):{//actor_2_facebook_likes
					 if(arrayA[i]->actor_2_facebook_likes > arrayB[j]->actor_2_facebook_likes){
						 array[a] = filmcpy(arrayB[j],array[a]);
						 j++;
						 break;
					 }else{
						 array[a] = filmcpy(arrayA[i],array[a]);
						 i++;
						 break;
					 }
				 }
				 case(26):{//imdb_score
					 if(arrayA[i]->imdb_score > arrayB[j]->imdb_score){
						 array[a] = filmcpy(arrayB[j],array[a]);
						 j++;
						 break;
					 }else{
						 array[a] = filmcpy(arrayA[i],array[a]);
						 i++;
						 break;
					 }
				 }
				 case(27):{//aspect_ratio
					 if(arrayA[i]->aspect_ratio > arrayB[j]->aspect_ratio){
						 array[a] = filmcpy(arrayB[j],array[a]);
						 j++;
						 break;
					 }else{
						 array[a] = filmcpy(arrayA[i],array[a]);
						 i++;
						 break;
					 }
				 }
				 case(28):{//movie_facebook_likes
					 if(arrayA[i]->movie_facebook_likes > arrayB[j]->movie_facebook_likes){
						 array[a] = filmcpy(arrayB[j],array[a]);
						 j++;
						 break;
					 }else{
						 array[a] = filmcpy(arrayA[i],array[a]);
						 i++;
						 break;
					 }
				 }
			 }
		 }
		 a++;
	 }//end of while loop
	 if(i==mid){//arrayA caught up to end
		 while(j<k){
			 array[a] = filmcpy(arrayB[j],array[a]);
			 j++; a++;
		 }
	 }else if(j==k){
		 while(i<mid){
			 array[a] = filmcpy(arrayA[i],array[a]);
			 i++; a++;
		 }
	 }
	 
	 free_strings(arrayA, mid);
	 free_strings(arrayB, k);
	 free(arrayA);
	 free(arrayB);
	 return array;
}

film* filmcpy(film* filmA, film* filmB){//copy film A to film B
	filmB->color = (char*) malloc(strlen(filmA->color)+1);
	filmB->color = strcpy(filmB->color, filmA->color);//
	filmB->director_name = (char*) malloc(strlen(filmA->director_name)+1);
	filmB->director_name = strcpy(filmB->director_name, filmA->director_name);//
	filmB->num_critic_for_reviews = filmA->num_critic_for_reviews;
	filmB->duration = filmA->duration;
	filmB->director_facebook_likes = filmA->director_facebook_likes;
	filmB->actor_3_facebook_likes = filmA->actor_3_facebook_likes;
	filmB->actor_2_name = (char*) malloc(strlen(filmA->actor_2_name)+1);
	filmB->actor_2_name = strcpy(filmB->actor_2_name, filmA->actor_2_name);//
	filmB->actor_1_facebook_likes = filmA->actor_1_facebook_likes;
	filmB->gross = filmA->gross;
	filmB->genres = (char*) malloc(strlen(filmA->genres)+1);
	filmB->genres = strcpy(filmB->genres, filmA->genres);//
	filmB->actor_1_name = (char*) malloc(strlen(filmA->actor_1_name)+1);
	filmB->actor_1_name = strcpy(filmB->actor_1_name, filmA->actor_1_name);//
	filmB->movie_title = (char*) malloc(strlen(filmA->movie_title)+1);
	filmB->movie_title = strcpy(filmB->movie_title, filmA->movie_title);//
	filmB->num_voted_users = filmA->num_voted_users;
	filmB->cast_total_facebook_likes = filmA->cast_total_facebook_likes;
	filmB->actor_3_name = (char*) malloc(strlen(filmA->actor_3_name)+1);
	filmB->actor_3_name = strcpy(filmB->actor_3_name, filmA->actor_3_name);//
	filmB->facenumber_in_poster = filmA->facenumber_in_poster;
	filmB->plot_keywords = (char*) malloc(strlen(filmA->plot_keywords)+1);
	filmB->plot_keywords = strcpy(filmB->plot_keywords, filmA->plot_keywords);//
	filmB->movie_imdb_link = (char*) malloc(strlen(filmA->movie_imdb_link)+1);
	filmB->movie_imdb_link = strcpy(filmB->movie_imdb_link, filmA->movie_imdb_link);//
	filmB->num_user_for_reviews = filmA->num_user_for_reviews;
	filmB->language = (char*) malloc(strlen(filmA->language)+1);
	filmB->language = strcpy(filmB->language, filmA->language);//
	filmB->country = (char*) malloc(strlen(filmA->country)+1);
	filmB->country = strcpy(filmB->country, filmA->country);//
	filmB->content_rating = (char*) malloc(strlen(filmA->content_rating)+1);
	filmB->content_rating = strcpy(filmB->content_rating, filmA->content_rating);//
	filmB->budget = filmA->budget;
	filmB->title_year = filmA->title_year;
	filmB->actor_2_facebook_likes = filmA->actor_2_facebook_likes;
	filmB->imdb_score = filmA->imdb_score;
	filmB->aspect_ratio = filmA->aspect_ratio;
	filmB->movie_facebook_likes = filmA->movie_facebook_likes;
	 
	return filmB;
}

void free_strings(film** array, int len){
	int i=0;
	for (i=0; i<len; i++){
		free(array[i]->color);
		free(array[i]->director_name);
		free(array[i]->actor_2_name);
		free(array[i]->genres);
		free(array[i]->actor_1_name);
		free(array[i]->movie_title);
		free(array[i]->actor_3_name);
		free(array[i]->plot_keywords);
		free(array[i]->movie_imdb_link);
		free(array[i]->language);
		free(array[i]->country);
		free(array[i]->content_rating);
	}
}

film* replace_NULL_w_empty(film* f){
	if(f->color == NULL){
		f->color = (char*) malloc(1);
		f->color = "";
	}
	if(f->director_name == NULL){
		f->director_name = (char*) malloc(1);
		f->director_name = "";
	}
	if(f->actor_2_name == NULL){
		f->actor_2_name = (char*) malloc(1);
		f->actor_2_name = "";
	}
	if(f->genres == NULL){
		f->genres = (char*) malloc(1);
		f->genres = "";
	}
	if(f->actor_1_name == NULL){
		f->actor_1_name = (char*) malloc(1);
		f->actor_1_name = "";
	}
	if(f->movie_title == NULL){
		f->movie_title = (char*) malloc(1);
		f->movie_title = "";
	}
	if(f->actor_3_name == NULL){
		f->actor_3_name = (char*) malloc(1);
		f->actor_3_name = "";
	}
	if(f->plot_keywords == NULL){
		f->plot_keywords = (char*) malloc(1);
		f->plot_keywords = "";
	}
	if(f->movie_imdb_link == NULL){
		f->movie_imdb_link = (char*) malloc(1);
		f->movie_imdb_link = "";
	}
	if(f->language == NULL){
		f->language = (char*) malloc(1);
		f->language = "";
	}
	if(f->country == NULL){
		f->country = (char*) malloc(1);
		f->country = "";
	}
	if(f->content_rating == NULL){
		f->content_rating = (char*) malloc(1);
		f->content_rating = "";
	}
	return f;
}
