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

/*
Quick Notes:

Check what Type it is:
    std::isspace(' ')
    isdigit('1')
    isalpha('A')
    isalnum('2')
    islower('a')
    isupper('A')
    tolower('A')
    toupper('a')
    
 
Available API's:
    sort(arr, arr.size())
    sort(arr, arr.size(), std::greater<int>())
    sort(arr, arr.size(), std::less<int>())
    sort(arr.begin(), s.end(), [](const int& x, const in& y){ return x < y;})

    swap(a, b); --> swap(T& a, T& b)
 
    find(s.begin(), s.end(), 'c')
    find_if(s.begin(), s.end(), [](const char& a){return a=='x'; })
 
    erase(arr, 'a')
    erase_if(arr, [](const char& x){return (x-'0') % 2 == 0})
 
     std::count_if(s.begin(), s.end(),
     [](unsigned char c){ return std::isdigit(c); } // correct
     );

    std::remove(s2.begin(), s2.end(), ' ')
 
    std::reverse(v.begin(), v.end());
 
    to_string(1023)

    itoa(list.begin(), list.end(), -4)
    Fills the range [first, last) with sequentially increasing values, starting with value and repetitively evaluating ++value.


Quick Tips:
Reverse a String:
    - Insert into stack<char>; top() -> pop() till empty()
    - reverse(s.begin(), s.end()) or reverse(s.rbegin(), s.rend())
    - Two pointer technique
    - Recursive func call with swap
 
Split a String:
    - Use Stringstream.     stringstream ss(str) and while(getline(ss, tempStr, del))
    - Use String tokenizer (strtok).  char *t = strtok(str, "-");   while(t!=NULL) printf(" % s\n", token);
      token = strtok(NULL, " - ");
    - Use find to point to delimeter. s.substr(0, s.find(delimiter)) while loop

String API's:
 s2.erase( std::remove(s2.begin(), s2.end(), ' '), s2.end());

 cout << str.size() << endl;
 cout << str1.length() << endl;
 
 string result = str + " " + str1;
  
 r2.append(str1);
 
 str.push_back('!');
  
 str.pop_back();
  
 str.insert( 5, " Subodh");
 
 str.erase(5, 7);
 
 string myStr = str.substr(6, 6); // std::string substr(size_t pos = 0, size_t len = npos) const;
 
 cout << myStr << endl;
  
 auto pos = myStr.find("oh");
 
 if(pos < myStr.length())
 cout << "Found String" << endl;
 else
 cout << "String doesn't exist" << endl;
 
 if(strstr(str, "simple") != NULL)
 
 // replace -- many overloads.
 
 myStr.replace(0, 3 , 3, '?');
 
 // Comparision
 
 if(r4 == r3)
 cout << "Same strings" << endl;
 else
 cout << " different" << endl;
 
 if(r3.compare(r4) == 0)
 cout << "Same" << endl;
 else
 cout << "Different" << endl;
 
C++ Containers:
Vector API's:

 // Element access
 at - access specified element with bounds checking
 operator[] - access specified element
 front - access the first element
 back - access the last element
 data - direct access to the underlying contiguous storage

 Iterators
 begin
 cbegin - returns an iterator to the beginning
 end - returns an iterator to the end
 rbegin - returns a reverse iterator to the beginning
 rend
 crend - returns a reverse iterator to the end
 
 Capacity
 empty - checks whether the container is empty
 size - returns the number of elements
 max_size - returns the maximum possible number of elements
 reserve - reserves storage
 capacity - returns the number of elements that can be held in currently allocated storage

 Modifiers
 clear - clears the contents
 insert - inserts elements
 emplace - constructs element in-place
 erase -  erases elements
 push_back - adds an element to the end
 emplace_back - constructs an element in-place at the end
 pop_back - removes the last element
 resize - changes the number of elements stored
 swap - swaps the contents
 
Stack API's
 Element Access
 • top – accesses the top element (public member function)
 Capacity
 • empty – checks whether the container adaptor is empty (public member function)
 • size – returns the number of elements (public member function)
 Modifiers
 • push – inserts element at the top (public member function)
 • push_range (C++23) – inserts a range of elements at the top (public member function)
 • emplace (C++11) – constructs element in-place at the top (public member function)
 • pop – removes the top element (public member function)
 • swap (C++11) – swaps the contents (public member function)
 
Queue API's
 Element Access
 • front – accesses the first element (public member function)
 • back – accesses the last element (public member function)
 Capacity
 • empty – checks whether the container adaptor is empty (public member function)
 • size – returns the number of elements (public member function)
 Modifiers
 • push – inserts element at the end (public member function)
 • push_range (C++23) – inserts a range of elements at the end (public member function)
 • emplace (C++11) – constructs element in-place at the end (public member function)
 • pop – removes the first element (public member function)
 • swap (C++11) – swaps the contents (public member function)
 
List API's
 Element Access
 • front – accesses the first element (public member function)
 • back – accesses the last element (public member function)
 Iterators
 • begin / cbegin (C++11) – returns an iterator to the beginning (public member function)
 • end / cend (C++11) – returns an iterator to the end (public member function)
 • rbegin / crbegin (C++11) – returns a reverse iterator to the beginning (public member function)
 • rend / crend (C++11) – returns a reverse iterator to the end (public member function)
 Capacity
 • empty – checks whether the container is empty (public member function)
 • size – returns the number of elements (public member function)
 • max_size – returns the maximum possible number of elements (public member function)
 Modifiers
 • clear – clears the contents (public member function)
 • insert – inserts elements (public member function)
 • insert_range (C++23) – inserts a range of elements (public member function)
 • emplace (C++11) – constructs element in-place (public member function)
 • erase – erases elements (public member function)
 • push_back – adds an element to the end (public member function)
 • emplace_back (C++11) – constructs an element in-place at the end (public member function)
 • append_range (C++23) – adds a range of elements to the end (public member function)
 • pop_back – removes the last element (public member function)
 • push_front – inserts an element at the beginning (public member function)
 • emplace_front (C++11) – constructs an element in-place at the beginning (public member function)
 • prepend_range (C++23) – adds a range of elements to the beginning (public member function)
 • pop_front – removes the first element (public member function)
 • resize – changes the number of elements stored (public member function)
 • swap – swaps the contents (public member function)
 Operations
 • merge – merges two sorted lists (public member function)
 • splice – transfers elements from another list (public member function)
 • remove / remove_if – removes elements satisfying specific criteria (public member function)
 • reverse – reverses the order of the elements (public member function)
 • unique – removes consecutive duplicate elements (public member function)
 • sort – sorts the elements (public member function)
 
Set API's
 
 Iterators
 • begin / cbegin (C++11) – returns an iterator to the beginning (public member function)
 • end / cend (C++11) – returns an iterator to the end (public member function)
 • rbegin / crbegin (C++11) – returns a reverse iterator to the beginning (public member function)
 • rend / crend (C++11) – returns a reverse iterator to the end (public member function)
 Capacity
 • empty – checks whether the container is empty (public member function)
 • size – returns the number of elements (public member function)
 • max_size – returns the maximum possible number of elements (public member function)
 Modifiers
 • clear – clears the contents (public member function)
 • insert – inserts elements or nodes (since C++17) (public member function)
 • insert_range (C++23) – inserts a range of elements (public member function)
 • emplace (C++11) – constructs element in-place (public member function)
 • emplace_hint (C++11) – constructs elements in-place using a hint (public member function)
 • erase – erases elements (public member function)
 • swap – swaps the contents (public member function)
 • extract (C++17) – extracts nodes from the container (public member function)
 • merge (C++17) – splices nodes from another container (public member function)
 Lookup
 • count – returns the number of elements matching a specific key (public member function)
 • find – finds element with specific key (public member function)
 • contains (C++20) – checks if the container contains an element with specific key (public member function)

Map API's
 Element Access
 • at – accesses specified element with bounds checking (public member function)
 • operator[] – accesses or inserts specified element (public member function)
 Iterators
 • begin / cbegin (C++11) – returns an iterator to the beginning (public member function)
 • end / cend (C++11) – returns an iterator to the end (public member function)
 • rbegin / crbegin (C++11) – returns a reverse iterator to the beginning (public member function)
 • rend / crend (C++11) – returns a reverse iterator to the end (public member function)
 Capacity
 • empty – checks whether the container is empty (public member function)
 • size – returns the number of elements (public member function)
 • max_size – returns the maximum possible number of elements (public member function)
 Modifiers
 • clear – clears the contents (public member function)
 • insert – inserts elements or nodes (since C++17) (public member function)
 • insert_range (C++23) – inserts a range of elements (public member function)
 • insert_or_assign (C++17) – inserts an element or assigns to the current element if the key exists (public member function)
 • emplace (C++11) – constructs element in-place (public member function)
 • emplace_hint (C++11) – constructs elements in-place using a hint (public member function)
 • try_emplace (C++17) – inserts in-place if key does not exist; does nothing if it exists (public member function)
 • erase – erases elements (public member function)
 • swap – swaps the contents (public member function)
 • extract (C++17) – extracts nodes from the container (public member function)
 • merge (C++17) – splices nodes from another container (public member function)
 Lookup
 • count – returns the number of elements matching a specific key (public member function)
 • find – finds an element with a specific key (public member function)
 • contains (C++20) – checks if the container contains an element with a specific key (public member function)
 
Unordered_map
 Iterators
 • begin / cbegin – returns an iterator to the beginning (public member function)
 • end / cend – returns an iterator to the end (public member function)
 Capacity
 • empty – checks whether the container is empty (public member function)
 • size – returns the number of elements (public member function)
 • max_size – returns the maximum possible number of elements (public member function)
 Modifiers
 • clear – clears the contents (public member function)
 • insert – inserts elements or nodes (since C++17) (public member function)
 • insert_range (C++23) – inserts a range of elements (public member function)
 • insert_or_assign (C++17) – inserts an element or assigns to the current element if the key exists (public member function)
 • emplace – constructs element in-place (public member function)
 • emplace_hint – constructs elements in-place using a hint (public member function)
 • try_emplace (C++17) – inserts in-place if key does not exist; does nothing if it exists (public member function)
 • erase – erases elements (public member function)
 • swap – swaps the contents (public member function)
 • extract (C++17) – extracts nodes from the container (public member function)
 • merge (C++17) – splices nodes from another container (public member function)
 Lookup
 • at – accesses specified element with bounds checking (public member function)
 • operator[] – accesses or inserts specified element (public member function)
 • count – returns the number of elements matching a specific key (public member function)
 • find – finds element with a specific key (public member function)
 
 
Deque
 Element Access
 • at – accesses specified element with bounds checking (public member function)
 • operator[] – accesses specified element (public member function)
 • front – accesses the first element (public member function)
 • back – accesses the last element (public member function)
 Iterators
 • begin / cbegin (C++11) – returns an iterator to the beginning (public member function)
 • end / cend (C++11) – returns an iterator to the end (public member function)
 • rbegin / crbegin (C++11) – returns a reverse iterator to the beginning (public member function)
 • rend / crend (C++11) – returns a reverse iterator to the end (public member function)
 Capacity
 • empty – checks whether the container is empty (public member function)
 • size – returns the number of elements (public member function)
 • max_size – returns the maximum possible number of elements (public member function)
 • shrink_to_fit (DR*) – reduces memory usage by freeing unused memory (public member function)
 Modifiers
 • clear – clears the contents (public member function)
 • insert – inserts elements (public member function)
 • insert_range (C++23) – inserts a range of elements (public member function)
 • emplace (C++11) – constructs element in-place (public member function)
 • erase – erases elements (public member function)
 • push_back – adds an element to the end (public member function)
 • emplace_back (C++11) – constructs an element in-place at the end (public member function)
 • append_range (C++23) – adds a range of elements to the end (public member function)
 • pop_back – removes the last element (public member function)
 • push_front – inserts an element at the beginning (public member function)
 • emplace_front (C++11) – constructs an element in-place at the beginning (public member function)
 • prepend_range (C++23) – adds a range of elements to the beginning (public member function)
 • pop_front – removes the first element (public member function)
 • resize – changes the number of elements stored (public member function)
 • swap – swaps the contents (public member function)
 
 
 forward_list
 Element Access
 • front – accesses the first element (public member function)
 Iterators
 • before_begin / cbefore_begin – returns an iterator to the element before the beginning (public member function)
 • begin / cbegin – returns an iterator to the beginning (public member function)
 • end / cend – returns an iterator to the end (public member function)
 Capacity
 • empty – checks whether the container is empty (public member function)
 • max_size – returns the maximum possible number of elements (public member function)
 Modifiers
 • clear – clears the contents (public member function)
 • insert_after – inserts elements after a given position (public member function)
 • emplace_after – constructs elements in-place after a given position (public member function)
 • insert_range_after (C++23) – inserts a range of elements after a given position (public member function)
 • erase_after – erases an element after a given position (public member function)
 • push_front – inserts an element at the beginning (public member function)
 • emplace_front – constructs an element in-place at the beginning (public member function)
 • prepend_range (C++23) – adds a range of elements to the beginning (public member function)
 • pop_front – removes the first element (public member function)
 • resize – changes the number of elements stored (public member function)
 • swap – swaps the contents (public member function)
 Operations
 • merge – merges two sorted lists (public member function)
 • splice_after – transfers elements from another forward_list (public member function)
 • remove / remove_if – removes elements satisfying specific criteria (public member function)
 • reverse – reverses the order of the elements (public member function)
 • unique – removes consecutive duplicate elements (public member function)
 • sort – sorts the elements (public member function)

*/

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


