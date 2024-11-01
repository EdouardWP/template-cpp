#include "zipfs.h"
#include <iostream>

using namespace session19;  // This allows us to call functions from session19 directly

int main() {
    std::string fileName = "balling.txt"; 

    // Step 1: Read the book into a vector of characters
    std::vector<char> bookContent = readBook(fileName);
    
    // Step 2: Compute word frequency
    std::map<std::string, int> wordFrequencies = computeWordFrequency(bookContent);
    
    // Step 3: Count unique words
    int uniqueWordCount = countUniqueWords(bookContent);
    std::cout << "Number of unique words: " << uniqueWordCount << std::endl;
    
    // Step 4: Sort the word frequencies in descending order
    std::multimap<int, std::string, std::greater<int>> sortedFrequencies = sortFrequencies(wordFrequencies);

    // Step 5: Write the ranked word frequencies to a file
    writeFrequenciesToFile(sortedFrequencies, "../src/rankedfrequencies.txt");  // Writes to src

    // Step 6: Count and display hapax legomena
    countHapaxLegomena(sortedFrequencies);

    return 0;
}
