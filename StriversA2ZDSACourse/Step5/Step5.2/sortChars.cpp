#include <bits/stdc++.h>
using namespace std; 
class Solution {
public:
    string frequencySort(string s) {
    // Step 1: Count the frequency of each character
    std::unordered_map<char, int> frequency;
    for (char c : s) {
        frequency[c]++;
    }

    // Step 2: Use a max heap (priority queue) to sort characters by frequency
    auto cmp = [](const std::pair<char, int>& a, const std::pair<char, int>& b) {
        return a.second < b.second; // Max heap based on frequency
    };
    std::priority_queue<std::pair<char, int>, std::vector<std::pair<char, int>>, decltype(cmp)> maxHeap(cmp);

    // Push all characters with their frequencies into the heap
    for (const auto& entry : frequency) {
        maxHeap.push(entry);
    }

    // Step 3: Build the output string
    std::string result;
    while (!maxHeap.empty()) {
        auto [charWithMaxFreq, freq] = maxHeap.top();
        maxHeap.pop();
        result.append(freq, charWithMaxFreq); // Append character freq times
    }

    return result;
    }
};