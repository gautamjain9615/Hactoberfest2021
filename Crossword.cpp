#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

#define SIZE 10

bool canPlaceWord(const vector<string>& grid, int row, int col, const string& word, bool isVertical) {
    int len = word.size();
    if (isVertical) {
        if (row + len > SIZE) return false;
        for (int i = 0; i < len; ++i) {
            if (grid[row + i][col] != '-' && grid[row + i][col] != word[i])
                return false; // Conflict
        }
    } else {
        if (col + len > SIZE) return false;
        for (int i = 0; i < len; ++i) {
            if (grid[row][col + i] != '-' && grid[row][col + i] != word[i])
                return false; // Conflict
        }
    }
    return true;
}

void placeWord(vector<string>& grid, int row, int col, const string& word, bool isVertical) {
    int len = word.size();
    for (int i = 0; i < len; ++i) {
        if (isVertical) {
            grid[row + i][col] = word[i];
        } else {
            grid[row][col + i] = word[i];
        }
    }
}

void removeWord(vector<string>& grid, int row, int col, const string& word, bool isVertical) {
    int len = word.size();
    for (int i = 0; i < len; ++i) {
        if (isVertical) {
            grid[row + i][col] = '-';
        } else {
            grid[row][col + i] = '-';
        }
    }
}

bool crosswordSolver(vector<string>& grid, unordered_set<string>& wordsSet, int index) {
    if (index == wordsSet.size()) {
        for (const auto& line : grid) {
            cout << line << endl;
        }
        return true;
    }

    string word = *next(wordsSet.begin(), index);
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (grid[i][j] == '-' || grid[i][j] == word[0]) {
                if (canPlaceWord(grid, i, j, word, true)) {
                    placeWord(grid, i, j, word, true);
                    if (crosswordSolver(grid, wordsSet, index + 1)) return true;
                    removeWord(grid, i, j, word, true);
                }
                if (canPlaceWord(grid, i, j, word, false)) {
                    placeWord(grid, i, j, word, false);
                    if (crosswordSolver(grid, wordsSet, index + 1)) return true;
                    removeWord(grid, i, j, word, false);
                }
            }
        }
    }
    return false;
}

int main() {
    vector<string> grid(SIZE);
    for (int i = 0; i < SIZE; ++i) {
        cin >> grid[i];
    }

    string input;
    cin >> input;
    unordered_set<string> wordsSet;
    size_t pos = 0;
    while ((pos = input.find(';')) != string::npos) {
        wordsSet.insert(input.substr(0, pos));
        input.erase(0, pos + 1);
    }
    wordsSet.insert(input); // Add last word

    crosswordSolver(grid, wordsSet, 0);
    return 0;
}
