#include <iostream>
#include <string>
#include <cctype>  // for toupper()

using namespace std;

int main() {
    // Array of English alphabet letters
    char letters[] = {
        'A','B','C','D','E','F','G','H','I','J',
        'K','L','M','N','O','P','Q','R','S','T',
        'U','V','W','X','Y','Z'
    };

    // Parallel array of Morse codes (using ASCII 46 = '.', ASCII 45 = '-')
    string morseCode[] = {
        ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
        "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
        "..-", "...-", ".--", "-..-", "-.--", "--.."
    };
    string message;
    cout << "Enter a short message (letters only): ";
    getline(cin, message);

    cout << "\nMorse Code Translation:\n";

    string fullMorseMessage = ""; // To store full Morse code message

    // Loop through each character in the input message
    for (char ch : message) {
        if (isalpha(ch)) { // Check if the character is a letter
            ch = toupper(ch); // Convert to uppercase for matching

            // Search for the letter in the letters array
            for (int i = 0; i < 26; ++i) {
                if (letters[i] == ch) {
                    cout << ch << ": " << morseCode[i] << endl;
                    fullMorseMessage += morseCode[i] + "   "; // Add three spaces after each letter
                    break;
                }
            }
        }
    }

    // Output full Morse code message
    cout << "\nFull Morse code with spaces:\n";
    cout << fullMorseMessage << endl;

    return 0;
}