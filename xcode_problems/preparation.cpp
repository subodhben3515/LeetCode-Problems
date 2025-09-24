//
//  preparation.cpp
//  C++ Training Project
//
//  Created by Subodh Benjamin on 09/05/25.
//
#include <iostream>
#include <vector>
#include "pthread.h"

using namespace std;
//s

// C Program for
// checking duplicate
// values in a arrayasdas

void sort(vector<int>& arr, unsigned long size)
{
    //return;
    for(int i = 0; i < size; i++)
    {
        bool swapped = false;
        for(int j = 0; j < size - i - 1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = true;
            }
        }
        
        if(swapped != true)
            break;
    }
    cout <<"After sorting: " << endl;
    for(int i = 0; i < size; i++)
    {
        cout << " " << arr[i];
    }
    cout << endl;
    
}

void dupl()
{
    vector<int> arr = {1,1,4,3,5,5,1};
    
    auto size = arr.size();
    cout<< "size is: " << size << endl;
    sort(arr, size);
    
    for(int i = 0; i < size; i++)
    {
        int flag = 0;
        while(i < size - 1  && arr[i] == arr[i+1])
        {
            flag = 1;
            i++;
        }
        if(flag)
        {
            cout << " Duplicates: " ;
            cout << " " << arr[i] << endl;
        }
    }
    
}

// 5. Write a Program to Replace all 0’s with 1’s in a Number.

void replwithone()
{
    int a = 102301;
    int result = 0;
    int i = 0;
    while(a > 0)
    {
        if(a % 10 == 0)
            result = result + pow(10, i);
        else
            result = result + (a % 10) * pow(10,i);
        i++;
        a = a/10;
    }
    cout << "result is " << result << endl;
}

//6. Write a Program to convert the binary number into a decimal number.

void binaryToDecimal()
{
    int bin = 11011;
    int decimal = 0;
    int i = 0;
    while(bin > 0)
    {
        if(bin % 10 != 0)
        {
            decimal = decimal + pow(2, i);
            cout << "if case, decimal : " << decimal << " i: " << i << endl;
        }
        
        i++;
        bin = bin/10;
    }
    cout << "decimal val is: " << decimal << endl;
}


//8. Write a program to Factorial of a Number.

void factorial()
{
    int a = 13;
    long ans = 1;
    while (a !=1) {
        ans = ans * a;
        a--;
    }
    cout << "factorial is : " << ans << endl;
}

int factorialRecursive(int n)
{
    if(n == 1)
    {
        return 1;
    }
    
    return n * factorialRecursive(n-1);
}

    //9. Write a Program to Check if a number is an Armstrong number or not.


