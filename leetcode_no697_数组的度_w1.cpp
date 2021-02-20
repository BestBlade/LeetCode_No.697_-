﻿/* ------------------------------------------------------------------|
给定一个非空且只包含非负数的整数数组 nums，数组的度的定义是指数组里任一元素出现频数的最大值。

你的任务是在 nums 中找到与 nums 拥有相同大小的度的最短连续子数组，返回其长度。

 

示例 1：

输入：[1, 2, 2, 3, 1]
输出：2
解释：
输入数组的度是2，因为元素1和2的出现频数最大，均为2.
连续子数组里面拥有相同度的有如下所示:
[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
最短连续子数组[2, 2]的长度为2，所以返回2.
示例 2：

输入：[1,2,2,3,1,4,2]
输出：6
 

提示：

nums.length 在1到 50,000 区间范围内。
nums[i] 是一个在 0 到 49,999 范围内的整数。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/degree-of-an-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*
*
*	执行用时：36 ms, 在所有 C++ 提交中击败了95.77%的用户
*	内存消耗：24.1 MB, 在所有 C++ 提交中击败了98.04%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

int findShortestSubArray(vector<int>& nums) {
    unordered_map<int, int> cnt;
    int maxcnt = 0;
    for (int& num : nums) {
        cnt[num]++;
        maxcnt = max(maxcnt, cnt[num]);
    }

    int minlen = INT_MAX;
    for (int i = 0; i < nums.size(); i++) {
        if (cnt[nums[i]] == maxcnt) {
            for (int j = i; j < nums.size(); j++) {
                if (nums[j] == nums[i]) {
                    cnt[nums[i]]--;
                }
                if (cnt[nums[i]] == 0) {
                    minlen = min(minlen, j - i + 1);
                    break;
                }
            }
        }
    }
    return minlen;
}

int main() {
    vector<int> nums = { 1,2,2,3,1,4,2 };
    findShortestSubArray(nums);
}