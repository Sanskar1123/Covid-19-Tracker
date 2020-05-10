COORD coord = {0,0};
void gotoxy(int x, int y)
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

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

void quit()
{
    clrscr();
    gotoxy(75,18);
    printf("!!!THANKYOU!!!");
    gotoxy(72,20);
    printf("STAY HOME STAY SAFE\n\n\n\n\n\n\n\n\n\n\n\n\n");
    delay(3);
    exit(1);
}
