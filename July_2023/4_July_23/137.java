import java.util.HashMap;
import java.util.Map;

class Solution {
    public int singleNumber(int[] nums) {
        int size = nums.length;
        Map<Integer, Integer> mp = new HashMap<>();
        for (int i = 0; i < size; i++) {
            int num = nums[i];
            mp.put(num, mp.getOrDefault(num, 0) + 1);
        }
        int ans = 0;
        for (Map.Entry<Integer, Integer> entry : mp.entrySet()) {
            if (entry.getValue() == 1) {
                ans = entry.getKey();
                break;
            }
        }
        return ans;
    }
}
