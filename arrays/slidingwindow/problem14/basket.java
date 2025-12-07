// problem 14 - fruits into the basket
// leetcode - 904
// topics - arrays, variable size sliding window, hashmap

public int totalFruit(int[] a) {
        int i=0;
        int j=0;
        int winLen=0;
        int maxLen=0;
        Map<Integer,Integer> mp = new HashMap<>();
        while(j<a.length){
            if(mp.containsKey(a[j])) mp.put(a[j],mp.get(a[j])+1);
            else mp.put(a[j],1);

            while(mp.size()>2){
                if(mp.get(a[i])>1) mp.put(a[i],mp.get(a[i])-1);
                else mp.remove(a[i]);
                i++;
            }
            winLen=j-i+1;
           maxLen=Math.max(maxLen,winLen); j++;
        }
        return maxLen;
}
