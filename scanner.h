#ifndef SCANNERCSVSORTER_H   /* Include guard */
#define SCANNERCSVSORTER_H

struct Node {
	struct Node * next;
        char line[500];
        int soi;
        char value[500];
};

int sortFile(int key, int strOrInt);

void Msort(struct Node** headRef);



struct Node* SortedMerge(struct Node* a, struct Node* b);
void FrontBackSplit(struct Node* source, struct Node** frontRef, struct Node** backRef);



void printList(struct Node * p);
struct Node* freeptr(struct Node* ptr);


int getKey(char * sortBy){
        int key=-1;
        if (strcmp(sortBy, "color")==0){
                key = 0;
        }
	else if (strcmp(sortBy, "director_name")==0){
                key = 1;
        }
	else if (strcmp(sortBy, "num_critic_for_reviews")==0){
                key = 2;
        }
	else if (strcmp(sortBy, "duration")==0){
                key = 3;
        }
	else if (strcmp(sortBy, "director_facebook_likes")==0){
                key = 4;
        }
	else if (strcmp(sortBy, "actor_3_facebook_likes")==0){
                key = 5;
        }
	else if (strcmp(sortBy, "actor_2_name")==0){
                key = 6;
        }
	else if (strcmp(sortBy, "actor_1_facebook_likes")==0){
                key = 7;
        }
	else if (strcmp(sortBy, "gross")==0){
                key = 8;
        }
  else if (strcmp(sortBy, "genres")==0){
                key = 9;
        }
	else if (strcmp(sortBy, "actor_1_name")==0){
                key = 10;
        }
	else if (strcmp(sortBy, "movie_title")==0){
                key = 11;
        }
	else if (strcmp(sortBy, "num_voted_users")==0){
                key = 12;
        }
	else if (strcmp(sortBy, "cast_total_facebook_likes")==0){
                key = 13;
        }
	else if (strcmp(sortBy, "actor_3_name")==0){
                key = 14;
        }
	else if (strcmp(sortBy, "facenumber_in_poster")==0){
                key = 15;
        }
	else if (strcmp(sortBy, "plot_keywords")==0){
                key = 16;
        }
	else if (strcmp(sortBy, "movie_imdb_link")==0){
                key = 17;
        }
  else if (strcmp(sortBy, "num_user_for_reviews")==0){
                key = 18;
        }
  else if (strcmp(sortBy, "language")==0){
                key = 19;
        }
	else if (strcmp(sortBy, "country")==0){
                key = 20;
        }
	else if (strcmp(sortBy, "content_rating")==0){
                key = 21;
        }
	else if (strcmp(sortBy, "budget")==0){
                key = 22;
        }
	else if (strcmp(sortBy, "title_year")==0){
                key = 23;
        }
	else if (strcmp(sortBy, "actor_2_facebook_likes")==0){
                key = 24;
        }
	else if (strcmp(sortBy, "imdb_score")==0){
                key = 25;
        }
	else if (strcmp(sortBy, "aspect_ratio")==0){
                key = 26;
        }
	else if (strcmp(sortBy, "movie_facebook_likes")==0){
                key = 27;
        }

	return key;
};

#endif   
     
