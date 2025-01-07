//Given an array of integers "nums" and an integer "target",
//return index of the two numbers whose sum is equals to target.
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
        int[] nums = {9, 12, 6, 8, 2, 10};
        int target = 14;
        System.out.println(Arrays.toString(nums));
        System.out.println(Arrays.toString(twoSum(nums, target)));
        //Arrays.toString method is used to convert an array into a human-readable string representation.
    }
}