/*
 
 Alg:
 
 first sort
 Then overwrite duplicate items with unique ones
 */

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

/*
 Alg:
 
 % is 0 then result+10^x
 % is non-zero then result + % * 10^x
 */
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

/*
 Alg:
 
 if % is non zero
 % -> result + 2^index
 index++
 divide by 10
 */
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

/*
 Alg:
 
 Multiply prev remainder with 10 and add remainder
 */
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
/*
 
 % with 2 -> get remainder
 / with 2 -> use it again with %
 
 ex: 15
 
 15%2 = 1
 7%2  = 1
 3%2  = 1
 1%2  = 1
 0
 
 */
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
// Tree height
// Binary tree - balanced or not


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

int heightOfTree(treeNode* head)
{
    if(head == NULL)
        return -1;
    
    int lheight = heightOfTree(head->left);
    int rheight = heightOfTree(head->right);
    
    return 1+std::max(lheight, rheight);
    
}

bool isBalancedTree(treeNode* head)
{
    if(head == NULL)
        return 0;
    
    int lheight = isBalancedTree(head->left);
    int rheight = isBalancedTree(head->right);
    
    if((lheight == -1) || (rheight == -1) || abs(lheight-rheight) > 1)
        return false;
    
    //return isBalancedTree(head->left) and isBalancedTree(head->right);
    return 1+std::max(lheight, rheight);
}

