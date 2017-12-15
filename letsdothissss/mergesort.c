#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"mergesort.h"


int floatcmp(char* str,char*str2){
	
	float f,s;
	
	if(strlen(str)==0){
		return 0;
	}
	
	if(strlen(str2)==0){
		return 1;
	}
	
	f = atof(str);
	
	s= atof(str2);
	
	if(f<=s){
		return 0;
	}
	else{
	return 1;
	}
}


void MergeColor(imdb *list,imdb *leftlist,imdb *rightlist,int leftCount,int rightCount) {
	int indexLeft=0; int indexRight=0; int indexMain=0;
	while(indexLeft<leftCount && indexRight< rightCount) {
		if((strcasecmp(leftlist[indexLeft].color,rightlist[indexRight].color))<=0){
			list[indexMain++] = leftlist[indexLeft++];}
		else {
			list[indexMain++] = rightlist[indexRight++];}
	}
	while(indexLeft < leftCount){
		list[indexMain++] = leftlist[indexLeft++];}
	while(indexRight < rightCount){
		list[indexMain++] = rightlist[indexRight++];}
}

void MergeDirector(imdb *list,imdb *leftlist,imdb *rightlist,int leftCount,int rightCount) {
	int indexLeft=0; int indexRight=0; int indexMain=0;
	while(indexLeft<leftCount && indexRight< rightCount) {
		if((strcasecmp(leftlist[indexLeft].director_name,rightlist[indexRight].director_name))<=0){
			list[indexMain++] = leftlist[indexLeft++];}
		else {
			list[indexMain++] = rightlist[indexRight++];}
	}
	while(indexLeft < leftCount){
		list[indexMain++] = leftlist[indexLeft++];}
	while(indexRight < rightCount){
		list[indexMain++] = rightlist[indexRight++];}
}


void MergeActor2(imdb *list,imdb *leftlist,imdb *rightlist,int leftCount,int rightCount) {
	int indexLeft=0; int indexRight=0; int indexMain=0;
	while(indexLeft<leftCount && indexRight< rightCount) {
		if((strcasecmp(leftlist[indexLeft].actor_2_name,rightlist[indexRight].actor_2_name))<=0){
			list[indexMain++] = leftlist[indexLeft++];}
		else {
			list[indexMain++] = rightlist[indexRight++];}
	}
	while(indexLeft < leftCount){
		list[indexMain++] = leftlist[indexLeft++];}
	while(indexRight < rightCount){
		list[indexMain++] = rightlist[indexRight++];}
}

void MergeGenre(imdb *list,imdb *leftlist,imdb *rightlist,int leftCount,int rightCount) {
	int indexLeft=0; int indexRight=0; int indexMain=0;
	while(indexLeft<leftCount && indexRight< rightCount) {
		if((strcasecmp(leftlist[indexLeft].genres,rightlist[indexRight].genres))<=0){
			list[indexMain++] = leftlist[indexLeft++];}
		else {
			list[indexMain++] = rightlist[indexRight++];}
	}
	while(indexLeft < leftCount){
		list[indexMain++] = leftlist[indexLeft++];}
	while(indexRight < rightCount){
		list[indexMain++] = rightlist[indexRight++];}
}

void MergeActor1(imdb *list,imdb *leftlist,imdb *rightlist,int leftCount,int rightCount) {
	int indexLeft=0; int indexRight=0; int indexMain=0;
	while(indexLeft<leftCount && indexRight< rightCount) {
		if((strcasecmp(leftlist[indexLeft].actor_1_name,rightlist[indexRight].actor_1_name))<=0){
			list[indexMain++] = leftlist[indexLeft++];}
		else {
			list[indexMain++] = rightlist[indexRight++];}
	}
	while(indexLeft < leftCount){
		list[indexMain++] = leftlist[indexLeft++];}
	while(indexRight < rightCount){
		list[indexMain++] = rightlist[indexRight++];}
}

void MergeMovieTitle(imdb *list,imdb *leftlist,imdb *rightlist,int leftCount,int rightCount) {
	int indexLeft=0; int indexRight=0; int indexMain=0;
	while(indexLeft<leftCount && indexRight< rightCount) {
		if((strcasecmp(leftlist[indexLeft].movie_title,rightlist[indexRight].movie_title))<=0){
			list[indexMain++] = leftlist[indexLeft++];}
		else {
			list[indexMain++] = rightlist[indexRight++];}
	}
	while(indexLeft < leftCount){
		list[indexMain++] = leftlist[indexLeft++];}
	while(indexRight < rightCount){
		list[indexMain++] = rightlist[indexRight++];}
}

void MergeActor3(imdb *list,imdb *leftlist,imdb *rightlist,int leftCount,int rightCount) {
	int indexLeft=0; int indexRight=0; int indexMain=0;
	while(indexLeft<leftCount && indexRight< rightCount) {
		if((strcasecmp(leftlist[indexLeft].actor_3_name,rightlist[indexRight].actor_3_name))<=0){
			list[indexMain++] = leftlist[indexLeft++];}
		else {
			list[indexMain++] = rightlist[indexRight++];}
	}
	while(indexLeft < leftCount){
		list[indexMain++] = leftlist[indexLeft++];}
	while(indexRight < rightCount){
		list[indexMain++] = rightlist[indexRight++];}
}

