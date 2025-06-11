#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> flipAndInvertImage(std::vector<std::vector<int>>& image) {
        int n = image.size(); // Get the size of the image
        
        for (int i = 0; i < n; ++i) {
            // Flip the row horizontally
            for (int j = 0; j < (n + 1) / 2; ++j) {
                // Swap the elements
                std::swap(image[i][j], image[i][n - 1 - j]);
            }
            // Invert the row
            for (int j = 0; j < n; ++j) {
                image[i][j] = image[i][j] ^ 1; // Invert using XOR
            }
        }
        
        return image; // Return the modified image
    }
};
