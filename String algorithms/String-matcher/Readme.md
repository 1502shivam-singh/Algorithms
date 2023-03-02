# String matcher

My very own devised string matching algorithm ~

Given a string S and another string W, we need to find, whether W is a substring of S. 
If W is a substring of S, then return the index where W starts in S, else -1. 

based off of the concept of finite automatons. Once we find the suitable index, we execute the string matching automaton to do it's work :- 

![image](https://user-images.githubusercontent.com/57267960/222542334-b0a5e0e4-1b95-485c-a0b4-d4622d7a03a0.png) 

☝ *Not the automaton for the algorithm, but for reference to how finite automatons execute*

For example

    S = "abcdefefgh"
    W = "def"
    
This will return 3 as S[3]...S[5] = `"def"`

Good thing about this algorithm is that its in O(n) time complexity (where, n = S.size()).

Time complexity = O(n)
Space complexity = O(1)