void MergePlot(imdb *list,imdb *leftlist,imdb *rightlist,int leftCount,int rightCount) {
	int indexLeft=0; int indexRight=0; int indexMain=0;
	while(indexLeft<leftCount && indexRight< rightCount) {
		if((strcasecmp(leftlist[indexLeft].plot_keywords,rightlist[indexRight].plot_keywords))<=0){
			list[indexMain++] = leftlist[indexLeft++];}
		else {
			list[indexMain++] = rightlist[indexRight++];}
	}
	while(indexLeft < leftCount){
		list[indexMain++] = leftlist[indexLeft++];}
	while(indexRight < rightCount){
		list[indexMain++] = rightlist[indexRight++];}
}

void MergeLink(imdb *list,imdb *leftlist,imdb *rightlist,int leftCount,int rightCount) {
	int indexLeft=0; int indexRight=0; int indexMain=0;
	while(indexLeft<leftCount && indexRight< rightCount) {
		if((strcasecmp(leftlist[indexLeft].movie_imdb_link,rightlist[indexRight].movie_imdb_link))<=0){
			list[indexMain++] = leftlist[indexLeft++];}
		else {
			list[indexMain++] = rightlist[indexRight++];}
	}
	while(indexLeft < leftCount){
		list[indexMain++] = leftlist[indexLeft++];}
	while(indexRight < rightCount){
		list[indexMain++] = rightlist[indexRight++];}
}

void MergeLang(imdb *list,imdb *leftlist,imdb *rightlist,int leftCount,int rightCount) {
	int indexLeft=0; int indexRight=0; int indexMain=0;
	while(indexLeft<leftCount && indexRight< rightCount) {
		if((strcasecmp(leftlist[indexLeft].language,rightlist[indexRight].language))<=0){
			list[indexMain++] = leftlist[indexLeft++];}
		else {
			list[indexMain++] = rightlist[indexRight++];}
	}
	while(indexLeft < leftCount){
		list[indexMain++] = leftlist[indexLeft++];}
	while(indexRight < rightCount){
		list[indexMain++] = rightlist[indexRight++];}
}

void MergeCountry(imdb *list,imdb *leftlist,imdb *rightlist,int leftCount,int rightCount) {
	int indexLeft=0; int indexRight=0; int indexMain=0;
	while(indexLeft<leftCount && indexRight< rightCount) {
		if((strcasecmp(leftlist[indexLeft].country,rightlist[indexRight].country))<=0){
			list[indexMain++] = leftlist[indexLeft++];}
		else {
			list[indexMain++] = rightlist[indexRight++];}
	}
	while(indexLeft < leftCount){
		list[indexMain++] = leftlist[indexLeft++];}
	while(indexRight < rightCount){
		list[indexMain++] = rightlist[indexRight++];}
}

void MergeRating(imdb *list,imdb *leftlist,imdb *rightlist,int leftCount,int rightCount) {
	int indexLeft=0; int indexRight=0; int indexMain=0;
	while(indexLeft<leftCount && indexRight< rightCount) {
		if((strcasecmp(leftlist[indexLeft].content_rating,rightlist[indexRight].content_rating))<=0){
			list[indexMain++] = leftlist[indexLeft++];}
		else {
			list[indexMain++] = rightlist[indexRight++];}
	}
	while(indexLeft < leftCount){
		list[indexMain++] = leftlist[indexLeft++];}
	while(indexRight < rightCount){
		list[indexMain++] = rightlist[indexRight++];}
}

void MergeNumCritic(imdb *list,imdb *leftlist,imdb *rightlist,int leftCount,int rightCount) {
	int indexLeft=0; int indexRight=0; int indexMain=0;
	while(indexLeft<leftCount && indexRight< rightCount) {
		if((floatcmp(leftlist[indexLeft].num_critic_for_reviews,rightlist[indexRight].num_critic_for_reviews))==0){
			list[indexMain++] = leftlist[indexLeft++];}
		else {
			list[indexMain++] = rightlist[indexRight++];}
	}
	while(indexLeft < leftCount){
		list[indexMain++] = leftlist[indexLeft++];}
	while(indexRight < rightCount){
		list[indexMain++] = rightlist[indexRight++];}
}

void MergeDur(imdb *list,imdb *leftlist,imdb *rightlist,int leftCount,int rightCount) {
	int indexLeft=0; int indexRight=0; int indexMain=0;
	while(indexLeft<leftCount && indexRight< rightCount) {
		if((floatcmp(leftlist[indexLeft].duration,rightlist[indexRight].duration))==0){
			list[indexMain++] = leftlist[indexLeft++];}
		else {
			list[indexMain++] = rightlist[indexRight++];}
	}
	while(indexLeft < leftCount){
		list[indexMain++] = leftlist[indexLeft++];}
	while(indexRight < rightCount){
		list[indexMain++] = rightlist[indexRight++];}
}

