#The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

#P   A   H   N
#A P L S I I G
#Y   I   R
#And then read line by line: "PAHNAPLSIIGYIR"

def convert(self, s: str, numRows: int) -> str:

    if numRows == 1 or numRows >= len(s):
        return s

    output = [[] for _ in range(numRows)]

    direction = 1
    rowN = 0

    for ch in s:
        output[rowN].append(ch)
        if rowN == 0:
            direction = 1
        elif rowN == numRows-1:
            direction = -1
        
        rowN = rowN+direction
    
    for i in range(numRows):
        output[i] = ''.join(output[i])

    return ''.join(output)
