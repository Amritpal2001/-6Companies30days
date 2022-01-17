#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> max10nums(vector<int> &nums)
{
    int n = nums.size();
    vector<int> res;
    priority_queue<int,vector<int>, greater<int>> pq(nums.begin(), nums.begin()+10);
    for(int i=10;i<n;i++)
    {
        if(pq.top()<nums[i])
        {
            pq.pop();
            pq.push(nums[i]);
        }
    }
    while(!pq.empty())
    {
        res.push_back(pq.top());
        pq.pop();
    }
    return res;
}

int main()
{
    vector<int> nums={2324,1,435,4,4534,1,6,34,4356534,223,34,0,435,656,435,5432,223,12,223,35,3759,5,35678,87,5675};
    vector<int> res=max10nums(nums);
    for(int i:res)
        cout<<i<<" ";
    cout<<endl;
    return 0;
    // Time Complexity : N*log(10);
}