void MergeDirLike(imdb *list,imdb *leftlist,imdb *rightlist,int leftCount,int rightCount) {
	int indexLeft=0; int indexRight=0; int indexMain=0;
	while(indexLeft<leftCount && indexRight< rightCount) {
		if((floatcmp(leftlist[indexLeft].director_facebook_likes,rightlist[indexRight].director_facebook_likes))==0){
			list[indexMain++] = leftlist[indexLeft++];}
		else {
			list[indexMain++] = rightlist[indexRight++];}
	}
	while(indexLeft < leftCount){
		list[indexMain++] = leftlist[indexLeft++];}
	while(indexRight < rightCount){
		list[indexMain++] = rightlist[indexRight++];}
}

void MergeActor3Like(imdb *list,imdb *leftlist,imdb *rightlist,int leftCount,int rightCount) {
	int indexLeft=0; int indexRight=0; int indexMain=0;
	while(indexLeft<leftCount && indexRight< rightCount) {
		if((floatcmp(leftlist[indexLeft].actor_3_facebook_likes,rightlist[indexRight].actor_3_facebook_likes))==0){
			list[indexMain++] = leftlist[indexLeft++];}
		else {
			list[indexMain++] = rightlist[indexRight++];}
	}
	while(indexLeft < leftCount){
		list[indexMain++] = leftlist[indexLeft++];}
	while(indexRight < rightCount){
		list[indexMain++] = rightlist[indexRight++];}
}

void MergeActor2Like(imdb *list,imdb *leftlist,imdb *rightlist,int leftCount,int rightCount) {
	int indexLeft=0; int indexRight=0; int indexMain=0;
	while(indexLeft<leftCount && indexRight< rightCount) {
		if((floatcmp(leftlist[indexLeft].actor_2_facebook_likes,rightlist[indexRight].actor_2_facebook_likes))==0){
			list[indexMain++] = leftlist[indexLeft++];}
		else {
			list[indexMain++] = rightlist[indexRight++];}
	}
	while(indexLeft < leftCount){
		list[indexMain++] = leftlist[indexLeft++];}
	while(indexRight < rightCount){
		list[indexMain++] = rightlist[indexRight++];}
}

void MergeActor1Like(imdb *list,imdb *leftlist,imdb *rightlist,int leftCount,int rightCount) {
	int indexLeft=0; int indexRight=0; int indexMain=0;
	while(indexLeft<leftCount && indexRight< rightCount) {
		if((floatcmp(leftlist[indexLeft].actor_1_facebook_likes,rightlist[indexRight].actor_1_facebook_likes))==0){
			list[indexMain++] = leftlist[indexLeft++];}
		else {
			list[indexMain++] = rightlist[indexRight++];}
	}
	while(indexLeft < leftCount){
		list[indexMain++] = leftlist[indexLeft++];}
	while(indexRight < rightCount){
		list[indexMain++] = rightlist[indexRight++];}
}

void MergeGross(imdb *list,imdb *leftlist,imdb *rightlist,int leftCount,int rightCount) {
	int indexLeft=0; int indexRight=0; int indexMain=0;
	while(indexLeft<leftCount && indexRight< rightCount) {
		if((floatcmp(leftlist[indexLeft].gross,rightlist[indexRight].gross))==0){
			list[indexMain++] = leftlist[indexLeft++];}
		else {
			list[indexMain++] = rightlist[indexRight++];}
	}
	while(indexLeft < leftCount){
		list[indexMain++] = leftlist[indexLeft++];}
	while(indexRight < rightCount){
		list[indexMain++] = rightlist[indexRight++];}
}

void MergeVote(imdb *list,imdb *leftlist,imdb *rightlist,int leftCount,int rightCount) {
	int indexLeft=0; int indexRight=0; int indexMain=0;
	while(indexLeft<leftCount && indexRight< rightCount) {
		if((floatcmp(leftlist[indexLeft].num_voted_users,rightlist[indexRight].num_voted_users))==0){
			list[indexMain++] = leftlist[indexLeft++];}
		else {
			list[indexMain++] = rightlist[indexRight++];}
	}
	while(indexLeft < leftCount){
		list[indexMain++] = leftlist[indexLeft++];}
	while(indexRight < rightCount){
		list[indexMain++] = rightlist[indexRight++];}
}

void MergeCastLike(imdb *list,imdb *leftlist,imdb *rightlist,int leftCount,int rightCount) {
	int indexLeft=0; int indexRight=0; int indexMain=0;
	while(indexLeft<leftCount && indexRight< rightCount) {
		if((floatcmp(leftlist[indexLeft].cast_total_facebook_likes,rightlist[indexRight].cast_total_facebook_likes))==0){
			list[indexMain++] = leftlist[indexLeft++];}
		else {
			list[indexMain++] = rightlist[indexRight++];}
	}
	while(indexLeft < leftCount){
		list[indexMain++] = leftlist[indexLeft++];}
	while(indexRight < rightCount){
		list[indexMain++] = rightlist[indexRight++];}
}

