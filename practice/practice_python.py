def twoSum(self, nums: List[int], target: int) -> List[int]:
    twoIndice = []

    #python use dictionary
    numIndice = {}
    for i, num in enumerate(nums):
        wanted  = target - num
        if wanted in numIndice:
            twoIndice.append(i)
            twoIndice.append(numIndice[wanted])
            return twoIndice
        numIndice[num] = i
    
    return twoIndice


def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
    dummyHead = ListNode(0)
    curNode = dummyHead
    carry = 0
    while (l1 is not None) or (l2 is not None) or (carry != 0):
        value1 = l1.val if (l1 is not None) else 0
        value2 = l2.val if (l2 is not None) else 0
        
        sum2 = value1 + value2 + carry
        carry = sum2//10
        remainder = sum2%10

        nextNode = ListNode(remainder)
        curNode.next = nextNode
        curNode = nextNode
        
        l1 = l1.next if l1 else None
        l2 = l2.next if l2 else None
        
    

    result = dummyHead.next
    return result

# merge two sorted list
def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
    dummyHead = ListNode(0)
    tail = dummyHead

    while list1 and list2 :
        if list1.val >= list2.val:
            tail.next = list2
            list2 = list2.next
        else:
            tail.next = list1
            list1 = list1.next
        tail = tail.next
    tail.next = list1 if list1 else list2

    return dummyHead.next

# match parentheses

def isValid(self, s: str) -> bool:
    match = {'}':'{', ']':'[', ')':'('}

    missing = []

    for c in s:
        if c in match.values():
            missing.append(c)
        elif c in match:
            if not missing or match[c] != missing.pop():
                return False
    return not missing

# find the median of two sorted list

def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
    i1 = i2 = 0
    len1 = len(nums1)
    len2 = len(nums2)
    totalNum = len1 + len2

    merge = []
    #merge two list
    for i in range(totalNum):
        if i1 < len1 and i2 <len2:
            if nums1[i1] < nums2[i2]:
                merge.append(nums1[i1])
                i1 = i1 + 1
            else:
                merge.append(nums2[i2])
                i2 = i2 + 1
        elif i1 < len1:
            merge.append(nums1[i1])
            i1 = i1 + 1
        else:
            merge.append(nums2[i2])
            i2 = i2 + 1
        
    if totalNum%2 != 0:
        return float(merge[totalNum//2])
    else:
        return float((merge[totalNum//2-1]+merge[totalNum//2])/2.0)

# Longest Substring Without Repeating Characters
def lengthOfLongestSubstring(self, s: str) -> int:
    longest = 0
    left = 0
    lenS = len(s)
    charIndex = {}

    for right in range(lenS):
        if( (s[right] not in charIndex) or (charIndex[s[right]] < left)):
            charIndex[s[right]] = right
            longest = max(longest, right - left +1)
        else:
            left = charIndex[s[right]] + 1
            charIndex[s[right]] = right
            
    
    return longest


        if num*sign < minN:
            return minN
        
        i = i+1

    return num*sign        

# You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

# Find two lines that together with the x-axis form a container, such that the container contains the most water.

def maxArea(self, height: List[int]) -> int:
    left = 0
    right = len(height) - 1
    container = 0
    while left < right:
        area = min(height[left], height[right])*(right - left)
        container = max(container, area)

        if height[left] < height[right]:
            left = left + 1
        else:
            right = right - 1
    
    return container

#Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

#Notice that the solution set must not contain duplicate triplets.

def threeSum(self, nums: List[int]) -> List[List[int]]:
    lenS = len(nums)
    triplets = []
    nums.sort()

    for i in range(lenS):
        if i > 0 and nums[i] == nums[i-1]:
            continue;

        left = i+1
        right = lenS-1
        while left < right:
            sums = nums[i] + nums[left] + nums[right]

            if sums == 0:
                triplets.append([nums[i], nums[left], nums[right]])

                while left < right and nums[left] == nums[left+1]:
                    left+= 1
                while left < right and nums[right] == nums[right-1]:
                    right-= 1
                left+= 1
                right-= 1
            
            elif sums < 0:
                left+= 1
            else:
                right-= 1
    
    return triplets

#Longest Palindromic Substring

def longestPalindrome(self, s: str) -> str:
    longest = s[0]

    lenS = len(s)

    def searchPalin(left,right):
        while(left >= 0 and right < lenS):
            if (s[left] == s[right]):
                left -= 1
                right += 1
            else:
                break
        
        return s[left+1:right]



    for i in range(lenS-1):
        # search palindrome using each i as a center
        oddP = searchPalin(i-1,i+1)
        evenP = searchPalin(i, i+1)

        if len(oddP) > len(longest):
            longest = oddP
        
        if len(evenP) > len(longest):
            longest = evenP



    return longest
