package tictactoe;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.*;

import javax.swing.*;
public class TicTacToe 
{   
    static int a[][] =new int[3][3];
    static int  triger=0,lp;
    private static final int triggercheck()
    {  triger=triger+1;
       if(triger==9)
           
       { JOptionPane.showMessageDialog(null,"Sorry Its A Draw!", ":( :( :("
              , JOptionPane.INFORMATION_MESSAGE);
      a[0][0]=-10;a[1][1]=-10;a[2][2]=-10;
      System.exit(0);
       }
       return triger;
    }
    
    static String str1=new String();
    static String str2=new String();
    private static void createGUI() 
    {
                JFrame frame = new JFrame();
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setTitle("TicTacToe-By Sainyam Kapoor");
                frame.setSize(450,450);
                str1=JOptionPane.showInputDialog("Enter Player1's Name");
                str2=JOptionPane.showInputDialog("Enter Player2's Name");
                final ImageIcon cross = new ImageIcon("images/cross.jpg");
                final ImageIcon zero = new ImageIcon("images/zero.jpg");
                final ImageIcon clear = new ImageIcon("images/clear.jpg");
                
                frame.setLayout(new GridLayout(3, 3));
                final JButton b1 = new JButton(clear);
                frame.add(b1);
                final JButton b2 = new JButton(clear);
                frame.add(b2);
                final JButton b3 = new JButton(clear);
                frame.add(b3);
                final JButton b4 = new JButton(clear);
                frame.add(b4);
                final JButton b5 = new JButton(clear);
                frame.add(b5);
                final JButton b6 = new JButton(clear);
                frame.add(b6);
                final JButton b7 = new JButton(clear);
                frame.add(b7);
                final JButton b8 = new JButton(clear);
                frame.add(b8);
                final JButton b9 = new JButton(clear);
                frame.add(b9);
                
                        
                b1.addActionListener(new ActionListener() {
                       @Override
                     public void actionPerformed(ActionEvent e)
                          { int k=triggercheck();
                              if(k%2==0)                   
                            {b1.setIcon(zero);
                            
                            a[0][0]=4;
                            }
                            else
                            { 
                               b1.setIcon(cross);
                               
                               a[0][0]=1;
                                
                            }
                          
                          ifplayerwins();
                          }
                    });
                b2.addActionListener(new ActionListener() {
                       @Override
                     public void actionPerformed(ActionEvent e)
                          { int k=triggercheck();
                              if(k%2==0)                  
                            {b2.setIcon(zero);
                            a[0][1]=4;
                            }
                            else
                            { 
                               b2.setIcon(cross);
                               a[0][1]=1;
                                
                            }
                          
                          ifplayerwins();
                          
                          
                         }
                    });
                b3.addActionListener(new ActionListener() {
                       @Override
                     public void actionPerformed(ActionEvent e)
                          { int k=triggercheck();
                              if(k%2==0)                   
                            {b3.setIcon(zero);
                            
                            a[0][2]=4;
                            }
                            else
                            { 
                               b3.setIcon(cross);
                               
                               a[0][2]=1;
                                
                            }
                          ifplayerwins();
                          
                         }
                    });
                b4.addActionListener(new ActionListener() {
                       @Override
                     public void actionPerformed(ActionEvent e)
                          { if(triggercheck()%2==0)                   
                            {b4.setIcon(zero);
                            
                            a[1][0]=4;
                            }
                            else
                            { 
                               b4.setIcon(cross);
                               
                               a[1][0]=1;
                                
                            }
                          ifplayerwins();
                          
                         }
                    });
                b5.addActionListener(new ActionListener() {
                       @Override
                     public void actionPerformed(ActionEvent e)
                          { if(triggercheck()%2==0)                   
                            {b5.setIcon(zero);
                            
                            a[1][1]=4;
                            }
                            else
                            { 
                               b5.setIcon(cross);
                               
                               a[1][1]=1;
                                
                            }
                          ifplayerwins();
                          
                         }
                    });
                b6.addActionListener(new ActionListener() {
                       @Override
                     public void actionPerformed(ActionEvent e)
                          { if(triggercheck()%2==0)                   
                            {b6.setIcon(zero);
                            
                            a[1][2]=4;
                            }
                            else
                            { 
                               b6.setIcon(cross);
                              
                               a[1][2]=1;
                                
                            }
                          ifplayerwins();
                          
                         }
                    });
                b7.addActionListener(new ActionListener() {
                       @Override
                     public void actionPerformed(ActionEvent e)
                          { if(triggercheck()%2==0)                   
                            {b7.setIcon(zero);
                            
                            a[2][0]=4;
                            }
                            else
                            { 
                               b7.setIcon(cross);
                               
                               a[2][0]=1;
                                
                            }
                          ifplayerwins();
                          
                         }
                    });
                b8.addActionListener(new ActionListener() {
                       @Override
                     public void actionPerformed(ActionEvent e)
                          { if(triggercheck()%2==0)                   
                            {b8.setIcon(zero);
                            
                            a[2][1]=4;
                            }
                            else
                            { 
                               b8.setIcon(cross);
                              
                               a[2][1]=1;
                                
                            }
                          ifplayerwins();
                          
                         }
                    });
                b9.addActionListener(new ActionListener() {
                       @Override
                     public void actionPerformed(ActionEvent e)
                          { if(triggercheck()%2==0)                   
                            {b9.setIcon(zero);
                           
                            a[2][2]=4;
                            }
                            else
                            { 
                               b9.setIcon(cross);
                               
                               a[2][2]=1;
                                
                            }
                          ifplayerwins();
                          
                         }
                    });
                
                
                
		frame.setVisible(true);
    
    }
    
    private static int checkusr()
    {int i=0,j=0;
    
    
    for(i=0;i<=2;i++)
    {j=a[0][i]+a[1][i]+a[2][i];
     if(j==3)
         return 1;
     else if (j==12)
         return 2;}   
    for(i=0;i<=2;i++)
    {j=a[i][0]+a[i][1]+a[i][2];
     if(j==3)
         return 1;
     else if (j==12)
         return 2;
    }
    j=a[0][0]+a[1][1]+a[2][2];
    if(j==3)
         return 1;
     else if (j==12)
         return 2;
    j=a[2][0]+a[1][1]+a[0][2];
    if(j==3)
         return 1;
     else if (j==12)
         return 2;
     
    
    return 0;
    
    }
   private static void ifplayerwins()
   {    
       
        int k=checkusr();
     
        String strk=new String();
        if(k==1)
         strk=str1;
        else 
        if(k==2)
           strk=str2;
        else
        return;
        String str="Player " + strk +" wins";
       final ImageIcon youwon = new ImageIcon("images/youwon.gif");
        JOptionPane.showMessageDialog(null, str, "Yippe!"
              , JOptionPane.INFORMATION_MESSAGE, youwon);
        System.exit(0);
     return;
   }
   public static void main(String[] args)
   {   int i,j;
       for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            a[i][j]=0;
       createGUI() ;
   }
    
}
