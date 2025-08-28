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

#Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

#Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

def reverse(self, x: int) -> int:
    sign = True if x > 0 else False
    INT_MAX = 2**31 - 1  # 2147483647
    INT_MIN = -2**31  
    
    first_digit_pos = int(str(abs(INT_MAX))[-1])
    other_digit_pos = int(str(abs(INT_MAX))[:-1])
    
    first_digit_neg = int(str(abs(INT_MIN))[-1])
    other_digit_neg = int(str(abs(INT_MIN))[:-1])

    #devide by 10,100,... get the remainder as the reverse
    result  = 0
    while x != 0:
        
        remainder = x%10 if x >0 else -(abs(x)%10)
        # check if overflow
        if sign and (result > other_digit_pos or (result == other_digit_pos and remainder > first_digit_pos)):
            return 0
        elif not sign and (result < -other_digit_neg or (result == -other_digit_neg and remainder < -first_digit_neg)):
            return 0
        
        result = result*10 + remainder
        
        x = x // 10 if x >0 else -(abs(x)//10)

    return result
