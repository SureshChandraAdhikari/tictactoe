#include <iostream>
using namespace std;

char space[3][3] = {{'1','2','3'}, {'4','5','6'}, {'7','8','9'}};
int row, col;
char token = 'X';
bool tie = false;
string n1, n2;

void displayBoard() {
    cout << "   |     |    \n";
    cout << " " << space[0][0] << " | " << space[0][1] << "   | " << space[0][2] << " \n";
    cout << "___|_____|____\n";
    cout << "   |     |    \n";
    cout << " " << space[1][0] << " | " << space[1][1] << "   | " << space[1][2] << " \n";
    cout << "___|_____|____\n";
    cout << "   |     |    \n";
    cout << " " << space[2][0] << " | " << space[2][1] << "   | " << space[2][2] << " \n";
    cout << "   |     |    \n";
}

void functionOne() {
    cout << "Enter The Name of Player1: \n";
    getline(cin, n1);
    cout << "Enter The Name of Player2: \n";
    getline(cin, n2);

    cout << n1 << " is Player1 so he/she will play first\n";
    cout << n2 << " is Player2 so he/she will play second\n";

    displayBoard();
}

void functionTwo() {
    int digit;
    if(token == 'X') {
        cout << n1 << ", please enter: ";
    } else {
        cout << n2 << ", please enter: ";
    }
    cin >> digit;

    if(digit >= 1 && digit <= 9) {
        row = (digit - 1) / 3;
        col = (digit - 1) % 3;

        if(space[row][col] != 'X' && space[row][col] != '0') {
            space[row][col] = token;
            token = (token == 'X') ? '0' : 'X';
        } else {
            cout << "Space is occupied, try again!\n";
            functionTwo();
        }
    } else {
        cout << "Invalid input, try again!\n";
        functionTwo();
    }

    displayBoard();
}

bool functionThree() {
    for(int i = 0; i < 3; i++) {
        if(space[i][0] == space[i][1] && space[i][0] == space[i][2]) return true;
        if(space[0][i] == space[1][i] && space[0][i] == space[2][i]) return true;
    }
    if(space[0][0] == space[1][1] && space[0][0] == space[2][2]) return true;
    if(space[0][2] == space[1][1] && space[0][2] == space[2][0]) return true;

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(space[i][j] != 'X' && space[i][j] != '0') return false;
        }
    }

    tie = true;
    return false;
}

int main() {
    functionOne();

    while(!functionThree()) {
        functionTwo();
    }

    if(token == 'X' && !tie) {
        cout << n2 << " wins!!\n";
    } else if(token == '0' && !tie) {
        cout << n1 << " wins!!\n";
    } else {
        cout << "It's a draw!!\n";
    }

    return 0;
}