void btree()
{

    treeNode* head = (treeNode*)malloc(sizeof(treeNode));
    head->left = head->right = NULL;
    head->data = 5;
    
    void insToLeft(treeNode*, int);
    insToLeft(head, 4);
    insToRight(head, 6);
    insToLeft(head->left, 2);
    insToRight(head->left, 6);
    insToLeft(head->right, 1);
    insToRight(head->right, 9);
    /*
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
    insToRight(head, -1);*/

    
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
    
    cout << "Height of tree: " << heightOfTree(head) << endl;
    
    cout << "Is Balanced Tree: " << isBalancedTree(head) << endl;
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

// String functions/Manipulations

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
    d.A::print();
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
    shared_ptr<operOver> sp = make_shared<operOver>("Shared");
    unique_ptr<operOver> up = make_unique<operOver>("Unique");
    
    cout << sp->s1 << endl;
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
     div by 16 -> quo 0 rem 3
     
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
/*
 
 ASCII
 
 '0' - 48
 'a' - 97
 'A' - 65
 
 */
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

// TODO

// STL
// searching
// Graphs - BFS, DFS
// Check if a value exists along a path from root to leaf


    // String parsing


void decimalToBinary()
{
    
    int i = 12345;
    int j = 0;
    int arr[32]{};
    
    while(i!=0)
    {
        arr[j] = i%2;
        i = i/2;
        j++;
    }
    
    int size = sizeof(arr)/sizeof(arr[0]);
    for(int k = size-1; k >=0; --k)
        cout << " " << arr[k] ;
    cout << endl;
}

void decToBin()
{
    int i = 12345;
    constexpr int MAX_BIT_SIZE=32;
    int arr[MAX_BIT_SIZE]{0};
    int index=0;
    
    for(int j = MAX_BIT_SIZE-1; j >=0; --j)
    {
        arr[index] = (i >> j) & 1;
        index++;
    }
    cout <<"Binary rep: " << endl;
    
    bool started  = false;
    for(int z : arr)
    {
        if(z != 0)
            started = true;
        
        if(started == true)
            cout<<z;
    }
    cout << endl;
    
}
/*
 
 Arista P2
 
 Rows of string
 
 cus name, cus id, cus dob, cus last working date(dd.mm.yyyy)
 
 find the difference between the dates in days.
 
 Alg:
 
 take one row
 use stringstream to save values using , as delimiter
 stringstream ss(row[0]);
 
 getline(ss, myCusName, ',')
 
 After getting start and end date parse them
 
 stringstream s1(startDate)
 s1 >> int >> char....
 
 years -> days (*365)
 Add leap years -> days++
 for loop from Jan to months
 
 add days of current month.
 Now you get days from 00-00-0000
 */
vector<int> findDifferenceInDays(vector<string> input)
{
    vector<int> result;
    
    std::regex pattern{"\\d{2}\\.\\d{2}\\.\\d{4}"};
    
    std::smatch s;
    
        // 3️⃣ Use regex_iterator to find *all* matches
    auto begin = sregex_iterator(input[0].begin(), input[0].end(), pattern);
    auto end   = sregex_iterator();
    
    cout << "Input: " << input[0] << "\n";
    
        // 4️⃣ Loop through all matches
    int index = 1;
    for (auto it = begin; it != end; ++it) {
        smatch match = *it;
        cout << "Date " << index++ << ": " << match.str() << "\n";
    }

    
    /*
    if (regex_search(input[0], s, pattern, regex_constants::match_any)) {
        cout << "Matched: " << s.str() << endl;
    } else {
        cout << "No match found" << endl;
    }
    cout << input[0] << endl;
    cout << s.size() << endl;
    cout << s.str() << endl;
    cout << s[0] << endl;
    
    s.suffix();

    cout << s[0] << endl;
    cout << "Regex pattern: " << "\\d{2}\\.\\d{2}\\.\\d{4}" << endl;

    
    string::const_iterator searchStart( input[0].cbegin() );
    while ( regex_search( searchStart, input[0].cend(), s, pattern ) )
    {
        cout << ( searchStart == input[0].cbegin() ? "" : " " ) << s[0];
        searchStart = s.suffix().first;
    }
    cout << endl;*/

 //   regex_search(input[0], s, pattern);

  //  cout << s[0] << endl;
    
    return result;
}

void aristaP2()
{
    vector<string> input{"Subodh, 62253011, 28.06.1995, 14.12.2025",
        "Nikk, 453453, 04.07.1994, 12.12.2021"};
    vector<int> result(2);
    result = findDifferenceInDays(input);
    
    for(int i: result)
        cout << i << endl;
}


// TODO

// STL
// Arista ques
// searching
// Whats the best alg/stl
// Singleton and observer
//Pointer to char and char pointer
// String parsing
// Trim whitespaces at beginning and end
// Graphs -BFS, DFS
// Binary tree - balanced or not
// Tree traversals
// Check if a value exists along a path from root to leaf

void greaterElement()
{
    
    vector<int> input{3,1,4,5,6,3,2,6,2,5,7};
    // op         4,4,5,6,7,6,6,7,5,7,0
    
    // Brute force way
    cout << "Input: " << endl;
    for(int k : input)
        cout << " " << k ;
    
    cout << endl;
    vector<int> result(input.size(), 0);
    
    for(int i = 0; i< input.size(); i++)
    {
        for(int j = i+1; j < input.size(); j++)
        {
            if(input[i] < input[j])
            {
                result[i] = input[j];
                break;
            }
        }
    }
    
    cout << " Result: " << endl;
    for(int k : result)
        cout << " " << k ;
    
    cout << endl;
}

    // Stack based

void printStackPreservingOriginal(std::stack<int> s) { // Pass by value to create a copy
    while (!s.empty()) {
        std::cout << s.top() << " ";
        s.pop();
    }
    std::cout << std::endl;
}


void greaterElementStackBased()
{
    stack<int> s;
    vector<int> input{3,1,4,5,6,3,2,6,2,5,7};
        // op         4,4,5,6,7,6,6,7,5,7,0
    
    cout << "Input: " << endl;
    for(int k : input)
        cout << " " << k ;
    cout << endl;
    vector<int> result(input.size(), 0);
    
    for(int index = input.size()-1; index >= 0 ; index--)
    {

        while(!s.empty() && s.top() <= input[index])
            s.pop();
        
        if(s.empty())
            result[index] = 0;
        else
            result[index] = s.top();
        
        s.push(input[index]);
    }
    
    cout << " Result: " << endl;
    for(int j : result)
        cout << " " << j ;
    
    cout << endl;
}

template <typename T>
class CircularBuffer {
private:
    vector<T> list;
    int maxSize;
    int startIndex;
    int count;
public:
        // Constructor
    CircularBuffer(size_t _capacity) :
    maxSize(_capacity),
    startIndex(0),
    count(0)
    {
    }
    
        // Add an element to the buffer (write)
    void push(const T& item) {
        if(isFull())
        {
            cout << "Buffer is full" << endl;
            return;
        }
        
        list.push_back(item);
        count++;
    }
    
        // Remove an element from the buffer (read)
    T pop() {
        if(isEmpty())
            cout << "Buffer is empty" << endl;
        
        auto item = list[startIndex];
        count--;
        startIndex = (startIndex+1)%maxSize;
        return item;
    }
    
        // Check if the buffer is empty
    bool isEmpty() const {
        return count == 0;
    }
    
        // Check if the buffer is full
    bool isFull() const {
        return count == maxSize;
    }
    
        // Get the current number of elements
    size_t size() const {
        return count;
    }
    
        // Get the maximum capacity
    size_t getCapacity() const {
        return maxSize;
    }
};

void circBuffer()
{
    
    CircularBuffer<int> intArray(10);
    
    cout << "Size: " << intArray.size() << endl;

    for(int i = 1; i <=10 ; i++)
        intArray.push(i);

    cout << "Size: " << intArray.size() << endl;
    cout << "Capacity: " << intArray.getCapacity() << endl;

    intArray.push(21);
    cout << " pop: " << intArray.pop();
    cout << "Size: " << intArray.size() << endl;
    intArray.push(21);
    cout << "Size: " << intArray.size() << endl;

    


}

/*
 
 decimal to hexadecimal -> mod 16 and divide by 16
 decimal to binary -> mod 2 and divide by 2
 
 hexdecimal to decimal -> last char * 16^0 + char-1 * 16^1...
 binary to decimal -> last digit * 2^0 + last digit-1 * 2^1...
 
 hexadecimal to binary -> No direct way, Either use switch case, or stl libs like stoul, bitset
 binary to hexadecimal -> No direct way, Either use switch case, or stl libs like stoul, bitset
 
 Bitwise Manip:
 
 1's compliment -> ~X
 2's Compliment -> ~X+1 (or) -X
 
 Get lowest set bit -> X & -X
 Strip lowest set bit -> X & (X-1) // (X-1)  inverts all the bits till it encounters the lowest set '1' and it also inverts that lowest set '1'.
 
 sum = a|b (if there is no carry)
 else sum is without + with carry
 carry = (a & b) << 1

 */
void hexToBinaryNik()
{
    string s("16F");
    cout << "Direct string to decimal " << stoul(s, nullptr, 16) << endl;
    bitset<32> bin(stoul(s, nullptr, 16));
    cout << "In Binary: " << bin << endl;

    string s1("1111");
    cout << "Direct string bin to decimal " << stoul(s1, nullptr, 2) << endl;

    int result = 0;
    int j =0;
    for(int i = s.size()-1; i>=0; --i)
    {
        if(s[i] >= 'A' && s[i] <= 'F')
        {
            int temp = 10 + (s[i] - 'A');
            cout << " hex temp value " << temp << endl;
            result = result + temp*pow(16,j);
            //result = result+pow(temp,i);
            cout << " result value " << result << endl;

            j++;
        }
        else
        {
            int temp = s[i] - '0';
            cout << " int temp value " << temp << endl;

            result = result + temp*pow(16,j);
            cout << " result value " << result << endl;

            j++;
        }
    }
    cout << "result is : " << result << endl;
}


/*
 Merge overlapping arrays
 
 I/P:
 (1,5),(3,7),(4,6),(6,8)
 OP:
 (1,8)
 
 IP:
 (10,12),(12,15)
 OP:
 (10,15)
 
 IP:
 (10,12),(12,15), (17,18)
 OP:
 (10,15)
 
 IP:
 (17,18),(10,12),(12,15),
 OP:
 (17,15)
 
 */

typedef struct MyPair
{
public:

    int first;
    int last;
    
    MyPair(int x, int y) :
    first(x),
    last(y)
    {}
}mp;

mp checkIfOverlapping(vector<mp> pa)
{
    int finalFirst = 0;
    int finalLast = 0 ;
    int foundOverlap = 0;
    
    for(int i = 0; i < pa.size()-1; i++)
    {
        cout << "i: " << i << " size: " << pa.size()-2 << endl;
        if(pa[i].last >= pa[i+1].first)
        {
            foundOverlap = 1;
            if(finalFirst == 0)
                finalFirst = pa[i].first;
            
            if(i == pa.size()-2)
            {
                cout << "setting finalLast" << endl;
                finalLast = pa[i+1].last;
            }
        }
        else if(foundOverlap == 1)
        {
            finalLast = pa[i].last;
            break;
        }
    }
    mp result(finalFirst, finalLast);

    return result;
}
void overlappingArray()
{
    vector<mp> pairArray;
    mp p1(10,12);
    mp p2(12, 15);
    mp p3(17, 18);
    mp p4(6, 8);

    pairArray.push_back(p1);
    pairArray.push_back(p2);
    pairArray.push_back(p3);
    pairArray.push_back(p4);

    auto result = checkIfOverlapping(pairArray);
    
    cout << " " << result.first << " " << result.last << endl;
    
}

    //Reverse a single byte.

void reverseByte()
{
    long num = 10011010;
    long result = 0;
    
    while(num>0)
    {
        int temp = num%10;
        
        result = (result*10) + temp;
        
        num = num/10;
    }
    cout << " Result : " << result << endl;
}

/* Remove white spaces from a string.
  use alg, erase along with remove
  use remove_if , ::isspace
  copy non space charactes to new string

 */

void removeWhiteSpaces()
{
    string s("  Hello   world!");
    int shiftPlaces = 0;
    int size = 0;
    int origSize = s.size();
    cout << " size: " << s.size() << endl;

    
    for(int i = 0 ;i < s.size() ; i++)
    {
        if (s[i] == ' ')
        {
            shiftPlaces = 1;
            for(int j = i+1; j <s.size();j++)
            {
                if(s[j] != ' ')
                {
                    s[j-shiftPlaces] = s[j];
                    //size--;
                }
                else
                {
                    shiftPlaces++;
                }
            }
            size += shiftPlaces;
            cout << "shiftPlaces: " << shiftPlaces << endl;
        }
    }
    string s1;
    s1 = s.substr(0, origSize - size);
    cout << " size: " << size << endl;
    cout << "String : " << s1<< endl;
    
    
    // Optimzed
    //Op1
    string s2("  Hello   world!");
    cout << "s2: " << s2 << endl;

    s2.erase( std::remove(s2.begin(), s2.end(), ' '), s2.end());
    cout << "s2: " << s2 << endl;
    
    //Op2
    string s3("  Hello   world!");
    cout << "s3: " << s3 << endl;
    
    s3.erase( std::remove_if(s3.begin(), s3.end(), [](char c ){ return c == ' ';}), s3.end());
    cout << "s3: " << s3 << endl;
    
    //op3
    string s4("  Hello   world!  ");
    int startIndex = 0;
    for(char c : s4)
    {
        if(c == ' ')
            startIndex++;
        else
            break;
    }
    cout << "s4: " << s4 << endl;

    //std::erase(s4, ' '); cpp20
    auto it = std::remove_if(s4.begin(), s4.end(),
    [](char c)
    {
        return c == ' ';
    });
    cout << "s4: " << s4 << endl;

    s4.erase(it, s4.end());
    cout << "s4: " << s4 << endl;

}
/*
 Reverse every word in a string. Example: "Lord is Great" should be displayed as "droL si taerG".
 */

void revString()
{
    string s("Lord is Great");
    cout << "s: " << s << endl;

    int startIndex{255};
    
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == ' ' || i+1 == s.size())
        {
            cout << " startInd: " << startIndex << endl;
            std::reverse(s.begin() + startIndex, s.begin()+i);
            startIndex = 255;
        }
        else if(s[i] != ' ')
        {
            if(startIndex == 255)
                startIndex = i;
            continue;
        }
    }
    
    cout << "revString s: " << s << endl;
    
    // using stack?
    std::stack<char> myStack;
    string s1("Lord is Great");

    cout << "Using Stack" << endl;
    for(char c : s1)
    {
        cout<< "pushing c: " << c << endl;
        myStack.push(c);
    }
    
    cout << "Size: " << myStack.size() << endl;
    //for(int i = 0; i < myStack.size(); i++)
    while(!myStack.empty())
    {
        //.char item = ;
        cout << " " <<  myStack.top() << " " ;

        myStack.pop();

    }
    cout <<endl;
    
    }

