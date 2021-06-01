#include <string>
#include <nlohmann/json.hpp>
#include "MediaCollection.h"

using json = nlohmann::json;


int main() {
   std::string fileName{"my.json"};

    MediaCollection mediaCollection;
    mediaCollection.createContent(fileName);
    mediaCollection.createFilters();

    auto extractedData =  mediaCollection.extract(FilterType::disjunction);

    for(auto& ext : extractedData) {
        ext.print();
    }

    return 0;
}
