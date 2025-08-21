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
