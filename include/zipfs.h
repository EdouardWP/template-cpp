#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <locale>
#include <algorithm>

/**
 * @file zipfs.h
 * @brief Provides functions and utilities for text processing, word frequency analysis, and handling Russian text. 
 * Organized into namespaces for session-specific tasks.
 */

namespace session19 {

    std::vector<char> readBook(const std::string& fileName) {
        std::ifstream file(fileName);
        std::vector<char> result;

        if (!file.is_open()) {
            std::cout << "Error: Could not open the file." << std::endl;
            return result; 
        }

        char ch;
        while (file.get(ch)) {
            result.push_back(std::isalpha(ch) ? std::tolower(ch) : ' ');
        }
        return result; 
    }

    // MILESTONE 2: Function to get frequency of each word
    std::map<std::string, int> computeWordFrequency(const std::vector<char>& book) {
        std::map<std::string, int> wordFrequency; // creates the key:value pair system from class
        std::string content(book.begin(), book.end()); // Convert vector<char> to string for easier word extraction
        std::stringstream ss(content);
        std::string word;

        // Extract words and count their frequencies
        while (ss >> word) {
            wordFrequency[word]++; // Increment the count of each word in the map
        }
        return wordFrequency;
    }

    // MILESTONE 3: Counting unique words
    int countUniqueWords(const std::vector<char>& book) {
        std::set<std::string> uniqueWords;
        std::string content(book.begin(), book.end());
        std::stringstream ss(content);
        std::string word;

        while (ss >> word) {
            uniqueWords.insert(word); // Only unique words are stored in the set
        }
        return uniqueWords.size();  // Returns the count of unique words
    }

    // MILESTONE 4: Sorting word frequencies in descending order
    std::multimap<int, std::string, std::greater<int>> sortFrequencies(const std::map<std::string, int>& frequencies) {
        std::multimap<int, std::string, std::greater<int>> sortedFrequencies;  // Multimap with descending order for keys
        
        // Insert each word-frequency pair into the multimap with frequency as key
        for (const auto& pair : frequencies) {
            sortedFrequencies.insert({pair.second, pair.first});
        }
        return sortedFrequencies;
    }

    // MILESTONE 5: Outputting the frequencies to a file with rank (1,2,3,4,etc)
    void writeFrequenciesToFile(const std::multimap<int, std::string, std::greater<int>>& sortedFrequencies, const std::string& outputFileName) {
        std::ofstream outFile(outputFileName);
        if (!outFile.is_open()) {
            std::cout << "Error: Could not open the output file." << std::endl;
            return;
        }

        // Writing each word's rank, frequency, and text to the file
        int rank = 1;
        for (const auto& pair : sortedFrequencies) {
            outFile << rank++ << " " << pair.first << " " << pair.second << std::endl;
        }
    }

    // MILESTONE 6: Function to count and display hapax legomena (words that appear only once)
    void countHapaxLegomena(const std::multimap<int, std::string, std::greater<int>>& sortedFrequencies) {
        int hapaxCount = 0, exampleLimit = 3; // As you specifically state not all 
        std::cout << "\nHapax Legomena (words that appear only once):" << std::endl;
        // Iterate over sortedFrequencies to find words with frequency of 1
        for (const auto& pair : sortedFrequencies) {
            if (pair.first == 1 && hapaxCount++ < exampleLimit) {
                std::cout << "- " << pair.second << std::endl;
            }
        }
        std::cout << "\nTotal number of hapax legomena: " << hapaxCount << std::endl;
    }
}

namespace russianText {

    std::vector<wchar_t> readBook(const std::string& fileName) {
        std::wifstream file(fileName);
        file.imbue(std::locale("en_US.UTF-8")); // Set locale to UTF-8 for wide characters
        std::vector<wchar_t> result;

        if (!file.is_open()) {
            std::wcout << L"Error: Could not open the file." << std::endl;
            return result;
        }

        wchar_t ch;
        // Read each character from the file
        while (file.get(ch)) {
            if (std::iswalpha(ch)) {
                result.push_back(std::towlower(ch));  // Keep alphabetic characters in lowercase for consistency
            } else {
                result.push_back(L' '); // Replace non-alphabetic characters with a space
            }
        }
        return result;  
    }

