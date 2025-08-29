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
