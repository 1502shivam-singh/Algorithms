# String matcher

My very own devised string matching algorithm ~

Given a string S and another string W, we need to find, whether W is a substring of S. 
If W is a substring of S, then return the index where W starts in S, else -1. 

For example

    S = "abcdefefgh"
    W = "def"
    
This will return 3 as S[3]...S[5] = `"def"`

Good thing about this algorithm is that its in O(n) time complexity (where, n = S.size()).

Time complexity = O(n)
Space complexity = O(1)
