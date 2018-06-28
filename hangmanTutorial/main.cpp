#include <iostream>

/** Tutorial:https://www.youtube.com/watch?v=VWUhXnq_qKI*/
using namespace std;

/** game header*/
void printMessage(string message, bool printTop = true, bool printBottom = true) {
    // top border
    if(printTop) {
        cout << "+---------------------------------+" << endl;
        cout << "|";
    }else {
        cout << "|";
    }
    bool front = true;
    // 33 is the defined max character length of the game borders
    // i initiate as message.length() because want to center the message within the 33 spaces
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
// any way to simplify this code?
// potentially use a data structure, array, hashset to store number and will return blank if number reoccuring
// this hangman is being reprinted every time, not being saved or anything
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
/** Letters guessed and not correct are displayed */
void printLetters(string input, char from, char to){
    string s;
    for(char i = from; i <= to; i++){
        if(input.find(i) == string::npos) { // npos is end of string, if input did not contain i
            s += i; // add the character
            s += " ";
        }
        else
            s += "  ";
    }
    printMessage(s, false, false);
}


int main() {
    string guesses;
    printMessage("HANG MAN");
    drawHangman(6);
    printLetters("AGH", 'A', 'M');
    printLetters("AGH", 'N', 'Z');
    getchar(); // gets a character from stdin
    return 0;
}