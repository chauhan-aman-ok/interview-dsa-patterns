// leetcode - 1, two sum
// topics - arrays, hashmap

public int[] twoSum(int[] nums, int target) {
         int[] res=new int[2];
        HashMap<Integer,Integer> mp=new HashMap<>();
        int j=0;
        while(j<nums.length){
            if(mp.containsKey(target-nums[j])){
                res[0]=j;
                res[1]=mp.get(target-nums[j]);
                return res;
            }
            mp.put(nums[j],j);
            j++;
        }
        return res;
}
