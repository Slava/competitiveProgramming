import java.io.*;
import java.math.*;
import java.util.*;

public class Main{
    private void solve () throws IOException {
        int n = nextInt();
        int[] d = new int[n];
        for (int i = 1; i < n; i++)
            d[i] = nextInt();
        int a = nextInt(), b = nextInt(), ans = 0;
        for (int i = a; i < b; i++)
            ans += d[i];
        out.println(ans);
    }
    public static void main (String[] argc){
        new Main().run();
    }
    BufferedReader in;
    PrintWriter out;
    StringTokenizer toker;

    public void run (){
        try{
//              FileReader stdin = new FileReader("a.in");
//              FileWriter stdout = new FileWriter("a.out");
                in = new BufferedReader(new InputStreamReader(System.in));
                toker = null;
                out = new PrintWriter(System.out);
                solve();
                in.close();
                out.close();
        }
        catch (Exception e){
            System.exit(1);
        }
    }
    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }
    long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }
    double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }
    String nextToken() throws IOException {
        while (toker == null || !toker.hasMoreTokens()){
            toker = new StringTokenizer(in.readLine());
        }
        return toker.nextToken();
    }
}




// lang: Java 6
// memory: 34400 KB
// author: imslavko
// submit_date: Nov 7, 2011 3:58:44 PM
// contest: 38
// link: /contest/38/submission/839415
// time: 110 ms
// verdict: Accepted
// problem: 38A - Army
// ID: 839415
// downloaded by very stupid script
