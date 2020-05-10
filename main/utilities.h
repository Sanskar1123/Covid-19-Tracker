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
    gotoxy(40,18);
    printf("Hope the world comes out of this crisis soon, and this program becomes of no use");
    gotoxy(74,20);
    printf("!!!THANKYOU!!!");
    gotoxy(71,22);
    printf("STAY HOME, STAY SAFE\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

    delay(3);
    exit(1);
}
