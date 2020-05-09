

//DISPLAY MENU FUNCTION
int once =1,data_days=7;
char country_name[50];

void display_welcome_menu()
{
    clrscr();
    int j=16,i=j+1;char option;
    menu_start :
    gotoxy(62,10);
    printf("!!!Welcome to the Covid-19 Tracker!!!\n");
    gotoxy(30,j-1);
    printf("How do you wish to proceed?");
    gotoxy(30,j+1);
    printf("    Server Log-in");
    gotoxy(30,j+2);
    printf("    User Log-in");
    gotoxy(30,i);
    printf("-->");
    option = _getch();
    switch(option)
    {
        case 80 :   if(i<j+2)
                        i++;
                    clrscr();
                    goto menu_start;
                    break;
        case 72 :   if(i>j+1)
                        i--;
                    clrscr();
                    goto menu_start;
                    break;
        case 13 :   gotoxy(30,j+6);
                    break;
        default :   goto menu_start;
    }
    switch(i-j)
    {
        case 1  :   printf("CALL ADD FUNCTION");
                    display_server_menu();
                    break;
        case 2  :   printf("CALL USER FUNCTION");
                    display_user_menu();
                    break;
        default :   goto menu_start;
    }

}


void display_server_menu()
{
    clrscr();

    char username[20],password[20];
    int p=0;
    gotoxy(30,12);
    printf("USERNAME          :");
    gotoxy(30,15);
    printf("PASSWORD          :");
    gotoxy(60,12);
    fgets(username, 20, stdin);
    gotoxy(60,15);
    do
    {
        password[p] = _getch();
        if(password[p] == '\b')
        {

            if(p!=0)
                {
                    p -= 2;
                    printf("\b \b");
                }
            else
                password[0] = '\n';
        }
        else if(password[p] != '\r')
        {
            printf("*");
        }
        p++;
    }while(password[p-1]!='\r');
    password[p-1]='\0';

    gotoxy(30,20);
    //printf("%s\n\n%s",username,password);
    _getch();
    display_country_menu(1);

}
void display_user_menu()
{
    clrscr();
    display_country_menu(0);
}
void display_country_menu(int check)
{
    clrscr();
    int j=15,i=j+1;char option;
    menu_start :
    gotoxy(75,10);
    printf("!!!Welcome!!!\n");
    gotoxy(30,j-1);
    printf("Choose any country:-");
    gotoxy(30,j+1);
    printf("    (i)   INDIA");
    gotoxy(30,j+2);
    printf("    (ii)  CHINA");
    gotoxy(30,j+3);
    printf("    (iii) USA");
    gotoxy(30,j+4);
    printf("    (iv)  ITALY");
    gotoxy(30,j+5);
    printf("    (v)   SPAIN");
    gotoxy(30,i);
    printf("-->");
    option = _getch();
    switch(option)
    {
        case 27 :   display_welcome_menu();
                    break;
        case 80 :   if(i<j+5)
                        i++;
                    clrscr();
                    goto menu_start;
                    break;
        case 72 :   if(i>j+1)
                        i--;
                    clrscr();
                    goto menu_start;
                    break;
        case 13 :   gotoxy(30,j+6);
                    break;
        default :   goto menu_start;
    }

    switch(i-j)
    {
        case 1 :    strcpy(country_name,"indiatest");
                    break;
        case 2 :    strcpy(country_name,"china");
                    break;
        case 3 :    strcpy(country_name,"usa");
                    break;
        case 4 :    strcpy(country_name,"italy");
                    break;
        case 5 :    strcpy(country_name,"spain");
                    break;
        default:    goto menu_start;
    }

    if(check == 1 )
    {
        function_add();
    }
    else
    {
        FileHandle();
    }
}
