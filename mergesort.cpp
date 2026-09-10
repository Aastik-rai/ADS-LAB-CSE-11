#include <bits/stdc++.h>
using namespace std;



void mergeA(vector<int>&arr,int low,int mid,int high){
    vector<int>temp;
    int left=low;
    int right=mid+1;
    while(left<=mid&&right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;

        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
        
    }
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;    
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;    
    }
    int n=temp.size();
    for(int i =0;i<n;i++){
        arr[low+i]=temp[i];
    }

}
void mS(vector<int>&arr,int low,int high){
    if(low>=high)return;
    int mid=(low+high)/2;
    mS(arr,low,mid);
    mS(arr,mid+1,high);
    mergeA(arr,low,mid,high);
}
void mergeSort(vector<int>&arr,int n){
    mS(arr,0,n-1);
}


int main(){
    vector<int>arr={3,2,4,2,23,4,3,2,2,1};
    int n=arr.size();
    mergeSort(arr,n);
    for(auto it:arr){
        cout<<it<<" ";
    }

}


