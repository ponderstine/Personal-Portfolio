#include "SudokuSolver.hpp"

/*
Main driver function for the sudoku solver program. Created October 9th, 2020 by Ponder Stine.
*/
int main(int argc, char* argv[]){

    // check command line (CL) arguments for proper program call, else throw an error
    if (argc!=2){
        cout << "Err: program call should be <executible name> <Input data file>" << endl;
        return -1;
    }
    
    // open the input data file
    string filename=argv[1];
    ifstream in_file;
    in_file.open(filename);

    // if input file does not open properly, throw error
    if (!in_file.is_open()){
        cout << "Err: could not open the input data file" << endl;
        return -1;
    }

    // init vars for parsing
    string line1;
    string line3;
    int board[81];
    int orig[81];
    int i=0;

    // parse through
    //for every line (in input file)
    while (getline(in_file,line1,'\n')){
        stringstream line2(line1);
        //for every char (in line in input file)
        while (getline(line2, line3, ' ')){
            // convert string to int and store in orig and board array, iterate count
            board[i]=stoi(line3);
            orig[i]=stoi(line3);
            i++;
        }
    }

    // display starting board
    cout << "Starting board:" << endl;
    showBoard(board);

    // check if starting board is kosher
    bool check1 = checkBoard(board);

    // if starting board has conflicting points, throw error
    if (!check1){
        cout << "Err: The input data file has errors in it." << endl;
        return -1;
    }

    // start solving, init vars for solve loop
    cout << "Solving with brute force..." << endl << endl;
    bool check2=false;
    int j=0;

    // while puzzle is not done (check2)
    while (!check2){
        // iterate loop count
        j++;

        // run alg to iterate 1 digit up one
        bruteForce(orig, board, check1);

        // check if board has conflicting numbers
        check1 = checkBoard(board);

        // if no conflicting numbers, check if board is done (aka no more zeros)
        if (check1){
            check2 = isDone(board);
        }

        // every 1 mil loops print the board to CL
        if (j%1000000==0){
            cout << "Board after " << j << " loops:" << endl;
            showBoard(board);
        }
    }
    
    // alg finished, display results
    cout << "Finished board:" << endl;
    showBoard(board);
    cout << "Solved puzzle in " << j << " loops." << endl;

    return 0;
}