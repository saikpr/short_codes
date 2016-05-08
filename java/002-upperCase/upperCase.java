/*WAP to Convert words in a paragraph to upper case	
Version 1.00 16-01-2014
By Sainyam Kapoor
*/
import java.util.Scanner;

public class upperCase
{
	public static void main(String[] args)
	{
		System.out.println("Hello There!");
		String base[] =new String[100];
		String temp= new String();
		char ch;
		Scanner input = new Scanner(System.in);
		temp=input.nextLine();
		int i=-1,k,k1;
		boolean trigger=false;
		while(temp.isEmpty()==false)
		{   i=i+1;
			k=temp.indexOf(' ');
			if(k==0)
				{
					temp=temp.substring(1,temp.length());}
			k=temp.indexOf(' ');k=temp.indexOf(' ');
			ch= Character.toUpperCase(temp.charAt(0));
			if(k==-1)
				base[i]=ch+temp.substring(1,temp.length());
			else
				{   base[i]=ch+temp.substring(1,k);
					temp=temp.substring(k+1,temp.length());
					trigger=false;
					
				while(trigger==false)
					{	k=temp.indexOf(' ');
						if(k==-1)
						{
							ch= Character.toUpperCase(temp.charAt(0));
							base[i]=base[i]+" "+ch+temp.substring(1,temp.length());
							trigger=true;
						}
						else
						{	ch= Character.toUpperCase(temp.charAt(0));
							base[i]=base[i]+" "+ch+temp.substring(1,k);
							temp=temp.substring(k+1,temp.length());
						}
					}
				}
			temp=input.nextLine();
		}
		int j=0;
		for(j=0;j<=i;j++)
		System.out.println(base[j]);
	}
}