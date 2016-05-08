/*Program to implement DFS algo
Version 1.00 09-01-2014
By swat
*/
import java.io.*;
import java.util.*;
class stack
{
    int arr[]=new int[100],i,j,k,tp;
    stack()
    {
        tp=-1;
    }
    void push(int n)
    {
        arr[++tp]=n;
    }
    void pop()
    {
        tp--;
    }
    int top()
    {
        return arr[tp];
    }
    boolean empty()
    {
        if (tp==-1)
            return true;
        else
            return false;
    }
            
} 
public class DFS
{
    public static void main(String aa[])
    {
        Scanner inputst=new Scanner(System.in);
        stack stck=new stack();
        System.out.print("Enter N :");
        int n;
        n=inputst.nextInt();
        int i,j,k,l;
        boolean trigger=false;
        int a[][]=new int[n+1][n+1];
        int v[]=new int[n+1];
        System.out.println("Adj Matrix :");
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                a[i][j]=inputst.nextInt();
            }
        }
        stck.push(1); 
        // Printng 1 As we Assumed it to be our root
        System.out.print("TransVersal Order Of graph : "+'1'+" "); 
        v[1]=1;
        while(!stck.empty())
        {
            k=stck.top();
            trigger=false;
            for(i=1;i<n+1;i++)
            {
                if(a[k][i]==1 && v[i]==0)
                {
                    v[i]=1;
                    stck.push(i);
                    trigger=true;
                    break;
                }
            }
            if(trigger==true)
                System.out.print(i+" ");
            else
                stck.pop();
        }
    }
}