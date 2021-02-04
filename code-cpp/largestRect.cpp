#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    stack<int> possibleLeftBars;
    heights.push_back(0);
    int maxGlobalArea = 0;

    for (int bar = 0; bar < heights.size(); bar++) {
        if (possibleLeftBars.empty()) {
            //this bar can make a left node
            possibleLeftBars.push(bar);
        } else {
            //stack is not empty..evaluate this bar against previous
            int currentLeftBarHeight = heights[possibleLeftBars.top()];
            int thisBarHeight = heights[bar];

            if (thisBarHeight >= currentLeftBarHeight) {
                //this again could be a left bar candidate with a bigger area..who knows
                //don't kill the old one because that can still form an area with this one
                possibleLeftBars.push(bar);
            } else {
                //now the prev bar can definitely not work with this one
                //so we try popping it as a candidate and check the max area we could obtain
                while (!possibleLeftBars.empty() && heights[possibleLeftBars.top()] > heights[bar]) {
                    int leftTallerBar = possibleLeftBars.top();
                    //pop the bar..see how far it has come on the breadth
                    possibleLeftBars.pop();

                    //see what area we could get from the current
                    int width = possibleLeftBars.empty() ? bar : bar - possibleLeftBars.top() - 1;
                    int areaWithThisBar = heights[leftTallerBar] * width;
                    maxGlobalArea = max(maxGlobalArea, areaWithThisBar);
                }
                //then add this bar to the height
                possibleLeftBars.push(bar);
            }
        }
    }
    return maxGlobalArea;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // vector<int> heights = {2, 1, 5, 6, 2, 3};
    // vector<int> heights = {1, 2, 6, 10};
    // vector<int> heights = {};
    // vector<int> heights = {0, 9};
    vector<int> heights = {9, 0};
    // vector<int> heights = {2, 1, 2};
    // vector<int> heights = {6, 7, 5, 2, 4, 5, 9, 3};

    std::cout << largestRectangleArea(heights) << endl;
    return 0;
}
