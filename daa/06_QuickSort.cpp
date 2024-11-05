#include<bits/stdc++.h>
using namespace std;

int partition(int first, int last, vector<int>&nums)
{
    int i = first-1;
    int j = first;
    int pivot = nums[last];

    for(;j<last; j++)
    {
        if(nums[j] < pivot)
        {
            i++;
            swap(nums[i], nums[j]);
        }
    }

    swap(nums[i+1], nums[j]);
    return i+1;
}
void quickSort(int first, int last, vector<int>&nums)
{
    if(first >= last) return;

    int pi = partition(first, last, nums);
    quickSort(first, pi - 1, nums);
    quickSort(pi+1, last, nums);
}
int main()
{
    vector<int>nums = {15,10,20,5,25};
    int n = nums.size();

    quickSort(0, n-1, nums);

    for(auto it : nums)
    {
        cout<<it<<" ";
    }
}