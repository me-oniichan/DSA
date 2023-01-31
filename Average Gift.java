import java.util.*;
import java.util.concurrent.SubmissionPublisher;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner s = new Scanner(System.in);
        int t = s.nextInt();
        while(t-->0){
            int n = s.nextInt(), x= s.nextInt(), elem;
            int min=(int)1e9, max=0;
            for(int i=0; i <n;i++){
                elem = s.nextInt();
                min = Math.min(elem, min);
                max = Math.max(elem, max);
            }
            if(x>=min&&x<=max) System.out.println("YES");
            else System.out.println("NO");
        }
	}
}