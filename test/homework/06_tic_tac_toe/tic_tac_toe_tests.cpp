#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test is game over with a vector that has 9 pegs with value of space"){

	TicTacToe tic_tac_toe;

	REQUIRE(false == tic_tac_toe.game_over());
}

TEST_CASE("Test is first player set correctly when starting the game"){

	TicTacToe tic_tac_toe;
	tic_tac_toe.start_game("x");

	REQUIRE(tic_tac_toe.get_player() == "X");
}

TEST_CASE("Test if board is full - game over "){

	TicTacToe tic_tac_toe;
	tic_tac_toe.start_game("X");
  REQUIRE(tic_tac_toe.get_player() == "X");

  tic_tac_toe.mark_board(1);
  REQUIRE(tic_tac_toe.get_player() == "O");
  REQUIRE(false == tic_tac_toe.game_over());

  tic_tac_toe.mark_board(2);
  REQUIRE(tic_tac_toe.get_player() == "X");
  REQUIRE(false == tic_tac_toe.game_over());

  tic_tac_toe.mark_board(3);
  REQUIRE(tic_tac_toe.get_player() == "O");
  REQUIRE(false == tic_tac_toe.game_over());

  tic_tac_toe.mark_board(6);
  REQUIRE(tic_tac_toe.get_player() == "X");
  REQUIRE(false == tic_tac_toe.game_over());

  tic_tac_toe.mark_board(4);
  REQUIRE(tic_tac_toe.get_player() == "O");
  REQUIRE(false == tic_tac_toe.game_over());

  tic_tac_toe.mark_board(7);
  REQUIRE(tic_tac_toe.get_player() == "X");
  REQUIRE(false == tic_tac_toe.game_over());

  tic_tac_toe.mark_board(5);
  REQUIRE(tic_tac_toe.get_player() == "O");
  REQUIRE(false == tic_tac_toe.game_over());

  tic_tac_toe.mark_board(9);
  REQUIRE(tic_tac_toe.get_player() == "X");
  REQUIRE(false == tic_tac_toe.game_over());

  tic_tac_toe.mark_board(8);
  REQUIRE(tic_tac_toe.get_player() == "O");
  REQUIRE(true == tic_tac_toe.game_over());



}

TEST_CASE("Test game over if all 9 slots are full"){

  TicTacToe game;
  game.start_game("X");
  game.mark_board(1); REQUIRE_FALSE(game.game_over());
  game.mark_board(); REQUIRE_FALSE(game.game_over());
  game.mark_board(); REQUIRE_FALSE(game.game_over());
  game.mark_board(); REQUIRE_FALSE(game.game_over());
  game.mark_board(); REQUIRE_FALSE(game.game_over());
  game.mark_board(); REQUIRE_FALSE(game.game_over());
  game.mark_board(); REQUIRE_FALSE(game.game_over());
  game.mark_board(8); REQUIRE(game.game_over()); 
    REQUIRE(game.get_winner() == "C");
}

TEST_CASE("Test win by first column") {
    TicTacToe game;
    game.start_game("X");
    game.mark_board(1); REQUIRE_FALSE(game.game_over());
    game.mark_board(2); REQUIRE_FALSE(game.game_over());
    game.mark_board(4); REQUIRE_FALSE(game.game_over());
    game.mark_board(3); REQUIRE_FALSE(game.game_over());
    game.mark_board(7); REQUIRE(game.game_over());
    REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win by first column"){
 TicTacToe game;
    game.start_game("X");
    game.mark_board(1); REQUIRE_FALSE(game.game_over());
    game.mark_board(2); REQUIRE_FALSE(game.game_over());
    game.mark_board(4); REQUIRE_FALSE(game.game_over());
    game.mark_board(3); REQUIRE_FALSE(game.game_over());
    game.mark_board(7); REQUIRE(game.game_over());
    REQUIRE(game.get_winner() == "X");
}



  TEST_CASE("Test win by second column") {
    TicTacToe game;
    game.start_game("X");
    game.mark_board(2); REQUIRE_FALSE(game.game_over());
    game.mark_board(1); REQUIRE_FALSE(game.game_over());
    game.mark_board(5); REQUIRE_FALSE(game.game_over());
    game.mark_board(3); REQUIRE_FALSE(game.game_over());
    game.mark_board(8); REQUIRE(game.game_over());
    REQUIRE(game.get_winner() == "X");
}

TEST_CASE ("Test win by third column"){

   TicTacToe game;
    game.start_game("X");
    game.mark_board(3); REQUIRE_FALSE(game.game_over());
    game.mark_board(1); REQUIRE_FALSE(game.game_over());
    game.mark_board(6); REQUIRE_FALSE(game.game_over());
    game.mark_board(2); REQUIRE_FALSE(game.game_over());
    game.mark_board(9); REQUIRE(game.game_over());
    REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win by first row"){
  TicTacToe game;
  game.start_game("X");
  game.mark_board(1); REQUIRE_FALSE(game.game_over());
  game.mark_board(4); REQUIRE_FALSE(game.game_over());
  game.mark_board(2); REQUIRE_FALSE(game.game_over());
  game.mark_board(5); REQUIRE_FALSE(game.game_over());
  game.mark_board(3); REQUIRE_FALSE(game.game_over());
  REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win by second row"){
  TicTacToe game;
  game.start_game("X");
  game.mark_board(4); REQUIRE_FALSE(game.game_over());
  game.mark_board(1); REQUIRE_FALSE(game.game_over());
  game.mark_board(5); REQUIRE_FALSE(game.game_over());
  game.mark_board(2); REQUIRE_FALSE(game.game_over());
  game.mark_board(6); REQUIRE_FALSE(game.game_over());
  REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win by third row"){
  TicTacToe game;
  game.start_game("X");
  game.mark_board(7); REQUIRE_FALSE(game.game_over());
  game.mark_board(1); REQUIRE_FALSE(game.game_over());
  game.mark_board(8); REQUIRE_FALSE(game.game_over());
  game.mark_board(2); REQUIRE_FALSE(game.game_over());
  game.mark_board(9); REQUIRE_FALSE(game.game_over());
  REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win diagonally from top left"){
  TicTacToe game;
  game.start_game("X");
  game.mark_board(1); REQUIRE_FALSE(game.game_over());
  game.mark_board(2); REQUIRE_FALSE(game.game_over());
  game.mark_board(5); REQUIRE_FALSE(game.game_over());
  game.mark_board(3); REQUIRE_FALSE(game.game_over());
  game.mark_board(9); REQUIRE_FALSE(game.game_over());
  REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win diagonally from bottom left"){
  TicTacToe game;
  game.start_game("X");
  game.mark_board(7); REQUIRE_FALSE(game.game_over());
  game.mark_board(1); REQUIRE_FALSE(game.game_over());
  game.mark_board(5); REQUIRE_FALSE(game.game_over());
  game.mark_board(2); REQUIRE_FALSE(game.game_over());
  game.mark_board(3); REQUIRE_FALSE(game.game_over());
  REQUIRE(game.get_winner() == "X");
}