void MergePoster(imdb *list,imdb *leftlist,imdb *rightlist,int leftCount,int rightCount) {
	int indexLeft=0; int indexRight=0; int indexMain=0;
	while(indexLeft<leftCount && indexRight< rightCount) {
		if((floatcmp(leftlist[indexLeft].facenumber_in_poster,rightlist[indexRight].facenumber_in_poster))==0){
			list[indexMain++] = leftlist[indexLeft++];}
		else {
			list[indexMain++] = rightlist[indexRight++];}
	}
	while(indexLeft < leftCount){
		list[indexMain++] = leftlist[indexLeft++];}
	while(indexRight < rightCount){
		list[indexMain++] = rightlist[indexRight++];}
}

void MergeReview(imdb *list,imdb *leftlist,imdb *rightlist,int leftCount,int rightCount) {
	int indexLeft=0; int indexRight=0; int indexMain=0;
	while(indexLeft<leftCount && indexRight< rightCount) {
		if((floatcmp(leftlist[indexLeft].num_user_for_reviews,rightlist[indexRight].num_user_for_reviews))==0){
			list[indexMain++] = leftlist[indexLeft++];}
		else {
			list[indexMain++] = rightlist[indexRight++];}
	}
	while(indexLeft < leftCount){
		list[indexMain++] = leftlist[indexLeft++];}
	while(indexRight < rightCount){
		list[indexMain++] = rightlist[indexRight++];}
}

void MergeBudget(imdb *list,imdb *leftlist,imdb *rightlist,int leftCount,int rightCount) {
	int indexLeft=0; int indexRight=0; int indexMain=0;
	while(indexLeft<leftCount && indexRight< rightCount) {
		if((floatcmp(leftlist[indexLeft].budget,rightlist[indexRight].budget))==0){
			list[indexMain++] = leftlist[indexLeft++];}
		else {
			list[indexMain++] = rightlist[indexRight++];}
	}
	while(indexLeft < leftCount){
		list[indexMain++] = leftlist[indexLeft++];}
	while(indexRight < rightCount){
		list[indexMain++] = rightlist[indexRight++];}
}

void MergeYear(imdb *list,imdb *leftlist,imdb *rightlist,int leftCount,int rightCount) {
	int indexLeft=0; int indexRight=0; int indexMain=0;
	while(indexLeft<leftCount && indexRight< rightCount) {
		if((floatcmp(leftlist[indexLeft].title_year,rightlist[indexRight].title_year))==0){
			list[indexMain++] = leftlist[indexLeft++];}
		else {
			list[indexMain++] = rightlist[indexRight++];}
	}
	while(indexLeft < leftCount){
		list[indexMain++] = leftlist[indexLeft++];}
	while(indexRight < rightCount){
		list[indexMain++] = rightlist[indexRight++];}
}

void MergeMovieLike(imdb *list,imdb *leftlist,imdb *rightlist,int leftCount,int rightCount) {
	int indexLeft=0; int indexRight=0; int indexMain=0;
	while(indexLeft<leftCount && indexRight< rightCount) {
		if((floatcmp(leftlist[indexLeft].movie_facebook_likes,rightlist[indexRight].movie_facebook_likes))==0){
			list[indexMain++] = leftlist[indexLeft++];}
		else {
			list[indexMain++] = rightlist[indexRight++];}
	}
	while(indexLeft < leftCount){
		list[indexMain++] = leftlist[indexLeft++];}
	while(indexRight < rightCount){
		list[indexMain++] = rightlist[indexRight++];}
}

void MergeScore(imdb *list,imdb *leftlist,imdb *rightlist,int leftCount,int rightCount) {
	int indexLeft=0; int indexRight=0; int indexMain=0;
	while(indexLeft<leftCount && indexRight< rightCount) {
		if((floatcmp(leftlist[indexLeft].imdb_score,rightlist[indexRight].imdb_score))==0){
			list[indexMain++] = leftlist[indexLeft++];}
		else {
			list[indexMain++] = rightlist[indexRight++];}
	}
	while(indexLeft < leftCount){
		list[indexMain++] = leftlist[indexLeft++];}
	while(indexRight < rightCount){
		list[indexMain++] = rightlist[indexRight++];}
}

void MergeAspect(imdb *list,imdb *leftlist,imdb *rightlist,int leftCount,int rightCount) {
	int indexLeft=0; int indexRight=0; int indexMain=0;
	while(indexLeft<leftCount && indexRight< rightCount) {
		if((floatcmp(leftlist[indexLeft].aspect_ratio,rightlist[indexRight].aspect_ratio))==0){
			list[indexMain++] = leftlist[indexLeft++];}
		else {
			list[indexMain++] = rightlist[indexRight++];}
	}
	while(indexLeft < leftCount){
		list[indexMain++] = leftlist[indexLeft++];}
	while(indexRight < rightCount){
		list[indexMain++] = rightlist[indexRight++];}
}


void MergeSortColor(imdb *list,int count) {
	int mid,i;
	imdb *leftlist, *rightlist;
	if(count < 2) return; 
	mid = count/2;  
	leftlist = (imdb*)malloc(mid*sizeof(imdb)); 
	rightlist = (imdb*)malloc((count- mid)*sizeof(imdb)); 
	for(i = 0;i<mid;i++){
		leftlist[i] = list[i]; 
	}
	for(i = mid;i<count;i++){
		rightlist[i-mid] = list[i];
	}
	MergeSortColor(leftlist,mid);  
	MergeSortColor(rightlist,count-mid);  
	MergeColor(list,leftlist,rightlist,mid,count-mid);  
        free(leftlist);
        free(rightlist);
}

