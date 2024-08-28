#include <bits/stdc++.h>
using namespace std;

/*
Goal: Check whether is it a valid sudoku just check every row, col and box
Intuition: Make use of set data structure to check through every single row, col and boxes

        bool isValidSudoku(vector<vector<char>>& board) {
            
            ios_base :: sync_with_stdio(false);
            cin.tie(nullptr);
            cout.tie(nullptr);
            
            vector<unordered_set<char>> rows(9), cols(9), boxes(9);
            
            for (int i = 0; i < 9; i++)
                for (int j = 0; j < 9; j++) {
                    
                    char val = board[i][j];
                    
                    if (val == '.') continue;
                    
                    int box = i / 3 * 3 + j / 3;
                    
                    // Checking row, col & box
                    if (rows[i].count(val) || cols[j].count(val) || boxes[box].count(val))
                        return false;
                        
                    rows[i].insert(val);
                    cols[j].insert(val);
                    boxes[box].insert(val);
                }
                
            return true;
        }
};