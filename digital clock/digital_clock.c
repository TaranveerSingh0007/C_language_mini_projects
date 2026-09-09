// header files
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

//defining colors
#define RED "\033[1;31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define RESET "\033[0m"

void fill_time(char*,int); // function for time
void fill_date(char*); // function for date
int input_format(); //input
void clear_screen(); //function to clear screen

//main function 
int main(){
    char time[50] , date[50];
    int format = input_format();

    while(1){
//calling of functions
     fill_time(time,format);
     fill_date(date);
     clear_screen();
     
     printf("\n\n");
     printf(RED"DIGITAL CLOCK \n\n");
     printf(RESET"current time : ");
     printf(YELLOW"%s\n",time);
     printf(RESET"date : ");
     printf(GREEN"%s\n",date);
     printf(RESET"\n\n developed by Taranveer Singh Jassal");

     Sleep(1000); // this command pauses output of function for 1000 milliseconds
    }
    return 0;
}

// void function for time with two options and using time.h library
void fill_time(char* buffer,int format){

    time_t rawtime; // declared time as rawtime
    struct tm *current_time; //take pointer of current time as structure

    time(&rawtime); //declare adress of time
    current_time = localtime(&rawtime);
    
    if(format == 1){
       strftime(buffer,50,"%H:%M:%S",current_time);
    }
    else{
       strftime(buffer,50,"%I:%M:%S %p",current_time);
    }
}

// fill date using math.h library by creating a pointer
void fill_date(char* buffer){
    time_t rawtime; 
    struct tm *current_time;

    time(&rawtime);
    current_time = localtime(&rawtime);

    strftime(buffer,50,"%A %B %d %Y",current_time);
}

// menu for taking input of time format
int input_format(){
    int format;
    printf("\n choose the time format :");
    printf("\n[1] 24 hour format");
    printf("\n[2] 12 hour format(default)");
    printf("make a choice(1/2) :");
    if (scanf("%d", &format) != 1) format = 2;
    return format;
}

// function to clear screen , works for both windows and macbook
void clear_screen(){
   #ifdef _WIN32
     system("cls");
    #else
     system("clear");
    #endif  
}