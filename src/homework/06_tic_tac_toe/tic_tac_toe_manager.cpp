//cpp
#include "tic_tac_toe_manager.h"
#include <iostream>

void TicTacToeManager::save_game(TicTacToe b){

    games.push_back(b);
    update_winner_count(b.get_winner());
}

void TicTacToeManager::get_winner_total(int& x, int& o, int& t){

    x = x_win;
    o = o_win;
    t = ties;
}

void TicTacToeManager::update_winner_count(std::string winner){

    if (winner == "X"){
        x_win++;
    } else if (winner == "O"){
        o_win++;
    } else {
        ties++;
    }
}

std::ostream& operator<<(std::ostream& out, const TicTacToe& b){

    out <<  "\nGame History:\n";
    for (const auto& game : manager.games) {

         out << game << "\n";
    }

    return out;
}

std::istream