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