void armstrongNumber()
{
    int a = 370;
    int b = a;
    int count=0;
    int c = a;
    
    while(a > 0)
    {
        count++;
        a = a/10;
    }
    
    int sum = 0;
    
    while(b > 0)
    {
        sum = sum + pow(b%10, count);
        b = b/10;
    }
    
    if (sum == c)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

// 11. Write a Program to reverse a number.

void reverseNumber()
{
    
    int a  = 4321;
    int b = 0;
    int  i = 0;
    while (a != 0) {
        b = (b * 10) + (a % 10);
        cout << " b is : " << b << endl;
        a = a/10;
        i++;
    }
    cout << "Rev number is: " << b << endl;
}

// 12. Check whether a number is a palindrome.

void palindrome()
{
    int a = 55455;
    int c =a ;
    
    int b = 0;
    
    while (a != 0) {
        b = (b*10) + a%10;
        a = a/10;
    }
    if (b == c) {
        cout << "Yes Palindrome" << endl;
    }
    else
    {
        cout << "Nope" << endl;
    }
}

// 16. Write a C Program to find the Maximum and minimum of two numbers without using any loop or condition.
// C program to rotate
// Array by  k elements

void rotateElements()
{
    vector<int> elements = {1,2,3,4,5};
    cout << "before shift" << endl;
    for(auto j : elements)
    {
        cout << " " << j;
    }
    cout << endl;
    int shift = 6;
    int shiftNew = shift;
    // new vector
  /*  vector<int> result{};
    
    for (int i = shift; i < elements.size(); i++) {
        result.emplace_back(elements[i]);
    }
    for (int i = 0; i < shift; i++) {
        result.emplace_back(elements[i]);
    }
    cout << "after shift" << endl;
    for(auto j : result)
    {
        cout << " " << j;
    }
    cout << endl;*/
    
    // input 1,2,3,4,5
    // op 3,4,5,1,2
    // sihft = 2
    
    // same vector
    
   /* for (int i = shift; i < elements.size(); i++)
    {
        if(shiftNew == 0)
            break;
        int temp, j(0);
        
        // promote elements by shift
        
        
        // preserve shift elements and demote them at back
        // determine position
        // size - shifts
        // shift--
        
     //   vector<int>::iterator it = elements.begin();
        
     //   for (auto z=0; it != elements.end() && z<shift; it++,z++) {
            
            
     //   }
    }*/
    int z = 0;
    auto vecSize = elements.size();

    vector<int> dummy(elements.begin(), elements.begin()+shift);
   
    for (int i =0; i < shift; i++) {
        cout << "Going to shift " << elements[i] << endl;

        elements.push_back(elements[i]);
    }
     /*for (auto it = elements.begin(); it != elements.end() &&
     z<shift ; it++,
     z++) {
     cout << "Going to shift " << *it << endl;
     elements.push_back(*it);
     }*/
    
    cout << "after shift" << endl;
    for(auto l : elements)
    {
        cout << " " << l;
    }
    cout << endl;
    
    elements.erase(elements.begin(), elements.begin()+shift);
    
    
    cout << "after erase same" << endl;
    for(auto l : elements)
    {
        cout << " " << l;
    }
    cout << endl;
}



    // C Program for Sorting
    // First half in Ascending order
    // and Second Descending order

// input { 11, 23, 42, 16, 83, 73, 59 }
// output { 11 16 23 83 73 59 42 }

void halfHalf()
{
    vector<int> input({11, 23, 42, 16, 83, 73, 59, 55});
    
    auto size = input.size()/2;
    
    cout << "Before logic"<<endl;
    for (auto list : input) {
        cout << " " << list;
    }
    cout << endl;
    
    for (int i =0; i < size; i++) {
        for (int j = 0; j < size-1; j++) {
            if (input[j] > input[j+1]) {
                auto temp = input[j];
                input[j] = input[j+1];
                input[j+1] = temp;
            }
        }
    }

    for (auto i =size; i < input.size(); i++) {
        
        for (auto k = size; k < input.size()-1; k++) {
            if (input[k] < input[k+1]) {
                auto temp = input[k];
                input[k] = input[k+1];
                input[k+1] = temp;
            }
        }
    }
    
    cout << "After logic"<<endl;
    for (auto list : input) {
        cout << " " << list;
    }
    cout << endl;
}

// remove dupl without sort

void removeDuplWOSort()
{
    vector<int> a({1,1,2,4,3,3,5,6,5,7,1});
    auto size = a.size();
    
    cout << "Before removal, size: "<<size << endl;
    for (auto list : a) {
        cout << " " << list;
    }
    cout << endl;
    
    for(int i = 0 ; i < size ; i++)
    {
        for (int j = i+1; j < size; j++) {
            if (a[i] == a[j]) {
                for (int k = j; k < size-1; k++) {
                    a[k] = a[k+1];
                }
                size--;
                j--;
            }
        }
    }
    
    cout << "After removal, size is: "<< size << endl;
    for(int i = 0 ; i < size ; i ++)
    {
        cout << " " << a[i];
    }
    cout << endl;
    
    
}

    // 5. Write a Program to Replace all 0’s with 1’s in a Number.


void repl0w1()
{
    auto a = 10012300;
    
    // op 11112311
    
    // idea:
    
}

// convert decimal to binary

// 8
// 0000 1000

void dec2bin()
{
    vector<int> result(10);
    auto a = 11;
    
        if (a%2 == 0)
        {
            auto div = a/2;
            result[div-1] = 1;
        }
        else
        {
            auto remainder = a%2;
            
            if(remainder == 1)
            {
                result[0] = 1;
            }
            auto div = a/2;
            result[div-1] = 1;
        }

    cout << " result is: " << endl;
    for (int i = 7; i >= 0; --i) {
        cout << " " << result[i] ;
    }
    cout << endl;
    
}

void charTest()
{
    char s = 65;
    
    cout << "value of s:" << s;
    
}

void swapWo3rdVar()
{
    int a = 5;
    int b = 10;
    
    cout << "a: " << a << " b: " << b<< endl;

    a = a+b;
    b = a-b;
    a = a-b;
    
    cout << "a: " << a << " b: " << b<< endl;
}

void repl0w1Test()
{
    long N = 400032033;
    long result = 0;
    int i =0;
    long dup = N;

    while (dup > 0) {
        int remainder = dup % 10;
        if (remainder == 0) {
            remainder = 1;
        }
        
        result = remainder*pow(10, i) + result;
        
        i++;
        dup = dup/10;
    }
    
    cout << "Original: " << N << "result: " << result << endl;
}

void b2d()
{
    int bin = 1011000;
    int dup = bin;
    int result = 0;
    int i =0;
    
    while (dup > 0) {

        if (dup % 10 != 0) {
            result = pow(2, i) + result;
        }
        
        dup = dup /10;
        i++;
    }
    
    cout << "bin: " << bin << " decimal: " << result << endl;
}

int factwR(int num)
{
    if(num == 0)
        return 1;
    return num*factwR(num-1);
}

void revNum()
{
    int N = 54321;
    long result{0}, i{0};
    
    while (N>0) {
        
        result =  result* 10 +  N%10 ;
        
        i++;
        N = N/10;
    }
    cout << "result is : " << result << endl;

}

inline bool notInFinal(int a, int* final, int finalSize)
{
    if (finalSize == 0 ) {
        return true;
    }
    for (int i =0; i <  finalSize; i++) {
        if (final[i] == a) {
            return false;
        }
    }
    return true;
}

void priRep()
{
    int arr[] = {3,5,1,2,1,6,1,7,3,6,7};
    
    int final[10];
    int finalSize=0;
    
    cout << "Original array, size: " << sizeof(arr)/sizeof(arr[0]) << endl;
    
    for(int i : arr)
        cout<< " " << i;
    
    cout << endl;
    for (int i =0; i < sizeof(arr)/sizeof(arr[0]); i++)
    {
        for (int j = 0; j < sizeof(arr)/sizeof(arr[0]); j++)
        {
            if (i == j) {
                continue;
            }
            
            if (arr[i] == arr[j]) {
                if (notInFinal(arr[i], final, finalSize)) {
                    final[finalSize] = arr[i];
                    finalSize++;
                }
            }
            
        }
    }
    
    cout << " final arr" << endl;
    
    for (int i = 0; i < finalSize; i++) {
        cout << " " << final[i];
    }
    
    cout << endl;
    
}

void remRep()
{
    int arr[] = {3,5,1,2,1,6,1,7,3,6,7};
    
    int final[10];
    int finalSize=0;
    int j = 0;
    int size=sizeof(arr)/sizeof(arr[0]);
    
    cout << "Original array, size: " << sizeof(arr)/sizeof(arr[0]) << endl;
    
    for(int i : arr)
        cout<< " " << i;
    
    cout << endl;
    for (int i =0; i < sizeof(arr)/sizeof(arr[0]); i++)
    {
        //j = 0;
        for (j = 0; j < sizeof(arr)/sizeof(arr[0]); j++)
        {
            if (i == j) {
                continue;
            }
            
            if (arr[i] == arr[j]) {
                break;
            }
        }
        
        if (j == size) {
            final[finalSize] = arr[i];
            finalSize++;
        }
    }
    cout << " final arr" << endl;
    
    for (int i = 0; i < finalSize; i++) {
        cout << " " << final[i];
    }
    
    cout << endl;
    
}

void priOnce()
{
    int arr[] = {3,5,1,2,1,6,1,7,3,6,7};
    int final[10];
    int finalSize=0;
    
    cout << "Original array, size: " << sizeof(arr)/sizeof(arr[0]) << endl;
    
    for(int i : arr)
        cout<< " " << i;
    
    cout << endl;
    for (int i =0; i < sizeof(arr)/sizeof(arr[0]); i++)
    {
        for (int j = 0; j < sizeof(arr)/sizeof(arr[0]); j++)
        {
            if (i == j) {
                continue;
            }
            
            //if (arr[i] == arr[j]) {
                if (notInFinal(arr[i], final, finalSize)) {
                    final[finalSize] = arr[i];
                    finalSize++;
                }
           // }
            
        }
    }
    
    cout << " final arr" << endl;
    
    for (int i = 0; i < finalSize; i++) {
        cout << " " << final[i];
    }
    
    cout << endl;
    
}


void bubsrt()
{
    int arr[] = {3,5,1,2,6,7};

    for (int i =0; i < (sizeof(arr)/sizeof(arr[0])); i++)
    {
        for (int j = i+1; j < (sizeof(arr)/sizeof(arr[0])) -1; j++)
        {
            if (arr[i] > arr[j])
            {
                arr[i] = arr[i] + arr[j];
                arr[j] = arr[i] - arr[j];
                arr[i] = arr[i] - arr[j];
            }
        }
    }
    
    cout<< "After sorting: " << endl;
    
    for (int i : arr) {
        cout << " " << i ;
    }
    cout << endl;
}

// Linked list, stack, queue,

// Single lnked list
// create, search, delete, insert

typedef struct linked_list
{
    int number;
    struct linked_list* next;
}node;

void singlyLL()
{
    void createList(node*);
    void printList(node*);
    void searchList(node*);
    void insertToList(node*);
    node* deleteFromList(node*);
    node* reverseList(node*);

    
    node *head = (node*)malloc(sizeof(node));
    
    createList(head);
    printList(head);
    //10
    searchList(head);
    //insertToList(head);
    printList(head);
    cout << "Head addr is " << std::addressof(head) << endl;
   // head = deleteFromList(head);
    //cout << "After deletion, Head addr is " << std::addressof(head) << endl;

    printList(head);
    cout << "Reversing the list " << endl;
    head = reverseList(head);
    printList(head);


}

node* reverseList(node* head)
{
    node *prev, *current;
    
    prev = NULL; current = head;
    
    cout << "val at head: " << head->number << endl;
    while(current != NULL)
    {
        node* temp = current->next;
        if(temp != NULL)
        cout << "val of temp: " << temp->number << endl;

        current->next = prev;
        prev = current;
        current = temp;
    }
    
    return prev;
}

node* delFList(node* prev, node* curr, int num)
{
    node* tempHead = prev;
    if (prev == NULL) {
        cout << "Cannot del as list is empty" << endl;
    } else {
        if (prev->number == num) {
            tempHead=prev->next;
            free(prev);
            prev=tempHead;
        } else if (curr->number == num){
            prev->next = curr->next;
            free(curr);
        }
        else if(curr->next!=NULL)
        {
            tempHead = delFList(curr, curr->next, num);
        }
        else
        {
            cout<< "Element not found" << endl;
        }
    }
    return tempHead;
}

node* deleteFromList(node* list)
{
    cout << " Enter which element you want to delete: " << endl;
    int del;
    cin >> del;
    
    node* delFList(node*, node*, int);
    
    return delFList(list, list->next, del);
    
}


void insToList(node* list, int num)
{
    if (list == NULL) {
        cout << "Cannot insert as list is empty" << endl;
    } else {
        if (list->number == num) {
            node* newList = (node*)malloc(sizeof(node));
            newList->next = list->next;
            newList->number = 1;
            list->next = newList;
            cout<<"Inseted!" << endl;
        } else if(list->next != NULL) {
            insToList(list->next, num);
            
        }
        else if (list->next == NULL)
        {
            cout<< "Cannot find requested element: " << num << " in the list" << endl;
            
        }
    }
}


void insertToList(node* list)
{
    int num;
    
    cout << "Enter after which element you want to insert" << endl;
    
    cin >> num;
    
    void insToList(node*, int);
    
    insToList(list, num);
    
}



void createList(node *list)
{
    int number = 0;
    cout << "Insert elem (-1 to end)" << endl;
    cin >> number;
    
    if (number == -1) {
        list->number = -1;
        list->next = NULL;
        return;
    }
    else
    {
        list->next = (node*)malloc(sizeof(node));
        list->number = number;
    }
    
    createList(list->next);
    
}

void printList(node *list)
{
    if (list != NULL)
    {
        //if (list->number != -1)
        //{
            cout << " " << list->number;
            printList(list->next);
        //}
        //else
        //{
            cout << "End of list";
            cout << endl;
        //10}
    }
}

void searchList(node* list)
{
    int search{0};
    cout << "Enter which element you want tto search:" << endl;
    
    cin >> search;
    
    bool findElem(node* list, int);
    
    cout << " Element: " << search << " is in the list: " << findElem(list, search) << endl;
    
    
    
}

bool findElem(node* list, int elem)
{
    if (list == NULL) {
        return false;
    }
    
    if (list->number == elem) {
        return true;
    }
    else if (list->next == NULL)
    {
        return false;
    }
    else
    {
        return findElem(list->next, elem);
    }
}

// Doubly LL - TODO
typedef struct doubly
{
    int data;
    struct doubly *prev;
    struct doubly *next;
}dnode;

void printdlist(dnode* list)
{
    if (list->data == -1)
    {
        return;
    }
    else
    {
        cout<< " " << list->data;
        printdlist(list->next);
    }
}


void insDL(dnode* list)
{
    cout<< "Enter values, -1 to stop:" << endl;
    
    int num;
    cin >> num;
    
    if (num == -1) {
        list->data = num;
        list->next = NULL;
        return;
    }
    else
    {
        list->data = num;
        list->next = (dnode*)malloc(sizeof(dnode));
        list->next->prev = list;
    }

    insDL(list->next);
    
}

void doubleLL()
{
    dnode *head = (dnode*)malloc(sizeof(dnode));
    head->prev = head->next = NULL;
    
    void insDL(dnode*);
    void printdlist(dnode*);
    
    insDL(head);
    printdlist(head);
}

// Binary tree
typedef struct bNode
{
    int data;
    struct bNode *left;
    struct bNode *right;

}treeNode;

void insToLeft(treeNode* list, int num)
{
    if (list->left == NULL)
    {
        list->left = (treeNode*)malloc(sizeof(treeNode));
        list->left->data = num;
        list->left->left = list->left->right = NULL;
    }
    else
    {
        insToLeft(list->left, num);
    }
}

void insToRight(treeNode* list, int num);
void insToRight(treeNode* list, int num)
{
    if (list->right == NULL)
    {
        list->right = (treeNode*)malloc(sizeof(treeNode));
        list->right->data = num;
        list->right->left = list->right->right = NULL;
    }
    else
    {
        insToRight(list->right, num);
    }
}

void inorderTraversal(treeNode* list)
{
    if (list == NULL) {
        return;
    }
    
    inorderTraversal(list->left);
    cout << " " << list->data;
    inorderTraversal(list->right);
}

void preOrderTraversal(treeNode* list)
{
    if (list == NULL) {
        return;
    }
    
    cout << " " << list->data;
    preOrderTraversal(list->left);
    //cout << " " << list->data;
    preOrderTraversal(list->right);
}

void postOrderTraversal(treeNode* list)
{
    if (list == NULL) {
        return;
    }
    
    postOrderTraversal(list->left);
        //cout << " " << list->data;
    postOrderTraversal(list->right);
    cout << " " << list->data;

}

void btree()
{

    treeNode* head = (treeNode*)malloc(sizeof(treeNode));
    head->left = head->right = NULL;
    head->data = 5;
    
    void insToLeft(treeNode*, int);
    insToLeft(head, 4);
    insToRight(head->left, 10);
    insToLeft(head, 3);
    insToLeft(head, 2);
    insToLeft(head, 1);
    insToRight(head, 6);
    insToRight(head, 7);
    insToRight(head, 8);
    insToRight(head, 9);
    insToRight(head, 10);
    insToLeft(head, 0);
    insToRight(head, -1);

    
    void inorderTraversal(treeNode* list);
    
    cout << "Inorder " << endl;
    inorderTraversal(head);
    cout  << endl;
    
    cout << "Preorder " << endl;
    preOrderTraversal(head);
    cout  << endl;
    
    cout << "PostOrder " << endl;
    postOrderTraversal(head);
    cout  << endl;
    
}

void insertionSort()
{
    int arr[] = {4,3,1,5,7,2};

    
    cout << endl;
    for (int i : arr) {
        cout << " " << i ;
    }
    cout << endl;
    
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0])-1 ; i++) {
        for (int j = i+1; j > 0; j--) {
            if (arr[j] < arr[j-1]) {
                int temp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = temp;
                //j = j-1;
            }
        }
        
        cout << "Round " << i+1 << " iteration: " << endl;
        for (int k : arr) {
            cout << " " << k ;
        }
        cout << endl;
    }

    cout << endl;
    for (int i : arr) {
        cout << " " << i ;
    }
    cout << endl;
}

