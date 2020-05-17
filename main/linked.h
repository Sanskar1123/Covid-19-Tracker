
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

//function to delete list
void *deleteListDates(node *list){
    corona *temp = list->head;
    corona *trav;

    while(temp){
        trav = temp->next;
        free(temp);
        temp = trav;
    }

    list->head = NULL;
}



//function to display the news
void info(node *head)
{
  FILE *fptr;
  char country[50],ch[500];
  clrscr();
  strcpy(country, country_name);
  strcat(country, "info.txt");
  printf("\n");
  if((fptr=fopen(country,"r")) == NULL)
  {
    printf("\nNO DATA FOUND FOR THE COUNTRY !\n ");
    exit(1);
  }
  else
  {
    fptr=fopen(country,"r");

  int TotalDeaths = Deaths(head, startingDate(head), endingDate(head));
  int TotalRecovered = Recovered(head, startingDate(head), endingDate(head));
  puts("");
  //printing the stored result
  gotoxy(30,10);
  printf("Total cases               :           %d", EndDate(head, endingDate(head)));
  gotoxy(30,11);
  printf("Deaths                    :           %d", TotalDeaths);
  gotoxy(30,12);
  printf("Recovered                 :           %d", TotalRecovered);
  gotoxy(30,13);
  printf("Growth rate of the virus  :           %0.2f", B);
  puts("\n\n");


    while (fgets(ch,500,fptr) != NULL)
    {
      printf("%s", ch);
    }
    printf("\n\n");
    fclose(fptr);
  }

  printf("\n\n\n  Press to ESC to go back");
    char back;
    s:
    back = _getch();
    switch(back)
    {
        case 27 :   display_user_menu(head);
        default :   goto s;
    }
}




//function for data between the dates
void betweenThe_dates(node *head){
  float date, start1, end1;
  //taking the users input for start date
  float start, end;
  clrscr();
  start1 = startingDate(head);
  end1 = endingDate(head);
  gotoxy(20,10);
  printf("Input dates in the format DD.M between: %.1f and %.1f", start1, end1);
  gotoxy(20,13);
  printf("Enter the starting date in the format DD.MM   :      ");
  scanf("%f",&start);
  //check if a valid date is entered
  int resultStart = check_start(head, start);
  while(resultStart == 0 && start > 0){
    printf("Invalid Input, Enter the date again or Enter 0 to exit the program...\n");
    start1 = startingDate(head);
    end1 = endingDate(head);
    printf("\nInput dates in the format DD.MM between: %.1f and %.1f\n\n", start1, end1);
    printf("Enter the starting date in the format DD.MM :      ");
    scanf("%f",&start);
    resultStart = check_start(head, start);
  }

  // input for the ending date
  fflush(stdin);
  gotoxy(20,15);
  printf("Enter the end date in the format DD.MM        :      ");
  scanf("%f",&end);
  int resultEnd = check_end(head, end, start);
  //printf("%d ", resultEnd);
  while(resultEnd == 0 && end > 0){
    printf("Invalid Input, Enter the date again or Enter 0 to exit the program...\n");
    start1 = startingDate(head);
    end1 = endingDate(head);
    printf("\nInput dates in the format DD.MM between: %.1f and %.1f\n\n", start1, end1);
    printf("Enter the end date in the format DD.MM      :      ");
    scanf("%f",&end);
    resultEnd = check_end(head, end, start);
  }

  //storing the result in variables
  int TotalCases = Cases(head, start, end);
  int TotalDeaths = Deaths(head, start, end);
  int TotalRecovered = Recovered(head, start, end);
  puts("");
  //printing the stored result

  printf("\t\t\tNew cases         :       %d\n", TotalCases);
  printf("\t\t\tDeaths reported   :       %d\n", TotalDeaths);
  printf("\t\t\tRecovered cases   :       %d\n\n", TotalRecovered);
  printf("\t\t\tThe growth rate of the virus between this time was  : %0.2f\n", b);
  printf("\t\t\tThe overall growth rate of the virus                : %0.2f\n\n", B);
  if(b<B)
  {
      printf("\t\t\tHence, the growth rate between these days was lesser than the overall growth rate of virus");
  }
  else
  {
      printf("\t\t\tHence, the growth rate between these days was higher than the overall growth rate of virus");
  }
  //display(head);
  printf("\n\n\n  Press to ESC to go back");
    char back;
    s:
    back = _getch();
    switch(back)
    {
        case 27 :   display_user_menu(head);
        default :   goto s;
    }
}

