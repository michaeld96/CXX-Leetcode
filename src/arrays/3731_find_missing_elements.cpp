#include <cassert>
#include <vector>

using namespace std;

vector<int> findMissingElements(vector<int>& nums) 
{
    std::vector<int> missing;
    int min = *std::min_element(nums.begin(), nums.end());
    int max = *std::max_element(nums.begin(), nums.end());
    for (int i = min + 1; i < max; ++i) {
        auto itr = std::find(nums.begin(), nums.end(), i);
        if (itr == nums.end()) {
            missing.push_back(i);
        }
    }

    return missing;
}

int main()
{
    vector<int> input = { 1,4,2,5 };
    const int expected = 3;
    const vector<int> result = findMissingElements(input);
    assert(expected == result[0]);
    return 0;
}