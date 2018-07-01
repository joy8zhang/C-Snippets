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

bool findDigit(int input, char i){
    while(input > 0){
        int digit = input % 10;
        if(digit == i-'0') return true;
        input/=10;

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

bool printNumbersSymbolsAndCheckWin(int digit, string numToGuess1, string numToGuess2, string numToGuessTotal, char symbolToGuess){
    bool won = true;
    string n1, n2, nTotal;
    for(int i = 0; i < numToGuess1.length(); i++){
        if(!findDigit(digit,numToGuess1[i])){
            won = false;
            n1 += "_  ";
        }else {
            n1 += digit;
            n1 += " ";
        }
    }
    for(int i = 0; i < numToGuess2.length(); i++){
        if(!findDigit(digit,numToGuess2[i])){
            won = false;
            n2 += "_  ";
        }else {
            n2 += digit;
            n2 += " ";
        }
    }
    for(int i = 0; i < numToGuessTotal.length(); i++){
        if(!findDigit(digit,numToGuessTotal[i])){
            won = false;
            nTotal += "_  ";
        }else {
            nTotal += digit;
            nTotal += " ";
        }
    }
    printMessage(n1, false);
    printMessage(n2, false);
    printMessage(nTotal, false);
    return won;
}

int triesLeft(int digit, string numToGuess1, string numToGuess2, string numToGuessTotal, char symbolToGuess){
    int error = 0;
    bool noError = false;
    for(int i = 0; i < numToGuess1.length(); i++){
        if(findDigit(digit,numToGuess1[i])){
            noError = true;
            break;
        }
    }
    for(int i = 0; i < numToGuess2.length(); i++){
        if(findDigit(digit,numToGuess2[i])){
            noError = noError || true;
            break;
        }
    }
    for(int i = 0; i < numToGuessTotal.length(); i++){
        if(findDigit(digit,numToGuessTotal[i])){
            noError = noError || true;
            break;
        }
    }
    if(!noError)
        error++;
    return error;

    //TODO: symbol guess implementation
}


int main() {
    printMessage("HANGMAN");
    printAvailableDigits(154);
    printSymbols();
    printNumbersSymbolsAndCheckWin(2, "123", "235", "3642", 'x');
    return 0;
}