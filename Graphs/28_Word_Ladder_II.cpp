/*
Given two distinct words startWord and targetWord, and a list denoting wordList of unique words of equal lengths. Find the length of the shortest transformation sequence from startword to targetWord.
Keep the following conditions in mind:
-> A word can only consist of lowercase characters.
-> Only one letter can be changed in each transformation.
-> Each transformed word must exist in the wordList including the targetWord.
-> startWord may or may not be part of the wordList.
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

vector<vector<string>> findSequences(string beginWord, string endWord, vector<string> &wordList)
{
    unordered_set<string> st(wordList.begin(), wordList.end());
    queue<vector<string>> q;
    q.push({beginWord});
    vector<string> usedOnLevel;
    usedOnLevel.push_back(beginWord);

    int lvl = 0;
    vector<vector<string>> ans;
    while (!q.empty())
    {
        vector<string> vec = q.front();
        q.pop();
        // esase all words that has been used in the previous levels to transform
        if (vec.size() > lvl)
        {
            lvl++;
            for (auto it : usedOnLevel)
            {
                st.erase(it);
            }
        }

        string word = vec.back();
        if (word == endWord)
        {
            // first sequence
            if (ans.size() == 0)
            {
                ans.push_back(vec);
            }
            else if (ans[0].size() == vec.size())
            {
                ans.push_back(vec);
            }
        }

        for (int i = 0; i < word.size(); i++)
        {
            char original = word[i];
            for (char c = 'a'; c <= 'z'; c++)
            {
                word[i] = c;
                if (st.count(word) > 0)
                {
                    vec.push_back(word);
                    q.push(vec);
                    // mark as visited on the level;
                    usedOnLevel.push_back(word);
                    vec.pop_back();
                }
            }
            word[i] = original;
        }
    }
    return ans;
}

int main()
{
    string startWord, targetWord;
    cin >> startWord >> targetWord;

    int m;
    cin >> m;
    vector<string> wordList(m);
    for (int i = 0; i < m; i++)
    {
        cin >> wordList[i];
    }

    vector<vector<string>> output = findSequences(startWord, targetWord, wordList);
}