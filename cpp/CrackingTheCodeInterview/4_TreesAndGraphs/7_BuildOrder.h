//https://leetcode.com/problems/course-schedule-ii/
#ifndef ALGORITHMICCHALLENGES_7_BUILDORDER_H
#define ALGORITHMICCHALLENGES_7_BUILDORDER_H

#include <vector>

class SolutionTopologicalSort {
    using ItemsT = std::vector<std::vector<int>>;
    const short ADDED = 1;
    const short VISITED = 2;
    bool addItem(int index, std::vector<short>& addedItems, const ItemsT& items, std::vector<int>& result) {
        if (addedItems[index] == ADDED)
            return true;
        if (addedItems[index] == VISITED)
            return false;
        addedItems[index] = VISITED;
        for (auto dependency : items[index])
            if (!addItem(dependency, addedItems, items, result))
                return false;
        result.push_back(index);
        addedItems[index] = ADDED;
        return true;
    }

public:
    std::vector<int> findOrder(int numItems, const std::vector<std::vector<int>>& prerequisites) {
        ItemsT items(numItems);
        for (const auto& prerequisite : prerequisites)
            items[prerequisite.front()].push_back(prerequisite.back());
        std::vector<short> addedItems(numItems, 0);
        std::vector<int> result;
        for (int i = 0; i < numItems; ++i)
            if (!addItem(i, addedItems, items, result))
                return {};
        return result;
    }
};


#endif //ALGORITHMICCHALLENGES_7_BUILDORDER_H
