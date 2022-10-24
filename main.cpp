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

int initialize(int newArray[][10], int r=-1){ // default return is -1
    int i;
    if(r == -1){
        for(i = 0; i < ROWS; i++){
            for(int j = 0; j < COLUMNS; j++){
                newArray[i][j] = -1;
            }

        }
    }
    else{
        // initialize num_array
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
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            cout << newArray[i][j] << "\t";
        }
        cout << endl;
    }
}

bool isWrongFormat(string email){
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

int main(){
    bool askAgain = true;
    int column;
    int row;
    string email;
    int num_array[10][10]; // array HIDDEN from user
    int disp_array[10][10]; // array SHOWN to users
    

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
    cout << "Choose coordinates: " ;
    /*
    take in coordinates, then copy location from num_array to
    disp_array. Ask again and check if the same integer matches
    in disp_array.
    */ 















    return 0;
}
