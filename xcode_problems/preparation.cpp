//
//  preparation.cpp
//  C++ Training Project
//
//  Created by Subodh Benjamin on 09/05/25.
//
#include <iostream>
#include <vector>
#include "pthread.h"
#include <arpa/inet.h>
#include <errno.h>
#include <netinet/in.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <cstring>
#include <regex>


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

string removeNumerics(string &s)
{
    string temp;
    
    for(int i = 0 ; i < s.size() ; i ++)
    {
        if(s[i] >= 65 or s[i] <=91)
        {
            temp = temp+s[i];
            continue;
        }
        
    }
    cout<< "Without numerics: " << temp;
    return temp;
}

bool stringPalindromCheck()
{
    string s = "S4U3B4U66666666666s";
    //string::iterator start = s.begin();//cout <<"start value: " << *start;
    //string::iterator end = s.end();
    
    int i = 0;
    auto j = s.size();
    while(i<j)
    {
        while(i<j && !isalpha(s[i])) i++;
        while(i<j && !isalpha(s[j])) j--;

        if(tolower(s[i]) != tolower(s[j]))
        {
            cout<< "Not a palindrome" << endl;;

            return false;
        }
           
        i++;
        j--;
    }
    cout<< "It's palindrome" << endl;

    //string s2 = removeNumerics(s);
    
    //char *start, *end;
    
    //start = s;
    //end = (char*)(&s2+s2.size());
    
    cout<< "string addr is: " << &s << endl;
    return true;
    
    
}

void copyConstructorDemo()
{
    class string
    {
    public:
        char *c;
        
        string()
        {
            c = new char[20];
            strcpy(c, "Default value");
            cout << "c: " << c << endl;
        }
        string(char* value)
        {
            c = new char[20];
            strcpy(c, value);
            cout << "c: " << c << endl;
        }
        //string(string& s)
        void print()
        {
            cout << "Addr of c:" << &c << endl;
            cout << "c points to address: " << static_cast<void*>(c) << endl;
            cout << "c: " << c << endl;
        }
        
        void deleteChar()
        {
            delete c;
        }
        string(const string &s)
        {
            c = new char[20];
            strcpy(c, s.c);
            
        }
        
        string& operator=(string& other)
        {
            cout << "Subodh assignment operation"<< endl;;
            if(this != &other)
            {
                delete[] c;
                c = new char[20];
                strcpy(c, other.c);
            }
            //this->c = other.c;
            
            return *this;
        }
    };
    
    string s1;
    string s2 ="Subodh";
    s2.print();
    string s3 = s2;
   // s3=s2;
    s3.print();
    string s4 = s2;
    s2.deleteChar();
    s3.print();
    s4.print();
    string s5;
    s5 = s4;
    s5.print();
}

void reverseSentence(string& s)
{
    cout << "Size: " << s.size() << endl;
    string tmp(s.size(), '\0');
    for(int i = 0; i < s.size(); i++)
    {
        cout << "Copying" << s[s.size() - i - 1] << endl;
        tmp[i] = s[s.size() - i - 1];
    }
    
    cout << "Reversed Sentence: " << tmp << endl;
    
    s = tmp;
}

void reverseWords(string& s)
{
    int first = 0; int last = 0;
    //int nextFirst = 0;
    int i = 0;
    int lastTmp=0;
    
    while(true)
    {
        cout <<"first while, i:" << i << "s[i] =" <<s[i]<< endl;
        last = lastTmp;
        while(s[i] != ' ' && s[i]  != '\0') {cout << " second while" << endl;last++;i++;}
        lastTmp = last;
        
        //nextFirst = last+1;
        last--;
        
        while(first < last)
        {
            cout<< "third while" << endl;
            char tmp = s[first];
            s[first] = s[last];
            s[last] = tmp;
            
            first++;
            last--;
        }
        first = lastTmp +1;

        if(s[i] == '\0')
            return;
        else{
            i++;lastTmp++;}
        
        
    }
}

