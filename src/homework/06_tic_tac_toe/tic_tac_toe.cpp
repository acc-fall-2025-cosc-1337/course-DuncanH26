//cpp
#include "tic_tac_toe.h"

using strd::cout;

bool TicTacToe::game_over()
{
   if(check_row_win() || check_column_win || check_diagonal_win()){

    set_winner();
    return true;
   } else if (check_board_full()){

    winner = "C";
    return true;

   } else {

    return false;
   }
}

void TicTacToe::start_game(std::string first_player){
    if (first_player == "X" || first_player == "O"){
        player = first_player;
    clear_board();
    } else {

    }

}

 void TicTacToe::mark_board(int position){
    if (position >= 1 && position <= 9 && pegs[position - 1] == " "){
        pegs[position - 1] = player;
        set_next_player();
    } else {
        std::cout << "Invalid position"
    }
 }


 std::string TicTacToe::get_player() const{

    return player;
 }

 void TicTacToe::display_board() const{
    for(int i=0; i < peg.size(); i+=3){

        cout<<pegs[i]<<"|"<<pegs[i+1]<<"|"<<pegs[i+2]<<"\n";


    }


 }

void set_next_player()
{

    if(player == 'X'){
        player = "0";
    }
    else{

        player = "X";
    }

}

bool TicTacToe::check_board_full()
{

    auto full = true;

    for(auto &peg: pegs)
    {
        if(peg == " "){

            full = false;
            break;
        }

    }
    return full;
}

void TicTacToe::clear_board()
{
    for(auto &peg: pegs)
    {
        peg = " ";
    }

}

std::string TicTacToe::get_winner() {
    return winner;
}

bool TicTacToe::check_column_win() {

    return (pegs[0] == pegs[3] && pegs[3] == pegs[6] && pegs[0] != " ") ||
           (pegs[1] == pegs[4] && pegs[4] == pegs[7] && pegs[1] != " ") ||
           (pegs[2] == pegs[5] && pegs[5] == pegs[8] && pegs[2] != " ");
}

bool TicTacToe::check_row_win() {

    return (pegs[0] == pegs[1] && pegs[1] == pegs[2] && pegs[0] != " ") ||
           (pegs[3] == pegs[4] && pegs[4] == pegs[5] && pegs[3] != " ") ||
           (pegs[6] == pegs[7] && pegs[7] == pegs[8] && pegs[6] != " ");
}

bool TicTacToe::check_diagonal_win() {

    return (pegs[0] == pegs[4] && pegs[4] == pegs[8] && pegs[0] != " ") ||
           (pegs[2] == pegs[4] && pegs[4] == pegs[6] && pegs[2] != " ");
}
void TicTacToe::set_winner() {

    if (player == "X") {
        winner = "O";
    } else {
        winner = "X";
    }
}

void TicTacToe::set_next_player(){

    if (player == "X") {
        player = "O";
    } else {
        player = "X";
    }
}


std::ostream& operator<<(std::ostream& out, const TicTacToe& b){

    for(size_t i = 0; i < b.pegs.size(); i += 3){

        out << b.pegs[i] << "" << b.pegs[i + 1] << "" <<b.pegs[i + 2] << "\n"
    }
}
           