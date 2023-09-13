#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N;
    while(cin >> N){
        vector<bool> nums(1000, false);
        
        while(N--){
            int num;
            cin >> num;
            if(!nums[num - 1])
                nums[num - 1] = true;
        }
        for(int i = 0; i < nums.size(); i++){
            if(nums[i])
                cout << i + 1 << endl;
        }
    }
    
    return 0;
}

