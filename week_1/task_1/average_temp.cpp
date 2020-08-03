#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main()
{
    vector<size_t>res;
    int count = 0;
    size_t N;
    int64_t average = 0;
    cin >> N;
    int number;
    vector<int64_t> nums;
    for (size_t i = 0; i < N; ++i) {
        cin >> number;
        nums.push_back(number);
        average += number;
    }
    average = average / static_cast<int>(N);

    for (size_t i = 0; i < N; ++i){
        if (nums[i] > average) {
            count +=1;
            res.push_back(i);
        }
    }
    cout << res.size()<<endl;
    for(auto el: res){
        if (res[0] == el){
            cout << el;
        } else {
            cout << " " << el;
        }
    }

    return 0;
}