#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

void menu(void){

	printf("--usage: to get this menu\n");
	printf("--set eps_number: to add a new show\n");
	printf("--done line_number: to mark a show as done\n");
	printf("--delete line_numer: to delete the show\n");
}



int main(int argc, char * argv[]){


    if(argc <= 1){
        menu();
        exit(0);
    }

    FILE * fptr;
    const char * path = "/home/malisio/Documents/.file.txt";

    if(strcmp(argv[1], "--set") == 0){

        fptr=fopen(path , "a");

        if(fptr == NULL){
            printf("Couldn't open the file,exiting\n");
            return 1;
        }

        int eps= atoi(argv[3]);
        fprintf(fptr,"%s  %d\n", argv[2], eps);
        fclose(fptr);

    }




    else if(strcmp(argv[1], "--done") == 0){
        fptr=fopen(path, "r+");
        char  series[1024];

        if(fptr== NULL){
            printf("Error!\n");
            return 1;
        }

    bool running = true;
    int series_line=atoi(argv[2]);
    int current_line=1;

    do{
        fgets(series,200 ,fptr);
        if(series_line == current_line ){
            series[strlen(series)-1]='\0';
            fseek(fptr,-strlen(series) - 1, SEEK_CUR);
            fprintf(fptr,"%s [*]\n", series);
            running=false;
            break;

        }

        else if(feof(fptr)){
            printf("the line: %d wasn't found!\n", series_line);
            running=false;
            return 1;
        }

    current_line++;

    }while (running);
    fclose(fptr);

    }
    else if(strcmp(argv[1], "--delete") == 0){
        fptr=fopen(path, "r");
        FILE * fptr2;
        fptr2= fopen("/tmp/.tmp.txt", "w");
        if(fptr== NULL || fptr2== NULL){
            printf("Null error\n");
            return 1;
        }

        int current_line=1;
        int target_line= atoi(argv[2])+1;
        char string[1024];
        bool running =true;
        while(running){
            fgets(string, 200, fptr);
            if(feof(fptr)){
                running=false;
            }
            else if(current_line==target_line){
                fprintf(fptr2,"%s", string);
            }
            current_line++;
        }
        rename("/tmp/.tmp.txt", path);
        fclose(fptr);
        fclose(fptr2);
        return 0;
    }

    else if(strcmp(argv[1], "--list")==0){
        fptr= fopen(path, "r");
        if(fptr==NULL){
            printf("Create file first plz\n");
            return 1;
        }
        bool running = true;
        char string[1024];
        while(running){
            fgets(string,200, fptr);
            if(feof(fptr)){
                break;
            }
            printf("%s", string);
        }
        fclose(fptr);

    }
    else if(strcmp(argv[1] , "--usage")==0){
        menu();
    }
	
    return 0;
	//Author:m4lisio
	//License:GLP
	//Enjoy!
}