/*

 Check if words are anagrams
 a word, phrase, or name formed by rearranging the letters of another, such as spar, formed from rasp.
 
 diff between threads and processes in tech sense
 
 deck of cards in hand.top card on the table, next top card to the bottom of deck
 
 static vs volatile
 
 struct vs union. Calc memory
 find out size of struct using own func

 
 alg to find max sum of non adjacent elements in an array
 
 bit manip using 2s compliment
 any other bitmanip programs
 
 
 https://www.techinterviewhandbook.org/grind75/
 
 https://www.pramp.com/
 
 */



// Check if words are anagrams
//a word, phrase, or name formed by rearranging the letters of another, such as spar, formed from rasp.
bool checkAnagrams()
{
    string s1("rasp");
    string s2("spar");
    
    if(s1.size() != s2.size())
        return false;
    
    std::sort(s1.begin(), s1.end());
    std::sort(s2.begin(), s2.end());

    return s1 == s2;
//    vector<int> a{1,2,3};
//    vector<int> b{1,2,3};
//    
//    return a == b;

}

/*
 a deck of cards where top card in kept on table and next top at the bottom of deck. Repeat this until deck is empty. Then take the deck from the table and put it in your hand. This is considered as one cycle. After how many cycles does the deck comes to original position c++
 */

