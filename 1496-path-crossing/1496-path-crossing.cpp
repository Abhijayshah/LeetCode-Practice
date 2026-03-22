class Solution {
public:
    bool isPathCrossing(string path) {
        
        // Set to store visited coordinates
        set<pair<int,int>> visited;
        
        int x = 0, y = 0;   // starting point
        
        visited.insert({x, y});  // mark origin as visited
        
        // Traverse the path
        for(char dir : path){
            
            if(dir == 'N') y++;      // move up
            else if(dir == 'S') y--; // move down
            else if(dir == 'E') x++; // move right
            else if(dir == 'W') x--; // move left
            
            // If already visited → path crosses
            if(visited.count({x, y})) return true;
            
            // Otherwise mark as visited
            visited.insert({x, y});
        }
        
        return false;  // no crossing found
    }
};