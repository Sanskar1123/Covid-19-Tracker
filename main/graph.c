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
#include"utilities.h"
#include"linked.h"

void function_add(){
  clrscr();
  node1 *head = create1();

  char country[50], countryName[50];
  strcpy(countryName, country_name);
  strcpy(country, strcat(countryName, ".txt"));
  gotoxy(0,10);
  //function for input in the linked list and file handling
  FileHandle1(head, country);
  printf("\t\t\tData for the last 3 days were: \n");
  //printing the last 3 days
  displayLast_3(head);
  deleteList(head);
  //write call
  write(head, country);
  gotoxy(30,20);
  printf("Thank You for adding to our database..\n");
  delay(2);
  quit();

}


void main(){
  clrscr();
  display_welcome_menu();
}




