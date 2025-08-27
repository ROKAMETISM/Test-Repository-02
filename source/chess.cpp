#include <iostream>
using namespace std;

class Chess;
class Piece;

class Piece {
    private:
        int x, y; //x = file, y = rank
        bool is_white; //true = white, false = black
    public:
        Piece(int file, int rank, bool color) : x(file), y(rank), is_white(color) {};
        bool isWhite() {return is_white;};
        bool isBlack() {return !is_white;};
        char getFile() { return char(x + 'a' - 1); };
        int getRank() { return y; };
        void printPosition();
        void printColor() { cout << (is_white ? "White" : "Black") << endl; };
};

class Chess {
    private:
        Piece board[8][8];
        bool white_to_move; //true = white to move, false = black to move
    public:
        Chess();
        void initBoard();
        void printBoard();
};



int main() {
    string user_input;
    cout << "Input List : (q = quit) (i = initialize board)" << endl;
    cin >> user_input;
    Piece p(1, 2, true), p2(3, 4, false);
    p.printPosition();
    p2.printPosition();
    cout << p.isBlack() << " , " << p2.isWhite() << endl;
    return 0;   
}


void Piece::printPosition() {
    cout << "Piece Position -> " << getFile() << getRank() << endl; 
    cout << "File: " << getFile() << " Rank: " << getRank() << endl;
    return;
}