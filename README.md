# Covid-19 Tracker
 DS Project 

We have made a Corona Virus Progression program, which shows the progress of the virus in 5 countries-:

1) India
2) Italy
3) USA
4) Spain
5) China

This program Excessively uses Linked list, Stack, file handling, the knowledge of the conio.h library etc. We have also made a Mathematical algorithm to determine the growth of the virus for the upcoming days.

Make sure to include all the .h and .txt files in the same folder as the .c file.


NOTE -----::>  WE HIGHLY RECOMMEND YOU TO USE THE FULL SCREEN FOR BEST VISUAL AESTHETICS.........   :)


After running the program you will see a welcome screen with 2 options --:>

1) Server side login
2) User login

NOTE--> In all the menu pages you have to use ARROW KEYS, ENTER KEY and ESC KEY to choose the option or to go back to previous page.

------------------------------------------------------------------------------------------------------------------------------

1) THE SERVER SIDE - 

This is the part of the program which can be used to add new entries to the existing databse..... 
In the server side login, you will be taken to a login screen where you have to use the given credentials -----:>

USERNAME :    ADMIN      //All Capital letters

PASSWORD :    vaccine

After entering the password press enter and you will be taken to a menu screen for selecting the country in whose database you'd like to add the entry.

Note - Please be regular in adding the entries for better results.......

After selecting a country you will be shown the last 3 entries in the database to which you can add the new one.

•  You will be asked for the DATE :-> Please enter the date in the format DD.M (for example, 1.4 as in April 1st).

•  The total number of cases on the date of the entry.

• The total number of deaths

• The number of people recovered on that particular day.

You will also be asked if you want to change the input, if not, Thank You for adding to the database......


2) USER LOGIN - 

This will take the user to a country selection screen where you will be asked to choose a country whose data the person wants to access, and then given 3 choices to choose from, which are ----:>


• The inBetween Dates Data:-
    
    You will be asked to enter 2 dates ->
    1) The starting date from which you want to see the data, to
    2) The date till which the data is to be accessed

NOTE ----:>>>>    Please enter the date in the format DD.M (for example, 1.4 as in April 1st).

And result in this following form will be shown->     

    Total cases: 82836    Cases in between: 82265      Deaths: 4616      Recovered: 78747


• The Information Center---:>
    
    In this section, you will be shown the major news headlines for the selected country, like when was the first case appeared or the first death that was recorded etc.
    
• The Growth Tracker --:>
    
    The growth tracker will use the data from the last 7 days and will predict the progression of the virus for the next 15 days...
    
    The model was tested various times, to predict the cases for some past days and checking if the model was precise, and the results were approximately accurate comapared to the results of the tested date.
    

You can press escape key on the keyboard after any of the before mentioned functions and you will be taken to the previous menu, to choose another feature that they want to explore or if the user wishes to Quit the application...

    To Quit from the program press escape on the features menu screen,
    Then the user will be given a warning to check whether if they really want to exit or not
    Press ENTER key on this screen to Quit, and ESC key to stay in the program.


------------------------------------------------------------------------------------------------------------------------------


THINGS WE USED ----------::>

1) To make the menu to navigate through the program, conio.h library functions, such as, gotoxy(); _getch(); getc(); switch() statements etc were used.
2) Data File Handling in C is used to read the data from the countries database that we made, analyse the data, calculate the growth rate of the disease.
3) Linked list is used to store the data which is obtained from the database, and calculate the results which are displayed.
4) A Mathematical algorithm was made by us to find how much growth will happen in the next few days, most accuracy achieved for data prediction within the next 15 days.
5) Stack is used for the prediction of the growth of the virus , basically, to store the previous data and pop the data for the last 7 days for better prediction of data.

        The working of the mathematical function is included in the submission as a pdf file (model_explaination.pdf). 
    
<<<<<<< HEAD
NOTE ->> We highly recommend you to go through the file (model_explaination.pdf) atleast once.    

    Make sure all the following files are included in the same folder as our main.c file ,    Corona.c         -----:>
=======
    Make sure all the following files are included in the same folder as our main.c file ,    main.c         -----:>
>>>>>>> c700805eefca36cb13392b72d53923a00858cccd
    
        1)  add.h
        2)  linked.h
        3)  menu.h
        4)  utilities.h
        5)  india.txt                   //database for Total recordes in India till 9 May
        6)  spain.txt                   //database for Total recordes in Spain till 9 May
        7)  china.txt                   //database for Total recordes in China till 9 May
        8)  italy.txt                   //database for Total recordes in Italy till 9 May
        9)  usa.txt                     //database for Total recordes in USA till 9 May
        10) indiainfo.txt               //Some main Headlines in India
        11) spaininfo.txt               //Some main Headlines in Spain
        12) chinainfo.txt               //Some main Headlines in China
        13) italyinfo.txt               //Some main Headlines in Italy
        14) usainfo.txt                 //Some main Headlines in USA
        


------------------------------------------------------------------------------------------------------------------------------

This project was made by        ----------::>

                                                                                                    
                                    Arihant Jain        -          1910110085                  
                                    Bhaven Jain         -          1910110112                  
                                    Devyansh Sehgal     -          1910110134                  
                                    Sanskar Agarwal     -          1910110352                  
                                    Sarthak Khurana     -          1910110354                  
                                                        
