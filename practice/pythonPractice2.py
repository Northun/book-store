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


#Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums

#Input: nums = [1,1,2]
#Output: 2, nums = [1,2,_]

# use two pointer approach

def removeDuplicates(self, nums: List[int]) -> int:
    lenS = len(nums)

    j = 1
    for i in range(1,lenS):
        if nums[i] != nums[i-1]:
            nums[j] = nums[i]
            j = j+1
        
    return j

# Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
    if (not head or not (head.next)):
        return head
    

    
    cur = head
    pre = cur

    next = cur.next
    head = next

    nextNext = cur.next.next
    next.next = cur
    cur.next = nextNext
    cur = nextNext


    while (cur and cur.next):
        next = cur.next
        nextNext = cur.next.next

        pre.next = next
        next.next = cur
        pre = cur
        cur.next = nextNext

        cur = nextNext

    

    return head


#Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

#Return the sum of the three integers.

def threeSumClosest(self, nums: List[int], target: int) -> int:
    # sort the array 
    nums.sort()

    # go through all the elements, and use two pointer method to find closest combination
    lenS = len(nums)
    closeTotal = nums[0] + nums[1] + nums[lenS-1]
    for i in range(lenS):
        left = i+1
        right = lenS-1
        while left < right:
            total = nums[i] + nums[left] +nums[right]
            if abs(total-target) < abs(closeTotal - target):
                if abs(total - target) == 0:
                    return total
                closeTotal = total
            if total < target:
                left += 1
            else:
                right -= 1
    
    return closeTotal


# Given an integer x, return true if x is a palindrome, and false otherwise.

def isPalindrome(self, x: int) -> bool:
    if x < 0:
        return False

    xCopy = x
    
    reverse = 0
    while xCopy > 0:
        reverse = reverse*10 + xCopy%10
        xCopy = xCopy//10
        
    #reverse = reverse*10 + xCopy//10

    return reverse == x

#Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
def letterCombinations(self, digits: str) -> List[str]:
    if not digits:
        return []

    digitMap = {
        '2':'abc',
        '3':'def',
        '4': 'ghi',
        '5': 'jkl',
        '6': 'mno',
        '7': 'pqrs',
        '8': 'tuv',
        '9': 'wxyz',
    }

    idxMax = len(digits)

    def combine(idx, combination):
        if idx == idxMax:
            result.append(combination[:])
            # we don't return value since we modify result already
            return
        
        
        for ch in digitMap[digits[idx]]:
            combine(idx+1, combination + ch)

    result = []
    combine(0,"")

    return result

# Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

def generateParenthesis(self, n: int) -> List[str]:

    result = []
    
    #recursive approach
    def addP(openP, closeP, s):
        if openP == closeP and openP == n:
            result.append(s)
            return 
        
        if openP < n:
            addP(openP+1, closeP, s+"(")
        
        if closeP < openP:
            addP(openP, closeP+1, s+")")

    addP(0,0,"")

    return result

# Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
def permute(self, nums: List[int]) -> List[List[int]]:
    lenS = len(nums)

    result = []

    # using swap to do in site permutation
    def perm(startP):
        if startP == lenS:
            result.append(nums[:])
            return
        
        for i in range(startP, lenS):
            nums[i], nums[startP] = nums[startP], nums[i]
            perm(startP+1)
            nums[i], nums[startP] = nums[startP], nums[i]

    
    perm(0)
    
    return result


# Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
int search(vector<int>& nums, int target) {
    int left = 0;
    //int lenS = len(nums)
    int right = nums.size() - 1;

    //int leftnum = nums[0];
    //int rightnum = nums[-1];

    while (left <= right){
        int mid = (left + right) / 2;

        if (nums[mid] == target)
            return mid;

        if (nums[left] <= nums[mid]){
            //left side is sorted
            if (nums[left] <= target && target < nums[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }

        else{
            if (nums[mid] < target && target <= nums[right])
                left = mid + 1;
            else
                right = mid - 1;
        }
    }
    return -1;
}