//function for the prediction of data
void prediction(node *list){
    float value,t = 0,n,once = 1,x = -1,y, sumxy=0,sumxx=0,sumy=0,sumx=0,a,b, data[data_days];
    corona *temp = list->head;
    clrscr();
    while(temp != NULL){
        y = temp->cases;
        y = log(y);
            if(once)
            {
                for(int i = 0; i< data_days;i++)
                    data[i]=y;
                once = 0;
            }
            for(int i = 0; i<data_days-1;i++)
                data[i]=data[i+1];
            data[data_days-1] = y;
            sumy = 0;
            sumx = 0;
            sumxx = 0;
            sumxy = 0;
            for(int i = 0; i<data_days;i++)
            {
                sumy += data[i];
                sumx += i;
                sumxx += (i)*(i);
                sumxy += (i)*data[i];
            }
            temp = temp->next;
    }

        n = data_days;
        b = ((n*sumxy)-(sumx*sumy))/((n*sumxx)-(sumx*sumx));
        a = (sumy - b*sumx)/n;
        a = exp(a);
        if(exp(data[0])<a)
            a = exp(data[0]);
        b = exp(b);
	int i=0;
	float endDate = endingDate(list);

	int predict;
	gotoxy(30,10);int j = 13;
	printf("Enter the number of days upto which you want to see the predicted data: ");
	scanf("%d",&predict);
	while(predict < 0 || predict > 15){
        printf("The model predicts data upto 15 days with more accuracy.\n");
        printf("Please Enter number between 1 and 15: ");
        scanf("%d",&predict);
	}
    for(i = data_days; i<n+predict; i++)
    {
        gotoxy(30,j);
        value =  a*pow(b, i);
        printf("The total infected population on %0.1f.20 will be around:\t", endDate+1);
        printf("%0.0f",value);
        endDate += 1;
        ++j;
    }

    gotoxy(20,j+2);
    printf("The predicted data is based on mathematical model and is subject to external circumstances....\n\n");
    printf("\n\nPress to ESC to go back");

    char back;
    s:
    back = _getch();
    switch(back)
    {
        case 27 :   display_user_menu(list);
        default :   goto s;
    }
}


//display menu function for choices
void display_user_menu(node *head)
{
    clrscr();
    int j=15, i = j+1; char option;
    user_menu :
    gotoxy(70,10);
    printf("%s's data",country_name);
    gotoxy(30,j-1);

    gotoxy(34,j+1);
    printf("Information center");
    gotoxy(34,j+2);
    printf("Get information between selected dates");
    gotoxy(34,j+3);
    printf("Predict real-time data using Mathematical Model");
    gotoxy(30,i);
    printf("-->");
    option = _getch();
    switch(option)
    {
        case 27 :       {
                        char o;
                        gotoxy(40,30);
                        y:
                        printf("Are you sure you want to quit?");
                        gotoxy(40,31);
                        printf("(Press Enter to quit | Press ESC to continue exploring)");
                        o = _getch();
                        switch(o)
                        {
                            case 13 :   quit();

                            case 27 :   clrscr();
                                        goto user_menu;

                            default :   goto y;

                        }

                        goto user_menu;
                        }
        case 80 :   if(i<j+3)
                        i++;
                    clrscr();
                    goto user_menu;
        case 72 :   if(i>j+1)
                        i--;
                    clrscr();
                    goto user_menu;
        case 13 :   gotoxy(30, j+5);
                    break;
        default :   goto user_menu;
    }
    switch(i-j)
    {
        case 1  :   info(head);
                    break;
        case 2  :   betweenThe_dates(head);
                    break;
        case 3  :   prediction(head);
                    break;
        default :   goto user_menu;
    }

}


//file handling and linked list inputs
void FileHandle(){
  node *head = create();
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

  fclose(fptr);
  fclose(fptr1);
  fclose(fptr2);
  fclose(fptr3);

  //mediocre effects
  //display(head);
  //delay(8);           // change the time here---------------------------------------
  //clrscr();

  display_user_menu(head);
}


