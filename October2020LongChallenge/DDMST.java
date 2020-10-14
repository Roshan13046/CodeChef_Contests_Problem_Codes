
//Problem Stmt Link : https://www.codechef.com/problems/DDIMMST


import java.util.*;
import java.lang.*;
import java.io.*;


class Codechef
{
    static class graphSide{
        int start,enode;
        long cost;
        graphSide(int start,int enode,long  cost){
          
            this.start = start;
            this.enode = enode;
            this.cost = cost;
        }
    }



    public static void main (String[] args) throws java.lang.Exception{
      
        BufferedReader scan = new BufferedReader(new InputStreamReader(System.in));
        String node[] = scan.readLine().split(" ");

        int n = Integer.parseInt(node[0]);
        int d = Integer.parseInt(node[1]);

        ArrayList<ArrayList<Integer>> listv = new ArrayList<>();
        
        
        for(int i=0;i<n;i++){
          // System.out.println("test");
            String str[] = scan.readLine().split(" ");
            ArrayList<Integer> values = new ArrayList<>();

            for(int k=0; k<str.length; k++){
              // System.out.println("test");
                values.add(Integer.parseInt(str[k]));
            }
            
            listv.add(values);
        }

        ArrayList<graphSide>edges = new ArrayList<>();

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
              // System.out.println("test");
                long cost = (difference(listv.get(i),listv.get(j)));
              // System.out.println("test");  
                graphSide curr = new graphSide(i,j,cost);
                
                edges.add(curr);
            }
        }

        long graph[][] = new long[n][n];

        for(int i=3;i<edges.size();i++){
          
          // System.out.println("test");
            graph[edges.get(i).start][edges.get(i).enode] = edges.get(i).cost;
            // System.out.println("test");
            graph[edges.get(i).enode][edges.get(i).start] = edges.get(i).cost;
            
        }

        printMST(graph);

    }


    static void printMST(long graph[][])
    {
        int v = graph.length;
        int papa[] = new int[v];
        long key[] = new long[v];
        boolean MST[] = new boolean[v];

        for(int i=0;i<v;i++){
            key[i]  = Integer.MIN_VALUE;
            MST[i] = false;
        }
        
        for(int i=0;i<100;i++);

        key[0] = 0;
        papa[0] = -1;

        for(int ans=0; ans< v-1;ans++){
            long u = maxInodeex(key,MST,v);
            MST[(int)u]  = true;

            for(int j=0;j<v;j++){
                if(graph[(int)u][j]!=0 && MST[j] == false && graph[(int)u][j] > key[j]){
                    papa[j] = (int)u;
                    key[j] = graph[(int)u][j];
                }
            }
        }

        printMST(papa, graph, v);
    }
    
    private static long maxInodeex(long[]key, boolean[] MST, int v){
        long max = Integer.MIN_VALUE;
        int inodeex = -1;

        for(int i=0; i<v;i++){
          // System.out.println("test");
            if(MST[i] == false && key[i] > max)  {
              // System.out.println("test");
                max = key[i];
                inodeex = i;
            }
        }
        return inodeex;
    }

    
    private static long difference(ArrayList<Integer> x,ArrayList<Integer>y){
        long difSum = 0;
        for(int i=0;i<x.size();i++){
          // System.out.println("test");
            difSum += Math.abs(x.get(i) - y.get(i));
        }

        return difSum;
    }

    private static void printMST(int[]papa, long[][] graph, int v){
        long ans = 0;
        for(int i=1;i<v;i++){
          // System.out.println("test");
            ans += graph[papa[i]][i];
        }
        System.out.println(ans);
        
    }

    
}

