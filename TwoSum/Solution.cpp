class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> hash;

        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int requiredNum = target - num;

            auto it = hash.find(requiredNum);

            if (it != hash.end()) {
                return {i, it->second};
            }
            hash.insert({num, i});
        }

        return {};
    }

    /*
    Your code's 138ms runtime is primarily due to the extensive use of std::cout
    statements within the loop. Input/output operations are generally very slow
    and can significantly impact performance, especially in competitive
    programming contexts where strict time limits apply.

    Beyond the std::cout statements, there are a few logical issues that could
    make the code less efficient and potentially incorrect:

    Order of insertion and lookup: You're inserting num into the hash map before
    checking if requiredNum (its complement) exists. This means if requiredNum
    is the same as num (e.g., nums = [3,3], target = 6), hash.find(requiredNum)
    will find the current element that was just inserted at index i. Incorrect
    if(i == it->second) logic: This condition is meant to prevent using the same
    element twice. However, because you insert num at index i immediately before
    checking for requiredNum, if requiredNum == num, it->second will always be
    i. This means it will always continue, potentially missing the correct pair
    if target is 2 * num and num appears twice at different indices. Manual
    index management: You're manually managing i as an index with a range-based
    for loop, which can lead to off-by-one errors or confusion. A traditional
    for loop (for (int i = 0; i < nums.size(); ++i)) is usually clearer when
    indices are needed.

            int i = 0;
            int j = 0;
            for (int num : nums) {
                //std::cout << " i: " << i << "j: " << j << endl;
                //std::cout << "Inserting num: " << num << endl;
                hash.insert({num, i});
                auto requiredNum = target - num;

                auto it = hash.find(requiredNum);

                if (it != hash.end()) {
                    if(i == it->second)
                    {
                        i++;
                        continue;

                    }
                    //std::cout << "Subodh found elem: " << num << endl;

                    j = it->second;
                    //std::cout << " i: " << i << "j: " << j << endl;
                    break;
                    // return {i , it->first};
                } else {

                    //std::cout << "Incrementing i: " << i << endl;
                    ++i;
                    //std::cout << "Incrementing i: " << i << endl;
                }
            }

            return {i, j};
        }*/
};
