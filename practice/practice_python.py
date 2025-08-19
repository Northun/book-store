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