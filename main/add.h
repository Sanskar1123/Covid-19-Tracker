

//struct for corona data

typedef struct corona1{
  int death;
  float date;
  int recover;
  int cases;
  struct corona1 *next;
}corona1;

//struct for final list
typedef struct node1{
  struct corona1 *head;
  int data;
}node1;

//creating a linked list for all the data
node1 *create1(){
  node1 *list = (node1*)malloc(sizeof(node1));
  list->head = NULL;
  list->data = 0;
  return list;
}


//taking inputs per node and storing in temp to return in 1 list
corona1 *inputs1(float date, int cases, int recovered, int deaths){
  corona1 *temp = (corona1*)malloc(sizeof(corona1));
  temp->date = date;
  temp->cases = cases;
  temp->recover = recovered;
  temp->death = deaths;
  return temp;
}

//starting the inserting process
void InsertEnd1(node1 *list, corona1 *input){
  corona1 *temp = list->head;
  corona1 *tmp = (corona1*)malloc(sizeof(corona1));
  tmp = input;
  while(temp->next != NULL)
    temp = temp->next;
  temp->next = tmp;
}
//insert function main
void insert1(node1 *check, corona1 *inp){
  corona1 *temp = check->head;
  if(check->data == 0){
    check->head = inp;
    ++(check->data);
  }
  else
    InsertEnd1(check, inp);
}

//file handling and linked list inputs
void FileHandle1(node1 *head, char country[50]){
  float date, start1, end1;

  int deaths, recovered, cases;


  //input into the linked list
  FILE *fptr; //*fptr1, *fptr2, *fptr3, *fopen();
  int c,d,e,f;
  if((fptr = fopen(country,"r")) == NULL){
    printf("Data for the entered country is not available yet...\n");
    exit(1);
  }

  //fptr1 = fopen(country,"r");
  //fptr2 = fopen(country,"r");
  //fptr3 = fopen(country,"r");
  c = getc(fptr);

  while(c != EOF){
    fscanf(fptr,"%f %d %d %d",&date,&cases,&deaths,&recovered);
    fflush(stdin);
    /*fscanf(fptr1,"%*f %*d %*d %d",&recovered);
    fflush(stdin);
    fscanf(fptr2,"%*f %*d %d %*d",&deaths);
    fflush(stdin);
    fscanf(fptr3,"%*f %d %*d %*d",&cases);*/
    //fflush(stdin);
    insert1(head, inputs1(date,cases,recovered,deaths));  //date, cases, recovered , death
    c = getc(fptr);
  }
  fclose(fptr);
  //fclose(fptr1);
  //fclose(fptr2);
  //fclose(fptr3);
}

void *deleteList(node1 *list){
    corona1 *temp = list->head;
    node1 *next;

    while(temp != NULL){
        next = temp->next;
        free(temp);
        temp = next;
    }
    list = NULL;
}

//Function for Writing into the data in the file
void write(node1 *head, char country[50]){
  float date;
  int deaths, recovered, cases;
  int check1;
  //input into the linked list
  FILE *fptr;
  int c,d,e,f;
  if((fptr = fopen(country,"a")) == NULL){
    printf("Data for the entered country is not available yet...\n");
    exit(1);
  }

  printf("Enter the date in the format DD.MM: ");
  scanf("%f",&date);
  fflush(stdin);
  printf("Enter the Total number of cases on %0.1f: ",date);
  scanf("%d",&cases);
  fflush(stdin);
  printf("Enter the number of Deaths: ");
  scanf("%d",&deaths);
  fflush(stdin);
  printf("Enter the number of Recovered cases: ");
  scanf("%d",&recovered);
  fflush(stdin);

  printf("\nThe date you entered is: \nDate: %0.1f\tCases: %d\tDeaths: %d\tRecovered: %d\n", date, cases, deaths, recovered);
  printf("Would you like to proceed or edit your selection: \n");
  printf("Enter 1 to proceed and 0 to edit: ");
  scanf("%d", &check1);
  if(check1 == 0){
    while(check1 == 0){
      if(check1 == 0){
        printf("Enter the date in the format DD.MM: ");
        scanf("%f",&date);
        fflush(stdin);
        printf("Enter the Total number of cases on %0.1f: ",date);
        scanf("%d",&cases);
        fflush(stdin);
        printf("Enter the number of Deaths: ");
        scanf("%d",&deaths);
        fflush(stdin);
        printf("Enter the number of Recovered cases: ");
        scanf("%d",&recovered);
        fflush(stdin);

        printf("\nThe date you entered is: \nDate: %0.1f\tCases: %d\tDeaths: %d\tRecovered: %d\n", date, cases, deaths, recovered);
        printf("Would you like to proceed or edit your selection: \n");
        printf("Enter 1 to proceed and 0 to edit: ");
        scanf("%d", &check1);
      }
      if(check1 == 1){
        fprintf(fptr, "\n%0.1f      %d      %d      %d", date, cases, deaths, recovered);
        break;
      }
    }
  }
  else
    fprintf(fptr, "\n%0.1f     %d      %d      %d", date, cases, deaths, recovered);
  fclose(fptr);
  fflush(stdin);
}

//Displaying the last 3 elements
void displayLast_3(node1 *list){
  corona1 *temp = list->head;
  while(temp->next->next->next != NULL)
    temp = temp->next;
  while(temp != NULL){
    printf("Date: %0.1f\tCases: %d\tDeaths: %d\tRecovered: %d\n", temp->date, temp->cases, temp->death, temp->recover);
    temp = temp->next;
  }
}