/*
 
 Setting bit
 number | ((Uint)1 << n);
 
 Clearing bit
 
 number & ~((Uint)1 << n);

 Toggle bit
 
 number ^ ((Uint)1 << n);

 Checking bit
 
 number & ((Uint)1 << n);
 
 

 

void stringTest()
{
    
    string s1 = "test";
    char b[5] = "test";
    
    if (s1 == *b) {
        cout << "Same string: " << *s1 << endl;
    }
    else
        cout << "Not same" << endl;
}*/

void runningSum()
{
    vector<int> input { 2,1,3,4,0,5,1};
    
    vector<int> output;
    
    int sum = 0;
    
    for (int i : input) {
        sum = sum + i;
        output.emplace_back(sum);
    }
    
    for (int i=0; i < 7; i++) {
        cout<< input[i] << " ";
    }
    cout << endl;
    
    for (int i=0; i < output.size(); i++) {
        cout<< output[i] << " ";
    }
    cout << endl;
}

// templates

template <typename T>
T multiply(T a, T b)
{
    return a*b;
}

template <typename T>
class test
{
public:
    T a;
    T b;
    
    test(T x, T y) : a(x) , b(y)
    {
        cout << " a: " << a << " b: " << b << endl;
    }
};

template <typename A, typename B, typename C>
class test3
{
public:
    A a;
    B b;
    C c;
    
