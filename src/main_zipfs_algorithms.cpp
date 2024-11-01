#include "zipfs.h"
#include <iostream>

using namespace session20;  // This allows us to use functions from session20 directly

int main() {
    std::string fileName = "text.txt";  

    // Step 1: Read the book into a vector of characters
    std::vector<char> bookContent = readBook(fileName);

    // Step 2: Extract words from the character vector
    std::vector<std::string> words = extractWords(bookContent);

    // Step 3: Count frequencies of each word
    std::vector<std::pair<std::string, int>> wordFrequencies = countFrequencies(words);

    // Step 4: Sort the frequencies in descending order
    sortFrequencies(wordFrequencies);

    // Step 5: Output sorted word frequencies
    std::cout << "Ranked word frequencies:\n";
    int rank = 1;
    for (const auto& [word, frequency] : wordFrequencies) {
        std::cout << rank++ << ": " << word << " - " << frequency << "\n";
    }

    return 0;
}
