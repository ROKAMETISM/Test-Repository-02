#include <iostream>
using namespace std;

class Chess {
    private:
        
    public:
        void init_board();
        void print_board();
};

class Piece {
    private:
        int x, y; //x = file, y = rank
        bool is_white; //true = white, false = black
        int piece_type; //0=pawn, 1=king, 2=queen, 3=bishop, 4=knight, 5=rook
    public:
        Piece(int x, int y, bool is_white, int piece_type);
        bool isWhite();
        bool isBlack();

};

int main() {
    string user_input;
    cout << "Input List : (q = quit) (i = initialize board)" << endl;
    cin >> user_input;
    return 0;   
}