# Covid-19 Tracker
 DS Project 

We have made a Corona Virus Progression program, which shows the progress of the virus in 5 countries-:

1) India
2) Italy
3) USA
4) Spain
5) China

This program Excessively uses Linked list, file handling, the knowledge of the conio.h library etc. We have also used a exponential growth algorithm to determine the growth of the virus for the upcoming days.

Make sure to include all the .h and .txt files in the same folder as the .c file.

After running the program you will be see a welcome screen with 2 options 

1) Server side login
2) User login

1) THE SERVER SIDE
This is the program which can be used to add new entries to the existing databse..... 
In the server side login, you will be taken to a login screen where you have to use the given credentials -----:>

USERNAME :    admin
PASSWORD :    vaccine

After entering the password press enter and you will be taken to a menu screen for selecting the country in whose database you'd like to add the entry.

Note - Please be regular in adding the entries for better results.......

After selecting a country you will be shown the last 3 entries in the database to which you can add the new one.

•  You will be asked for the DATE :-> Please enter the date in the format DD.M (for example, 1.4 as in April 1st).

•  The total number of cases on the date of the entry.

• The total number of deaths

• The number of people recovered on that particular day.

You will also be asked if you want to change the input, if not, Thank You for adding to the database......


2) USER LOGIN
This will take the user to a country selection screen where you will be asked to choose a country whose data the person wants to access, and then given 3 choices to choose from, which are ----:>


• The inBetween Dates Data:-
    
    You will be asked to enter 2 dates ->
    1) The starting date from which you want to see the data, to
    2) The date till which the data is to be accessed

NOTE ----:>>>>    Please enter the date in the format DD.M (for example, 1.4 as in April 1st).

And result in this following form will be shown->     

    Total cases: 82836    Cases in between: 82265      Deaths: 4616      Recovered: 78747


• The information Center---:>
    
    In this section, you will be shown the major news headlines for the selected country, like when was the first case appeared or the first death that was recorded etc.
    
• The Growth Tracker --:>
    
    The growth tracker will use the data from the last 7 days and will predict the progression of the virus for the next 15 days...
    The model was tested various times, to predict the cases for some past days and checking if the model was precise, and the results were approximately accurate comapared to the results of the tested date.
    