    test3(A ans, B bsn, C cs): a(ans), b(bsn), c(cs){};
    
    void op()
    {
        cout << a << b << c;
    }
    
};

template <typename T> constexpr T val = T(3.14);


template <typename T> int sizePtr(T x)
{
    return ((char*)((&x+1)) - (char*)&x);
}

void dequeue(int* buffer)
{
    
}

void enqueue(int* buffer, int val, int& indexToBeinserte)
{
    if(indexToBeinserte == 30)
    {
        indexToBeinserte = 0;
        //dequeue(buffer);
        //size--;
    }
    
    buffer[indexToBeinserte] = val;
    indexToBeinserte++;
    
}


void circularBuffer()
{
    int buffer[30];
    //int currSize = 0;
    int indexToBeinserted = 0;
    
    for(int i = 0; i <= 29; i ++)
        enqueue(buffer, i, indexToBeinserted);
    
    for(int j : buffer)
        cout << j << " ";
    
    cout << endl;
    for(int i = 31; i <= 60; i ++)
        enqueue(buffer, i, indexToBeinserted);
    
    for(int j : buffer)
        cout << j << " ";
}

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
bool isEvenTurn = true;

void* printOddNumbers(void* arg)
{
    for(int i = 1 ; i <= 10 ; i+=2)
    {
        pthread_mutex_lock(&mutex1);
        while(isEvenTurn)
            pthread_cond_wait(&cond, &mutex1);
        
        cout<< "Odd Number: " << i << endl;
        isEvenTurn = true;
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex1);
    }
    return nullptr;
}

