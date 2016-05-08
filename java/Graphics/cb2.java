import java.applet.*;
import javax.swing.*;
import java.awt.*;

public class cb2 extends Applet 
{
	
	int p,sizex,sizey;
	public void init()
	{
		String i,j,sx,sy; 
		i=JOptionPane.showInputDialog("Enter N:");
		sx=JOptionPane.showInputDialog("Enter Sizex:");
		sy=JOptionPane.showInputDialog("Enter Sizey:");
		sizex=Integer.parseInt(sx);sizey=Integer.parseInt(sy);
		p=Integer.parseInt(i);
	}
	public void paint(Graphics g)
	{
		int i,a=50,b=50,j;
		for(i=0;i<p;i++)
		{
			for(j=0;j<p;j++)
			{
				if((i+j)%2==0)
				{
					g.setColor(Color.red);
					g.fillRect(a,b,sizex,sizey);
					a+=sizex;
				}
				else
				{
					g.setColor(Color.black);
					g.fillRect(a,b,sizex,sizey);
					a+=sizex;
				}
			}
			a=50;
			b+=sizey;
		}
	}
}