#include <iostream>
#include <fstream>
#include <string>
#include <string_view>


// Function to find the longest word in a text file
int getLongestWord(const std::string& path) {
    std::ifstream file(path);

    if (!file) {
        // Return an error code if the file could not be opened
        std::cerr << "sample_text.txt could not be opened for reading!\n";
        return 1;
    }

    std::string currentWord; // To store the current word being read
    std::string longestWord; // To store the longest word found

    // Read words from the file
    while (file >> currentWord) {
        // Update longestWord if the currentWord is longer
        if (currentWord.length() > longestWord.length()) {
            longestWord = currentWord;
        }
    }

    // Close the file after reading
    file.close();

    // Check if a longest word was found and print it
    if (!longestWord.empty()) {
        std::cout << "The longest word is: " << longestWord << "\n";
        std::cout << "The length of the word is: " << longestWord.length() << "\n";
        return 0; // Return 0 to indicate success
    } else {
        std::cout << "No words found in the file.\n";
        return 1; // Return 1 to indicate that no words were found
    }
}


int main(int argc, char** argv) {
    // Check if a file path was provided as a command-line argument
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <path-to-text-file>\n";
        return 1; // Return an error code if no file path is provided
    }
    
    // Get the path to the text file from the command-line arguments
    std::string pathToTxt = argv[1];

    // Call the function to get the longest word in the specified file
    getLongestWord(pathToTxt);

    return 0;
}