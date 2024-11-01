#include <gtest/gtest.h>
#include "zipfs.h"
#include <vector>
#include <string>
#include <map>

// Using the session19 namespace for convenience
using namespace session19;

TEST(ZipfsTest, ComputeWordFrequencyTest) {
    // Sample input
    std::vector<char> bookContent = {'t', 'e', 's', 't', ' ', 't', 'e', 's', 't', ' ', 'c', 'o', 'd', 'e'};

    // Expected output
    std::map<std::string, int> expectedFrequencies = {{"test", 2}, {"code", 1}};

    // Run the function
    std::map<std::string, int> actualFrequencies = computeWordFrequency(bookContent);

    // Verify the output matches the expected result
    EXPECT_EQ(actualFrequencies, expectedFrequencies);
}

TEST(ZipfsTest, CountUniqueWordsTest) {
    // Sample input
    std::vector<char> bookContent = {'u', 'n', 'i', 'q', 'u', 'e', ' ', 't', 'e', 's', 't', ' ', 'c', 'o', 'd', 'e'};

    // Expected unique word count
    int expectedUniqueCount = 3;

    // Run the function
    int actualUniqueCount = countUniqueWords(bookContent);

    // Verify the output matches the expected result
    EXPECT_EQ(actualUniqueCount, expectedUniqueCount);
}

