#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <windows.h>
#include <conio.h>
#include "add.h"
#include "menu.h"
#include "linked.h"
#include "utilities.h"

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

  display_welcome_menu();

}


void main(){
  node *head = create();
  float date, start1, end1;
  //function for input in the linked list and file handling
  display_welcome_menu();
  //taking the users input for start date
  float start, end;
///*
  printf("Enter the starting date in the format DD.MM: ");
  scanf("%f",&start);
  //check if a valid date is entered
  int resultStart = check_start(head, start);
  while(resultStart == 0 && start > 0){
    printf("Invalid Input, Enter the date again or Enter 0 to exit the program...\n");
    start1 = startingDate(head);
    end1 = endingDate(head);
    printf("\nInput dates in the format DD.MM between: %.1f and %.1f\n\n", start1, end1);
    printf("Enter the starting date in the format DD.MM: ");
    scanf("%f",&start);
    resultStart = check_start(head, start);
  }

///*


  // input for the ending date
  fflush(stdin);
  printf("Enter the end date in the format DD.MM: ");
  scanf("%f",&end);
  int resultEnd = check_end(head, end, start);
  //printf("%d ", resultEnd);
  while(resultEnd == 0 && end > 0){
    printf("Invalid Input, Enter the date again or Enter 0 to exit the program...\n");
    start1 = startingDate(head);
    end1 = endingDate(head);
    printf("\nInput dates in the format DD.MM between: %.1f and %.1f\n\n", start1, end1);
    printf("Enter the end date in the format DD.MM: ");
    scanf("%f",&end);
    resultEnd = check_end(head, end, start);
  }

  //storing the result in varibles
  int TotalCases = Cases(head, start, end);
  int TotalDeaths = Deaths(head, start, end);
  int TotalRecovered = Recovered(head, start, end);

  //printing the stored result
  printf("Total cases: %d\t", EndDate(head, end));
  printf("Cases in between: %d\t", TotalCases);
  printf("  Deaths: %d\t", TotalDeaths);
  printf("  Recovered: %d\n", TotalRecovered);
  //display(head);

}
