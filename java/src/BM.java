import java.util.HashMap;

/**
 * @ClassName BM
 * @Author lzheng
 * @Date 2019/10/7 14:04
 * @Version 1.0
 * @Description:
 */


public class BM {
    public static void main(String[] args) {
        char[] l="BNVHABVCABDAB我草SDFACAAS".toCharArray();
        char[] p="我草".toCharArray();
        int l_len=l.length;
        int p_len=p.length;
        HashMap<Character,Integer> badChar=new HashMap<>();
        for(int i=0;i<p_len-1;i++){
            badChar.put(p[i],i);
        }
        int i=p_len-1;
        int j=p_len-1;
        while(i<l_len&&j>=0){
            if (l[i]==p[j]){
                i--;
                j--;
            }else{
                if (!badChar.containsKey(l[i])){
                    i+=p_len;
                    j=p_len-1;
                }else {
                    i+=j-badChar.get(l[i]);
                    j=p_len-1;
                }
            }
        }
        System.out.println(i+1);
    }


}
