    #ifndef INVERTED_INDEX_H
    #define INVERTED_INDEX_H

    #include <cstdio>
    #include <vector>
    #include <map>

    #ifndef SEARCH_ENGINE_INVERTEDINDEX_H
    #define SEARCH_ENGINE_INVERTEDINDEX_H

    #endif //SEARCH_ENGINE_INVERTEDINDEX_H

    struct Entry {
        size_t doc_id, count;

        //Given operator is required to conduct text scenarios
        bool operator == (const Entry& other) const {
            return (doc_id == other.doc_id &&
                      count == other.count);
        }
    };

    class InvertedIndex {
    public:
        InvertedIndex() = default;
        void UpdateDocumentBase(std::vector<std::string> input_docs);
        std::vector<Entry> GetWordCount(const std::string& word);

    private:

        std::vector<std::string> docs;
        std::map<std::string, std::vector<Entry>> freq_dictionary;
    };

    #endif // INVERTED_INDEX_H