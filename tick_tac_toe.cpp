#include <iostream>
#include <string>
using namespace std;

 char space[3][3] = {{'0' , '1', '2'} , {'3', '4', '5'} , {'6', '7', '8'}};
 int row;
 int col;
 char token = 'X'; // player 1 is X , player 2 is O
 bool isTie = false;
 string n1 = "";
 string n2 = "";
 int rounds;
 int player1Score;
 int player2Score;

void function1()
{
    // playing grid
     cout<< "   |     |   \n";
     cout<< " "<<space[0][0]<<" |  "<<space[0][1]<<"  | "<<space[0][2]<<"  \n";
     cout<< "___|_____|____\n";
     cout<< "   |     |   \n";
     cout<< " "<<space[1][0]<<" |  "<<space[1][1]<<"  | "<<space[1][2]<<"  \n";
     cout<< "___|_____|____\n";
     cout<< "   |     |   \n";
     cout<< " "<<space[2][0]<<" |  "<<space[2][1]<<"  | "<<space[2][2]<<"  \n";
     cout<< "   |     |   \n";
}

int check1(){
    // check where there is a possibility of completion of triplet
    int targetRowOpp = -1;
    int targetRowAlgo = -1;
    int targetColOpp = -1;
    int targetColAlgo = -1;
    int targetDiagOpp = -1;
    int targetDiagAlgo = -1;

    int countRowX = 0;
    int countRowO = 0;
    for(int i = 0 ; i < 3; i++){
        // check for each row
        countRowX = 0;
        countRowO = 0;
        for(int j = 0 ; j < 3; j++){
        if(space[i][j] == 'X') countRowX++;
        else if(space[i][j] == 'O') countRowO++;
        }
        
        if(countRowX == 2 && countRowO == 0){
            targetRowOpp = i;
        }
        if(countRowX == 0 && countRowO == 2){
            targetRowAlgo = i;
        }
    }

    for(int j = 0 ; j < 3; j++){
        // check for each col
        countRowX = 0;
        countRowO = 0;
        for(int i = 0 ; i < 3; i++){
        if(space[i][j] == 'X') countRowX++;
        if(space[i][j] == 'O') countRowO++;
        }

        if(countRowX == 2 && countRowO == 0){
            targetColOpp = j;
        }  
         if(countRowX == 0 && countRowO == 2){
            targetColAlgo = j;
        }  
    }

    // check for diagonal1
    int i = 0;
    int j = 0;
     int count1 = 0;
     int count2 = 0;
    while(i <= 2 && j <= 2){
        if(space[i][j] == 'X') count1++;
        if(space[i][j] == 'O') count2++;
        i++;
        j++;
    }
    if(count1 == 2 && count2 == 0) targetDiagOpp = 1;
    if(count1 == 0 && count2 == 2) targetDiagAlgo = 1;
   
    // check for diagonal2
     i = 0;
     j = 2;
     count1 = 0;
     count2 = 0;
    while(i <= 2 && j >= 0){
        if(space[i][j] == 'X') count1++;
        if(space[i][j] == 'O') count2++;
        i++;
        j--;
    }
   if(count1 == 2 && count2 == 0) targetDiagOpp = 2;
   if(count1 == 0 && count2 == 2) targetDiagAlgo = 2;

   // first check for the algorithm
   if(targetRowAlgo != -1){
    // a row can be completed
    for(int j = 0 ; j < 3; j++){
        if(space[targetRowAlgo][j] != 'X' && space[targetRowAlgo][j] != 'O') return 3*targetRowAlgo + j;
    }

   }
   else if(targetColAlgo != -1){
    // a col can be completed
        for(int i = 0; i < 3 ; i++){
            if(space[i][targetColAlgo] != 'X' && space[i][targetColAlgo] != 'O') return 3*i + targetColAlgo;
        }

   }

   else if(targetDiagAlgo != -1){
    // a diagonal can be completed
    if(targetDiagAlgo == 1){
        // it's diagonal 1
        int i = 0;
        int j = 0;
        while(i < 3 && j < 3){
            if(space[i][j] != 'X' && space[i][j] != 'O') return 3*i + j;
            i++;
            j++;
        }
    }
    else{
        // it's diagonal 2
        int i = 0;
        int j = 2;
        while(i < 3 && j >= 0){
            if(space[i][j] != 'X' && space[i][j] != 'O') return 3*i + j;
            i++;
            j--;
        }
    }
   }

   else if(targetRowOpp!= -1){
     for(int j = 0 ; j < 3; j++){
        if(space[targetRowOpp][j] != 'X' && space[targetRowOpp][j] != 'O') return 3*targetRowOpp + j;
    }
   }
   else if(targetColOpp != -1){
    for(int i = 0; i < 3 ; i++){
            if(space[i][targetColOpp] != 'X' && space[i][targetColOpp] != 'O') return 3*i + targetColOpp;
        }
   }
   else if(targetDiagOpp != -1){
    // a diagonal can be completed 
    // a diagonal can be completed
    if(targetDiagOpp == 1){
        // it's diagonal 1
        int i = 0;
        int j = 0;
        while(i < 3 && j < 3){
            if(space[i][j] != 'X' && space[i][j] != 'O') return 3*i + j;
            i++;
            j++;
        }
    }

    else{
        // it's diagonal 2
        int i = 0;
        int j = 2;
        while(i < 3 && j >= 0){
            if(space[i][j] != 'X' && space[i][j] != 'O') return 3*i + j;
            i++;
            j--;
        }
    }
   }
   else{
    //
   }
   
    // no such condition exists
    // best place to play?

    //play at a empty spot
    int index = 0;
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            if(space[i][j] != 'X' && space[i][j] != 'O') index = 3*i + j;
        }
    }
    // we will optimize it more  
    return index;
}

