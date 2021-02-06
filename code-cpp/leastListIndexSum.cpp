#include <bits/stdc++.h>

/*
 * Given two lists, You need to help them find out their common interest with the least list index sum. 
 * If there is a choice tie between answers, output all of them with no order requirement. 
 * You could assume there always exists an answer.
 */
typedef pair<int, int> pii;

template <typename T>
ostream& operator<<(ostream& c, vector<T>& vs) {
    for (auto v : vs) {
        c << " -> " << v;
    }
    c << std::endl;
    return c;
}

typedef pair<string, int> psi;

vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
    map<string, int> list1Idx;
    for (int i = 0; i < list1.size(); i++) {
        list1Idx[list1[i]] = i;
    }
    vector<string> commonElementsWithLeastIdx;
    auto compare = [](psi a, psi b) {
        return a.second > b.second;
    };
    priority_queue<psi, vector<psi>, decltype(compare)> commonElemIdxQueue(compare);

    for (int i = 0; i < list2.size(); i++) {
        string elem = list2[i];
        if (list1Idx.find(elem) != list1Idx.end()) {
            int idxDiff = i + list1Idx[elem];
            commonElemIdxQueue.push(make_pair(elem, idxDiff));
        }
    }
    //guaranteed to have a common element
    int leastSum = commonElemIdxQueue.top().second;
    do {
        commonElementsWithLeastIdx.push_back(commonElemIdxQueue.top().first);
        commonElemIdxQueue.pop();
    } while (!commonElemIdxQueue.empty() && commonElemIdxQueue.top().second == leastSum);

    return commonElementsWithLeastIdx;
}

int main() {
    vector<string> list1 = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
    // vector<string> list2 = {"Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"};
    vector<string> list2 = {"KFC", "Shogun", "Burger King"};
    vector<string> out = findRestaurant(list1, list2);
    std::cout << out << endl;
    return 0;
}
