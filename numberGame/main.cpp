#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
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
    if (guessCount >= 4)
        printMessage("/|\\", false, false);
    else
        printMessage("", false, false);
    if (guessCount == 5)
        printMessage("/  ", false, false);
    if (guessCount >= 6)
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
        if(input== nullptr){
            s += to_string(i);
            s += " ";
        }
        else if(string(input).find(to_string(i)) == string::npos){
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
    printMessage(symbol, false);
}
/** blanks out incorrect digits guessed*/
void printAvailableDigits(char taken[]){
    printMessage("Available Digits");
    printDigits(taken, 0, 9);
}

bool printNumbersSymbolsAndCheckWin(char guess[], string numToGuess1, string numToGuess2, string numToGuessTotal, char symbolToGuess) {
    bool won = true;
    bool symbolGuessed = false;
    bool spaceDigit = false;
    bool spaceSymbol = false;
    string n1, n2, nArithmetics, nTotal;
    if(guess==nullptr){
        won = false;
        return won;
    }
    for (int i = 0; i < numToGuess1.length(); i++) {
        for(int j = 0; j < strlen(guess); j++){
            if (guess[j] - '0' <= 9) {
                if (!findDigit(guess[j], numToGuess1[i])) {
                    won = false;
                    spaceDigit = true;
                } else {
                    n1 += guess[j];
                    n1 += " ";
                    spaceDigit = false;
                    break;
                }
            }
        }
        if(spaceDigit)
            n1 += "_ ";
    }
    for (int i = 0; i < numToGuess2.length(); i++) {
        for(int j = 0; j < strlen(guess); j++) {
            if (guess[j] - '0' <= 9) {
                if (!findDigit(guess[j], numToGuess2[i])) {
                    won = false;
                    spaceDigit = true;
                } else {
                    n2 += guess[j];
                    n2 += " ";
                    spaceDigit = false;
                    break;
                }
            }
        }
        if(spaceDigit)
            n2 += "_ ";
        if(spaceSymbol)
            nArithmetics += "_  ";
    }
    for (int i = 0; i < numToGuessTotal.length(); i++) {
        for(int j = 0; j < strlen(guess); j++) {
            if (guess[j] - '0' <= 9) {
                if (!findDigit(guess[j], numToGuessTotal[i])) {
                    won = false;
                    spaceDigit = true;
                } else {
                    nTotal += guess[j];
                    nTotal += " ";
                    spaceDigit = false;
                    break;
                }
            }
        }
        if(spaceDigit)
            nTotal += "_ ";
    }
    for(int j = 0; j < strlen(guess); j++) {
        if (!guess[j] - '0' <= 9) {
            if (!(guess[j] == symbolToGuess)) {
                won = false;
                spaceSymbol = true;

            } else {
                nArithmetics += guess[j];
                nArithmetics += " ";
                spaceSymbol = false;
                won = true;
                break;
            }
        }
    }
    if(spaceSymbol)
        nArithmetics += "_ ";


    printMessage(n1, false);
    printMessage(n2, false);
    printMessage(nArithmetics, false);
    printMessage(nTotal, false);
    return won;
}
string loadRandomNum(string path){
    string numRand;
    vector<string> v;
    ifstream reader(path);
    if(reader.is_open()){
        while(getline(reader, numRand))
            v.push_back(numRand);
        int randomLine = rand() % v.size();
        numRand = v.at(randomLine);
        reader.close();
    }
    return numRand;
}

string loadRandomSymbol(string path){
    string symbol;
    vector<string> v;
    ifstream symbolReader(path);
    if(symbolReader.is_open()){
        while(getline(symbolReader, symbol))
            v.push_back(symbol);
        int randomLine = rand() % v.size();
        symbol = v.at(randomLine);
        symbolReader.close();
    }
    return symbol;
}

int triesLeft(char guess[], string numToGuess1, string numToGuess2, string numToGuessTotal, char symbolToGuess){
    int error = 0;
    bool noError = false;

    for(int j = 0; j < strlen(guess); j++){
        if (guess[j] - '0' <= 9) {
            for (int i = 0; i < numToGuess1.length(); i++) {
                if (findDigit(guess[j], numToGuess1[i])) {
                    noError = true;
                    break;
                } else noError = false;
            }
            for (int i = 0; i < numToGuess2.length(); i++) {
                if (findDigit(guess[j], numToGuess1[i])) {
                    noError = true;
                    break;
                } else noError = noError || false;
            }
            for (int i = 0; i < numToGuessTotal.length(); i++) {
                if (findDigit(guess[j], numToGuess1[i])) {
                    noError = true;
                    break;
                } else noError = noError || false;
            }
        }else {
            if (guess[j] == symbolToGuess) {
                noError = true;
                break; // wins game
            }else noError = noError || false;
        }
        if(!noError)
            error++;
    }
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
    srand(time(0));
    vector<char> guessVector;
    string numToGuess1 = loadRandomNum("numbers.txt");
    string numToGuess2 = loadRandomNum("numbers.txt");
    char symbolToGuess = loadRandomSymbol("symbols.txt")[0];
    string numtoGuessTotal = to_string(calculateTotal(stoi(numToGuess1), stoi(numToGuess2), symbolToGuess));
    int tries = 0;
    bool win = false;
    do{
        system("clear");
        printMessage("HANGMAN");
        drawHangman(tries);
        printAvailableDigits(&guessVector[0]);
        printMessage("Guess the Math");
        printSymbols();
        win = printNumbersSymbolsAndCheckWin(&guessVector[0], numToGuess1, numToGuess2, numtoGuessTotal, symbolToGuess);
        if(win)
            break;
        char x;
        cout << ">";
        cin >> x;
        if(&guessVector[0] == nullptr)
            guessVector.push_back(x);
        else if(string(&guessVector[0]).find(x))
            guessVector.push_back(x);

        tries = triesLeft(&guessVector[0], numToGuess1, numToGuess2, numtoGuessTotal, symbolToGuess);


    }while(tries < 7);

    if(win)
        printMessage("YOU WON");
    else
        printMessage("GAME OVER");

    return 0;
}