void cycle(vector<int> &hand)
{
    vector<int> table;

    while(true)
    {
        if(!hand.empty())
        {
            table.push_back(hand[0]);
            hand.erase(hand.begin());
        }
        
        if(!hand.empty())
        {
            hand.push_back(hand[0]);
            hand.erase(hand.begin());
        }
        
        if(hand.empty())
        {
            hand = table;
            break;
        }
    }
    

    
    
}

bool isOriginalOrder(vector<int> &deck, vector<int> &originalDeck)
{
    return deck == originalDeck;
}

void deckOfCards()
{
    vector<int> deck;
    for(int i = 1; i<=52; i++)
        deck.push_back(i);
    
    vector<int> originalDeck = deck;
    int numOfCycles = 0;
    
    do
    {
        cycle(deck);
        numOfCycles++;
        
    } while(!isOriginalOrder(deck, originalDeck));
    
    cout << " Number of cycles: " <<numOfCycles << endl;
}

/*
 struct vs union. Calc memory
 find out size of struct using own func
 */
struct st
{
    int a;
    int b;
    bool c;
};

union stu
{
    int a;
    int b;
    bool c;
};

template <typename T>
int mySize(T a)
{
    return (char*)(&a+1) - (char*)(&a);
}

void findSize()
{
    st s;
    stu stus;
    
    cout << "Mysize: " << mySize<st>(s) << endl;
    cout << "Mysize: " << mySize<stu>(stus) << endl;

    
}

/*
 alg to find max sum of non adjacent elements in an array
 find all indices also

 */
void algMaxNonAdjSum()
{
    array<int, 10> arr{5,1,5,1,1,7,1,1,9,0};
    
    vector<int> dp(arr.size(), 0);
    
    dp[0] = arr[0];
    dp[1] = arr[1];
    
    for(int i = 2 ; i < arr.size(); i++)
    {
        dp[i] = max(dp[i-1], arr[i]+dp[i-2]);
    }
    
    cout << "Max value is: " << dp[arr.size()-1] << endl;
    
}

void twosCompliment()
{
    
}

/*
 1. Two Sum
 Solved
 Easy
 
 Topics
 premium lock icon
 Companies
 
 Hint
 Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
 
 You may assume that each input would have exactly one solution, and you may not use the same element twice.
 
 You can return the answer in any order.
 
 
 
 Example 1:
 
 Input: nums = [2,7,11,15], target = 9
 Output: [0,1]
 Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
 Example 2:
 
 Input: nums = [3,2,4], target = 6
 Output: [1,2]
 Example 3:
 
 Input: nums = [3,3], target = 6
 Output: [0,1]
 
 
 Constraints:
 
 2 <= nums.length <= 104
 -109 <= nums[i] <= 109
 -109 <= target <= 109
 Only one valid answer exists.
 
 
 Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?
 */

vector<int> TwoSum()
{
    vector<int> arr{2,7,11,15};
    int target = 9;
    
    unordered_map<int, int> hash;
    
    for(int i = 0; i < arr.size(); i++)
    {
        int toFind = target - arr[i];
        
        auto it = hash.find(toFind);
        if(it != hash.end())
        {
            cout << "Foound solution" << endl;
            return {i , it->second};
        }
        cout << "Inserting i: " << i << " arr[i]: " << arr[i] << endl;
        hash.insert({arr[i], i});
        
    }
    return {};
}

