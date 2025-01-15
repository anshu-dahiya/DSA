//You are given an array prices where prices[i] is the price of a given stock on the ith day.
//You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
//Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

//Example 1:
//Input: prices = [7,1,5,3,6,4]
//Output: 5
//Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
//Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

//Example 2:
//Input: prices = [7,6,4,3,1]
//Output: 0
//Explanation: In this case, no transactions are done and the max profit = 0.

public class Best_Time_To_Buy_And_Sell_Stock {

    public int maxProfit(int[] prices){
        int n = prices.length;
        int minPrice = prices[0];
        int profit;
        int maxProfit = 0;

        for(int i=1; i<n; i++){
            if(minPrice > prices[i]){
                minPrice = prices[i];
            }

            profit = prices[i] - minPrice;

            if(profit > maxProfit){
                maxProfit = profit;
            }
        }
        return maxProfit;
    }

    public static void main(String[] args) {
        Best_Time_To_Buy_And_Sell_Stock bs = new Best_Time_To_Buy_And_Sell_Stock();

        int[] prices1 = {7,1,5,3,6,4};
        System.out.println("Max Profit in Prices1: " + bs.maxProfit(prices1));

        int[] prices2 = {7,6,4,3,1};
        System.out.println("Max Profit in Prices2: " + bs.maxProfit(prices2));
    }
}
