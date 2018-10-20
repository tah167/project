
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include "scannerCSVsorter.h"
#include "mergesort.c

int main(int argc, char **argv){

        if (argc<3 || argc>7){

                return;
        }

	if(strcmp(argv[1],"-c")!=0){
                return;
        }

	char* sortBy= argv[2];
        int key;
        int strOrInt=0;
        // Get the key to sortBy
        key=getKey(sortBy);

        if(key==-1){
                /*char error[]="Error: Column Not in CSV\n";
                int errLen= strlen(err);
                write(STDERR, error, errlen);
        	*/
		printf("column not in CSV");
		return -1; 
	}

	else if(key==2|key==3|key==4|key==5|key==7|key==8|key==12|key==13|key==15|key==18|key==22|key==23|key==24|key==25|key==26|key==27){
                strOrInt=1;

        }

	char * dirName= (char*)malloc(sizeof(char)*2);
        char * outputDir= (char*)malloc(sizeof(char)*2);
        strcpy(dirName,".");
        strcpy(outputDir,".");
        int i=0;

        for(i=3;i<argc;i++){

                if(i==3 || i==5){
                        if(strcmp(argv[i],"-d")==0){

                                dirName= argv[i+1];
                        }

                        else if (strcmp(argv[i],"-o")==0){
                                outputDir=argv[i+1];

                        }
                }
        }
	DIR *currDir=opendir(dirName);
	struct dirent *curr; 

	if(currDir==NULL){
	printf ("Cant open dir");

	}

///////////////////////////////	
	while *curr=readdir(currDir)!=NULL){
			
			

	// an example call would be : int ans= sortFile(int key, int strOrInt);

	}
		
	return 1;

}

// TODO: change the sortfile to use it for each file rather than STDIN 
int sortFile(int key, int strOrInt){
	char names[500];
	char save[500];
	char pres;
	int quoteFlag = 1;
	char str[500];
	char temp[500];	
	char * pass;
	int count =0;
	
	memset(save, 0, sizeof(save));
	
	memset(temp, 0, sizeof(temp));
	
	fgets(names, 500, stdin);
		
	printf("%s", names);
	struct Node * head = NULL;
	struct Node * ptr = head;
	while (pres!=EOF){
		pres = getc(stdin);
		if (pres==EOF){
			if (key == count){
				strcpy(save, str);
			}			
			
			pass = temp;
			struct Node * n = (struct Node *) malloc(sizeof(struct Node));
			n->soi = strOrInt;
						
			if (save[0] == ','){
				memmove(save, save+1, strlen(save));
			}
			
			strcpy(n->line, pass);
			while (save[0]==' ' || save[0] == '"'){
				memmove(save, save+1, strlen(save));
			}
			while (save[strlen(save)-1] == ' ' || save[strlen(save)-1] == '"'){
				save[strlen(save)-1] = '\0';
			}
			strcpy(n->value, save);
			n->next = NULL;
			if (head==NULL){
				head = n;
				ptr = head;
			}else{
				ptr = head;
				while(ptr->next!=NULL){
					ptr = ptr->next;
				}
				ptr->next = n;
				ptr = n;
			}
			
			
			
			break;
		}
		
		if (pres=='"'){
			quoteFlag = quoteFlag * -1;
		}
		if (pres==','){
			
			if (quoteFlag == 1){
				
				if (count == key){
					
					strcpy(save, str);
				
				}
				count++;
				memset(str, 0, sizeof(str));
			}
			
		}
		if (pres=='\n'){
			pass = temp;
			if (count == key){
				
				strcpy(save, str);
									
			}
		
			struct Node * n = (struct Node *) malloc(sizeof(struct Node));
			n->soi = strOrInt;
			if (save[0] == ','){
				memmove(save, save+1, strlen(save));
			}
			while (save[0]==' ' || save[0] == '"'){
				memmove(save, save+1, strlen(save));
			}
			while (save[strlen(save)-1] == ' ' || save[strlen(save)-1] == '"'){
				save[strlen(save)-1] = '\0';
			}
			strcpy(n->line, pass);
			
			strcpy(n->value, save);
		
			
			
			n->next = NULL;
			if (head==NULL){
				head = n;
				ptr = head;
			}else{
				ptr = head;
				while(ptr->next!=NULL){
					ptr = ptr->next;
				}
				ptr->next = n;
				ptr = n;
			}
			if(head!=NULL){
				//printf("%s\n", head->line);
			}
			
			
			
			
			
			count=0;
			memset(temp, 0, sizeof(temp));
			memset(str, 0, sizeof(str));
		}else {
			
			
			temp[strlen(temp)] = pres;
			
			str[strlen(str)] = pres;
			
		}
	}	
	
	
	Msort(&head);
	
	printList(head);
	
	
	freeptr(head);
	
	return 0;
	
}
