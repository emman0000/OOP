//Programmer Emman Abrar Ali 23k0051 Assignment Task3
#include<iostream>
#include<vector>
#include<string>
using namespace std;
//tricky question 
//Keep it simple break down the chess board and its components into classes.
//Two main classes are the board and the chess piece. //Then each class will have its display methods and the chess class includes a move chess pieces method.

 //representaion of chess board in 2-D for essentially 
//representing the 8x8 grid using vector because it is a dynamic array.(and very easy to use)
//vector is 2D and uses pointer to access the chess pieces within the board.
//class for chess pieces 
class Piece {
    string type; string color;char symbol;  
public:
    Piece(string t, string c, char s) : type(t), color(c), symbol(s) {}
    char getSymbol() const { return symbol; }
};//end class
//class for board
class Board {
    vector<vector<Piece*>> board; //pointer to access the chess pieces within the board.
public:
    Board() {
        board.resize(8, vector<Piece*>(8, nullptr)); //using null pointer here allows us to check the space if it is empty or not 
//Initialisation of all chess pieces within the board
        // Initializing the pawns
        for(int i = 0; i < 8; i++) {
            board[1][i] = new Piece("Pawn", "W", 'P');
            board[6][i] = new Piece("Pawn", "B", 'p');
        }//end for loop

        // Initializing other pieces
        // Black pieces
        board[7][0] = new Piece("Rook", "B", 'R');
        board[7][7] = new Piece("Rook", "B", 'R');
        board[7][1] = new Piece("Knight", "B", 'N');
        board[7][6] = new Piece("Knight", "B", 'N');
        board[7][2] = new Piece("Bishop", "B", 'B');
        board[7][5] = new Piece("Bishop", "B", 'B');
        board[7][3] = new Piece("Queen", "B", 'Q');
        board[7][4] = new Piece("King", "B", 'K');

        // White pieces
        board[0][0] = new Piece("Rook", "W", 'r');
        board[0][7] = new Piece("Rook", "W", 'r');
        board[0][1] = new Piece("Knight", "W", 'n');
        board[0][6] = new Piece("Knight", "W", 'n');
        board[0][2] = new Piece("Bishop", "W", 'b');
        board[0][5] = new Piece("Bishop", "W", 'b');
        board[0][3] = new Piece("Queen", "W", 'q');
        board[0][4] = new Piece("King", "W", 'k');
    }
//function that will display the board and all co-ordinates
    void display() {
        // Display column letters at the top
        cout << "  a b c d e f g h" << endl;  cout << " +----------------" << endl;
        for (int i = 0; i < 8; i++) {
            cout << 8 - i << "|";
            for (int j = 0; j < 8; j++) {
                cout << " ";
                if (board[i][j] != nullptr) //printing the letter for each piece by crosschecking against the null pointer 
                    cout << board[i][j]->getSymbol();
                else
                    cout << ".";
            }
            cout << " |" << 8 - i << endl;
        }//end for loop

        cout << " +----------------" << endl;
        // Display column letters at the bottom
        cout << "  a b c d e f g h" << endl;
    }//end display function 

//function that includes all moves on the chess board including eliminating oponents pieces.
//does not include any checkmate strategy I don't know how to do that yet 
    bool moveit_moveit(string source, string destination) {
  //co-ordinate representation 
        int srcRow = 8 - (source[1] - '0');
        int srcCol = source[0] - 'a';
        int destRow = 8 - (destination[1] - '0');
        int destCol = destination[0] - 'a';
//validity of the move
        if (srcRow < 0 || srcRow > 7 || srcCol < 0 || srcCol > 7 ||
            destRow < 0 || destRow > 7 || destCol < 0 || destCol > 7) {
            cout << "Invalid move cannot be played" << endl;
            return false;
        }//end if condition here 

        if (board[srcRow][srcCol] == nullptr) {
            cout << "Invalid move no piece present at co-ordinates" << endl;
            return false;
        }

        // Moving pieces 
        delete board[destRow][destCol]; // Delete the piece at the destination if it exists
        board[destRow][destCol] = board[srcRow][srcCol];
        board[srcRow][srcCol] = nullptr;
        return true;
    }//end moveit_moveit function
};//end class Board

int main() {
  cout<<"Emman Abrar Ali 23k0051"<<endl;
    Board ChessBoard;
    // Display initial board
    ChessBoard.display();

    // Tests
    cout << (ChessBoard.moveit_moveit("g2", "g4") ? "Valid move" : "Invalid move") << endl;
    ChessBoard.display();
    cout<<(ChessBoard.moveit_moveit("f2","f4") ? "Valid move" : "Invalid move") << endl;
    ChessBoard.display();
    cout<<(ChessBoard.moveit_moveit("b2","c4") ? "Valid move" : "Invalid move") << endl;
    ChessBoard.display();
    cout<<(ChessBoard.moveit_moveit("c3","d5") ? "Valid move" : "Invalid move") << endl;
    ChessBoard.display();

    return 0;
}//end main 