void revStringWhilePreservingOrder()
{
    
    std::string s = "me love programming";
    string tmp(s);
    
    void reverseSentence(string&);
    
    void reverseWords(string&);
    
    reverseSentence(s);
    cout << " Modified sentence: " << s << endl;

    
    reverseWords(s);
    
    cout << " Original: " << tmp << endl;
    
    cout << " Modified: " << s << endl;
    

}

void changeEndianess()
{
    
    /*
     Little Endian: (Least significant byte is on the left most side or lowest memory address)
     0x00f0   16
     0x00f1    0
     
     Big Endian (Most significant byte is on the right most side or lowest memory address)
     0x00f0    0
     0x00f1   16
     
     
     In our example

     int a = 0x18192021;

     Little endian
     
     00d0 21
     00d1 20
     00d2 19
     00d3 18
     
     Big endian
     
     00d0 18
     00d1 19
     00d2 20
     00d3 21
     
     21 -> 0010 0001 (33)
     */
    int a = 0x18192021;

    cout << hex << " a: 0x" << a << endl;
    
    int leftMostByte = (a & 0x000000FF) << 24; // After AND opertion result would be 0x00000021
    int leftMiddleByte = ( a & 0x0000FF00) << 8; // After AND opertion result would be 0x0002000
    int rightMiddleByte = (a & 0x00FF0000) >> 8; // After AND opertion result would be 0x00190000
    int rightMostByte = (a & 0xFF000000) >> 24; // After AND opertion result would be 0x18000000
    
    int b = (leftMostByte | leftMiddleByte | rightMiddleByte | rightMostByte);
    
    cout << hex << " b: 0x" << b << endl;

}

void socketProgrammingTest()
{
    /*
     Server:
     
     socket
     bind
     listen
     accept
     send/recv/read
     close
     
     Client:
     
     socket
     connect
     send/recv/read
     close
     
     */
    int size =1024;
    char buffer[1024];
    
    char msg[]="hello";
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    
    struct sockaddr_in serverAddr;
    
    memset(&serverAddr, 0 , sizeof(serverAddr));
    
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr=inet_addr("0.0.0.0");
    serverAddr.sin_port = htons(8080);
    
    bind(sock, serverAddr, sizeof(serverAddr));
    
    listen(sock, 10);
   // auto addrLen = sizeof(serverAddr);
    socklen_t addrlen = sizeof(serverAddr);

    int new_sock = accept(sock, (struct sockaddr *)&serverAddr, &addrlen);
    
    read(new_sock,buffer, size);
    
    send(new_sock, msg, strlen(msg), 0);
    
    close(new_sock);
    close(sock);
    
    
    
    // Client
    
    // same socket
    connect(sock,(struct sockaddr *)&serverAddr,addrlen);
    
    send(new_sock, msg, strlen(msg), 0);

    
}

void testProgramPointers()
{
    int a = 5;
    int *p = &a;
    
    cout << "a: " << a << endl;
    cout << "*p: " << *p << endl;
}

void fileOpen()
{
    FILE *fp;
    char buff[100];
    
    fp = fopen("/tmp/dummy.txt", "rw");
    
    if(fp == NULL) {
        printf("Not able to open the file.\n");
        return;
    }
    fprintf(fp, "Using fprintf\n");
    fputc('X', fp);
    fputs("SUUUBBUU\n", fp);
    
    fgets(buff, 100, fp);
    
    cout << "buff: " << buff<< endl;
    
    fgets(buff, 100, fp);
    
    cout << "buff: " << buff<< endl;
    
    fclose(fp);
    
    
}

