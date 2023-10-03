#include <bits/stdc++.h> 
#include <array>

// Returns index of the duplicate
int *findDuplicate(int *first, int *last){
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
    int *index = findDuplicate(arr.begin(), arr.end()); 
    std::cout << *index; 
    return 0; 
} 