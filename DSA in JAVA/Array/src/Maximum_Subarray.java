//Given an integer array nums, find the subarray with the largest sum,
//and return its sum.

//Example 1: Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
//Output: 6
//Explanation: The subarray [4,-1,2,1] has the largest sum 6.

//Example 2:
//Input: nums = [1]
//Output: 1
//Explanation: The subarray [1] has the largest sum 1.

//Example 3:
//Input: nums = [5,4,-1,7,8]
//Output: 23
//Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.

public class Maximum_Subarray {
    public int maxSubarray(int[] nums){

        int sum = 0;
        int maxSum = nums[0];

        for(int i=0; i<nums.length; i++){

            sum = sum + nums[i];
            if(sum > maxSum){
                maxSum = sum;
            }
            if(sum < 0){
                sum = 0;
            }
        }
        return maxSum;
    }
    public static void main(String[] args){
        Maximum_Subarray ms = new Maximum_Subarray();

        int[] nums1 = {-2,1,-3,4,-1,2,1,-5,4};
        System.out.println("Max Subarray Sum: " + ms.maxSubarray(nums1));

        int[] nums2 = {1};
        System.out.println("Max Subarray Sum: " + ms.maxSubarray(nums2));

        int[] nums3 = {5,4,-1,7,8};
        System.out.println("Max Subarray Sum: " + ms.maxSubarray(nums3));
    }
}
