#include <array>
#include <fstream>
using namespace std;

bool check_individual_wins(char c, array<array<char, 3>, 3> &board) {
  // check diags
  if (board[0][0] == c && board[1][1] == c && board[2][2] == c) {
    return true;
  }

  if (board[0][2] == c && board[1][1] == c && board[2][0] == c) {
    return true;
  }

  for (int i = 0; i < 3; i++) {
    // check row
    if (board[i][0] == c && board[i][1] == c && board[i][2] == c) {
      return true;
    }
    // check col
    if (board[0][i] == c && board[1][i] == c && board[2][i] == c) {
      return true;
    }
  }

  return false;
}

bool check3(char c1, char c2, char a, char b, char c) {
  if (a != c1 && a != c2)
    return false;
  if (b != c1 && b != c2)
    return false;
  if (c != c1 && c != c2)
    return false;

  if (c1 != a && c1 != b && c1 != c)
    return false;
  if (c2 != a && c2 != b && c2 != c)
    return false;

  return true;
}

bool check_team_wins(char c1, char c2, array<array<char, 3>, 3> &board) {
  // check diags
  if (check3(c1, c2, board[0][0], board[1][1], board[2][2])) {
    return true;
  }

  if (check3(c1, c2, board[0][2], board[1][1], board[2][0])) {
    return true;
  }

  for (int i = 0; i < 3; i++) {
    // check row
    if (check3(c1, c2, board[i][0], board[i][1], board[i][2])) {
      return true;
    }
    // check col
    if (check3(c1, c2, board[0][i], board[1][i], board[2][i])) {
      return true;
    }
  }

  return false;
}

int main() {
  ifstream fin("tttt.in");
  ofstream fout("tttt.out");
  array<array<char, 3>, 3> board;
  string input;

  for (int i = 0; i < 3; i++) {
    fin >> input;
    board[i][0] = input[0];
    board[i][1] = input[1];
    board[i][2] = input[2];
    input.clear();
  }

  int individual_wins = 0, team_wins = 0;

  // 1) # of individual cows that won
  for (char c = 'A'; c <= 'Z'; c++) {
    if (check_individual_wins(c, board)) {
      individual_wins++;
    }
  }
  // 2) # of team cows that won
  for (char c1 = 'A'; c1 <= 'Z'; c1++) {
    for (char c2 = c1 + 1; c2 <= 'Z'; c2++) {
      if (check_team_wins(c1, c2, board)) {
        team_wins++;
      }
    }
  }

  fout << individual_wins << '\n' << team_wins << '\n';

  return 0;
}
