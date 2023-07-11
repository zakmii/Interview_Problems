# Interview_Problems
Just a collection of some good problem's solution. I tried my best to write Industry-standard code.

# I] Huffman Coding
    You are given an array 'freq' of Integers having 'N' elements. The array contains an encoded message.
    For each index 'i', 'freq[i]' denotes the frequency of the 'i'th' character in the message. 
    The characters are of an alien language having 'N' alphabets. 
    Given the frequency of each of the 'N' alphabets in the message, your task is to find out the Huffman codes for each of the 'N' alphabets in the message.

# II] Kirchoff's Matrix Tree
    You are given an adjacency matrix of an undirected connected graph. Find the total number of spanning trees.
    
    Solution: 1) Create a Laplacian matrix of the graph
              2) Remove any 1 row and any 1 column
              3) Find the determinant of the matrix
              4) Determinant is your answer
    P.S: Read about the special case when it is a complete graph. (Cayley's formula)
