#include <iostream>
#include <vector>
#include <cmath>
#include "functions.hpp"

using namespace std;


void print_game_board(vector<vector<int> > board)
{
    int board_size = board.size();
    cout << "\n\t The board:\n";
    for (int i = 0; i < board_size; i++)
    {
        print_row_in_board(board[i]);
        if (i != board_size - 1)
        {
            for (int j = 0; j < board_size; j++)
            {
                cout << "--------";
                if(j != 0)
                    cout << "-";
                cout << "+";
            }
            cout << '\b' << " " << '\b';
            cout << "\n";
        }
        
    }
}

void print_row_in_board(vector<int> row)
{
    int row_size = row.size();
    for (int i = 0; i <= 6; i++)
    {
        for (int j = 0;j < row_size;j++)
        {
            if (row[j] == CIRCLE)
                print_circle_state(i);
            else if (row[j] == CROSS)
                print_cross_state(i);
            else
                cout << "       ";
            if(j != row_size - 1)
                cout << " | ";
        }
        cout << "\n";
        
    }    
}

void print_circle_state(int state)
{
    switch (state)
    {
    case 0:
    case 6:
        cout << "   _   ";
        break;
    case 1:
    case 5:
        cout << "  _ _  ";
        break;
    case 2:
    case 4:
        cout << " _   _ ";
        break;
    case 3:
        cout << "_     _";
        break;
    }
}

void print_cross_state(int state)
{
    switch (state)
    {
    case 0:
        cout << "\\     /";
        break;
    case 1:
        cout << " \\   / ";
        break;
    case 2:
        cout << "  \\ /  ";
        break;
    case 3:
        cout << "   X   ";
        break;
     case 4:
        cout << "  / \\  ";
        break;
    case 5:
        cout << " /   \\ ";
        break;
   case 6:
        cout << "/     \\";
        break;
    }
}



bool check_row_win(vector<vector<int> > board)
{
    int flag_circle = 0, flag_cross = 0;
    for (int i = 0; i < pow(board.size(), 2); i++)
    {
        if (board[i / board.size()][i % board.size()] == CROSS)
            flag_cross++;
        else if (board[i / board.size()][i % board.size()] == CIRCLE)
            flag_circle++;
        else
            return false;
        if (flag_circle == board.size() || flag_cross == board.size())
            return true;
        if (flag_circle + flag_cross >= board.size())
        {
            flag_circle = 0;
            flag_cross = 0;
        }
    }
    return false;
}

bool check_cross_win(vector<vector<int> > board)
{
    int flag_circle = 0, flag_cross = 0, j = 0;
    for (int i = 0; i < board.size(); i++)
    {
        if (board[i][i] == CROSS)
            flag_cross++;
        else if (board[i][i] == CIRCLE)
            flag_circle++;          
    }
    if (flag_circle == board.size() || flag_cross == board.size())
        return true;
    flag_circle = 0;
    flag_cross = 0;
    for (int i = board.size() - 1; i >= 0; i--)
    {
        if (board[i][j] == CROSS)
            flag_cross++;
        else if (board[i][j] == CIRCLE)
            flag_circle++;
        else
            return false;
        j++;
    }
    if (flag_circle == board.size() || flag_cross == board.size())
        return true;
    return false;
}

bool check_col_win(vector<vector<int> > board)
{
    int flag_circle = 0, flag_cross = 0;
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board.size(); j++)
        {
            if (board[j][i] == CROSS)
                flag_cross++;
            else if (board[j][i] == CIRCLE)
                flag_circle++;
            else
                return false;
        }
        if (flag_circle == board.size() || flag_cross == board.size())
            return true;
        flag_circle = 0;
        flag_cross = 0;
    }
    return false;
}


bool check_tie(vector<vector<int> > board)
{
    for (int i = 0; i < pow(board.size(), 2); i++)
    {
        if (board[i / board.size()][i % board.size()] == EMPTY)
            return false;
    }
    return true;
}

void enter_turn(string player_name, int player_charter,vector<vector<int> > &board)
{
    int position[2], number_of_times_choosing = 0;
    string choice;

    do
    {
        if (number_of_times_choosing)
            cout << "This position is taken please try a diffrent one!!!\n";
        cout << player_name << " Enter position to put your charter:";
        cin >> choice;

        position[ROW] = atoi(&choice[0]) - 1;
        position[COLEM] = atoi(&choice[2]) - 1;

        if ((position[ROW] >= board.size() && position[ROW] <= 0) || (position[COLEM] >= board.size() && position[COLEM] <= 0))
            cout << "Bad input the postion given is out of board size!!!" << endl;
        number_of_times_choosing++;
    } while (board[position[ROW]][position[COLEM]] != EMPTY);
    
    board[position[ROW]][position[COLEM]] = player_charter;
}
