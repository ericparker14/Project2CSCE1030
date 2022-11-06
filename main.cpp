/* Authors: ac1414
 *          ame0205 - Amanda English (amandaenglish3@my.unt.edu)
 *          etp0040
 * Date: 10/21/2022
 * Instructor: Dr. Pradhumna Shrestha
 * Description: Recieves input from user for the size of the array and also for their email address. After this both the hidden
 *              and shown arrays are initialized and the user is to then reveal a number by entering a coordinate. Then, the us
 *              er is asked to guess for a match with the remaining coordinates. If they are correct they get two more points  
 *              and continue revealing and guessing other coordinates. If they want to quit or run out of points their points
 *              are displaying along with a message saying that they will me emailed their score.
 */
#include <iostream>
#include <cmath>
using namespace std;

const int ROWS = 10;
const int COLUMNS = 10;
int rowCount = 0;
int colCount = 0;



int initialize(int newArray[][10], int r=-1){ // default return is -1
/* Function: initialize
 * Parameters: array[][] and int
 * Return: no return
 * Description: This function puts elements into array, disp_array and num_array. Checks if the array the default value is being overwritten 
 * or if its not(if not all elements will be -1) and then the elements inputed are random numbers between 1 to 20 . 
 */
    int i;
    if(r == -1){ //all elements are made to -1
        for(i = 0; i < ROWS; i++){
            for(int j = 0; j < COLUMNS; j++){
                newArray[i][j] = -1;
            }

        }
    }
    else{
        // initialize num_array with numbers between 1 and 20
        for(int i = 0; i < ROWS; i++){
            for(int j = 0; j < COLUMNS; j++){
                newArray[i][j] = 1 + (rand() % 20);
            }
        }
    }
    // cout hidden array
    return 0;
}
void display(int newArray[][10], int rows = 10, int columns = 10){
/* Function: display
 * Parameters: array[][], int rows, int columns
 * Return: no return
 * Description: Displays the array[][] of choice 
 */

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            cout << newArray[i][j] << "\t";
        }
        cout << endl;
    }
}

bool isWrongFormat(string email){
 /* Function: isWrongFormat
 * Parameters: string
 * Return: bool
 * Description: Checks if the email is the correct format and the '@' and '.' are in the correct place 
 */

    // need to check that the @ is before the .
    srand(time(NULL));
    int atCount = 0;
    int dotCount = 0;
    char dot = '.';
    char at = '@';
    int atIndex = 0;
    int dotIndex = 0;
    bool needFixed = false;
    for (int i = 0; i < email.size(); i++) // loop through each character in string
    {
        atIndex = email.find_first_of('@');
        dotIndex = email.find_first_of('.');
        if (atIndex == dotIndex - 1){
            cout << "There needs to be a character after the @" << endl;
            return true;
        }
        if(dotIndex < atIndex){
            return true;
        }

        if(email.at(i) == at){
            atCount ++;
        }
        if (email.at(i) == dot){
            dotCount ++;
        }
    }
    if (atCount > 1 || dotCount > 1){ // makes sure theres only one dot and one @
        cout << "There are too many '.'s or '@'s in the email?" << endl;
        return true;
    }
    else if( atCount == 0 || dotCount == 0){ // if there are no '.' or '@'
        return true;
    }
    else{
        return false;
    }
}

bool CheckRepeat(int disp_array[][COLUMNS], int num_array[][COLUMNS], int rowCheck, int colCheck){
/* Function: CheckRepeat
 * Parameters: 2 array[][], user guess row and column
 * Return: bool
 * Description: Checks to ensure that the revealed number is not repeated. 
 */

bool match = false;

	if(disp_array[rowCheck][colCheck] == num_array[rowCheck][colCheck]){
	match = true;
	}
return match;
}


int main(){
/* Function: main
 * Parameters: none
 * Return: 0
 * Description: Is the main function that calls all the other functions. This is a guessing game where a number is revealed in an
 * array (the coordinates that are revealed are checked to ensure that the same coordinates are not checked and entered) and user is asked
 * to guess where else this number could be in the array. If correct the number is revealed in the displayed array and the user gains 2 points.
 * if incorrect the user loses a point and is asked to continue playing. This continues until user exits or points hit 0.
 */

    bool askAgain = true;
    int column;
    int row;
    int rowCord, rowGuess;
    int colCord, colGuess;
    char cont;
    
    int check_array[50][2];
    string email;
    int num_array[ROWS][COLUMNS]; // array HIDDEN from user
    int disp_array[ROWS][COLUMNS]; // array SHOWN to users
    

    // ask for email
    do{
        cout << "Enter a valid email:";
        getline(cin, email);
    }while(isWrongFormat(email));

    // ask for size of array

    do{

        cout << "Enter rows and columns of the matrix: ";
        cin >> column >> row;
        if (column > ROWS || row > COLUMNS || row <=1 || column <=1){
            askAgain = true;
        }
        else{
            askAgain = false;
        }
    }while(askAgain);
    initialize(num_array, 2);
    initialize(disp_array, -1);
    display(disp_array, row, column);
    int points = 10;

    do{    

    cout << "Choose coordinates to reveal: " ;
    /*
    take in coordinates, then copy location from num_array to
    disp_array. Ask again and check if the same integer matches
    in disp_array.
    */ 
    cin >> rowCord >> colCord;

    while (CheckRepeat(disp_array, num_array, rowCord,colCord)){
    cout << "Invalid coordinates.\nPlease guess coordinates you have not guessed yet: ";
    cin >> rowCord >> colCord;
    }
  

    disp_array[rowCord][colCord] = num_array[rowCord][colCord];
    display(disp_array, row, column); // shows updated array
    // ask for input to match  
    cout << "Choose coordinates for guess: ";
    cin >> rowGuess >> colGuess;
    if(num_array[rowGuess][colGuess] == num_array[rowCord][colCord]){
	disp_array[rowGuess][colGuess] = num_array[rowCord][colCord];
	points = points + 2;
	cout << "It's a match! Good job!\nPoints left: " << points << endl;
	//display(disp_array);

    }
    else{
	points--;
	cout << "It's not a match.\nPoints left: " << points << endl;
    }


    
    cout << "Do you wish to continue(y/n)? ";
    cin >> cont;
    cont = tolower(cont);
}while((cont == 'y')||(points == 0));//Checks if user wishes to continue
if(points == 0){// game exits due to 0 points
cout << "No more points left. GameOver!\n";
}
cout << "Remaining points: " << points << ".\nYour results will be emailed to " << email << endl;
cout << "Goodbye...\n";



    return 0;
}