bool validParanthesis()
{
    string s = "([}}])";
    if(s.length() % 2 != 0)
        return false;
    

    auto isClosingBrace = [](char c )
    {
        return c == ')' || c == '}' || c == ']';
    };
    
    auto addOpp = [](char c)
    {
        if(c == '(')
            return ')';
        else if (c == '{')
            return '}';
        else if (c == '[')
            return ']';
        else
            return c;
    };
    
    stack<char> st;
    for(char ch : s) //([}}])
    {
        if(st.empty())
        {
                //cout << "Inserting: " << ch;
            if(isClosingBrace(ch))
                return false;
            
            cout << "Pushing ch: "<< ch << endl;
            st.push(addOpp(ch));
            continue;
        }
        else
        {
            if(isClosingBrace(ch))
            {
                auto tmp = st.top();
                cout << "Comparing tmp: " << tmp << " ch: " << ch << endl;
                if(tmp == ch)
                {
                    cout << "Popping because equal tmp: "<< tmp << "ch: " << ch <<endl;
                    st.pop();
                }
                return false;
            }
            else
                cout << "Pushing ch: "<< ch << endl;
                st.push(addOpp(ch));
            
                // cout << "Comparing tmp: " << tmp << " ch: " << ch  << "diff: " << ch-tmp << endl;
                // if((ch - tmp != 1) && (ch - tmp != 2))
                // {
                //     return false;
                // }
                // st.pop();
        }
    }
    if(st.empty())
        return true;
    else
        return false;
}

/*
 [Q1]:  Given two sorted arrays, A (length m) and B (length n), where A[] has enough empty space at the end to hold all elements of B[]. Provide a C function void to merge B[] into Asuch that the resultant array A[] of size m+n remains sorted.
 
 e.g  Input: A=[1,5,8,null,null,null], m=3. Input: B=[2,6,9], n=3. Output: A=[1,2,5,6,8,9].
 
 */

void mergeSortedArray()
{
    int A[6] = {1,5,8,0,0,0};
    int m = 3;
    int B[3] = {2,6,9};
    int n = 3;
    int k = m+n-1;
    int i = m-1;
    int j = n-1;
    
    while(i>=0 && j>=0)
    {
        if(A[i] > B[j])
        {
            A[k--] = A[i--];
        }
        else
            A[k--] = B[j--];
    }
    
    // copy any leftover elements from B array
    while(j>=0)
    {
        A[k--] = B[j--];
    }
    
        
    for(int x: A)
        cout << " " << x ;
    cout << endl;
}
    
    
bool adjacentSet(int n)
{
    return (n & (n >> 1));
}

/*

 Function A which declares a pointer.
 Function B allocates the pointer.
 Function C assign a value to the pointer
 Function D print a value of the pointer
 Function E frees the pointer
 */
void funcB(int** p)
{
    *p = (int*)malloc(sizeof(int));
    
}

void funcC(int* p)
{
    *p = 2;
    
}

void funcD(int* p)
{
    cout << "Value is: " << *p << endl;
    
}

void funcE(int** p)
{
    free(*p);
    *p = NULL;
}

void funcA()
{
    int *p = NULL;
    
    //cout << *p;
    funcB(&p);
    funcC(p);
    funcD(p);
    cout << "Before free p: " << *p << endl;

    funcE(&p);
    
    //cout << "After free p: " << *p << endl;
    //if(*p == NULL)
    //{
    //    cout << "Really freed" << endl;
    //}

}



/*
 Apple Interview
 
 R1
 Merge 2 sorted arrys into a single one
 In a SLL, place odd index elements first and then even element indexes
 
 R2
 Own Sizeof functin
 How many bits have to be changed to turn A into B (A ^ B) Count 1's
 
 R3
 Write
 Function A which declares a pointer.
 Function B allocates the pointer.
 Function C assign a value to the pointer
 Function D print a value of the pointer
 Function E frees the pointer
 Whether binary number is a palindrome or not
 
 R4
 Check whether adjacent bits are set or not (n & (n >> 1))
 
 
 */
/*
 https://www.geeksforgeeks.org/dsa/top-100-data-structure-and-algorithms-dsa-interview-questions-topic-wise/
 

 
Find Closest to n and Divisible by m
Given two integers n and m (m != 0). Find the number closest to n and divisible by m. If there is more than one such number, then output the one having maximum absolute value.

Examples:

Input: n = 13, m = 4
Output: 12
Explanation: 12 is the closest to 13, divisible by 4.
*/


/*
 Given two integers a1 and a2, the first and second terms of an Arithmetic Series respectively, the problem is to find the nth term of the series.
 Examples :
 
 Input : a1 = 2,  a2 = 3,  n = 4
 Output : 5
 Explanation : The series is 2, 3, 4, 5, 6, ....   , thus the 4th term is 5.
 
 Input : a1 = 1, a2 = 3, n = 10
 Output : 19
 Explanation:  The series is: 1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21..... Thus,10th term is 19.
 */


/*
 Given an array arr[] of n integers and a target value, check if there exists a pair whose sum equals the target. This is a variation of the 2-Sum problem.
 
 Examples:
 
 Input: arr[] = [0, -1, 2, -3, 1], target = -2
 Output: true
 Explanation: There is a pair (1, -3) with the sum equal to given target, 1 + (-3) = -2.
 
 Input: arr[] = [1, -2, 1, 0, 5], target = 0
 Output: false
 Explanation: There is no pair with sum equals to given target.
 */

/*
 Given an array prices[] of length N, representing the prices of the stocks on different days, the task is to find the maximum profit possible by buying and selling the stocks on different days when at most one transaction is allowed. Here one transaction means 1 buy + 1 Sell.
 
 Note: Stock must be bought before being sold.
 
 Examples:
 
 Input: prices[] = {7, 10, 1, 3, 6, 9, 2}
 Output: 8
 Explanation: Buy for price 1 and sell for price 9.
 
 Input: prices[] = {7, 6, 4, 3, 1}
 Output: 0
 Explanation: Since the array is sorted in decreasing order, 0 profit can be made without making any transaction.
 
 Input: prices[] = {1, 3, 6, 9, 11}
 Output: 10
 Explanation: Since the array is sorted in increasing order, we can make maximum profit by buying at price[0] and selling at price[n-1]
 
 */

/*
 Product of Array Except Self
 Last Updated : 23 Jul, 2025
 Given an array arr[] of n integers, construct a product array res[] (of the same size) such that res[i] is equal to the product of all the elements of arr[] except arr[i].
 
 Example:
 
 Input: arr[] = [10, 3, 5, 6, 2]
 Output: [180, 600, 360, 300, 900]
 Explanation:
 
 For i=0, res[i] = 3 * 5 * 6 * 2 is 180.
 For i = 1, res[i] = 10 * 5 * 6 * 2 is 600.
 For i = 2, res[i] = 10 * 3 * 6 * 2 is 360.
 For i = 3, res[i] = 10 * 3 * 5 * 2 is 300.
 For i = 4, res[i] = 10 * 3 * 5 * 6 is 900.
 Input: arr[] = [12, 0]
 Output: [0, 12]
 Explanation:
 
 For i = 0, res[i] = 0.
 For i = 1, res[i] = 12.
 */


