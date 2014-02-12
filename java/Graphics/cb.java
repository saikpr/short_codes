import java.applet.*;
import java.awt.*;

public class cb extends Applet 
{
	public void init()
	{
		setSize(600,600);
	}
	public void paint(Graphics g)
	{
		int i,a=55,b=50,j;
		for(i=1;i<9;i++)
		{
			for(j=1;j<9;j++)
			{
				if((i+j)%2==0)
				{
					g.setColor(Color.red);
					g.fillRect(a,b,60,60);
					a+=60;
				}
				else
				{
					g.setColor(Color.blue);
					g.fillRect(a,b,60,60);
					a+=60;
				}
			}
			a=55;
			b+=60;
		}
	}
}