    // MILESTONE 2: Function to get frequency of each word
    std::map<std::wstring, int> computeWordFrequency(const std::vector<wchar_t>& book) {
        std::map<std::wstring, int> wordFrequency;
        std::wstring content(book.begin(), book.end());
        std::wstringstream ss(content);
        std::wstring word;

        // Extract words and count their frequencies
        while (ss >> word) {
            wordFrequency[word]++; // Increment the count of each word in the map
        }
        return wordFrequency;
    }

    // MILESTONE 3: Counting unique words
    int countUniqueWords(const std::vector<wchar_t>& book) {
        std::set<std::wstring> uniqueWords;
        std::wstring content(book.begin(), book.end());
        std::wstringstream ss(content);
        std::wstring word;

        while (ss >> word) {
            uniqueWords.insert(word); // Only unique words are stored in the set
        }
        return uniqueWords.size(); // Returns the count of unique words
    }

    // MILESTONE 4: Sorting word frequencies in descending order
    std::multimap<int, std::wstring, std::greater<int>> sortFrequencies(const std::map<std::wstring, int>& frequencies) {
        std::multimap<int, std::wstring, std::greater<int>> sortedFrequencies; // Multimap with descending order for keys
        
        // Insert each word-frequency pair into the multimap with frequency as key
        for (const auto& pair : frequencies) {
            sortedFrequencies.insert({pair.second, pair.first});
        }
        return sortedFrequencies;
    }

    // MILESTONE 5: Outputting the frequencies to a file with rank (1,2,3,4,etc)
    void writeFrequenciesToFile(const std::multimap<int, std::wstring, std::greater<int>>& sortedFrequencies, const std::string& outputFileName) {
        std::wofstream outFile(outputFileName);
        outFile.imbue(std::locale("en_US.UTF-8"));
        if (!outFile.is_open()) {
            std::wcout << L"Error: Could not open the output file." << std::endl;
            return;
        }
        int rank = 1;
        for (const auto& pair : sortedFrequencies) {
            outFile << rank++ << L" " << pair.first << L" " << pair.second << std::endl;
        }
    }

    // MILESTONE 6: Function to count and display hapax legomena (words that appear only once)
    void countHapaxLegomena(const std::multimap<int, std::wstring, std::greater<int>>& sortedFrequencies) {
        int hapaxCount = 0, exampleLimit = 3;
        std::wcout << L"\nHapax Legomena (words that appear only once):" << std::endl;
        for (const auto& pair : sortedFrequencies) {
            if (pair.first == 1 && hapaxCount++ < exampleLimit) {
                std::wcout << L"- " << pair.second << std::endl;
            }
        }
        std::wcout << L"\nTotal number of hapax legomena: " << hapaxCount << std::endl;
    }
}

namespace session20 {

    std::vector<char> readBook(const std::string& fileName) {
        std::ifstream file(fileName);
        std::vector<char> result;

        if (!file.is_open()) {
            std::cout << "Error: Could not open the file." << std::endl;
            return result;
        }

        char ch;
        while (file.get(ch)) {
            result.push_back(std::isalpha(ch) ? std::tolower(ch) : ' ');
        }
        return result;
    }

    std::vector<std::string> extractWords(const std::vector<char>& chars) {
        std::string content(chars.begin(), chars.end());
        std::istringstream stream(content);
        std::vector<std::string> words;
        std::string word;

        while (stream >> word) {
            words.push_back(word);
        }
        return words;
    }

    std::vector<std::pair<std::string, int>> countFrequencies(const std::vector<std::string>& words) {
        std::vector<std::pair<std::string, int>> wordFrequencies;

        for (const auto& word : words) {
            auto it = std::find_if(wordFrequencies.begin(), wordFrequencies.end(),
                                   [&](const auto& pair) { return pair.first == word; });
            if (it != wordFrequencies.end()) {
                it->second++;
            } else {
                wordFrequencies.emplace_back(word, 1);
            }
        }
        return wordFrequencies;
    }

    void sortFrequencies(std::vector<std::pair<std::string, int>>& wordFrequencies) {
        std::sort(wordFrequencies.begin(), wordFrequencies.end(),
                  [](const auto& a, const auto& b) { return a.second > b.second; });
    }
}

