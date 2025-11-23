//problem 5 - Count distinct elements in every window
// topics - fixed-size sliding window, hashmap
// available on gfg - Count distinct elements in every window



import java.util.ArrayList;
import java.util.HashMap;

public class distinct {
    public static ArrayList<Integer> countDistinct(int arr[], int k){
        HashMap<Integer,Integer> map = new HashMap<>();
        ArrayList<Integer> res = new ArrayList<>();

        for(int i=0;i<k;i++){
            if(map.containsKey(arr[i])){
                map.put(arr[i],map.get(arr[i])+1);
            }else{
                map.put(arr[i],1);
            }
        }
        res.add(map.size());
        int i=1;
        int j=k;

        while(j<arr.length){


            if(j<arr.length){
                if(map.containsKey(arr[j])){
                    map.put(arr[j],map.get(arr[j])+1);
                }else{
                    map.put(arr[j],1);
                }
                if(map.get(arr[i-1])==1){
                    map.remove(arr[i-1]);
                }else{
                    map.put(arr[i-1],map.get(arr[i-1])-1);
                }
            }
            res.add(map.size());
            i++;j++;

        }
        return res;
    }
}