void algorithm(){
    int digit = -1;   
    int suggestion = check1();
   if(suggestion != -1) digit = suggestion;
    
    row = digit / 3;
    col = digit % 3;

    if(space[row][col] != 'X' && space[row][col] != 'O' ){
        space[row][col] = 'O';
        token = 'X'; // player 1 chance again
    }
}

void function2()
{
    int digit;
    if(token == 'X'){
        cout<<n1<<"'s"<<" turn";
        cin >>digit;
    }

    if(token == 'O'){
        cout<<n2<<"'s"<<" turn";
        cin >>digit;
    }

    row = digit / 3;
    col = digit % 3;

    if(digit < 0 || digit > 8) {
        cout << "INVALID!!!" << endl;
    }

    if(token == 'X' && space[row][col] != 'X' && space[row][col] != 'O' ){
        space[row][col] = 'X';
        token = 'O'; // player 2 chance
    }
    else if(token == 'O' && space[row][col] != 'X' && space[row][col] != 'O' ){
        space[row][col] = 'O';
        token = 'X'; // player 1 chance
    }
    else{
        // if they enter at a box where already something is there again call the function
        function2();
    }
}

bool checkTie()
{
    // check for the rows
    for(int i = 0 ;i< 3 ;i++){
        int count1 = 0;
        int count2 = 0;
        // for this row
        for(int j = 0 ; j < 3 ; j++){
            if(space[i][j] == 'X') count1++;
            if(space[i][j] == 'O') count2++;
        }
        if(count1 == 0 && count2 == 0) return false;
        else if(count1 > 0 && count2 == 0) return false;
        else if(count1 == 0 && count2 > 0) return false;
    }

    // check for the columns
    for(int j = 0 ;j < 3 ;j++){
         int count1 = 0;
         int count2 = 0;
        // for this col
        for(int i = 0 ; i < 3 ; i++){
            if(space[i][j] == 'X') count1++;
            if(space[i][j] == 'O') count2++;
        }
        if(count1 == 0 && count2 == 0) return false;
        else if(count1 > 0 && count2 == 0) return false;
        else if(count1 == 0 && count2 > 0) return false;
    }

    // check for the diagonal1
    int i = 0;
    int j = 0;
     int count1 = 0;
     int count2 = 0;
    while(i<= 2 && j <=2){
        if(space[i][j] == 'X') count1++;
        if(space[i][j] == 'O') count2++;
        i++;
        j++;
    }
    if(count1 == 0 && count2 == 0) return false;
    else if(count1 > 0 && count2 == 0) return false;
    else if(count1 == 0 && count2 > 0) return false;

    // check for diagonal2
     i = 0;
     j = 2;
     count1 = 0;
     count2 = 0;
    while(i<=2 && j >= 0){
        if(space[i][j] == 'X') count1++;
        if(space[i][j] == 'O') count2++;
        i++;
        j--;
    }
    if(count1 == 0 && count2 == 0) return false;
    else if(count1 > 0 && count2 == 0) return false;
    else if(count1 == 0 && count2 > 0) return false;

    return true; // there is a tie
}

bool function3()
    {
        for(int i = 0; i < 3 ; i++){
            // check for rows and columns
        if((space[i][0] == space[i][1] && space[i][0] == space[i][2])|| (space[0][i] == space[1][i] && space[0][i] == space[2][i])){
                return true; // match found
            }
        }

        if((space[0][0] == space[1][1] && space[1][1] == space[2][2]) || (space[0][2] == space[1][1] && space[1][1] == space[2][0]) ){
            // check for diagonals
            return true; // match found
        }

        // check for early tie
        isTie = checkTie();
        return isTie;
    }

int main(){
    cout << "Enter the name of the first player : \n";
    getline(cin , n1);
    cout << "play against the computer? yes or no \n";
    string x = "";
    cin >> x;
    cin.ignore();

    if(x == "yes") {
    n2 = "algorithm"; // play against an algorithm
    cout<<n1<< " will play X \n";
    cout<<n2<< " will play O \n";
    cout << "No. of Rounds: \n";
    cin >> rounds;
    }
    else{
    cout << "Enter the name of the second player : \n";
    getline(cin , n2);
    cout<<n1<< " will play X \n";
    cout<<n2<< " will play O \n";
    cout << "No. of Rounds: \n";
    cin >> rounds;
    }

    while(rounds > 0){
    while(!function3()){
        function1();
        if(n2 != "algorithm")function2();
        else if(n2 == "algorithm"){
            function2(); // player 1 chance
            if(function3() == true) break; // game over
            algorithm(); // player 2 chance
        }
        function3();
    }

    if(token == 'X' && isTie == false){
        function1();
        player2Score++;
        cout << n2 << " WINS!!" <<endl;
    }
    else if(token == 'O' && isTie == false){
        function1();
        player1Score++;
        cout << n1 << " WINS!!" << endl;
    }
    else{
        function1();
        cout << "It's a Tie" << endl;
    }

    cout << "END OF THIS ROUND!" << endl;
    cout << "Current score is:" << endl;
    cout << n1 << ":" << player1Score << endl;
     cout << n2 << ":" << player2Score << endl;

    cout << endl;
     rounds--;
     if(rounds <= 0) break;
    // cout << "NEXT ROUND BEGINS" << endl;
   
    token = 'X'; // reset
    isTie = false; // reset

    // empty the matrix
    char ch = '0';
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            space[i][j] = ch;
            ch++;
        }
    }

}

if(player1Score > player2Score) {
    cout << n1 << "WINS!!" << endl;
}
else if(player1Score < player2Score){
    cout << n2 << "WINS!" << endl;
}
else{
    cout << "IT'S A TIE" << endl;
}

}

// end of code