void MergeSortDirector(imdb *list,int count) {
	int mid,i;
	imdb *leftlist, *rightlist;
	if(count < 2) return; 
	mid = count/2;  
	leftlist = (imdb*)malloc(mid*sizeof(imdb)); 
	rightlist = (imdb*)malloc((count- mid)*sizeof(imdb)); 
	for(i = 0;i<mid;i++){
		leftlist[i] = list[i]; 
	}
	for(i = mid;i<count;i++){
		rightlist[i-mid] = list[i];
	}
	MergeSortDirector(leftlist,mid);  
	MergeSortDirector(rightlist,count-mid);  
	MergeDirector(list,leftlist,rightlist,mid,count-mid);  
        free(leftlist);
        free(rightlist);
}
void MergeSortActor1(imdb *list,int count) {
	int mid,i;
	imdb *leftlist, *rightlist;
	if(count < 2) return; 
	mid = count/2;  
	leftlist = (imdb*)malloc(mid*sizeof(imdb)); 
	rightlist = (imdb*)malloc((count- mid)*sizeof(imdb)); 
	for(i = 0;i<mid;i++){
		leftlist[i] = list[i]; 
	}
	for(i = mid;i<count;i++){
		rightlist[i-mid] = list[i];
	}
	MergeSortActor1(leftlist,mid);  
	MergeSortActor1(rightlist,count-mid);  
	MergeActor1(list,leftlist,rightlist,mid,count-mid);  
        free(leftlist);
        free(rightlist);
}
void MergeSortActor2(imdb *list,int count) {
	int mid,i;
	imdb *leftlist, *rightlist;
	if(count < 2) return; 
	mid = count/2;  
	leftlist = (imdb*)malloc(mid*sizeof(imdb)); 
	rightlist = (imdb*)malloc((count- mid)*sizeof(imdb)); 
	for(i = 0;i<mid;i++){
		leftlist[i] = list[i]; 
	}
	for(i = mid;i<count;i++){
		rightlist[i-mid] = list[i];
	}
	MergeSortActor2(leftlist,mid);  
	MergeSortActor2(rightlist,count-mid);  
	MergeActor2(list,leftlist,rightlist,mid,count-mid);  
        free(leftlist);
        free(rightlist);
}
void MergeSortActor3(imdb *list,int count) {
	int mid,i;
	imdb *leftlist, *rightlist;
	if(count < 2) return; 
	mid = count/2;  
	leftlist = (imdb*)malloc(mid*sizeof(imdb)); 
	rightlist = (imdb*)malloc((count- mid)*sizeof(imdb)); 
	for(i = 0;i<mid;i++){
		leftlist[i] = list[i]; 
	}
	for(i = mid;i<count;i++){
		rightlist[i-mid] = list[i];
	}
	MergeSortActor3(leftlist,mid);  
	MergeSortActor3(rightlist,count-mid);  
	MergeActor3(list,leftlist,rightlist,mid,count-mid); 
        free(leftlist);
        free(rightlist);
}
void MergeSortGenre(imdb *list,int count) {
	int mid,i;
	imdb *leftlist, *rightlist;
	if(count < 2) return; 
	mid = count/2;  
	leftlist = (imdb*)malloc(mid*sizeof(imdb)); 
	rightlist = (imdb*)malloc((count- mid)*sizeof(imdb)); 
	for(i = 0;i<mid;i++){
		leftlist[i] = list[i]; 
	}
	for(i = mid;i<count;i++){
		rightlist[i-mid] = list[i];
	}
	MergeSortGenre(leftlist,mid);  
	MergeSortGenre(rightlist,count-mid); 
	MergeGenre(list,leftlist,rightlist,mid,count-mid);  
        free(leftlist);
        free(rightlist);
}
void MergeSortMovieTitle(imdb *list,int count) {
	int mid,i;
	imdb *leftlist, *rightlist;
	if(count < 2) return; 
	mid = count/2;  
	leftlist = (imdb*)malloc(mid*sizeof(imdb)); 
	rightlist = (imdb*)malloc((count- mid)*sizeof(imdb)); 
	for(i = 0;i<mid;i++){
		leftlist[i] = list[i]; 
	}
	for(i = mid;i<count;i++){
		rightlist[i-mid] = list[i];
	}
	MergeSortMovieTitle(leftlist,mid);  
	MergeSortMovieTitle(rightlist,count-mid);  
	MergeMovieTitle(list,leftlist,rightlist,mid,count-mid);  
        free(leftlist);
        free(rightlist);
}
void MergeSortPlot(imdb *list,int count) {
	int mid,i;
	imdb *leftlist, *rightlist;
	if(count < 2) return;
	mid = count/2;  
	leftlist = (imdb*)malloc(mid*sizeof(imdb)); 
	rightlist = (imdb*)malloc((count- mid)*sizeof(imdb)); 
	for(i = 0;i<mid;i++){
		leftlist[i] = list[i]; 
	}
	for(i = mid;i<count;i++){
		rightlist[i-mid] = list[i];
	}
	MergeSortPlot(leftlist,mid);  
	MergeSortPlot(rightlist,count-mid);  
	MergePlot(list,leftlist,rightlist,mid,count-mid);  
        free(leftlist);
        free(rightlist);
}
void MergeSortLink(imdb *list,int count) {
	int mid,i;
	imdb *leftlist, *rightlist;
	if(count < 2) return; 
	mid = count/2;  
	leftlist = (imdb*)malloc(mid*sizeof(imdb)); 
	rightlist = (imdb*)malloc((count- mid)*sizeof(imdb)); 
	for(i = 0;i<mid;i++){
		leftlist[i] = list[i]; 
	}
	for(i = mid;i<count;i++){
		rightlist[i-mid] = list[i];
	}
	MergeSortLink(leftlist,mid);  
	MergeSortLink(rightlist,count-mid);  
	MergeLink(list,leftlist,rightlist,mid,count-mid);  
        free(leftlist);
        free(rightlist);
}
void MergeSortLang(imdb *list,int count) {
	int mid,i;
	imdb *leftlist, *rightlist;
	if(count < 2) return;
	mid = count/2;  
	leftlist = (imdb*)malloc(mid*sizeof(imdb)); 
	rightlist = (imdb*)malloc((count- mid)*sizeof(imdb)); 
	for(i = 0;i<mid;i++){
		leftlist[i] = list[i]; 
	}
	for(i = mid;i<count;i++){
		rightlist[i-mid] = list[i];
	}
	MergeSortLang(leftlist,mid);  
	MergeSortLang(rightlist,count-mid);  
	MergeLang(list,leftlist,rightlist,mid,count-mid);  
       free(leftlist);
       free(rightlist);
}
void MergeSortCountry(imdb *list,int count) {
	int mid,i;
	imdb *leftlist, *rightlist;
	if(count < 2) return; 
	mid = count/2;  
	leftlist = (imdb*)malloc(mid*sizeof(imdb)); 
	rightlist = (imdb*)malloc((count- mid)*sizeof(imdb)); 
	for(i = 0;i<mid;i++){
		leftlist[i] = list[i]; 
	}
	for(i = mid;i<count;i++){
		rightlist[i-mid] = list[i];
	}
	MergeSortCountry(leftlist,mid);  
	MergeSortCountry(rightlist,count-mid);  
	MergeCountry(list,leftlist,rightlist,mid,count-mid);  
        free(leftlist);
        free(rightlist);
}
void MergeSortRating(imdb *list,int count) {
	int mid,i;
	imdb *leftlist, *rightlist;
	if(count < 2) return; 
	mid = count/2;  
	leftlist = (imdb*)malloc(mid*sizeof(imdb)); 
	rightlist = (imdb*)malloc((count- mid)*sizeof(imdb)); 
	for(i = 0;i<mid;i++){
		leftlist[i] = list[i]; 
	}
	for(i = mid;i<count;i++){
		rightlist[i-mid] = list[i];
	}
	MergeSortRating(leftlist,mid);  
	MergeSortRating(rightlist,count-mid);  
	MergeRating(list,leftlist,rightlist,mid,count-mid);  
        free(leftlist);
        free(rightlist);
}
void MergeSortNumCritic(imdb *list,int count) {
	int mid,i;
	imdb *leftlist, *rightlist;
	if(count < 2) return; 
	mid = count/2;  
	leftlist = (imdb*)malloc(mid*sizeof(imdb)); 
	rightlist = (imdb*)malloc((count- mid)*sizeof(imdb)); 
	for(i = 0;i<mid;i++){
		leftlist[i] = list[i]; 
	}
	for(i = mid;i<count;i++){
		rightlist[i-mid] = list[i];
	}
	MergeSortNumCritic(leftlist,mid);  
	MergeSortNumCritic(rightlist,count-mid); 
	MergeNumCritic(list,leftlist,rightlist,mid,count-mid);
        free(leftlist);
        free(rightlist);
}
void MergeSortDur(imdb *list,int count) {
	int mid,i;
	imdb *leftlist, *rightlist;
	if(count < 2) return;
	mid = count/2; 
	leftlist = (imdb*)malloc(mid*sizeof(imdb)); 
	rightlist = (imdb*)malloc((count- mid)*sizeof(imdb)); 
	for(i = 0;i<mid;i++){
		leftlist[i] = list[i]; 
	}
	for(i = mid;i<count;i++){
		rightlist[i-mid] = list[i];
	}
	MergeSortDur(leftlist,mid); 
	MergeSortDur(rightlist,count-mid);
	MergeDur(list,leftlist,rightlist,mid,count-mid);
        free(leftlist);
        free(rightlist);
}
void MergeSortDirLike(imdb *list,int count) {
	int mid,i;
	imdb *leftlist, *rightlist;
	if(count < 2) return;
	mid = count/2;  
	leftlist = (imdb*)malloc(mid*sizeof(imdb)); 
	rightlist = (imdb*)malloc((count- mid)*sizeof(imdb)); 
	for(i = 0;i<mid;i++){
		leftlist[i] = list[i]; 
	}
	for(i = mid;i<count;i++){
		rightlist[i-mid] = list[i];
	}
	MergeSortDirLike(leftlist,mid);
	MergeSortDirLike(rightlist,count-mid);
	MergeDirLike(list,leftlist,rightlist,mid,count-mid); 
        free(leftlist);
        free(rightlist);
}
void MergeSortActor3Like(imdb *list,int count) {
	int mid,i;
	imdb *leftlist, *rightlist;
	if(count < 2) return; 
	mid = count/2;
	leftlist = (imdb*)malloc(mid*sizeof(imdb)); 
	rightlist = (imdb*)malloc((count- mid)*sizeof(imdb)); 
	for(i = 0;i<mid;i++){
		leftlist[i] = list[i]; 
	}
	for(i = mid;i<count;i++){
		rightlist[i-mid] = list[i];
	}
	MergeSortActor3Like(leftlist,mid);  
	MergeSortActor3Like(rightlist,count-mid);  
	MergeActor3Like(list,leftlist,rightlist,mid,count-mid);
        free(leftlist);
        free(rightlist);
}
void MergeSortActor2Like(imdb *list,int count) {
	int mid,i;
	imdb *leftlist, *rightlist;
	if(count < 2) return;  
	mid = count/2;
	leftlist = (imdb*)malloc(mid*sizeof(imdb)); 
	rightlist = (imdb*)malloc((count- mid)*sizeof(imdb)); 
	for(i = 0;i<mid;i++){
		leftlist[i] = list[i]; 
	}
	for(i = mid;i<count;i++){
		rightlist[i-mid] = list[i];
	}
	MergeSortActor2Like(leftlist,mid); 
	MergeSortActor2Like(rightlist,count-mid);  
	MergeActor2Like(list,leftlist,rightlist,mid,count-mid); 
        free(leftlist);
        free(rightlist);
}
void MergeSortActor1Like(imdb *list,int count) {
	int mid,i;
	imdb *leftlist, *rightlist;
	if(count < 2) return; 
	mid = count/2;  
	leftlist = (imdb*)malloc(mid*sizeof(imdb)); 
	rightlist = (imdb*)malloc((count- mid)*sizeof(imdb)); 
	for(i = 0;i<mid;i++){
		leftlist[i] = list[i]; 
	}
	for(i = mid;i<count;i++){
		rightlist[i-mid] = list[i];
	}
	MergeSortActor1Like(leftlist,mid); 
	MergeSortActor1Like(rightlist,count-mid); 
	MergeActor1Like(list,leftlist,rightlist,mid,count-mid);
        free(leftlist);
        free(rightlist);
}
void MergeSortGross(imdb *list,int count) {
	int mid,i;
	imdb *leftlist, *rightlist;
	if(count < 2) return; 
	mid = count/2; 
	leftlist = (imdb*)malloc(mid*sizeof(imdb)); 
	rightlist = (imdb*)malloc((count- mid)*sizeof(imdb)); 
	for(i = 0;i<mid;i++){
		leftlist[i] = list[i]; 
	}
	for(i = mid;i<count;i++){
		rightlist[i-mid] = list[i];
	}
	MergeSortGross(leftlist,mid);  
	MergeSortGross(rightlist,count-mid); 
	MergeGross(list,leftlist,rightlist,mid,count-mid); 
        free(leftlist);
        free(rightlist);
}
void MergeSortVote(imdb *list,int count) {
	int mid,i;
	imdb *leftlist, *rightlist;
	if(count < 2) return; 
	mid = count/2;  
	leftlist = (imdb*)malloc(mid*sizeof(imdb)); 
	rightlist = (imdb*)malloc((count- mid)*sizeof(imdb)); 
	for(i = 0;i<mid;i++){
		leftlist[i] = list[i]; 
	}
	for(i = mid;i<count;i++){
		rightlist[i-mid] = list[i];
	}
	MergeSortVote(leftlist,mid);  
	MergeSortVote(rightlist,count-mid);  
	MergeVote(list,leftlist,rightlist,mid,count-mid);
        free(leftlist);
        free(rightlist);
}
void MergeSortCastLike(imdb *list,int count) {
	int mid,i;
	imdb *leftlist, *rightlist;
	if(count < 2) return; 
	mid = count/2;  
	leftlist = (imdb*)malloc(mid*sizeof(imdb)); 
	rightlist = (imdb*)malloc((count- mid)*sizeof(imdb)); 
	for(i = 0;i<mid;i++){
		leftlist[i] = list[i]; 
	}
	for(i = mid;i<count;i++){
		rightlist[i-mid] = list[i];
	}
	MergeSortCastLike(leftlist,mid);  
	MergeSortCastLike(rightlist,count-mid);  
	MergeCastLike(list,leftlist,rightlist,mid,count-mid);  
        free(leftlist);
        free(rightlist);
}
void MergeSortBudget(imdb *list,int count) {
	int mid,i;
	imdb *leftlist, *rightlist;
	if(count < 2) return; 
	mid = count/2;  
	leftlist = (imdb*)malloc(mid*sizeof(imdb)); 
	rightlist = (imdb*)malloc((count- mid)*sizeof(imdb)); 
	for(i = 0;i<mid;i++){
		leftlist[i] = list[i]; 
	}
	for(i = mid;i<count;i++){
		rightlist[i-mid] = list[i];
	}
	MergeSortBudget(leftlist,mid);  
	MergeSortBudget(rightlist,count-mid);  
	MergeBudget(list,leftlist,rightlist,mid,count-mid);  
        free(leftlist);
        free(rightlist);
}
void MergeSortPoster(imdb *list,int count) {
	int mid,i;
	imdb *leftlist, *rightlist;
	if(count < 2) return;
	mid = count/2;  
	leftlist = (imdb*)malloc(mid*sizeof(imdb)); 
	rightlist = (imdb*)malloc((count- mid)*sizeof(imdb)); 
	for(i = 0;i<mid;i++){
		leftlist[i] = list[i]; 
	}
	for(i = mid;i<count;i++){
		rightlist[i-mid] = list[i];
	}
	MergeSortPoster(leftlist,mid); 
	MergeSortPoster(rightlist,count-mid);  
	MergePoster(list,leftlist,rightlist,mid,count-mid);  
        free(leftlist);
        free(rightlist);
}
void MergeSortReview(imdb *list,int count) {
	int mid,i;
	imdb *leftlist, *rightlist;
	if(count < 2) return; 
	mid = count/2;  
	leftlist = (imdb*)malloc(mid*sizeof(imdb)); 
	rightlist = (imdb*)malloc((count- mid)*sizeof(imdb)); 
	for(i = 0;i<mid;i++){
		leftlist[i] = list[i]; 
	}
	for(i = mid;i<count;i++){
		rightlist[i-mid] = list[i];
	}
	MergeSortReview(leftlist,mid);  
	MergeSortReview(rightlist,count-mid);  
	MergeReview(list,leftlist,rightlist,mid,count-mid);  
        free(leftlist);
        free(rightlist);
}
void MergeSortMovieLike(imdb *list,int count) {
	int mid,i;
	imdb *leftlist, *rightlist;
	if(count < 2) return; 
	mid = count/2; 
	leftlist = (imdb*)malloc(mid*sizeof(imdb)); 
	rightlist = (imdb*)malloc((count- mid)*sizeof(imdb)); 
	for(i = 0;i<mid;i++){
		leftlist[i] = list[i]; 
	}
	for(i = mid;i<count;i++){
		rightlist[i-mid] = list[i];
	}
	MergeSortMovieLike(leftlist,mid); 
	MergeSortMovieLike(rightlist,count-mid);  
	MergeMovieLike(list,leftlist,rightlist,mid,count-mid); 
        free(leftlist);
        free(rightlist);
}
void MergeSortYear(imdb *list,int count) {
	int mid,i;
	imdb *leftlist, *rightlist;
	if(count < 2) return; 
	mid = count/2;  
	leftlist = (imdb*)malloc(mid*sizeof(imdb)); 
	rightlist = (imdb*)malloc((count- mid)*sizeof(imdb)); 
	for(i = 0;i<mid;i++){
		leftlist[i] = list[i]; 
	}
	for(i = mid;i<count;i++){
		rightlist[i-mid] = list[i];
	}
	MergeSortYear(leftlist,mid);  
	MergeSortYear(rightlist,count-mid);  
	MergeYear(list,leftlist,rightlist,mid,count-mid);  
        free(leftlist);
        free(rightlist);
}
void MergeSortAspect(imdb *list,int count) {
	int mid,i;
	imdb *leftlist, *rightlist;
	if(count < 2) return;
	mid = count/2;  
	leftlist = (imdb*)malloc(mid*sizeof(imdb)); 
	rightlist = (imdb*)malloc((count- mid)*sizeof(imdb)); 
	for(i = 0;i<mid;i++){
		leftlist[i] = list[i]; 
	}
	for(i = mid;i<count;i++){
		rightlist[i-mid] = list[i];
	}
	MergeSortAspect(leftlist,mid);  
	MergeSortAspect(rightlist,count-mid);  
	MergeAspect(list,leftlist,rightlist,mid,count-mid);
        free(leftlist);
        free(rightlist);
}
void MergeSortScore(imdb *list,int count) {
	int mid,i;
	imdb *leftlist, *rightlist;
	if(count < 2) return;
	mid = count/2; 
	leftlist = (imdb*)malloc(mid*sizeof(imdb)); 
	rightlist = (imdb*)malloc((count- mid)*sizeof(imdb)); 
	for(i = 0;i<mid;i++){
		leftlist[i] = list[i]; 
	}
	for(i = mid;i<count;i++){
		rightlist[i-mid] = list[i];
	}
	MergeSortScore(leftlist,mid);  
	MergeSortScore(rightlist,count-mid);  
	MergeScore(list,leftlist,rightlist,mid,count-mid);  
        free(leftlist);
        free(rightlist);
}
