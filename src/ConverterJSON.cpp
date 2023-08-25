#include "../include/ConverterJSON.h"

std::vector<std::string> ConverterJSON::GetTextDocuments() {
    std::ifstream configStream("config.json");
    json config;
    configStream >> config;

    std::vector<std::string> fileContents;
    for (const std::string& filePath : config["files"]) {
        std::ifstream fileStream(filePath);
        if (fileStream.is_open()) {
            std::string content((std::istreambuf_iterator<char>(fileStream)), std::istreambuf_iterator<char>());
            fileContents.push_back(content);
            fileStream.close();
        }
    }
    return fileContents;
}

int ConverterJSON::GetResponsesLimit() {
    std::ifstream configStream("config.json");
    json config;
    configStream >> config;

    return config["config"]["max_responses"];
}

std::vector<std::string> ConverterJSON::GetRequests() {
    std::ifstream requestsStream("requests.json");
    json requests;
    requestsStream >> requests;

    return requests["requests"];
}

void ConverterJSON::putAnswers(std::vector<std::vector<std::pair<int, float>>> answers) {
    json answersJson;

    int requestId = 1;
    for (const auto& response : answers) {
        json responseJson;

        bool result = !response.empty(); // Check if there are any documents in the response
        responseJson["result"] = result;

        if (result) {
            for (const auto& document : response) {
                json docJson;
                docJson["docid"] = document.first;
                docJson["rank"] = document.second;
                responseJson["relevance"].push_back(docJson);
            }
        }

        answersJson["answers"]["request" + std::to_string(requestId)] = responseJson;
        requestId++;
    }

    std::ofstream answersStream("answers.json");
    answersStream << std::setw(4) << answersJson;
    answersStream.close();
}
