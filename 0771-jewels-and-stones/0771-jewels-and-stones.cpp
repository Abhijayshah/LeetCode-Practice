class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {

        int count =0;               // count of jewels found 

        for(char s: stones){           // Traverse stones
            for(char j : jewels ){   // Traverse jewels
                if(s==j){           // if stone is jeweles 
                    count++;        // increment count 
                    break;          // no need to check further 

                }
            }
        }
        
        return count;               // retuirn total jewels 

    }
};