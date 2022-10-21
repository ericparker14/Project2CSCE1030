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

int initialize(int userNum){

    cout << "Initialize the two arrays using this function" << endl;
    return 0;
}
void display(){
    cout << "Fix this function to output disp_array" << endl;
}

int isWrongFormat(string userEmail){
    cout << "this needs to check validity of email and return boolean"<< endl;
    cout << "user email = " << userEmail << endl;
    return 0;
}
const int ROWS = 10;
const int COLUMNS = 10;

int main(){
    bool askAgain = true;
    int aRows;
    int aColumns;
    string email;
    int points = 10;
    int num_array[ROWS][COLUMNS]; // array HIDDEN from user
    int disp_array[ROWS][COLUMNS]; // array SHOWN to users

    // ask for email
    cout << "Enter email address: ";
    getline(cin, email);
    isWrongFormat(email);

    // ask for size of array
    while (askAgain){
        cout << "Enter rows and columns of the matrix: ";
        cin >> aRows >> aColumns;
        if (aRows > ROWS || aColumns > COLUMNS || aRows <=1 || aColumns <=1){
            cout << "Please enter valid rows/columns.";
            askAgain = true;
        }
        else{
            askAgain = false;
        }
    }

    















    return 0;
}
