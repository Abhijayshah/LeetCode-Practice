class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        
        unordered_set<string> startCities; // Store all cities that have outgoing paths
        
        // Insert all starting cities
        for (auto& path : paths) {
            startCities.insert(path[0]); // cityA has an outgoing path
        }
        
        // Find the city that never appears as a starting city
        for (auto& path : paths) {
            
            string destination = path[1]; // cityB
            
            // If destination not in startCities → it has no outgoing path
            if (startCities.find(destination) == startCities.end()) {
                return destination; // This is the destination city
            }
        }
        
        return ""; // Fallback (should not happen given constraints)
    }
};