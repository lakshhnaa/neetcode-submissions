class Solution {
    public boolean hasDuplicate(int[] nums) {
    Hashtable <Integer,Integer> hash = new Hashtable<>();

    for(int num:nums){
        if(!hash.containsKey(num)){
            hash.put(num,1);
        }
        else{
            return true;
        }
    }
    return false;
}
}