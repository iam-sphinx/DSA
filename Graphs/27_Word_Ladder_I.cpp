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
#include <queue>
#include <unordered_set>
using namespace std;
int wordLadderLength(string &startWord, string &targetWord, vector<string> &wordList)
{
    queue<pair<string, int>> q;
    q.push({startWord, 1});
    unordered_set<string> st(wordList.begin(), wordList.end());
    st.erase(startWord);
    while (!q.empty())
    {
        string word = q.front().first;
        int steps = q.front().second;
        q.pop();

        if (word == targetWord)
            return steps;

        // N x wordList x 26 x log N
        for (int i = 0; i < word.size(); i++)
        {
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;
                if (st.find(word) != st.end())
                {
                    st.erase(word);
                    q.push({word, steps + 1});
                }
            }
            word[i] = original;
        }
    }
    return 0;
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

    cout<<wordLadderLength(startWord, targetWord, wordList);
}