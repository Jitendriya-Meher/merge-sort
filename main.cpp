#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void merge_array(int *arr,int start, int mid, int end)
{
  // declare the two length of the array
  int len1= mid - start + 1; // from start to mid
  int len2= end - mid;       // from mid+1 to end
  
  // declare two array  dynamically
  int *arr1=new int[len1];
  int *arr2=new int[len2];

  // copy the values to new array
  int ind1=start;     
  int ind2=mid+1;
  
  for(int i=0; i<len1; i++)
    {
      arr1[i]= arr[ ind1 + i ];
    }
  
  for(int i=0; i<len2 ;i++)
    {
      arr2[i]= arr[ ind2 + i];
    }

  // merge two sorted array
  int i=0;
  int j=0;
  int arrind=start;

  while( i<len1 && j<len2 )
    {
      if( arr1[i] < arr2[j] )
      {
        arr[ arrind++ ]= arr1[ i++ ];
      }
      else
      {
        arr[ arrind++ ]= arr2[ j++ ];
      }
    }

  while( i<len1 )
    {
      arr [arrind ++ ]= arr1[ i++ ];
    }

  while( j<len2 )
    {
       arr[ arrind++ ]= arr2[ j++ ]; 
    }

  // delete the two new array
  delete []arr1;
  delete []arr2;
  
}

void merge_sort(int *arr,int start, int end)
{
  // base case
  if( start >= end )
  {
    return;
  }

  // find the mid index and divide the array into two parts
  int mid=start + (end-start)/2;

  // recursive call to left array
  merge_sort(arr,start,mid);

  // recursive call to right array
  merge_sort(arr,mid+1,end);

  // merge the two sorted array that comes from the recursive         call
  merge_array( arr, start, mid, end);
  
}

int main() {

  int arr[100];
  
  int n;
  cout<<" enter the size of the array :  ";
  cin>>n;

  cout<<endl<<" enter the elements into the arry : "<<endl;
  for(int i=0;i<n;i++)
    {
      cout<<" "<<i+1<<" :  ";
      cin>>arr[i];
    }cout<<endl;

  cout<<" array before sorting : "<<endl;
  for(int i=0;i<n;i++)
    {
      cout<<" "<<arr[i]<<" ";
    }cout<<endl;

  // function call to merge sort
  merge_sort(arr,0,n-1);
  cout<<endl;

  cout<<" array after sortng : "<<endl;
  for(int i=0;i<n;i++)
    {
      cout<<" "<<arr[i]<<" ";
    }cout<<endl;

  return 0;
  
}