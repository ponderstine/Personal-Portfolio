/* ********************************************************
        Func. file for the Sudoku Solving program
   ********************************************************
*/ 

#include "SudokuSolver.hpp"


/*
This function takes in the current sudoku board and displays it to the command line for the user.

Inputs: Board (arr of 81 ints)

Returns: None
*/
void showBoard(int board[81]){
    
    // init current index var
    int ind;

    // for every row
    for (int i=0; i<9; i++){

        // every 3 lines print horizontal bar
        if (i%3==0){
            cout << "____________________" << endl;
        }
        
        // for each element in a row
        for (int j=0; j<9; j++){
            // print vertical bars appropriately (after every 3 elements)
            if (j%3==0){
                cout << "|";
            }
            // calculate index and print
            ind = 9*i+j;
            cout << board[ind] << " ";
        }
        // print vertical bar at end of each row
        cout << "|" << endl;
    }
    //print bottom horizontal bar and return
    cout << "____________________" << endl << endl;
    return;
}

/*
This function is the main algorithm to solve the Sudoku. It uses a brute force algorithm of backtracking to solve. (https://en.wikipedia.org/wiki/Sudoku_solving_algorithms)

Inputs: Board (arr of 81 ints)

Returns: None
*/
void bruteForce(int orig[81], int board[81], bool lastCheck){

    //if last check is true then we find the first zero and iterate it to 1
    if (lastCheck){
        //cout << "new num" << endl;
        // iterate through every element
        for (int i=0; i<81; i++){
            // if element is 0 then add 1 and return
            if (board[i]==0){
                board[i]=1;
                return;
            }
        }
    } else {
        //cout << "iterate" << endl;

        //need to find index
            // last index where board[i]!=0 but orig[i]=0
        
            // go to first index where board[i]==0 and orig[i]==0
            // then work backwards to first orig=0 (and board should !=0 inherently)
        int ind;
        bool prev;
        for (ind=0; ind<81; ind++){
            if (orig[ind]==0 && board[ind]==0){
                break;
            } else if (orig[ind]==0 && board[ind]!=0){
                prev=true;
            }
        }

        if (prev && ind != 81){
            for (int j=ind-1; j>=0; j--){
                if (orig[j]==0){
                    ind = j;
                    break;
                }
            }
        } else if (ind == 81){
            ind--;
        }

        while (board[ind]==9){
            board[ind]=1;
            for (int j=ind-1; j>=0; j--){
                if (orig[j]==0){
                    ind = j;
                    break;
                }
            }

        }
        board[ind]++;
    }
    return;
}

/*
This function takes in the current sudoku board and checks it for any errors.

Inputs: Board (arr of 81 ints)

Returns: Bool (true if board has no errors, false if the board has errors)
*/
bool checkBoard(int board[81]){

    // init index and counter array
    int ind;
    int arr[10];

    // check rows
    // for every row
    for (int i=0; i<9; i++){
        
        // rezero counter array
        for (int a=0; a<10; a++){
            arr[a]=0;
        }

        // for every element
        for (int j=0; j<9; j++){

            // add count to array for count of each number
            ind = 9*i+j;
            arr[board[ind]]++;
        }

        // if number (!0) has count >1 then does not pass
        for (int k=1; k<10; k++){

            // if arr[k]>1 then a number was present more than once in a row so the sudoku is not good
            if (arr[k]>1){
                return false;
            }
        }
    }


    // check cols
    // for every col
    for (int i=0; i<9; i++){
        
        // rezero counter array
        for (int a=0; a<10; a++){
            arr[a]=0;
        }

        // for every element
        for (int j=0; j<9; j++){

            // add count to array for count of each number
            ind = 9*j+i;
            arr[board[ind]]++;
        }

        // if number (!0) has count >1 then does not pass
        for (int k=1; k<10; k++){

            // if arr[k]>1 then a number was present more than once in a row so the sudoku is not good
            if (arr[k]>1){
                return false;
            }
        }
    }


    // check boxes
    // for every box (col)
    for (int i=0; i<3; i++){

        // for every box (row)
        for (int j=0; j<3; j++){

            // rezero counter array
            for (int a=0; a<10; a++){
                arr[a]=0;
            }

            // w/in box
            // sort through each element and count occurences of each number
            for (int k=0; k<3; k++){
                for (int L=0; L<3; L++){
                    
                    ind = 27*j+9*L+3*i+k;
                    arr[board[ind]]++;
                    
                }
            }

            // for each box, check if any number occurs more than once
            for (int m=1; m<10; m++){

                // if arr[k]>1 then a number was present more than once in a row so the sudoku is not good
                if (arr[m]>1){
                    return false;
                }
            }
        }
    }
    // if nothing has been bad, then it is all clear
    return true;
}

/*
This function checks if there are any "open" spots (noted by zeros) in the sudoku. The board is "full" when there are no more empty spots.

Inputs: Board (array of 81)

Returns: Bool (true if the board is full, false if the board is not full)
*/
bool isDone(int board[81]){

    // iterate through every element
    for (int i = 0; i<81; i++){

        // if the element is 0 then there is a whole and we can return false
        if (board[i]==0){
            return false;
        }
    }

    // if we have gotten to this point then no elements were zero and the board is full, so return true
    return true;
}