#include <iostream>
#include <string>
#include <vector>
using namespace std;
void printMessage(string message, bool printTop = true, bool printBottom = true) {
    // top border
    if(printTop) {
        cout << "+---------------------------------+" << endl;
        cout << "|";
    }else {
        cout << "|";
    }

    bool front = true;
    for(int i = message.length(); i < 33; i++) {
        // moving the message/word guessed to the middle
        if(front) {
            message = " " + message;
        } else {
            message = message + " ";
        }
        front = !front;
    }
    cout << message.c_str();

    // bottom border
    if(printBottom) {
        cout << "|" << endl; // this gets pushed to the right because of the message printed
        cout << "+---------------------------------+" << endl;
    }else {
        cout << "|" << endl;
    }
}

void drawHangman(int guessCount = 0) {
    if (guessCount >= 1)
        printMessage("|", false, false);
    else
    if (guessCount >= 2)
        printMessage("|", false, false);
    else
        printMessage("", false, false);
    if (guessCount >= 3)
        printMessage("o", false, false);
    else
        printMessage("", false, false);
    if (guessCount == 4)
        printMessage("/  ", false, false); // interesting way to draw the hangman
    if (guessCount == 5)
        printMessage("/|  ", false, false); // extra spacing needed for centering
    if (guessCount >= 6)
        printMessage("/|\\", false, false);
    else
        printMessage("", false, false);
    if (guessCount >= 7)
        printMessage("|", false, false);
    else
        printMessage("", false, false);
    if (guessCount == 8)
        printMessage("/  ", false, false);
    if (guessCount >= 9)
        printMessage("/ \\", false, false);
    else
        printMessage("", false, false);
}

bool findDigit(char input, char i){
    int inputInt = input - '0';
    while(inputInt > 0){
        int digit = inputInt % 10;
        if(digit == i-'0') return true;
        inputInt/=10;
    }
    return false;

}

void printDigits(char input[], int from, int to){
    string s;
    for(int i = from; i <= to; i++){
        if(!strchr(input, i)){
            s += to_string(i);
            s += " ";
        }else
            s += " ";
    }
    printMessage(s, false, false);
}

void printSymbols(){
    string symbol;
    symbol += "+  ";
    symbol += "-  ";
    symbol += "x  ";
    symbol += "/  ";
    printMessage(symbol, false, false);
}
/** blanks out incorrect digits guessed*/
void printAvailableDigits(char taken[]){
    printMessage("Available Digits");
    printDigits(taken, 0, 9);
}

bool printNumbersSymbolsAndCheckWin(char guess[], string numToGuess1, string numToGuess2, string numToGuessTotal, char symbolToGuess) {
    bool won = true;
    bool symbolGuessed = false;
    string n1, n2, nArithmetics, nTotal;
    for (int i = 0; i < numToGuess1.length(); i++) {
        for(int j = 0; j < strlen(guess); j++){
            if (guess[j] - '0' <= 9) {
                if (!findDigit(guess[j], numToGuess1[i])) {
                    won = false;
                    n1 += "_  ";
                } else {
                    n1 += guess;
                    n1 += " ";
                }
            } else{
                if (!(guess[j] == symbolToGuess)) {
                    won = false;
                    nArithmetics += "_  ";
                } else {
                    nArithmetics += guess;
                    nArithmetics += " ";
                }
            }
        }

    }
    for (int i = 0; i < numToGuess2.length(); i++) {
        for(int j = 0; j < strlen(guess); j++) {
            if (guess[j] - '0' <= 9) {
                if (!findDigit(guess[j], numToGuess2[i])) {
                    won = false;
                    n2 += "_  ";
                } else {
                    n2 += guess;
                    n2 += " ";
                }
            } else{
                if (!(guess[j] == symbolToGuess)) {
                    won = false;
                    nArithmetics += "_  ";
                } else {
                    nArithmetics += guess;
                    nArithmetics += " ";
                }
            }
        }
    }
    for (int i = 0; i < numToGuessTotal.length(); i++) {
        for(int j = 0; j < strlen(guess); j++) {
            if (guess[j] - '0' <= 9) {
                if (!findDigit(guess[j], numToGuessTotal[i])) {
                    won = false;
                    nTotal += "_  ";
                } else {
                    nTotal += guess;
                    nTotal += " ";
                }
            }else {
                if (!(guess[j] == symbolToGuess)) {
                    won = false;
                    nArithmetics += "_  ";
                } else {
                    nArithmetics += guess;
                    nArithmetics += " ";
                }
            }
        }
    }


    printMessage(n1, false);
    printMessage(n2, false);
    printMessage(nArithmetics, false);
    printMessage(nTotal, false);
    return won;
}

