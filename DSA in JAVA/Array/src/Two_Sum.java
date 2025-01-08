//Given an array of integers "nums" and an integer "target",
//return index of the two numbers whose sum is equals to target.

//Example 1:
//Input: nums = [2,7,11,15], target = 9
//Output: [0,1]
//Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

//Example 2:
//Input: nums = [3,2,4], target = 6
//Output: [1,2]

//Example 3:
//Input: nums = [3,3], target = 6
//Output: [0,1]
import java.util.*;

public class Two_Sum {
    static int[] twoSum(int[] nums, int target){
        int n = nums.length;

        for (int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                if(nums[i] + nums[j] == target){
                    return new int[] {i, j};
                }
            }
        }
        return new int[]{};
    }

    public static void main(String[] args) {
        int[] nums1 = {2,7,11,15};
        int target1 = 9;
        System.out.println("Array1: " + Arrays.toString(nums1));
        System.out.println("Array1 target index: " + Arrays.toString(twoSum(nums1, target1)));
        //Arrays.toString method is used to convert an array into a human-readable string representation.

        int[] nums2 = {3,2,4};
        int target2 = 6;
        System.out.println("Array2: " + Arrays.toString(nums2));
        System.out.println("Array2 target index: " + Arrays.toString(twoSum(nums2, target2)));

        int[] nums3 = {3,3};
        int target3 = 6;
        System.out.println("Array3: " + Arrays.toString(nums3));
        System.out.println("Array3 target index: " + Arrays.toString(twoSum(nums3, target3)));
    }
}
