#include <iostream>

/** Tutorial:https://www.youtube.com/watch?v=VWUhXnq_qKI*/
using namespace std;

/** print the outline of the game*/
void PrintMessage(string message, bool printTop = true, bool printBottom = true) {
    // top border
    if(printTop) {
        cout << "+---------------------------------+" << endl;
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
    }

}
int main() {
    PrintMessage("HANG MAN");
    getchar(); // gets a character from stdin
    return 0;
}