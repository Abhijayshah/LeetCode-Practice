class FoodRatings {
public:
    // food -> {cuisine, rating}
    unordered_map<string, pair<string, int>> foodMap;
    // cuisine -> ordered set of { -rating, name }
    unordered_map<string, set<pair<int, string>>> cuisineMap;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); i++) {
            foodMap[foods[i]] = {cuisines[i], ratings[i]};
            cuisineMap[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        auto [cuisine, oldRating] = foodMap[food];
        // remove old entry
        cuisineMap[cuisine].erase({-oldRating, food});
        // insert new entry
        cuisineMap[cuisine].insert({-newRating, food});
        // update map
        foodMap[food].second = newRating;
    }
    
    string highestRated(string cuisine) {
        return cuisineMap[cuisine].begin()->second; // top element
    }
};
