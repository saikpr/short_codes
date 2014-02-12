import java.applet.*;
import java.awt.*;
import javax.swing.*;
public class cb1 extends Applet 
{
	int p;
	public void init()
	{
		String i; 
		i=JOptionPane.showInputDialog("Please input a value");
		p=Integer.parseInt(i);
	}
	public void paint(Graphics g)
	{
		int i,a=55,b=50,j;
		for(i=0;i<p;i++)
		{
			for(j=0;j<p;j++)
			{
				if((i+j)%2==0)
				{
					g.setColor(Color.white);
					g.fillRect(a,b,60,60);
					a+=60;
				}
				else
				{
					g.setColor(Color.black);
					g.fillRect(a,b,60,60);
					a+=60;
				}
			}
			a=55;
			b+=60;
		}
	}
}