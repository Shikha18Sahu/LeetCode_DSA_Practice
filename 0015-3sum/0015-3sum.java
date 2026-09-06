class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Set<List<Integer>> ans = new HashSet<>();
        for(int i = 0; i<nums.length; i++){
            Set<Integer>st = new HashSet<>(); 
            for(int j = i+1; j<nums.length; j++){
                int third = -(nums[i] + nums[j]);
                if(st.contains(third)){
                    List<Integer> temp= Arrays.asList(nums[i], nums[j], third); 
                    Collections.sort(temp); 
                ans.add(temp);
                
                 
            }
            st.add(nums[j]); 
        }
    }
    return new ArrayList<>(ans); 
}
}