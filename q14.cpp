// C++ program to find the only repeating element in an 
// array of size n and elements from range 1 to n-1. 
#include <bits/stdc++.h> 
#include <array>
  
  
// Returns index of second appearance of a repeating element 
// The function assumes that array elements are in range from 
// 1 to n-1. 
int *FindRepeatingElement(int *first, int *last){
    int *left = first;
    int *right = std::prev(last);
    int *mid;
      
    while(left <= right){
        mid = left + (right-left)/2;
          
        if(*mid == std::distance(first, mid)){
            left = mid+1;
        }
        else{
            right = mid - 1;
        }
    }
      
    return left;
}
  
// Driver code 
int main() 
{ 
    std::array<int, 6> arr {0, 0, 1, 2, 3, 4}; 
    int *index = FindRepeatingElement(arr.begin(), arr.end()); 
    std::cout << *index; 
    return 0; 
} 