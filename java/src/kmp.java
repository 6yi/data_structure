/**
 * @ClassName kmp
 * @Author lzheng
 * @Date 2019/10/7 13:03
 * @Version 1.0
 * @Description:
 */


public class kmp {

    public static int[] getNext(char[] p){
        int p_len=p.length;
        int [] next=new int[p_len];
        int j=-1;
        int i=0;
        next[0]=-1;
        while ((p_len - 1) > i){
            if(j==-1||p[j]==p[i]){
                j++;
                i++;
                next[i]=j;
            }else {
                j = next[j];
            }
        }
        return next;
    }
    public static void main(String[] args) {
        char[] l="BNVHABVCABDABDBDASDFACAAS".toCharArray();
        char[] p="ABDABDBD".toCharArray();
        int[] next=getNext(p);
        int l_len=l.length;
        int p_len=p.length;
        int i=0;
        int j=0;
        while (i<l_len&&j<p_len){
            if (j==-1||l[i]==p[j]){
                i++;
                j++;
            }else{
                j=next[j];
            }
            if (j==p_len){
                System.out.println("yes  "+(i-j));
            }
        }
    }


}
