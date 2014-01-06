/*Simple hello world program
Version 1.00 06-01-2014
By Sainyam Kapoor
*/

public class HelloWorld
{
	public static void main(String[] args)
	{
		String[] hello=new String[3];
		hello[0]="Hello ,there";
		hello[1]="I am Sainyam Kapoor";
		hello[2]="This will be my first Java program";
		for( String temp : hello)
			System.out.println(temp);
	}
}