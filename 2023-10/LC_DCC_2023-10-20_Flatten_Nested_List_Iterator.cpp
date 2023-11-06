// LC DCC 2023/10/20
// 341. Flatten Nested List Iterator
// Medium

#include <bits/stdc++.h>
using namespace std;

#define ll long long

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
*/

#include <vector>

class NestedIterator {
public:
    vector<int> flattened;
    int index;
    
    vector<int> flatten(vector<NestedInteger>& nested) {
        vector<int> result;
        for(auto& ni: nested) {
            if(ni.isInteger())
                result.push_back(ni.getInteger());
            else {
                auto subList = flatten(ni.getList());
                result.insert(result.end(), subList.begin(), subList.end());
            }
        }

        return result;
    }

    NestedIterator(vector<NestedInteger> nestedList) {
        flattened = flatten(nestedList);
        index = 0;
    }

    int next() {
        return flattened[index++];
    }

    bool hasNext() {
        return index < flattened.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        
    }

    return 0;
}

/* Sample Input:


Sample Output:


*/