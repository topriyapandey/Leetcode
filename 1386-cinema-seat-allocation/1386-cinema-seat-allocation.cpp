#include <vector>
#include <unordered_map>

class Solution {
public:
    int maxNumberOfFamilies(int n, std::vector<std::vector<int>>& reservedSeats) {
        std::unordered_map<int, int> reservedBitmasks;
        
        for (const auto& seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];
            reservedBitmasks[row] |= (1 << (col - 1));
        }
        
        int totalGroups = (n - reservedBitmasks.size()) * 2;
        
        for (const auto& [row, mask] : reservedBitmasks) {
            bool left = (mask & 0b0000111100) == 0;    // seats 2, 3, 4, 5
            bool right = (mask & 0b0011110000) == 0;   // seats 6, 7, 8, 9
            bool middle = (mask & 0b00001111000) == 0; // seats 4, 5, 6, 7 (mask: bits for seats 4-7)
            
            // Mask checks for specific 4-seat blocks:
            // Seats 2, 3, 4, 5 -> bits 1, 2, 3, 4 (0b0000011110 -> 0x1E)
            // Seats 6, 7, 8, 9 -> bits 5, 6, 7, 8 (0b0111100000 -> 0x1E0)
            // Seats 4, 5, 6, 7 -> bits 3, 4, 5, 6 (0b0001111000 -> 0x78)
            
            bool canLeft = (mask & 0x1E) == 0;
            bool canRight = (mask & 0x1E0) == 0;
            bool canMiddle = (mask & 0x78) == 0;
            
            if (canLeft && canRight) {
                totalGroups += 2;
            } else if (canLeft || canRight || canMiddle) {
                totalGroups += 1;
            }
        }
        
        return totalGroups;
    }
};