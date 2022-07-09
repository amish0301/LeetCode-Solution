#include<bits/stdc++.h>
using namespace std;

int main(){
    int nums[7] = {10, 20, 30, 40, 50, 5, 7};

    int s = 0, e = 6, ans = INT_MAX;
    while(s <= e)
    {
        int mid = s + (e - s) / 2;

        ans = min(ans, nums[mid]);

        if(nums[mid] <= nums[s])
            e = mid - 1;
        else
            s = mid + 1;
    }
    cout << ans;
    return 0;
}