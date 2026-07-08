

class Solution {
public:
    int findMaximumXOR(std::vector<int>& nums) {
        // Fast I/O for competitive programming platforms
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int n = nums.size();
        if (n < 2) return 0;
        
        // Max nodes possible = numbers * 32 bits + 1. 
        // Using a flat 1D array completely eliminates overhead.
        int max_nodes = n * 32 + 1;
        
        // Instead of vector<vector<int>>, we simulate a 2D grid with a flat array:
        // Row 'r' bit 'b' is accessed via: trie[r * 2 + b]
        int* trie = new int[max_nodes * 2](); // () initializes all elements to 0
        
        int node_cnt = 0;

        // --- 1. INSERTION PHASE ---
        for (int num : nums) {
            int row = 0;
            for (int i = 31; i >= 0; i--) {
                int bit = (num >> i) & 1;
                int index = row * 2 + bit;
                
                if (trie[index] == 0) {
                    trie[index] = ++node_cnt;
                }
                row = trie[index];
            }
        }

        // --- 2. SEARCH PHASE ---
        int max_xor = 0;
        for (int num : nums) {
            int row = 0;
            int current_xor = 0;
            for (int i = 31; i >= 0; i--) {
                int bit = (num >> i) & 1;
                int desired_bit = 1 - bit;
                int target_index = row * 2 + desired_bit;
                
                if (trie[target_index] != 0) {
                    current_xor |= (1 << i);
                    row = trie[target_index];
                } else {
                    row = trie[row * 2 + bit];
                }
            }
            max_xor = std::max(max_xor, current_xor);
        }

        // Free up the allocated memory
        delete[] trie;

        return max_xor;
    }
};