void* printEvenNumbers(void *arg)
{
    for(int i = 0 ; i <= 10 ; i+=2)
    {
        pthread_mutex_lock(&mutex1);
        while(!isEvenTurn)
            pthread_cond_wait(&cond, &mutex1);
        
        cout<< "Even Number: " << i << endl;
        isEvenTurn = false;
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex1);
    }
    return nullptr;
}



void threadOddEven()
{
    /*
     mutex: So that only one thread can access shared data at a time
     conditional variable: Sleep a thread until a condition is condition is met
     
     thread functionality
     
     for loop till n number
     lock mutex
     
        while
        wait
     print num
     notify
     unlock mutex
     */
    
    pthread_t t1, t2;//(printNumbers);//, t2;
    
    pthread_create(&t1, NULL, printEvenNumbers, NULL);
    pthread_create(&t2, NULL, printOddNumbers, NULL);
    
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
   // t1.join();
    
    
}

int main()
{
    //cout << "multiply is : " << multiply<int>(2, 3) << endl;
    //test<int> t(5,10);
    //test3<int, float, double> t1(5, 40.2, 50.5);
    //t1.op();
    cout << endl;
    
    struct tb{
        int a;
        int b;
    }tb;
    
    //cout << " " << sizePtr(tb) << endl;
    
    threadOddEven();//ircularBuffer();
    //cout << val<float> << endl;
    
    //runningSum();
    //int a = 9;
    //factorial();
    //cout << "factorial is : " << factwR(2) << endl;

    //cout << "testing" << endl;
    
    long cpp_version = __cplusplus;
    
    if (cpp_version == 199711L) {
        std::cout << "C++98/03" << std::endl;
    } else if (cpp_version == 201103L) {
        std::cout << "C++11" << std::endl;
    } else if (cpp_version == 201402L) {
       // std::cout << "C++14" << std::endl;
    } else if (cpp_version == 201703L) {
        std::cout << "C++17" << std::endl;
    } else if (cpp_version == 202002L) {
        std::cout << "C++20" << std::endl;
    } else if (cpp_version == 202302L) {
        std::cout << "C++23" << std::endl;
    } else {
        std::cout << "Unknown C++ version: " << cpp_version << std::endl;
    }
    
    return 0;
}

