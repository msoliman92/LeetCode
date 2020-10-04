/*
* 763. Partition Labels
* A string S of lowercase English letters is given. We want to partition this string into as many parts as possible 
* so that each letter appears in at most one part, and return a list of integers representing the size of these parts.
*
* Example 1:
* -----------
* Input: S = "ababcbacadefegdehijhklij"
* Output: [9,7,8]
* Explanation:
* The partition is "ababcbaca", "defegde", "hijhklij".
* This is a partition so that each letter appears in at most one part.
* A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.
*/

class Solution {
public:
    vector<int> partitionLabels(string S) 
    {
    vector<int> index(26 , 0);
    
    for(int i=0; i<S.length(); i++)
    index[S[i] - 'a'] = i;          // store the last index of that character
    
    int limit = 0, count = 0 ;
    
    vector<int> ans;
    
    for(int i=0; i<S.length(); i++)
    {
        limit = max( limit , index[S[i] - 'a']);    // ending of that particular char
        count++;
        if(i == limit)                          // if ending if set and i matches 
        {
            ans.push_back(count);
            count=0;
        }
    }
    return ans;
    }
};

