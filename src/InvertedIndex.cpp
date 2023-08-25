#include "../include/InvertedIndex.h"
#include <cctype>
#include <algorithm>
#include <iostream>

void InvertedIndex::UpdateDocumentBase(std::vector<std::string> input_docs) {
    docs = input_docs;
    freq_dictionary.clear();

    for (size_t doc_id = 0; doc_id < docs.size(); ++doc_id) {
        SplitAndIndexWords(doc_id, docs[doc_id]);
    }
}

void InvertedIndex::SplitAndIndexWords(size_t doc_id, const std::string& document) {
    std::string word;
    for (char c : document) {
        if (std::isalnum(c)) {
            word += c;
        } else if (!word.empty()) {
            freq_dictionary[word].push_back({doc_id, 1});
            word.clear();
        }
    }
    if (!word.empty()) {
        freq_dictionary[word].push_back({doc_id, 1});
    }
}

std::vector<Entry> InvertedIndex::GetWordCount(const std::string& word) {
    auto it = freq_dictionary.find(word);
    if (it != freq_dictionary.end()) {
        return it->second;
    }
    return {};
}
