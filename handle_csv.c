#include <stdio.h>
#include "Sorter_thread.h"
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>


film_arg * sort_csv(void * arg) {
	printf("%d,", (int)pthread_self());
	FILE* file = ((sortcsv_arg *)arg)->ofile;
	int sortby = ((sortcsv_arg *)arg)->sortby;

	int loop = 0;
	int emp = 0;
	//FILE* file = stdin; this is now the input	/*CHANGE THIS STUFF so that it accepts .csv files in the directory*/
	char line[5000];
	int a_size = 50;
	film** array = (film**)malloc(sizeof(film*)*a_size);
	int arrayloc = 0;
	while (fgets(line, sizeof(line), file) != NULL) {
		loop++;
		//printf("%d\n", loop-1);
		if (loop == 1) {		//skip first line containing categories
			continue;
		//	if(strcmp(line,"color,director_name,num_critic_for_reviews,duration,director_facebook_likes,actor_3_facebook_likes,actor_2_name,actor_1_facebook_likes,gross,genres,actor_1_name,movie_title,num_voted_users,cast_total_facebook_likes,actor_3_name,facenumber_in_poster,plot_keywords,movie_imdb_link,num_user_for_reviews,language,country,content_rating,budget,title_year,actor_2_facebook_likes,imdb_score,aspect_ratio,movie_facebook_likes")!=0){
		//		FILE* idrc = NULL;
		//		return idrc;//error invalid file
		//	}
		}

		film* x = NULL;
		x = (struct film*)malloc(sizeof(film));	//current film record being made


		int assignto = 0;	//determines where value will be stored
		char* val = strtok_fix(line, ",");

		while (val != NULL) {
			assignto++;
			//printf("current val is %s\n",val);
			if (assignto == 1 || assignto == 2 || assignto == 7 || assignto == 10 || assignto == 11 || assignto == 12 || assignto == 15 || assignto == 17 || assignto == 18 || assignto == 20 || assignto == 21 || assignto == 22) {
				while (val[0] == ' ') {
					val++;
				}
			}

			//if(assignto==1){
			//if(strcmp(val,"Color")!=0 && strcmp(val,"color")!=0 && strcmp(val, "Black and White")!=0){
			//x->color="";
			//continue;
			//}
			//}

			if (strcmp(val, "") == 0) {	//empty value
				if (assignto == 1) {
					x->color = "";
				}
				else if (assignto == 2) {
					x->director_name = "";
				}
				else if (assignto == 3) {
					x->num_critic_for_reviews = 0;
				}
				else if (assignto == 4) {
					x->duration = 0;
				}
				else if (assignto == 5) {
					x->director_facebook_likes = 0;
				}
				else if (assignto == 6) {
					x->actor_3_facebook_likes = 0;
				}
				else if (assignto == 7) {
					x->actor_2_name = "";
				}
				else if (assignto == 8) {
					x->actor_1_facebook_likes = 0;
				}
				else if (assignto == 9) {
					x->gross = 0;
				}
				else if (assignto == 10) {
					x->genres = "";
				}
				else if (assignto == 11) {
					x->actor_1_name = "";
				}
				else if (assignto == 12) {
					x->movie_title = "";
				}
				else if (assignto == 13) {
					x->num_voted_users = 0;
				}
				else if (assignto == 14) {
					x->cast_total_facebook_likes = 0;
				}
				else if (assignto == 15) {
					x->actor_3_name = "";
				}
				else if (assignto == 16) {
					x->facenumber_in_poster = 0;
				}
				else if (assignto == 17) {
					x->plot_keywords = "";
				}
				else if (assignto == 18) {
					x->movie_imdb_link = "";
				}
				else if (assignto == 19) {
					x->num_user_for_reviews = 0;
				}
				else if (assignto == 20) {
					x->language = "";
				}
				else if (assignto == 21) {
					x->country = "";
				}
				else if (assignto == 22) {
					x->content_rating = "";
				}
				else if (assignto == 23) {
					x->budget = 0;
				}
				else if (assignto == 24) {
					x->title_year = 0;
				}
				else if (assignto == 25) {
					x->actor_2_facebook_likes = 0;
				}
				else if (assignto == 26) {
					x->imdb_score = 0;
				}
				else if (assignto == 27) {
					x->aspect_ratio = 0;
				}
				else if (assignto == 28) {
					x->movie_facebook_likes = 0;
				}
				//val=strtok(NULL,",");	//move on to next token
				//continue;		//jump to next token
			}
			else if ((assignto == 3) | (assignto == 4) | (assignto == 5) | (assignto == 6) | (assignto == 8) | (assignto == 9) | (assignto == 13) | (assignto == 14) | (assignto == 16) | (assignto == 19) | (assignto == 23) | (assignto == 24) | (assignto == 25) | (assignto == 28)) {	//convert to int
				int numval = atoi(val);
				if (assignto == 3) {
					x->num_critic_for_reviews = numval;
				}
				else if (assignto == 4) {
					x->duration = numval;
				}
				else if (assignto == 5) {
					x->director_facebook_likes = numval;
				}
				else if (assignto == 6) {
					x->actor_3_facebook_likes = numval;
				}
				else if (assignto == 8) {
					x->actor_1_facebook_likes = numval;
				}
				else if (assignto == 9) {
					x->gross = numval;
				}
				else if (assignto == 13) {
					x->num_voted_users = numval;
				}
				else if (assignto == 14) {
					x->cast_total_facebook_likes = numval;
				}
				else if (assignto == 16) {
					x->facenumber_in_poster = numval;
				}
				else if (assignto == 19) {
					x->num_user_for_reviews = numval;
				}
				else if (assignto == 23) {
					x->budget = numval;
				}
				else if (assignto == 24) {
					x->title_year = numval;
				}
				else if (assignto == 25) {
					x->actor_2_facebook_likes = numval;
				}
				else {
					x->movie_facebook_likes = numval;
				}
				//val=strtok(NULL,",");	//move on to next token
				//continue;	//jump to next token

			}
			else if ((assignto == 26) | (assignto == 27)) {		//convert to double
				if (assignto == 26) {
					x->imdb_score = atof(val);
				}
				else {
					x->aspect_ratio = atof(val);
				}
				//val=strtok(NULL,",");	//move on to next token
				//continue;	//jump to next token
			}

			if (val[0] == '"') {	//opening quotation, check for closing quote
				while (val[strlen(val) - 1] != '"') {	//lacks a closing quote
					char* temp = strtok_fix(NULL, ",");
					char* teststr = (char*)malloc(strlen(temp) + 1);
					teststr = strcpy(teststr, temp);
					strcat(val, teststr);	//concatenates next token to current token
				}
			}
			//enter values if token is a string
			if (assignto == 1) {
				x->color = val;
			}
			else if (assignto == 2) {
				x->director_name = val;
			}
			else if (assignto == 7) {
				x->actor_2_name = val;
			}
			else if (assignto == 10) {
				x->genres = val;
			}
			else if (assignto == 11) {
				x->actor_1_name = val;
			}
			else if (assignto == 12) {
				x->movie_title = val;
			}
			else if (assignto == 15) {
				x->actor_3_name = val;
			}
			else if (assignto == 17) {
				x->plot_keywords = val;
			}
			else if (assignto == 18) {
				x->movie_imdb_link = val;
			}
			else if (assignto == 20) {
				x->language = val;
			}
			else if (assignto == 21) {
				x->country = val;
			}
			else if (assignto == 22) {
				x->content_rating = val;
			}

			if (assignto == 28) {		//x is a complete film to add to the array
				if ((loop - 1) == a_size) {
					a_size = a_size * 2;
					array = (film**)realloc(array, sizeof(film*)*a_size);
				}
				if (!strcmp(x->movie_title, "")) {
					if (!strcmp(x->movie_imdb_link, "")) {
						emp = 1;
						break;
					}
				}
				array[arrayloc] = (film*)malloc(sizeof(film));
				array[arrayloc] = filmcpy(x, array[arrayloc]);
				free(x);
				arrayloc++;
				assignto = 0;
			}


			val = strtok_fix(NULL, ",");	//move on to next token


		}

		if (emp) {
			emp = 0;
			break;
		}

	}//done reading file
	array = mergesort(array, arrayloc, sortby);

	

	//make a new string for filename
	//filenamenew = filename with "-sorted-<fieldname>" appended
	//fieldname determined by switching on sortby
/*
	char* sorttype;
	switch (sortby)
	{
	case(1):
		sorttype = "color";
		break;
	case(2):
		sorttype = "director_name";
		break;
	case(3):
		sorttype = "num_critic_for_reviews";
		break;
	case(4):
		sorttype = "duration";
		break;
	case(5):
		sorttype = "director_facebook_likes";
		break;
	case(6):
		sorttype = "actor_3_facebook_likes";
		break;
	case(7):
		sorttype = "actor_2_name";
		break;
	case(8):
		sorttype = "actor_1_facebook_likes";
		break;
	case(9):
		sorttype = "gross";
		break;
	case(10):
		sorttype = "genres";
		break;
	case(11):
		sorttype = "actor_1_name";
		break;
	case(12):
		sorttype = "movie_title";
		break;
	case(13):
		sorttype = "num_voted_users";
		break;
	case(14):
		sorttype = "cast_total_facebook_likes";
		break;
	case(15):
		sorttype = "actor_3_name";
		break;
	case(16):
		sorttype = "facenumber_in_poster";
		break;
	case(17):
		sorttype = "plot_keywords";
		break;
	case(18):
		sorttype = "movie_imdb_link";
		break;
	case(19):
		sorttype = "num_user_for_reviews";
		break;
	case(20):
		sorttype = "language";
		break;
	case(21):
		sorttype = "country";
		break;
	case(22):
		sorttype = "content_rating";
		break;
	case(23):
		sorttype = "budget";
		break;
	case(24):
		sorttype = "title_year";
		break;
	case(25):
		sorttype = "actor_2_facebook_likes";
		break;
	case(26):
		sorttype = "imdb_score";
		break;
	case(27):
		sorttype = "aspect_ratio";
		break;
	case(28):
		sorttype = "movie_facebook_likes";
		break;
	default:
		break;
	}

	char* nfilename = (char*)malloc(sizeof(char) * 100);
	memcpy(nfilename, filename, strlen(filename) - 4);
	nfilename[strlen(filename) - 4] = '\0';
	//nfilename = strcpy(nfilename, filename);
	nfilename = strcat(nfilename, "-sorted-");
	nfilename = strcat(nfilename, sorttype);
	nfilename = strcat(nfilename, ".csv");
	//make a new file and write to that file the sorted array

	chdir(dest_dir);
	FILE* nfile = fopen(nfilename, "w");
	int b;
	for (b = 0; b<arrayloc; b++) {
		fprintf(nfile, "%s,%s,%d,%d,%d,%d,%s,%d,%d,%s,%s,%s,%d,%d,%s,%d,%s,%s,%d,%s,%s,%s,%d,%d,%d,%f,%f,%d\n",array[b]->color,array[b]->director_name,array[b]->num_critic_for_reviews,array[b]->duration,array[b]->director_facebook_likes,array[b]->actor_3_facebook_likes,array[b]->actor_2_name,array[b]->actor_1_facebook_likes,array[b]->gross,array[b]->genres,array[b]->actor_1_name,array[b]->movie_title,array[b]->num_voted_users,array[b]->cast_total_facebook_likes,array[b]->actor_3_name,array[b]->facenumber_in_poster,array[b]->plot_keywords,array[b]->movie_imdb_link,array[b]->num_user_for_reviews,array[b]->language,array[b]->country,array[b]->content_rating,array[b]->budget,array[b]->title_year,array[b]->actor_2_facebook_likes,array[b]->imdb_score,array[b]->aspect_ratio,array[b]->movie_facebook_likes);
	}
	fclose(nfile);
	chdir(curr_dir);
	*/	
	
	film_arg * ret = (film_arg*)malloc(sizeof(film_arg));
    ret->film_list = (film**) malloc (sizeof(film*)*arrayloc);
	int n;
	for (n = 0; n < arrayloc; n++) {
        (ret->film_list)[n] = (film*) malloc (sizeof(film));
		filmcpy(array[n], (ret->film_list)[n]);
	}
	ret->amount = arrayloc;
	ret->threads = 0;
	return ret;
	
}

char* strtok_fix(char* str, char const * delim) {
	static char * src = NULL;
	char*p = 0;
	char*ret = 0;

	if (str != NULL) {
		src = str;
	}

	if (src == NULL) {
		return NULL;
	}

	if ((p = strpbrk(src, delim)) != NULL) {
		*p = 0;
		ret = src;
		src = ++p;
	}
	else if (*src) {
		ret = src;
		src = NULL;
	}

	return ret;
}
