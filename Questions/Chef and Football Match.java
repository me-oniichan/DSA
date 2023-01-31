//Problem Statement : https://www.codechef.com/problems/WATCHFB
package Questions;

import java.util.*;

class Codechef {
    public static void main(String[] args) throws java.lang.Exception {
        Scanner s = new Scanner(System.in);
        int t = s.nextInt();
        while (t-- > 0) {
            int c = s.nextInt();
            int a = 0, b = 0;
            while (c-- > 0) {
                int n = s.nextInt(), x = s.nextInt(), y = s.nextInt();
                if (n == 1 || x==y) {
                    a = x;
                    b = y;
                    System.out.println("YES");
                } else {
                    if (Math.min(x, y) >= Math.max(a, b))
                        System.out.println("NO");
                    else {
                        System.out.println("YES");
                        if (a > b) {
                            b = Math.min(x, y);
                            a = Math.max(y, x);
                        } else {
                            a = Math.min(x, y);
                            b = Math.max(y, x);
                        }
                    }
                }
            }
        }
        s.close();
    }
}