void stringTest()
{
    string str = "hello";
    string str1("bye");
    
    // Accessing
    cout << str[3] << endl;
    cout <<str1.at(2) << endl;
    
    // size
    cout << str.size() << endl;
    cout << str1.length() << endl;
    
    //concat
    string result = str + " " + str1;
    
    cout << result << endl;
    
    string r2("Bye");
    string r3 = r2;
    string r4 = r3;
    
    r2.append(str1);
    
    cout << r2 << endl;
    
    // insert/erase/pop/push
    
    cout << str << endl;

    str.push_back('!');
    
    cout << str << endl;

    str.pop_back();
    
    cout << str << endl;

    str.insert( 5, " Subodh");
    
    cout << str << endl;

    
    str.erase(5, 7);
    
    cout << str << endl;

    
    // substring
    
    str.insert( 5, " Subodh");

    string myStr = str.substr(6, 6);
    
    cout << myStr << endl;

    // find a string
    
    auto pos = myStr.find("oh");
    
    if(pos < myStr.length())
        cout << "Found String" << endl;
    else
        cout << "String doesn't exist" << endl;

    // replace -- many overloads.
    
    myStr.replace(0, 3 , 3, '?');
    cout << myStr << endl;
    
    // Comparision

    if(r4 == r3)
        cout << "Same strings" << endl;
    else
        cout << " different" << endl;
    
    if(r3.compare(r4) == 0)
        cout << "Same" << endl;
    else
        cout << "Different" << endl;
}

void regexPattern()
{
    string para = "Subodh number is +918331-89653. Other numbers are 12312 123 0123-123 12";
    std::regex pattern("\\+91\\d{4}-\\d{5}");
    
    if(std::regex_search(para, pattern))
        cout << "pattern present" << endl;
    else
        cout<< "Not found"  << endl;
    
    std::smatch match;
    if(std::regex_search(para, match, pattern))
        cout << "pattern present: " << match.str() << endl;
    else
        cout<< "Not found"  << endl;
    
}

int fpTest(int a, int b)
{
    return a+b;
}

void functionPointer()
{
    int (*func)(int, int);
    
    func = fpTest;
    
    cout << func(5,5) << endl;;
}


void diamondProblem()
{
    
    class A
    {
    public:
        virtual void print()
        {
            cout << "Base class A, print" << endl;
        }
    };
    
    class B : virtual public A
    {};
    class C : virtual public A
    {};
    class D : public B, public C
    {};
    
    D d;
    A a;
    a.print();
    d.print();
}

int&& x =5;
int z = 10;
int y = std::move(z);

class Env{
    
    Env(){};
    Env(const Env& e) = delete;
    ~Env(){};

    
public:
    int data;
    static Env& getInstance()
    {
        static Env ptr;

       /* if(ptr == NULL)
        {
            ptr = new Env();
        }*/
            return ptr;
    }
};

//Env Env::ptr;


void singletonDesignPattern()
{


    
    Env& ev1 = Env::getInstance();
    ev1.data = 5;
    //delete ev1;
    //ev1->data = 5;
    
    Env& ev2 = Env::getInstance();

    
    //, ev2;
    
    cout << "ev1: " << ev1.data << endl;
    cout << "ev2: " << ev2.data << endl;

    
    
    
}

class operOver
{
public:
    std::string s1;
    
    operOver(std::string str)
    {
        s1 = str;
    }
    
    std::string operator+(int val)
    {
        s1 = s1 + to_string(val);
        //strcat(s1, to_string(val));
        //strcpy(s1, result);
        return s1;
    }
};
void operatorOverload()
{
    operOver obj("Time is: ");
    
    cout << obj+1400 << endl;
    cout << obj.operator+(1500) << endl;
    
}

void bitwiseTest()
{
    std::bitset<8> i = 0b00011011;
    
    cout << "Original : " << i << endl;
    cout << "Setting 3rd bit to 1: "<< (i | std::bitset<8>(1 << 2)) << endl;
    cout << "Clearing 3rd bit to 0: "<< (i & ~std::bitset<8>(1 << 2)) << endl;
    cout << "Flipping 3rd bit : "<< (i ^ std::bitset<8>(1 << 2)) << endl;
    cout << "Flipping 4th bit : "<< (i ^ std::bitset<8>(1 << 3)) << endl;
    cout << "Checking if 3rd bit is 1: " << (i & std::bitset<8>(1 << 2)) << endl;
    cout << "Checking if 4th bit is 1: " << (i & std::bitset<8>(1 << 3)) << endl;


    auto a = i & std::bitset<8>(1 << 4);
    cout << "value of a[4]: " << a[4] << endl;
}

