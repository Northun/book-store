// Zigzag Conversion


  string convert(string s, int numRows) {
      if (numRows == 1 || numRows >= s.length()) {
          return s;
      }

      int direction = 1;
      int rowN = 0;

      vector<vector<char>> output(numRows);

      for (char c: s){
          output[rowN].push_back(c);
          if (rowN == 0){
              direction = 1;
          }
          else if(rowN == numRows-1){
              direction = -1;
          }
          rowN = rowN + direction;
      }

      string result;
      for (const auto& row:output){
          for (char c:row){
              result = result + c;
          }
      }

      return result;
  }

//Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

//Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
  int reverse(int x) {

 
      bool sign = (x>0);
      //INT_MAX = 2**31 - 1  # 2147483647
      //INT_MIN = -2**31  
      
      int last_digit_pos = INT_MAX%10;
      int other_digit_pos = INT_MAX/10;
      
      int last_digit_neg = -(INT_MIN%10);
      int other_digit_neg = -(INT_MIN/10);

      //devide by 10,100,... get the remainder as the reverse
      int result  = 0;
      while (x != 0){
          
          int remainder = x%10;
          // check if overflow
          if (sign && (result > other_digit_pos || (result == other_digit_pos and remainder > last_digit_pos)))
              return 0;
          else if (!sign && (result < -other_digit_neg || (result == -other_digit_neg and remainder < -last_digit_neg)))
              return 0;
          
          result = result*10 + remainder;
          
          x = x/10;
      }
      return result;
      
  }
//Input: nums = [1,1,2]
//Output: 2, nums = [1,2,_]
  int removeDuplicates(vector<int>& nums) {
       
      int lenS = nums.size();

      int j = 1;
      for (int i=1; i < lenS;i++){
          if (nums[i] != nums[i-1]){
              nums[j] = nums[i];
              j = j+1;
          }
      }
      return j;
  }




//Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

ListNode* swapPairs(ListNode* head) {
    if (!head || !(head->next)) {
        return head;
    }

    

  
    ListNode* cur = head;
    ListNode* pre = cur;

    ListNode* next = cur->next;
    head = next;

    ListNode* nextNext = cur->next->next;
    next->next = cur;
    cur->next = nextNext;
    cur = nextNext;


    while (cur && cur->next){
        ListNode* next = cur->next;
        ListNode* nextNext = cur->next->next;

        pre->next = next;
        next->next = cur;
        pre = cur;
        cur->next = nextNext;

        cur = nextNext;

    }

    return head;
}

//Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

//The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.

//Return the quotient after dividing dividend by divisor.

int divide(int dividend, int divisor) {
        int32_t Imax = int32_t((1u << 31) - 1);
        int32_t Imin = -(1u << 31);

        int sign = 1;
        if ((dividend < 0) ^ (divisor < 0)) {
            sign = -1;}

        
        if (dividend == Imin && divisor == -1)
            return Imax;
        
        if (divisor  == -1)
            return -dividend;
            
        if (divisor == 1)
            return dividend;
        
        if (dividend == 0)
            return 0;

        //convert to negative number to prevent overflow
        int negDividend =  dividend < 0 ? dividend : -dividend;
        int negDivisor = divisor < 0 ? divisor : -divisor;
        
        if (negDividend > negDivisor)
            return 0;

        int quotient = 0;
        //left shift a neg number will double it as long as no overflow
        while (negDividend <= negDivisor){
            int shift = 0;
            int shiftDivisor = negDivisor;
            // be careful, we should check overflow before we do the shift, since overflow is undefined
            while (shiftDivisor >= (Imin >>1) && negDividend <= (shiftDivisor<<1)){
                shiftDivisor = shiftDivisor << 1;
                // if we get positive number after shift, that means we overflow
            }
            // after the while loop, we actually shift one more than necessary
            negDividend = negDividend - (negDivisor << (shift));
            quotient = (1 << (shift)) + quotient;
        
        }
        return sign > 0 ? quotient : -quotient;
}



//Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

//Return the sum of the three integers.
int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());

    // go through all the elements, and use two pointer method to find closest combination
    int lenS = nums.size();
    int closeTotal = nums[0] + nums[1] + nums[lenS-1];
    for (int i=0; i < lenS; i++){
        int left = i+1;
        int right = lenS-1;
        while (left < right){
            int total = nums[i] + nums[left] +nums[right];
            if (abs(total-target) < abs(closeTotal - target)){
                if (abs(total - target) == 0)
                    return total;
                closeTotal = total;
            }
            if (total < target){
                left++;}
            else
                right--;
        }
    }
    return closeTotal;

}


//Given an integer x, return true if x is a palindrome, and false otherwise.
bool isPalindrome(int x) {
    if (x < 0)
        return false;

    int xCopy = x;
    
    int reverse = 0;

    int overflowBar = INT_MAX / 10;
    while (xCopy > 0){
        
        reverse = reverse*10 + xCopy%10;
        
        xCopy = xCopy/10;
        if (reverse > overflowBar)
            break;
    }


    return reverse == x;
}

// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

vector<string> letterCombinations(string digits) {

    vector<string> result;
    if (digits.size() == 0)
        return result;

    unordered_map<char, string> digitMap = {
        {'2',"abc"},
        {'3',"def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"},
    };

    int idxMax = digits.size();

    combine(result, digits, idxMax, 0, digitMap, "");

    return result;

    
}


void combine(vector<string>& result, const string& digits, int idxMax, int idx, const unordered_map<char, string>& digitMap, string combination){
    if (idx == idxMax){
        result.push_back(combination);
        // we don't return value since we modify result already
        return;
    }
    
    string letters = digitMap.at(digits[idx]);
    for (char ch : letters){
        combine(result, digits, idxMax, idx+1, digitMap, combination + ch);
    }
}
