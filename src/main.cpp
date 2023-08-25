#include <iostream>
#include <string>
#include <fstream>
#include "../include/ConverterJSON.h"
#include "../include/InvertedIndex.h"
#include <vector>

int main() {
    // Create an instance of the ConverterJSON class
    ConverterJSON converter;

    // Load data from config files using ConverterJSON methods
    std::vector<std::string> documents = converter.GetTextDocuments();
    int responsesLimit = converter.GetResponsesLimit();
    std::vector<std::string> requests = converter.GetRequests();

    // Create an instance of the InvertedIndex class
    InvertedIndex index;

    // Update the index with the loaded documents
    index.UpdateDocumentBase(documents);

    // Placeholder for search and ranking logic
    std::vector<std::vector<std::pair<int, float>>> searchResults;

    // Use the index to perform searches and populate searchResults

    // Update the answers using ConverterJSON method
    converter.putAnswers(searchResults);

    return 0;
}