void decimalToHexa()
{
    /*
     Hexadecimal -> 4 group of 4 bits -> 16 bits -> base16
     
     00011011 -> 0000 0000 0001 1011 -> 001B -> 1B
     
     17 -> convert to Hexa
     
     10001 -> Binary
     0001 0001 -> 11
     
     55 to Hexa
     div by 16 -> quo 3 rem 7
     div by 16 -> quo 0 rem 7
     
     37 is the Hex
     
     55
     
     110111 -> 0011 0111 -> 37
     
     40 to Hex -> 28
     
     div -> 2 8
     div -> 0 2
     
     28 to Hex -> 1C
     div -> 1 12
     div -> 0 1
     
     */
   // std::bitset<8> i = 0b00011011;

    
    std::bitset<16> x = 0x26;
    
    cout << "x: " << x << endl;
    cout << "WTF!!! " << x.to_ulong() << endl;
    
    string val;
    //int count  = 0;

    for(auto i = 15; i >= 0; --i)
    {
            val += std::bitset<1>(x[i]).to_string();
            //count++;
    }
    
    cout << "Final string: " << val << endl;
    
    std::bitset<16> dec(val);
    cout << "string to bitset: " << dec << endl;

    
    cout << "Decimal value is: " << dec.to_ulong() << endl;
    
}

void decToHex()
{
    
    int val = 33;
    cout << "Decimal: " << val << endl;
    
    std::bitset<16> hex(val);
    
    int remain = 0, quo = 0, temp = val;
    std::string s{"0x"};
    while(true)
    {
        quo = temp/16;
        
        if(quo == 0)
        {
            if (temp < 10)
                s +=(temp + '0');
            else
                s +=( (temp-10) + 'A');
            cout << "Adding temp: " << temp << endl;
            break;
        }
        remain = temp%16;
        
        cout << "Adding quo: " << quo << endl;
        if (quo < 10)
            s += (quo + '0');
        else
            s+= 'A' + (quo - 10);
        
        temp = remain;
        cout << "s is " << s << endl;
    }
    cout << "Hex is " << s << endl;
    
    // Optimized
    remain = 0; quo = 0; temp = val;
    string s1;
    
    while(temp > 0)
    {
        int remain = temp %16;
        
        if(remain < 10)
            s1 = char('0' + remain) + s1;
        else
            s1 = char('A' + (remain-10)) + s1;
        
        temp /= 16;
    }
    s1 = "0x" + s1;
    cout << "Optimized approach, hex: " << s1 << endl;
}

template <typename T>
T findMaxValue(T a, T b)
{
    return a > b ? a : b;
}

template <class C, class B>
int testClassTemplate(C c, B b)
{
    return c.i * b.j;
}

void templateTest()
{

    cout << findMaxValue(1,2) << endl;
    
}

// Template Metaprogramming

template<int N> struct factorialTemp
{
    static const int value = N * factorialTemp<N-1>::value;
};

template<> struct factorialTemp<0>
{
    static const int value = 1;
};

void factorialTemplate()
{
    cout << "factotial of 5: "<< factorialTemp<5>::value << endl;
}

// Own atoi function
void myAtoi()
{
    
    string s("536");
    int res = 0;
    
    for(char c : s)
    {
        res = (res*10)+(c-'0');
    }
    
    cout << "res: " << res << endl;
}

// TBD

// LL reverse

node* reverseLinkedList(node* head)
{
    node *prev, *curr;
    
    prev = NULL;
    curr = head;
    
    while(curr != NULL)
    {
        node * temp;
        
        temp = curr->next;
        
        curr->next = prev;
        
        prev = curr;
        curr = temp;
    }
    return prev;
}

