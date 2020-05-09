
float a,b,A,B;

//struct for corona data
typedef struct corona{
  int death;
  float date;
  int recover;
  int cases;
  struct corona *next;
}corona;

//struct for final list
typedef struct node{
  struct corona *head;
  int data;
}node;


//creating a linked list for all the data
node *create(){
  node *list = (node*)malloc(sizeof(node));
  list->head = NULL;
  list->data = 0;
  return list;
}

//taking inputs per node and storing in temp to return in 1 list
corona *inputs(float date, int cases, int recovered, int deaths){
  corona *temp = (corona*)malloc(sizeof(corona));
  temp->date = date;
  temp->cases = cases;
  temp->recover = recovered;
  temp->death = deaths;
  return temp;
}

//starting the inserting process
void InsertEnd(node *list, corona *input){
  corona *temp = list->head;
  corona *tmp = (corona*)malloc(sizeof(corona));
  tmp = input;
  while(temp->next != NULL)
    temp = temp->next;
  temp->next = tmp;
}
//insert function main
void insert(node *check, corona *inp){
  corona *temp = check->head;
  if(check->data == 0){
    check->head = inp;
    ++(check->data);
  }
  else
    InsertEnd(check, inp);
}

//printing the range of dates in a file the starting date
float startingDate(node *list){
  corona *temp = list->head;
  float date = temp->date;
  return date;
}
//printing the range of dates in a file the starting date
float endingDate(node *list){
  corona *temp = list->head;
  while(temp->next != NULL)
    temp = temp->next;
  float date = temp->date;
  return date;
}

//searching according to the dates for total cases

int Cases(node *list, float start, float end){
  corona *temp = list->head;
  float x=-1,y,sumxy=0,sumxx=0,sumy=0,sumx=0,value,n;
  //going to the starting date as mentioned by user
  while(temp->date != start)
    temp = temp->next;

  int variable = temp->cases;

  //adding the values
  while(temp->date != end){
    y = temp->cases;
    x += 1;
    y = log(y);
    sumy+=y;
    sumx+=x;
    sumxx+= x*x;
    sumxy+= x*y;
    temp = temp->next;
  }
  n = x+1;
  b = ((n*sumxy)-(sumx*sumy))/((n*sumxx)-(sumx*sumx));
  a = (sumy - b*sumx)/n;
  a = exp(a);
  b = exp(b);

  printf("%f\n",b);

  int tmp = temp->cases;
  //to include the values of the last date entered adding the value
  int CaseCheck = tmp-variable;
  return CaseCheck;
}

//searching according to the dates for deaths
int Deaths(node *list, float start, float end){
  corona *temp = list->head;

  //going to the starting date as mentioned by user
  while(temp->date != start)
    temp = temp->next;

  //variable to store starting date deaths value
  int variable = temp->death;

  //adding the values
  while(temp->date != end)
      temp = temp->next;
  int tmp = temp->death;

  //variable to store deaths
  int DeathCheck = tmp-variable;

  return DeathCheck;
}

//searching according to the dates for deaths
int Recovered(node *list, float start, float end){
  corona *temp = list->head;
  //going to the starting date as mentioned by user
  while(temp->date != start)
    temp = temp->next;

  int RecoverCheck = 0;
  //adding the values
  while(temp->date != end){
      RecoverCheck += temp->recover;
      temp = temp->next;
  }
  return RecoverCheck;
}



//file handling and linked list inputs
void FileHandle(node *head){
  float date, start1, end1;
  float x=-1,y,sumxy=0,sumxx=0,sumy=0,sumx=0,value,n;
  char country[50], countryName[50];
  int deaths, recovered, cases;



  strcpy(countryName, country_name);
  strcpy(country, strcat(countryName, ".txt"));

  //input into the linked list
  FILE *fptr, *fptr1, *fptr2, *fptr3;
  int c,d,e,f;
  fptr = fopen(country,"r");
  if(fptr == NULL){
    printf("%s %s",countryName, country_name);
    printf("Data for the entered country is not available yet...\n");
    exit(1);
  }

  fptr1 = fopen(country,"r");
  fptr2 = fopen(country,"r");
  fptr3 = fopen(country,"r");
  c = getc(fptr);

  while(c != EOF){
    fscanf(fptr,"%f %*d %*d %*d",&date);
    fflush(stdin);
    fscanf(fptr1,"%*f %*d %*d %d",&recovered);
    fflush(stdin);
    fscanf(fptr2,"%*f %*d %d %*d",&deaths);
    fflush(stdin);
    fscanf(fptr3,"%*f %d %*d %*d",&cases);
    fflush(stdin);

    y = cases;
    x += 1;
    y = log(y);
    sumy+=y;
    sumx+=x;
    sumxx+= x*x;
    sumxy+= x*y;

    insert(head, inputs(date,cases,recovered,deaths));  //date, cases, recovered , death
    c = getc(fptr);
  }

  n = x+1;
  B = ((n*sumxy)-(sumx*sumy))/((n*sumxx)-(sumx*sumx));
  A = (sumy - B*sumx)/n;
  A = exp(A);
  B = exp(B);

  printf("\n%f\n",B);

  fclose(fptr);
  fclose(fptr1);
  fclose(fptr2);
  fclose(fptr3);

  //mediocre effects
  //display(head);
  //delay(8);           // change the time here---------------------------------------
  //clrscr();

  start1 = startingDate(head);
  end1 = endingDate(head);
  printf("\nFor %s input dates between in the format DD.MM: %.1f and %.1f\n\n", countryName, start1, end1);

}

//Total number of cases at the end date
int EndDate(node *list, float end){
  corona *temp = list->head;
  while(temp->date != end)
    temp = temp->next;
  int last = temp->cases;
  return last;
}

//display
void display(node *list){
  corona *temp = list->head;

  while(temp!=NULL){
    printf("Date: %0.1f     Cases: %2d        Deaths: %2d        Recovered: %2d\n", temp->date, temp->cases, temp->death, temp->recover);
    temp=temp->next;
    //delay(1);           // change the time here------------------------
  }
}

//check function()
bool check_start(node *list, float input){
  corona *temp = list->head;
  if(input == 0)
    exit(-1);

  int checking = 0;
  while(temp != NULL){
    if(temp->date == input){
        checking = 1;
        return true;
    }
    temp = temp->next;
  }

  if(checking == 0)
    return false;
}


bool check_end(node *list, float input, float open){
  corona *temp = list->head;

  if(input == 0)
    exit(-1);

  int umm = open*10;
  int month = umm % 10;
  int date = umm/10;

  //calculating the month and the date for the user input starting date
  int num1 = input * 10;
  int month_input = num1%10;
  int date_input = num1/10;

  if(month_input > month)
    ;
  else if(month == month_input && date <= date_input)
    ;
  else
    return false;

  int checking = 0;
  while(temp != NULL){
    if(temp->date == input){
        checking = 1;
        return true;
    }
    temp = temp->next;
  }

  if(checking == 0)
    return false;
}

