#include <iostream>
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

void printDigits(int input, int from, int to){
    string s;
    for(int i = from; i <= to; i++){
        if(!findDigit(input, i)){
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
void printAvailableDigits(int taken){
    printMessage("Available Digits");
    printDigits(taken, 0, 9);
}

bool printNumbersSymbolsAndCheckWin(char guess, string numToGuess1, string numToGuess2, string numToGuessTotal, char symbolToGuess) {
    bool won = true;
    bool symbolGuessed = false;
    string n1, n2, nArithmetics, nTotal;
    for (int i = 0; i < numToGuess1.length(); i++) {
        if (guess - '0' <= 9) {
            if (!findDigit(guess, numToGuess1[i])) {
                won = false;
                n1 += "_  ";
            } else {
                n1 += guess;
                n1 += " ";
            }
        } else break;
    }
    for (int i = 0; i < numToGuess2.length(); i++) {
        if (guess - '0' <= 9) {
            if (!findDigit(guess, numToGuess2[i])) {
                won = false;
                n2 += "_  ";
            } else {
                n2 += guess;
                n2 += " ";
            }
        } else break;
    }
    for (int i = 0; i < numToGuessTotal.length(); i++) {
        if (guess - '0' <= 9) {
            if (!findDigit(guess, numToGuessTotal[i])) {
                won = false;
                nTotal += "_  ";
            } else {
                nTotal += guess;
                nTotal += " ";
            }
        } else break;
    }
    if (!(guess == symbolToGuess)) {
        won = false;
        nArithmetics += "_  ";
    } else {
        nArithmetics += guess;
        nArithmetics += " ";
    }

    printMessage(n1, false);
    printMessage(n2, false);
    printMessage(nArithmetics, false);
    printMessage(nTotal, false);
    return won;
}

int triesLeft(char guess, string numToGuess1, string numToGuess2, string numToGuessTotal, char symbolToGuess){
    int error = 0;
    bool noError = false;
    for(int i = 0; i < numToGuess1.length(); i++){
        if(guess-'0' <=9){
            if(findDigit(guess,numToGuess1[i])){
                noError = true;
                break;
            }
        }else break;

    }
    for(int i = 0; i < numToGuess2.length(); i++){
        if(guess-'0' <=9) {
            if (findDigit(guess, numToGuess2[i])) {
                noError = noError || true;
                break;
            }
        }else break;
    }
    for(int i = 0; i < numToGuessTotal.length(); i++){
        if(guess-'0' <=9) {
            if (findDigit(guess, numToGuessTotal[i])) {
                noError = noError || true;
                break;
            }
        }else break;
    }
    if(guess == symbolToGuess)
        noError = noError || true;
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
    printMessage("HANGMAN");
    printAvailableDigits(154);
    printMessage("Guess the Math");
    printSymbols();
    printNumbersSymbolsAndCheckWin('x', "123", "235", "3642", 'x');
    cout << triesLeft('5',"123","123","123",'x');
    cout << "calculates" << calculateTotal(1,4,'-');
    return 0;
}