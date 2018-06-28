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
bool findDigit(int input, int i){
    while(input > 0){
        int digit = input % 10;
        if(digit==i) return true;
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

bool printIntandCheckWin(int number1, int number2, int number3, char guessed){

}


int main() {
    printMessage("HANGMAN");
    // printDigits(134, 0, 9);
    printAvailableDigits(154);
    printSymbols();
    return 0;
}