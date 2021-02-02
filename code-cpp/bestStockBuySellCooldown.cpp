#include <bits/stdc++.h>

/*
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * Design an algorithm to find the maximum profit. You may complete as many transactions
 * as you like (ie, buy one and sell one share of the stock multiple times) with the 
 * following restrictions:

 * You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 * After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
 */

int f(int i, bool buyMode, vector<int> &prices, vector<vector<int> > &dp) {
    int n = prices.size();
    if (i >= n) {
        dp[i][buyMode] = 0;
        return 0;
    }
    if (dp[i][buyMode] != -1) {
        return dp[i][buyMode];
    }
    if (buyMode) {
        //we are in buy mode
        //either skip this or buy this and take the max
        //that would be the result of buying on the ith day.
        //profit would come only if selling
        int skipToday = f(i + 1, true, prices, dp);

        //buy today and turn into sell mode
        int buyToday = -prices[i] + f(i + 1, false, prices, dp);

        // return max(skipToday, buyToday);
        dp[i][buyMode] = max(skipToday, buyToday);
        return dp[i][buyMode];

    } else {
        //sellmode
        //you either sell today and book profit and are back in buy mode with lockdown
        // assert(boughtOn != MAX);
        //skip selling today but continue being in sell mode
        // int profitOnSellingToday = prices[i] - prices[boughtOn];
        int skipToday = f(i + 1, false, prices, dp);

        int sellToday = prices[i] + f(i + 2, true, prices, dp);
        // if (profitOnSellingToday < 0) {
        //     //why'd you want to sell at a loss
        //     dp[i][boughtOn] = skipToday;
        // } else {
        //     // return max(sellToday, skipToday);
        // }
        dp[i][buyMode] = max(sellToday, skipToday);
        return dp[i][buyMode];
    }
}

int f_rec(int i, bool buyMode, vector<int> &prices) {
    int n = prices.size();
    if (i >= n) {
        return 0;
    }
    if (buyMode) {
        //we are in buy mode
        //either skip this or buy this and take the max
        //that would be the result of buying on the ith day.
        //profit would come only if selling
        int skipToday = f_rec(i + 1, true, prices);
        //buy today and turn into sell mode
        int buyToday = -prices[i] + f_rec(i + 1, false, prices);
        return max(skipToday, buyToday);

    } else {
        //sellmode
        //you either sell today and book profit and are back in buy mode with lockdown
        int sellToday = prices[i] + f_rec(i + 2, true, prices);
        //skip selling today but continue being in sell mode
        int skipToday = f_rec(i + 1, false, prices);
        return max(sellToday, skipToday);
    }
}

int maxProfit(vector<int> &prices) {
    int n = prices.size();
    vector<vector<int> > dp(n + 5, vector<int>(2, -1));
    return f(0, true, prices, dp);
}

int main() {
    cin.tie(0);
    std::cout << "Here " << (1 << 31);
    ios::sync_with_stdio(false);

    vector<int> nums_a = {1, 2, 3, 0, 2};
    vector<int> nums_b = {1, 2, 3, 0, 2};
    vector<int> nums_c = {1, 2, 115, 1000, 2};
    vector<int> nums_d = {2, 1, 4, 5, 2, 9, 7};
    std::cout << maxProfit(nums_a) << std::endl;
    std::cout << maxProfit(nums_b) << std::endl;
    std::cout << maxProfit(nums_c) << std::endl;
    std::cout << maxProfit(nums_d) << std::endl;
    return 0;
}
