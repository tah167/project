#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include "scannerCSVsorter.h"


void LS(char * dirName, char * col){
	DIR *currDir=opendir(dirName);
	struct dirent *curr; 
	status =0;
	if(currDir==NULL){
		printf ("Cant open dir");
	}
	while (*curr=readdir(currDir)!=NULL){
	
			if (curr->d_type == DT_REG){
				int PID = fork();
				if (PID ==0){
					fileHandler(curr, col);
				}
				
			}
			if (curr->d_type == DT_DIR){
				int PID = fork();
				if (PID ==0){
					LS (strcat(dirName, col);
				}
			
			}
		
	}
	//WAIT LOOP HERE??
	wait(&status)
	//value += WEXITSTATUS(status); 	///// do something for return values
}
void fileHandler(char * nameToSort, char * column){
	//check nameToSort to see if it is a CSV
	if(strstr(nameToSort, "-sorted")){
		continue;
	}
		
	else if((strstr(nameToSort, ".csv")) == NULL){
		continue;
	}else{
		sortFile(nameToSort, column);
	}
	

}
int main(int argc, char **argv){
        if (argc<3 || argc>7){
                return;
        }
	if(strcmp(argv[1],"-c")!=0){
                return;
        }
	
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
		write(2, "Cant open dir", 14);
		
	}
///////////////////////////////	
	LS(dirName, argv[2]);
		
	return 1;
}
// TODO: change the sortfile to use it for each file rather than STDIN 
int sortFile(char * fileName, char * col){
	key = getKey(col);
	if(key==-1){
                /*char error[]="Error: Column Not in CSV\n";
                int errLen= strlen(err);
                write(STDERR, error, errlen);
        	*/
		printf("column not in CSV");
		return -1; 
	}
	char names[500];
	char save[500];
	char pres;
	int quoteFlag = 1;
	char str[500];
	char temp[500];	
	char * pass;
	int count =0;
	int opener = open(fileName, O_RD);
	if (opener < 0){
		write(2, "Error opening file", 19);
	}
	
	memset(save, 0, sizeof(save));
	
	memset(temp, 0, sizeof(temp));
	
	fgets(names, 500, opener);
		
	printf("%s", names);
	struct Node * head = NULL;
	struct Node * ptr = head;
	while (pres!=EOF){
		pres = getc(opener);
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
	
	fileName[strlen(fileName)-3] = 0;
   strcat(fileName, "-sorted-");
   strcat(fileName, col);
   strcat(fileName, ".csv");
   
	printList(fileName, head);
	
	
	freeptr(head);
	
	return 0;
	
}
