// This is the Brute force approach to the problem of AutoComplete System while normally Trie is used to solve this problem.
// This is just for the sake of understanding the problem and the approach to solve it.
// As it was the part of Basic user Input/Output in Step1.1 of TakeUForward A-Z DSA Course.
// This is the problem statement:
// https://practice.geeksforgeeks.org/problems/search-query-auto-complete

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
// } Driver Code Ends


class AutoCompleteSystem {
    vector<string> sentences;
    vector<int> times;
    string currentString = "";
    vector<string> getTop3Suggestions(string currentString) {
        // write code to return top 3 suggestions for given query prefix "currentString"
        vector<string> suggestions;
        vector<pair<int, string>> temp;
        for (int i = 0; i < sentences.size(); i++) {
            if (sentences[i].substr(0, currentString.size()) == currentString) {
                temp.push_back({times[i], sentences[i]});
            }
        }
        //  If several sentences have the same frequency, you need to use ASCII-code order
        sort(temp.begin(), temp.end(), [](pair<int, string> a, pair<int, string> b) {
            if (a.first == b.first) {
                return a.second < b.second;
            }
            return a.first > b.first;
        });
        for (int i = 0; i < min(3, (int)temp.size()); i++) {
            suggestions.push_back(temp[i].second);
        }
        return suggestions;
    }
public:
    AutoCompleteSystem(vector<string>& sentences, vector<int>& times) {
        this->sentences = sentences;
        this->times = times;
    }
    vector<string> input(char c) {
        // write code to return the top 3 suggestions when the current character in the stream is c
        // c == '#' means , the current query is complete and you may save the entire query into
        // historical data

        if (c == '#') {
            // save the current query into historical data if it is not already present and if it is present then update the frequency
            bool found = false;
            for (int i = 0; i < sentences.size(); i++) {
                if (sentences[i] == currentString) {
                    times[i]++;
                    found = true;
                    break;
                }
            }
            if (!found) {
                sentences.push_back(currentString);
                times.push_back(1);
            }
            currentString = "";
            return {};
        } else {
            currentString += c;
            return getTop3Suggestions(currentString);
        }
    }
};

/**
 * Your AutoCompleteSystem object will be instantiated and called as such:
 * AutoCompleteSystem* obj = new AutoCompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */

//{ Driver Code Starts.
int main() {

    int t;
	cin >> t;
    cin.ignore();
    while(t--) {
		int n;
		cin>>n;
        cin.ignore();
        vector<string> sentences(n);
		vector<int> times(n);
		for (int i = 0; i < n; ++i){
            
			getline(cin,sentences[i]);
			cin>>times[i];
            cin.ignore();
		}
		AutoCompleteSystem *obj = new AutoCompleteSystem(sentences,times);
		int q;
		cin>>q;
        cin.ignore();

		for (int i = 0; i < q; ++i){
			string query;
			getline(cin,query);
            string qq = "";
            for(auto &x:query){
			    qq+=x;
                vector<string> suggestions = obj->input(x);
                if(x=='#')
                    continue;
                cout<<"Typed : \""<<qq<<"\" , Suggestions: \n";
				for(auto &y:suggestions){
					cout<<y<<"\n";
				}
			}
		}
	}
	return 0;
}
// } Driver Code Ends


// I for myself consider even this approch a little bit advanced but this is the best I could think is possible with basic knowledge of C++.]
// I have used the concept of Tries to solve this problem.

//AutoCompletSystem class using Trie
// class AutoCompleteSystem {
//     struct TrieNode {
//         bool isEnd;
//         unordered_map<char, TrieNode*> children;
//         TrieNode() {
//             isEnd = false;
//         }
//     };
//     TrieNode* root;
//     string currentString = "";
//     vector<string> getTop3Suggestions(string currentString) {
//         // write code to return top 3 suggestions for given query prefix "currentString"
//         vector<string> suggestions;
//         TrieNode* temp = root;
//         for (int i = 0; i < currentString.size(); i++) {
//             if (temp->children.find(currentString[i]) == temp->children.end()) {
//                 return suggestions;
//             }
//             temp = temp->children[currentString[i]];
//         }
//         //  If several sentences have the same frequency, you need to use ASCII-code order
//         priority_queue<pair<int, string>> pq;
//         dfs(temp, currentString, pq);
//         for (int i = 0; i < min(3, (int)pq.size()); i++) {
//             suggestions.push_back(pq.top().second);
//             pq.pop();
//         }
//         return suggestions;
//     }
//     void dfs(TrieNode* root, string currentString, priority_queue<pair<int, string>>& pq) {
//         if (root->isEnd) {
//             pq.push({root->freq, currentString});
//             if (pq.size() > 3) {
//                 pq.pop();
//             }
//         }
//         for (auto it : root->children) {
//             dfs(it.second, currentString + it.first, pq);
//         }
//     }
// public:
//     AutoCompleteSystem(vector<string>& sentences, vector<int>& times) {
//         root = new TrieNode();
//         for (int i = 0; i < sentences.size(); i++) {
//             insert(sentences[i], times[i]);
//         }
//     }
//     void insert(string sentence, int times) {
//         TrieNode* temp = root;
//         for (int i = 0; i < sentence.size(); i++) {
//             if (temp->children.find(sentence[i]) == temp->children.end()) {
//                 temp->children[sentence[i]] = new TrieNode();
//             }
//             temp = temp->children[sentence[i]];
//         }
//         temp->isEnd = true;
//         temp->freq = times;
//     }
//     vector<string> input(char c) {
//         // write code to return the top 3 suggestions when the current character in the stream is c
//         // c == '#' means , the current query is complete and you may save the entire query into
//         // historical data
//         if (c == '#') {
//             // save the current query into historical data if it is not already present and if it is present then update the frequency
//             insert(currentString, 1);
//             currentString = "";
//             return {};
//         }
//         currentString += c;
//         return getTop3Suggestions(currentString);
//     }
// };


// Hope this helps you in understanding the problem and the solution.