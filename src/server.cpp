#include "../include/server.h"

std::vector<std::vector<RelativeIndex>> SearchServer::search(const std::vector<std::string>& queries_input, size_t max_responses) {
    // Implement search
}

std::map<std::string, size_t> SearchServer::get_indexes_for_request_words(std::vector<std::string>& vec) {
    // Implement get_indexes_for_request_words
}

void SearchServer::handleRequest(const std::string& request, std::vector<RelativeIndex>& relative_indices, size_t max_responses) {
    // Implement handleRequest
}
