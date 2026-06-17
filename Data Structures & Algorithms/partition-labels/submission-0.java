class Solution {
    public List<Integer> partitionLabels(String s) {
       int i = 0;
       List<Integer> ans = new ArrayList<>();
       int first = 0, end = 0; 
       while(i < s.length()) {
            char c = s.charAt(i);
            end = Math.max(s.lastIndexOf(c), end); 
            if(s.lastIndexOf(c) == i && end == i) {
                ans.add(end - first + 1);
                first = i+1;
            }
            i++;
       }
       return ans;
    }
}
