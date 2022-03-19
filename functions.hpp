#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int CROSS = 2;
const int CIRCLE = 1;
const int EMPTY = 0;

const int ROW = 0;
const int COLEM = 1;

void print_game_board(vector<vector<int> > board);

void print_row_in_board(vector<int> row);

void print_circle_state(int state);

void print_cross_state(int state);

void enter_turn(string player_name, int player_charter, vector<vector<int> > &board);

bool check_row_win(vector<vector<int> > board);
bool check_cross_win(vector<vector<int> > board);
bool check_col_win(vector<vector<int> > board);

bool check_tie(vector<vector<int> > board);

inline
bool check_win(vector<vector<int> > board) 
{
	return check_row_win(board) || check_cross_win(board) || check_col_win(board);
}