/*
 Container with Most Water
 Last Updated : 12 Aug, 2025
 Given an array arr[] of non-negative integers, where each element arr[i] represents the height of the vertical lines, find the maximum amount of water that can be contained between any two lines, together with the x-axis.
 
 Examples :
 
 Input: arr[] = [1, 5, 4, 3]
 Output: 6
 Explanation: 5 and 3 are 2 distance apart. So the size of the base = 2. Height of container = min(5, 3) = 3. So total area = 3 * 2 = 6.
 
 Input: arr[] = [3, 1, 2, 4, 5]
 Output: 12
 Explanation: 5 and 3 are 4 distance apart. So the size of the base = 4. Height of container = min(5, 3) = 3. So total area = 4 * 3 = 12.
 
 Input: arr[] = [2, 1, 8, 6, 4, 6, 5, 5]
 Output: 25
 Explanation: 8 and 5 are 5 distance apart. So the size of the base = 5. Height of container = min(8, 5) = 5. So, total area = 5 * 5 = 25.
 */

/*
 Container with Most Water
 Last Updated : 12 Aug, 2025
 Given an array arr[] of non-negative integers, where each element arr[i] represents the height of the vertical lines, find the maximum amount of water that can be contained between any two lines, together with the x-axis.
 
 Examples :
 
 Input: arr[] = [1, 5, 4, 3]
 Output: 6
 Explanation: 5 and 3 are 2 distance apart. So the size of the base = 2. Height of container = min(5, 3) = 3. So total area = 3 * 2 = 6.
 
 Input: arr[] = [3, 1, 2, 4, 5]
 Output: 12
 Explanation: 5 and 3 are 4 distance apart. So the size of the base = 4. Height of container = min(5, 3) = 3. So total area = 4 * 3 = 12.
 
 Input: arr[] = [2, 1, 8, 6, 4, 6, 5, 5]
 Output: 25
 Explanation: 8 and 5 are 5 distance apart. So the size of the base = 5. Height of container = min(8, 5) = 5. So, total area = 5 * 5 = 25.
 */

/*
 Maximum Subarray Sum - Kadane's Algorithm
 Last Updated : 22 Jul, 2025
 Given an integer array arr[], find the subarray (containing at least one element) which has the maximum possible sum, and return that sum.
 Note: A subarray is a continuous part of an array.
 
 Examples:
 
 Input: arr[] = [2, 3, -8, 7, -1, 2, 3]
 Output: 11
 Explanation: The subarray [7, -1, 2, 3] has the largest sum 11.
 
 Input: arr[] = [-2, -4]
 Output: -2
 Explanation: The subarray [-2] has the largest sum -2.
 
 Input: arr[] = [5, 4, 1, 7, 8]
 Output: 25
 Explanation: The subarray [5, 4, 1, 7, 8] has the largest sum 25.
 */

vector<int> maxSubarraySum()
{
    vector<int> arr{2, 3, -8, 7, -1, 2, 3};
    int tempStart = 0;
    int startIndex = 0;
    int endIndex = 0;
    int maxSum = arr[0];
    int resSum = 0;
    
    for(int i = 1; i < arr.size(); i++)
    {
        maxSum += arr[i];
        //maxSum = max(arr[i], maxSum + arr[i]);
        
        //resSum = max(maxSum, resSum);
        
        if(arr[i] > maxSum)
        {
            tempStart = i;
            maxSum = arr[i];
        }
        
        if(maxSum > resSum)
        {
            resSum = maxSum;
            startIndex = tempStart;
            endIndex = i;
        }
    }
    
    cout << "Max value is " << resSum << endl;
    vector<int> result(arr.begin()+startIndex , arr.begin()+endIndex+1);

    for(int k : result)
    {
        cout << " " << k;
    }
    cout << endl;
    return result;
    
}

node* createMyLL()
{
    node* dummyHead = new node{0, nullptr};
    node* tail = dummyHead;
    int n = 0;
    cout << "Enter elem to ins" << endl;
    while(cin >> n && n != -1)
    {
        node* newTail = new node{n , nullptr};
        tail->next = newTail;
        tail = newTail;
    }
    
    node* realHead = dummyHead->next;
    free(dummyHead);
    return realHead;
    
}

void removeDupLL(node* head)
{
    if(head == NULL)
        return;
    
    while(head->next!=NULL)
    {
        if(head->number == head->next->number)
        {
            head->next = head->next->next;
        }
        else
            head = head->next;
    }
}

void removeDupLL()
{
    
    node* head = createMyLL();
    printList(head);
    removeDupLL(head);
    printList(head);

}

int main()
{
    
    
    //mergeSortedArray();
//    auto i = TwoSum();
//    for(int j: i)
//        cout << " " << j << endl;
//    cout << endl;
    //1101
    //cout << " funcA: " << funcA() << endl;
    decToBin();
    return 0;
}

// Apple Interview
/*
 #include <stdio.h>
 #include "stdlib.h"

 // To execute C, please define "int main()"
 #pragma pack(1)
 struct myStruct -> 9 bytes
 {
 int data; -> 4
 char c; -> 1
 float f : 16 ; - > 4
 };
 
 gdb
 
 0x0         data
 0x4 offset  c
 page 2kb -> packet 1500 b (IP MTU)
 huge pages 2mb
 
 union myUnion -> 4
 {
 int socket1;
 int socket2;
 float f;
 };
 
 
 a1
 a2
 
 
 union
 {
 struct u1
 struct u2
 
 }
 
 socket2=40
 socket1
 
 myUnion.data = 5
 
 */
/*
 [Q1]:  Given two sorted arrays, A (length m) and B (length n), where A[] has enough empty space at the end to hold all elements of B[]. Provide a C function void to merge B[] into Asuch that the resultant array A[] of size m+n remains sorted.
 
 e.g  Input: A=[1,5,8,null,null,null], m=3. Input: B=[2,6,9], n=3. Output: A=[1,2,5,6,8,9].
 
 */
/*
 Merge A with B
 Merged A with all el
 sort A*/
/*
 void mergeAndSort()
 {
 int A[] = {1,5,8,0,0,0};
 int m = 3;
 int B[] = {2,6,9};
 //int n = 3;
 int j =0;
 
 // Merge B to A
 for(int i = m; i < 6; i++)
 {
 A[i] = B[j];
 j++;
 }
 
 int sizeOfA = sizeof(A)/sizeof(int);
 
 // bubble sort
 for(int i = 0; i< sizeOfA; i++ )
 {
 for(int j = i+1 ; j < sizeOfA-1; j++)
 {
 if(A[i] > A[j])
 {
 int temp = A[i];
 A[i] = A[j];
 A[j] = temp;
 }
 }
 }
 
 printf("Sorted list is: \n");
 for(int k = 0; k < sizeOfA; k++)
 printf(" %d\t", A[k] );
 
 }
 
 int main()
 {
 
 mergeAndSort();
 
 return 0;
 
 }
 */


/*
 QUestion 2:
 
 Input: 1 -> 2 -> 3 -> 4 -> 5 -> 6->NULL
 Output: 1 -> 3 -> 5 -> 2 -> 4 ->6-> NULL
 
 Input: 1 -> 2 -> 3 -> 4 -> 5 -> 6->NULL
 
 
 extractOddNodes()
 1->3->5->NULL
 
 extractEvenNodes()
 2->4->6->NULL
 
 Merge
 5's tail to be merged to head of evenNodes.
 */