int triesLeft(char guess[], string numToGuess1, string numToGuess2, string numToGuessTotal, char symbolToGuess){
    int error = 0;
    bool noError = false;
    for(int i = 0; i < numToGuess1.length(); i++){
        for(int j = 0; j < strlen(guess); j++) {
            if (guess[j] - '0' <= 9) {
                if (findDigit(guess[j], numToGuess1[i])) {
                    noError = true;
                    break;
                }
            } else {
                if(guess[j] == symbolToGuess)
                    noError = true;
                else break;
            }
        }

    }
    for(int i = 0; i < numToGuess2.length(); i++){
        for(int j = 0; j < strlen(guess); j++) {
            if (guess[j] - '0' <= 9) {
                if (findDigit(guess[j], numToGuess2[i])) {
                    noError = noError || true;
                    break;
                }
            } else {
                if(guess[j] == symbolToGuess)
                    noError = noError || true;
                else break;
            }
        }
    }
    for(int i = 0; i < numToGuessTotal.length(); i++){
        for(int j = 0; j < strlen(guess); j++) {
            if (guess[j] - '0' <= 9) {
                if (findDigit(guess[j], numToGuessTotal[i])) {
                    noError = noError || true;
                    break;
                }
            } else {
                if(guess[j] == symbolToGuess)
                    noError = noError || true;
                else break;
            }
        }
    }

    if(!noError)
        error++;
    return error;
}
// take two numbers from list
// take random symbol
// write calculator that calculates it and produces output of the total
// minus might be a problem
int calculateTotal(int num1, int num2, char symbol){
    int numTotal;
    switch(symbol){
        case 'x':
            numTotal = num1 * num2;
            break;
        case '+':
            numTotal = num1 + num2;
            break;
        case '-':
            numTotal = num1 - num2;
            break;
        case '/':
            numTotal = num1 / num2;
            break;
    }
    return numTotal;
}
// then stick all the information to figure out wins

int main() {
    char guesses[10];

    string numToGuess1, numToGuess2, numtoGuessTotal;
    char symbolToGuess;
    numToGuess1 = to_string(123);
    numToGuess2 = to_string(2);
    numtoGuessTotal = to_string(calculateTotal(stoi(numToGuess1), stoi(numToGuess2), symbolToGuess));

    int tries = 0;
    bool win = false;
    do{
        system("clear");
        printMessage("HANGMAN");
        drawHangman(tries);
        printAvailableDigits(guesses);
        printMessage("Guess the Math");
        printSymbols();
        win = printNumbersSymbolsAndCheckWin(guesses, numToGuess1, numToGuess2, numtoGuessTotal, symbolToGuess);

        if(win)
            break;
        char x;
        cout << ">";
        cin >> x;

        if(strchr(guesses,x))
            guesses[tries] = x;
        tries = triesLeft(guesses, numToGuess1, numToGuess2, numtoGuessTotal, symbolToGuess);
    }while(tries < 10);

    if(win)
        printMessage("YOU WON");
    else
        printMessage("GAME OVER");

    return 0;
}