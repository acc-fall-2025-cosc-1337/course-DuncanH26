//h
#ifndef TIC_TAC_TOE_MANAGER_H
#define TIC_TAC_TOE_MANAGER_H

#include <vector>
#inlude <string>
#include "tic_tac_toe.h"

class TicTacToeManager {
public:

get_winner_totals(int&, int&, int&): void
save_game(TicTacToe): void
update_winner_account(std::string): void

private:

games: std::vector<TicTacToe>
o_wins: int = {0}
ties: int = {0}
x_wins: int = {0}
}