node* reverseLLRecursive(node* head)
{
    /*
     find the last node
     pass last node to prev fun call as head
     set curr's next node to point to curr node
     */
    
    if(head == NULL || head->next == NULL)
        return head;
    
    node* revHead = reverseLLRecursive(head->next);
    
    head->next->next = head;
    head->next = NULL;
    
    return revHead;
    
}

void LLReverse()
{
    linked_list *head = (linked_list*)malloc(sizeof(linked_list));

    createList(head);
    printList(head);
    head = reverseLinkedList(head);
    printList(head);
    head = reverseLLRecursive(head);
    printList(head);
}
// Sorting

void sortingTest()
{
    std::vector<int> listToSort = {19,2,5,22,34,3,6,5};
    
    cout << " Before sorting" << endl;
    for(auto temp : listToSort)
    {
        cout << temp << " ";
    }
    cout << endl;
    
    for(int i =0 ; i< listToSort.size() ; i++)
    {
        for(int j = 0 ; j < listToSort.size() ; j++)
        {
            for(int k = j+1 ; k < listToSort.size() ; k++)
            {
                if(listToSort[j] > listToSort[k])
                {
                    auto tmp = listToSort[j];
                    listToSort[j] = listToSort[k];
                    listToSort[k] = tmp;
                }
            }
        }
    }
    
    cout << " After sorting" << endl;
    for(auto temp : listToSort)
    {
        cout << temp << " ";
    }
    cout << endl;
    
}

void selectionSort()
{
    /*
     
     Find largest or smallest and shift it to the last or first position
     
     */
    
    std::vector<int> arr = {19,2,5,22,34,3,6,5};
    cout << " Before sorting" << endl;
    for(auto temp : arr)
    {
        cout << temp << " ";
    }
    cout << endl;
    
    auto positionToSwap = arr.size()-1;
    int positionChoosen = 0;
    int j = 0;
    
    for(int i = arr.size()-1; i >=0  ; --i)
    {
        positionChoosen = i;
        cout << "new loop start" << endl;

        for(j = i-1; j >=0; --j)
        {
            if(arr[j] > arr[positionChoosen])
            {
                cout << "Largest element:" << arr[j] << "at pos j: " << j << endl;
                positionChoosen = j;
            }
        }
        
        cout << "loop ended: " << endl;
        
        std::swap(arr[positionToSwap], arr[positionChoosen]);
        positionToSwap--;
    }

    cout << " After sorting" << endl;
    for(auto temp : arr)
    {
        cout << temp << " ";
    }
    cout << endl;
    
}

void bubbleSort()
{
    std::vector<int> arr = {19,2,5,22,34,3,6,5};
    cout << " Before sorting" << endl;
    for(auto temp : arr)
    {
        cout << temp << " ";
    }
    cout << endl;
    
    
    bool swapped = false;
    for(int i = 0 ; i < arr.size()-1; i++)
    {
        for(int j = 0; j < arr.size()-1-i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                swapped = true;
                std::swap(arr[j], arr[j+1]);
            }
        }

    }
    cout << " After sorting" << endl;
    for(auto temp : arr)
    {
        cout << temp << " ";
    }
    cout << endl;
    
}

void insertionSortOptimized()
{
    /*
     Thinks left side is always sorted
     
     */
    std::vector<int> arr = {19,2,5,22,34,3,6,5};
    cout << " Before sorting" << endl;
    for(auto temp : arr)
    {
        cout << temp << " ";
    }
    cout << endl;
    
    for(int i = 1; i<arr.size(); i++)
    {
        int key = arr[i];
        int keyIndex = i;
        
        for(int j = i -1; j >= 0 ; --j)
        {
            if(key < arr[j])
            {
                std::swap(arr[j] , arr[keyIndex]);
                keyIndex = j;
            }
        }
    }
    
    cout << " After sorting" << endl;
    for(auto temp : arr)
    {
        cout << temp << " ";
    }
    cout << endl;
}

// Tree height
// STL
// Arista ques
// searching
// Whats the best alg/stl
// Singleton and observer


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
    
    insertionSortOptimized();//ircularBuffer();
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

