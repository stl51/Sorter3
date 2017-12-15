#ifndef MERGESORT_H_H
#define MERGESORT_H_H

struct imdb{ 
char* color;
char* director_name;
char* actor_2_name;
char*genres;
char* actor_1_name;
char* movie_title;
char* actor_3_name;
char* plot_keywords;
char* movie_imdb_link;
char* language;
char* country;
char* content_rating;
char* num_critic_for_reviews;
char* duration;
char* director_facebook_likes;
char* actor_3_facebook_likes;
char* actor_1_facebook_likes;
char* gross;
char* num_voted_users;
char* cast_total_facebook_likes;
char* facenumber_in_poster;
char* num_user_for_reviews; 
char* budget;
char* title_year;
char* actor_2_facebook_likes;
char* imdb_score;
char* aspect_ratio;
char* movie_facebook_likes;
};typedef struct imdb imdb;

int floatcmp(char* str,char*str2); 

void MergeColor(imdb *list,imdb *leftlist,imdb *rightlist,int leftCount,int rightCount); 
void MergeDirector(imdb *list,imdb *leftlist,imdb *rightlist,int leftCount,int rightCount); 
void MergeActor2(imdb *list,imdb *leftlist,imdb *rightlist,int leftCount,int rightCount);
void MergeGenre(imdb *list,imdb *leftlist,imdb *rightlist,int leftCount,int rightCount);
void MergeActor1(imdb *list,imdb *leftlist,imdb *rightlist,int leftCount,int rightCount);
void MergeMovieTitle(imdb *list,imdb *leftlist,imdb *rightlist,int leftCount,int rightCount);
void MergeActor3(imdb *list,imdb *leftlist,imdb *rightlist,int leftCount,int rightCount);
void MergePlot(imdb *list,imdb *leftlist,imdb *rightlist,int leftCount,int rightCount);
void MergeLink(imdb *list,imdb *leftlist,imdb *rightlist,int leftCount,int rightCount);
void MergeLang(imdb *list,imdb *leftlist,imdb *rightlist,int leftCount,int rightCount);
void MergeCountry(imdb *list,imdb *leftlist,imdb *rightlist,int leftCount,int rightCount);
void MergeRating(imdb *list,imdb *leftlist,imdb *rightlist,int leftCount,int rightCount);
void MergeNumCritic(imdb *list,imdb *leftlist,imdb *rightlist,int leftCount,int rightCount);
void MergeDur(imdb *list,imdb *leftlist,imdb *rightlist,int leftCount,int rightCount);
void MergeDirLike(imdb *list,imdb *leftlist,imdb *rightlist,int leftCount,int rightCount);
void MergeActor3Like(imdb *list,imdb *leftlist,imdb *rightlist,int leftCount,int rightCount);
void MergeActor2Like(imdb *list,imdb *leftlist,imdb *rightlist,int leftCount,int rightCount);
void MergeActor1Like(imdb *list,imdb *leftlist,imdb *rightlist,int leftCount,int rightCount);
void MergeGross(imdb *list,imdb *leftlist,imdb *rightlist,int leftCount,int rightCount);
void MergeVote(imdb *list,imdb *leftlist,imdb *rightlist,int leftCount,int rightCount);
void MergeCastLike(imdb *list,imdb *leftlist,imdb *rightlist,int leftCount,int rightCount);
void MergePoster(imdb *list,imdb *leftlist,imdb *rightlist,int leftCount,int rightCount);
void MergeReview(imdb *list,imdb *leftlist,imdb *rightlist,int leftCount,int rightCount);
void MergeBudget(imdb *list,imdb *leftlist,imdb *rightlist,int leftCount,int rightCount);
void MergeYear(imdb *list,imdb *leftlist,imdb *rightlist,int leftCount,int rightCount);
void MergeMovieLike(imdb *list,imdb *leftlist,imdb *rightlist,int leftCount,int rightCount);
void MergeScore(imdb *list,imdb *leftlist,imdb *rightlist,int leftCount,int rightCount);
void MergeAspect(imdb *list,imdb *leftlist,imdb *rightlist,int leftCount,int rightCount);


//end of diff merge functions//

void MergeSortColor(imdb *list,int count);
void MergeSortDirector(imdb *list,int count);
void MergeSortActor1(imdb *list,int count);
void MergeSortActor2(imdb *list,int count);
void MergeSortActor3(imdb *list,int count);
void MergeSortGenre(imdb *list,int count);
void MergeSortMovieTitle(imdb *list,int count);
void MergeSortPlot(imdb *list,int count);
void MergeSortLink(imdb *list,int count);
void MergeSortLang(imdb *list,int count);
void MergeSortCountry(imdb *list,int count);
void MergeSortRating(imdb *list,int count);
void MergeSortNumCritic(imdb *list,int count);
void MergeSortDur(imdb *list,int count);
void MergeSortDirLike(imdb *list,int count);
void MergeSortActor3Like(imdb *list,int count);
void MergeSortActor2Like(imdb *list,int count);
void MergeSortActor1Like(imdb *list,int count);
void MergeSortGross(imdb *list,int count);
void MergeSortVote(imdb *list,int count);
void MergeSortCastLike(imdb *list,int count);
void MergeSortBudget(imdb *list,int count);
void MergeSortPoster(imdb *list,int count);
void MergeSortReview(imdb *list,int count);
void MergeSortMovieLike(imdb *list,int count);
void MergeSortYear(imdb *list,int count);
void MergeSortAspect(imdb *list,int count);
void MergeSortScore(imdb *list,int count);

#endif