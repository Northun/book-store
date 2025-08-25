// my_project_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

//declaration for template
//template <int N>
//void factorial();

template <int N>
constexpr auto factorial() {
    static_assert(N >= 0 && "please input positive number");
    if constexpr (N <= 0)
    {
        return 1;
    }
    else {
        return N * factorial<N - 1>();
    }
}


//two sum
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> twoIndice {};

    //make a hashmap to store the number and index we need
    unordered_map<int, int> numIndexPair;

    for (int i=0; i < nums.size(); i++){
        int wanted = target - nums[i];

        if (numIndexPair.find(wanted) != numIndexPair.end()){
            twoIndice.push_back(i);
            twoIndice.push_back(numIndexPair[wanted]);
            return twoIndice;
        }

        numIndexPair[nums[i]] = i;


    }

    return twoIndice;
}

// use linked list to simulate add two integer

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    // use one variable to store a number
    int carry {0};

    //initialize a list node
    ListNode* dummyHead = new ListNode(0);
    ListNode* curNode = dummyHead;

    //if there are values in any list, we continue
    while(l1 || l2 || carry != 0){
        int currentL1 = 0;
        int currentL2 = 0;
        if(l1){
            currentL1 = l1->val;
        }
        
        if(l2){
            currentL2 = l2->val;
        }
        int sum2 = currentL1 + currentL2 + carry;
        int remain = 0;
        if (sum2 > 9){
            carry = 1;
            remain = sum2 - 10;
        }
        else{
            carry = 0;
            remain = sum2;
        }

        ListNode* next = new ListNode(remain);
        curNode->next = next;

        curNode = next;

        l1 = l1? l1->next : nullptr;
        l2 = l2? l2->next : nullptr;


    }
    ListNode* result = dummyHead->next;
    delete dummyHead;
    return result;
}



//merge two sorted list

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* dummyHead = new ListNode(0);
    ListNode* tail = dummyHead;

    while(list1 && list2){
        if (list1->val >= list2->val){
            tail->next = list2;
            list2 = list2->next;
            //only update with smallest, since we don't know if there are more small number to be inserted
        }else{
            tail->next = list1;
            list1 = list1->next;
        }
        tail = tail->next;
    }
    // so if one of the list is null, then we shoul add the remain of the other list to the end of result list
    tail->next = list1?list1 : list2;
    ListNode* result = dummyHead->next;
    delete dummyHead;
    return result;
}

//valid parentheses
bool isValid(string s) {
    
    std::unordered_map<char, char> match = {
        {')','('},
        {'}','{'},
        {']','['}
    } ;
    //store missing closing elements
    stack<char> missing;

    for(char c : s){
        auto it = match.find(c);
        if (it != match.end()){
            if(missing.empty() || missing.top() != match[c]){
                return false;
            }
            missing.pop();
        }else {
            missing.push(c);
        }
    }

    return missing.empty();
}

//median of two sorted list

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int totalSize = nums1.size() + nums2.size();

    // go through all numbers
    int index1 = 0;
    int index2 = 0;
    vector<int> merge;

    //merge first
    for (int i=0;i<totalSize;i++){
        if ((index1 < nums1.size()) && (index2 < nums2.size())){
            if(nums1[index1] < nums2[index2]){
                merge.push_back(nums1[index1]);
                index1 = index1 + 1;
                
            }else{
                merge.push_back(nums2[index2]);
                index2 = index2 + 1;
            }
        }
        else if(index1 < nums1.size()){
            merge.push_back(nums1[index1]);
            index1 = index1 + 1;
        }
        else{
            merge.push_back(nums2[index2]);
            index2 = index2 + 1;
        }
    }

    if (totalSize%2 != 0){
        return static_cast<double>(merge[totalSize/2]);
    }
    else{
        return static_cast<double>((merge[totalSize/2-1]+merge[totalSize/2])/2.0);
    }
    
}

//Longest Substring Without Repeating Characters
int lengthOfLongestSubstring(string s) {
    string subS {};
    int n = s.length();
    unordered_map<char, int> subIndex {};
    int longest = {0};
    int left = {0};

    for (int right = 0; right < n; right++){
        if (subIndex.count(s[right]) == 0 || subIndex[s[right]] < left ){
            subIndex[s[right]] = right;
            longest = max(longest, right - left +1);
        }else{
            left = subIndex[s[right]] +1;
            subIndex[s[right]] = right;
        }
    }
    return longest;

   
}

//String to Integer (atoi)
int myAtoi(string s) {
    vector<int> readIn = {};
    int sign = 1;//default is +
    bool validIn = false;

    int lenS = s.length();
    int i = {0};

    //remove leading empty space
    while(i < lenS && s[i] == ' '){
        i++;
    }

    if (i == lenS){
        return 0;
    }

    if(s[i] == '+'){
        i++;
        sign = 1;
    }else if(s[i] == '-'){
        i++;
        sign = -1;
    }
    long long num = 0;
    const long long MAXNUM = INT_MAX;
    const long long MINNUM = INT_MIN;
    while(isdigit(s[i]) && (i < lenS)){
        int digit = s[i] - '0';
        num = num*10 + digit;

        if(sign*num > MAXNUM){
            return MAXNUM;
        }

        if(sign*num < MINNUM){
            return MINNUM;
        }

        i++;
    }

    return static_cast<int>(sign*num);


}

// You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

//Find two lines that together with the x-axis form a container, such that the container contains the most water.
int maxArea(vector<int>& height) {
    int left {0};
    int lenList = height.size()-1;
    int right {lenList};

    int container = min(height[left], height[right]) * lenList;

    while(left < right){
        int area = min(height[left], height[right]) * (right - left);
        container = max(container, area);

        if (height[left] < height[right]){
            left = left + 1;
        }else{
            right = right - 1;
        }

    }
    return container;

}


//Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

//Notice that the solution set must not contain duplicate triplets.


vector<vector<int>> threeSum(vector<int>& nums) {
    //make a sum to index table
    unordered_map<int, int> numTable {};

    vector<vector<int>> triplets {};

    int lenS = nums.size();
    //sort nums to make avoiding duplicate easily
    sort(nums.begin(), nums.end());

    for (int i=0; i < lenS; i++){
        if (i >0 && nums[i-1] == nums[i]){
            continue;
        }

        int left = i+1;
        int right = lenS-1;
        while(left < right){
            int sum = nums[i] + nums[left] + nums[right];
            if(sum == 0){
                triplets.push_back({nums[i], nums[left], nums[right]});
                //move left or right, and avoid duplicate
                while(left < right && nums[left] == nums[left+1]) left++;
                while(left < right && nums[right] == nums[right-1]) right--;
                left++;
                right--;
            }else if (sum < 0){
                left++;}
            else{
                right--;}

            
        }
        
    }

    return triplets;
}


int main()
{
    std::cout << "Hello World!\n";
    std::cout << factorial<0>();
    static_assert(factorial<0>() == 1);
    static_assert(factorial<3>() == 6);
    static_assert(factorial<5>() == 120);

    factorial<-3>();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file







