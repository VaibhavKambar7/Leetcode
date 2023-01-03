#include<bits/stdc++.h>
using namespace std;

int merge(int arr[],int temp[],int left,int mid,int right)
{
    int i,j,k;
    int inv_count=0;
    i=left;
    j=mid;
    k=left;

    while((i<=mid-1) && (j<=right)){
        if(arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];

            inv_count = inv_count + (mid-i);
        }
    }

    while(i<=mid-1)
    {
        temp[k++] = arr[i++];
    }

    while(j<=right)
    {
        temp[k++] = arr[j++];
    }

    for(int i=left;i<=right;i++)
    {
        arr[i] = temp[i];
    }

    return inv_count;


}

int mergesort(int arr[],int temp[],int left,int right)
{
    int mid,inv_count=0;
    if(right>left)
    {

        mid=(left+right)/2;
        inv_count += mergesort(arr,temp,left,mid);
        inv_count += mergesort(arr,temp,mid+1,right);

        inv_count +=merge(arr,temp,left,mid+1,right);
    }

    return inv_count;

}

int main()
{
    int arr[] = {5,3,2,4,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    int temp[n];//in merge sort we need an extra empty array which stores final sorted array as ans
    int ans;

    ans = mergesort(arr,temp,0,n-1);

    cout<<"Number of inversions are "<<ans; 

    return 0;
}


//GFG

// long long m(long long arr[], long long l, long long m, long long r)
//     {
//         long long temp[r-l+1];
//         long long i,j,k;
//         i = l;
//         j = m+1;
//         k=0;
//         long long ci=0;
        
//         while(i<=m&&j<=r)
//         {
//             if(arr[i]<=arr[j])
//             {
//                 temp[k++] = arr[i++];
//             }
//             else
//             {
//                 temp[k++] = arr[j++];
//                 ci+=(m-i+1);
//             }
//         }
        
//         while(i<=m)
//         temp[k++] = arr[i++];
        
//         while(j<=r)
//         temp[k++] = arr[j++];
        
//         for(long long i=l;i<=r;i++)
//         {
//             arr[i] = temp[i-l];
//         }
        
//         return ci;
        
//     }
    
//     long long  ms(long long arr[], long long low, long long high)
//     {
//         long long ci=0;
//         if(low<high)
//         {
//             long long mid = (low+high)/2;
//             ci += ms(arr, low, mid);
//             ci += ms(arr, mid+1, high);
//             ci += m(arr, low, mid, high);
//         }
//         return ci;
//     }
//     long long int inversionCount(long long arr[], long long N)
//     {
//         // Your Code Here
//         return ms(arr, 0, N-1);
//     }