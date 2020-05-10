#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<stdbool.h>
#include <windows.h>
#include <conio.h>
#include"add.h"
#include"menu.h"
#include"linked.h"

//clear the terminal screen function
void clrscr(){
    system("@cls||clear");
}

//time delay function
void delay(int seconds){
  int milli = 1000*seconds;    //change to 1000
  clock_t start = clock();
  while(clock() < start + milli);
}

void userInput(){
    node *head = create();
    FileHandle(head);
}

void function_add(){
  node1 *head = create1();
  printf("Hope you don't have to this for a long time.......\n\n");

  char country[50], countryName[50];
  strcpy(countryName, country_name);
  strcpy(country, strcat(countryName, ".txt"));

  //function for input in the linked list and file handling
  FileHandle1(head, country);
  printf("Data for the last 3 days were: \n");
  //printing the last 3 days
  displayLast_3(head);
  deleteList(head);
  //write call
  write(head, country);
  printf("Thank You for adding to the database..\n");
  printf("Stay Home, Stay Safe\n");
  delay(8);
  exit(-1);
}


void main(){
  clrscr();
  FileHandle();

}
