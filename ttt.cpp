#include <iostream>
#include <vector>
#include "functions.hpp"

using namespace std;

int main()
{
	vector<vector<int> > game_board;
	string player1_name, player2_name;
	char play_again = 'n';
	int board_size, flag = 0;


	cout << "Welcome to Tic Tac Toe!!\n";
	cout << "This Game is for two players\n";
	cout << "Each player needs to get a row, across or column\n";
	cout << "To place your choice in the position you like, enter the box number in the order of row first and then column separated by :\n";
	cout << "For example if player 1 wants to put x in the 2 row but on the 1 column he will place his choice by entering 2:1\n";
	cout << "After each round ​the board will be printed\n";
	cout << "Let's start the fun!!!\n";

	cout << "Enter palyer 1 name (X):";
	cin >> player1_name;

	cout << "Enter palyer 2 name (0):";
	cin >> player2_name;

	cout << "Enter board size:";
	cin >> board_size;

	do
	{
		game_board = vector<vector<int>>(board_size, vector<int>(board_size, EMPTY));



		do
		{
			print_game_board(game_board);
			flag % 2 == 0 ? enter_turn(player1_name, CROSS, game_board) : enter_turn(player2_name, CIRCLE, game_board);

			flag++;
		} while (!check_win(game_board) && !check_tie(game_board));

		print_game_board(game_board);

		if (!check_tie(game_board))
		{
			flag--;
			cout << "Congratulation ";
			cout << (flag % 2 == 0 ? player1_name : player2_name) << " you WON!!!!!!!!!\n";
		}
		else
			cout << "Same times there is no winners only losers!!!\n";
		cout << "Do you want to play again? (y / n)? ";
		cin >> play_again;
	} while (play_again == 'y');
	return 0;
}