/*
typedef struct Node
{
    int data;
    struct Node* next;
    
        //Node(): data(0), next(NULL);
    
}Node;

void createLL(Node* head)
{
    
    printf("Inside createLL\n");
    if(head->next == NULL)
    {
        int temp = 0;
        printf("Insert element:, To stop inserting use -1\n");
        scanf("%d", &temp);
        
            // Stop inserting elements
        if(temp == -1)
            return;
        
        head->next = (Node*)malloc(sizeof(Node));
        head->next->data = temp;
        head->next->next = NULL;
        
        createLL(head->next);
    }
    
}

Node* extractEvenNodes(Node* head)
{
    Node* oddNodes = NULL;//(Node*)malloc(sizeof(Node));
    Node* headOddNodes;// = oddNodes;
    
    int index = 1;
    
    while (head!= NULL) {
        head = head->next;
        if(head == NULL)
        {
            printf("returning from evenNodes\n");
            return headOddNodes;
            
        }
        printf("data is: %d", head->data);
        index++;
        
        if(index%2 == 0)
        {
            if(oddNodes == NULL)
            {
                oddNodes = (Node*)malloc(sizeof(Node));
                oddNodes->data = head->data;
                oddNodes->next = NULL;
                headOddNodes = oddNodes;
            }
            else
            {
                if (oddNodes->next == NULL) {
                    oddNodes->next = (Node*)malloc(sizeof(Node));
                    oddNodes = oddNodes->next;
                    oddNodes->data = head->data;
                    oddNodes->next = NULL;
                }
            }
                //oddNodes = (Node*)malloc(sizeof(Node));
            if(oddNodes->next == NULL)
             {
             oddNodes->next = (Node*)malloc(sizeof(Node));
             oddNodes = oddNodes->next;
             }
             
             oddNodes->data = head->data;
             oddNodes->next = NULL;//(Node*)malloc(sizeof(Node));
                                     //ddNodes = oddNodes->next;
                                     //oddNodes = oddNodes->next;
                                     // oddNodes->data =
                                     // head->data;
                                     //oddNodes->next = NULL;
        }
    }
    return headOddNodes;
    
}

Node* extractOddNodes(Node* head)
{
    printf("Inside extractOddNodes\n");
    Node* oddNodes = (Node*)malloc(sizeof(Node));
    Node* headOddNodes = oddNodes;
    oddNodes->data = head->data;
    oddNodes->next = NULL;
    int index = 1;
    
    while (head!= NULL) {
        head = head->next;
        if(head == NULL)
        {
            printf("returning from evenNodes\n");
            return headOddNodes;
            
        }
        index++;
        
        if(index%2 != 0)
        {
            oddNodes->next = (Node*)malloc(sizeof(Node));
            oddNodes = oddNodes->next;
            oddNodes->data = head->data;
            oddNodes->next = NULL;
        }
    }
    return headOddNodes;
}

void printLL(Node* head)
{
    
    while (head != NULL) {
        
        printf("%d --> ", head->data);
        head = head->next;
    }
}

void LL(Node* head)
{
    printLL(head);
    
    Node* oddHead = extractOddNodes(head);
    printf("printing oddHead\n");
    printLL(oddHead);
    printf("\n");
    
    
    Node* evenHead = extractEvenNodes(head);
    printf("printing evenHead\n");
    printLL(evenHead);
    printf("\n");
    
    
    
    Node* tailOfOdd = oddHead;
    
        // Merge even at the end
    while(oddHead->next != NULL)
    {
        oddHead = oddHead->next;
    }
    
    oddHead->next = evenHead;
    printf("\n");
    printLL(tailOfOdd);
    printf("\n");
    
    
}

int main()
{
    Node* head = (Node*)malloc(sizeof(Node));
    head->data=1;
    head->next=NULL;
    createLL(head);
    LL(head);
    
    return 0;
    
}
 */
/*
 
 vector<int> monthToDays(13, 31);
 monthToDays[2] = 28;
 monthToDays[4] = 30;
 monthToDays[6] = 30;
 monthToDays[9] = 30;
 monthToDays[11] = 30;
 
 //int result[1];
 for(int i = 0; i< records_count; i++)
 {
 char* firstRecord = records[i];
 int j = 0;
 int numOfComma = 0;
 while(numOfComma != 2 )
 {
 if(firstRecord[j] == ',')
 {numOfComma++;}
 
 j++;
 }
 
 std::string day = firstRecord[j] +firstRecord[j+1];
 string month = firstRecord[j+3];
 string year = firstRecord[j+5] + firstRecord[j+6] + firstRecord[j+7] + firstRecord[j+8];
 
 int iday = stoi(day);
 int imonth = stoi(month);
 int iyear = stoi(year);
 
 
 
 }
 */




/*

#include <iostream>
#include <cstdio>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void print_llist(ListNode *head)
{
    ListNode *curr = head;
    printf("\n=== %s ===\n", __func__);
    while (curr)
    {
        printf("[%u]->", curr->val);
        curr = curr->next;
    }
    printf("[XXX]");
    printf("\n=== %s ===\n", __func__);
}

// 0 -> head
// 1 -> first

ListNode *delete_nth_node(ListNode *head, int n)
{
    cout << endl;
    cout << "Deleting node: " << n << endl;
    
    // if head is nullptr
    if(head == nullptr)
    {
        cout << "List is empty" << endl;
        return nullptr;
    }
    

        if(n == 0) // delete head
        {
            ListNode* temp;
            temp = head->next;
            
            delete head;
            return temp;
        }
        
        ListNode* curr;
        ListNode* prev;
        
        //1-2-3

        prev = nullptr;
        curr = head;
        
        while(n != 0) {
            prev = curr;
            curr = curr->next;
            if(curr == nullptr)
            {
                cout << "Index not found" << endl;
                return head;
            }
            n--;}
        
        prev->next = curr->next;
        
        delete curr;
        return head;
        
    
    return nullptr;
}

// 1-2-3-4-5
// 1-3-4-5

int main()
{
        // Test case 1
    ListNode *tc_node_1 = new ListNode(1);
    ListNode *tc_node_2 = new ListNode(2);
    ListNode *tc_node_3 = new ListNode(3);
    ListNode *tc_node_4 = new ListNode(4);
    ListNode *tc_node_5 = new ListNode(5);
    
    tc_node_1->next = tc_node_2;
    tc_node_2->next = tc_node_3;
    tc_node_3->next = tc_node_4;
    tc_node_4->next = tc_node_5;
    tc_node_5->next = nullptr;
    
    print_llist(tc_node_1);
    tc_node_1 = delete_nth_node(tc_node_1, 0);
    print_llist(tc_node_1);
    
    int a = 5;
    
    std::bitset<8> i(a);
    cout << "before shift" << endl;
    cout << i;
    cout << endl;
    auto j = (i | std::bitset<8>(1 << 4));
    cout << j;
    //cout << "After shift" << i | bitset<8>(1 << 4);
    return 0;
}
*/





