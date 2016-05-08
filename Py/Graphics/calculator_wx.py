from __future__ import division
__author__ = 'Sainyam Kapoor <sainyamkapoor@yahoo.com>'
__version__ = '0.1'
import wx
from math import * # So we can evaluate 'sqrt(8), sin(),etc'
class Calculator(wx.Frame):
   '''Main calculator Frame'''
   degorrad=False
   last=False
   def __init__(self):
       title = 'Calculator v'+__version__ +" by "+__author__
       window=wx.Frame.__init__(self, None, -1, title)
       sizer = wx.BoxSizer(wx.VERTICAL) # Main vertical sizer
       self.display = wx.ComboBox(self, -1) # Current calculation
       sizer.Add(self.display, 0, wx.EXPAND) 
       gsizer = wx.GridSizer(6, 4)
       for row in (('7', '8', '9', '/'),
                   ('4', '5', '6', '*'),
                   ('1', '2', '3', '-'),
                   ('0', '.', 'sqrt', '+'),
                   ('sin','cos','tan','C'),
                   ('(',')','=')):
           for label in row:
               b = wx.Button(self, -1, label)
               gsizer.Add(b)
               self.Bind(wx.EVT_BUTTON, self.OnButton, b)
               if label == '=':
                  self.equal=b
               
                  
       sizer.Add(gsizer, 1, wx.EXPAND)
       b1=wx.ToggleButton(self,-1,"deg/rad")
       gsizer.Add(b1)
       self.Bind(wx.EVT_TOGGLEBUTTON, self.OnButton, b1)
       # Set sizer and center
       self.SetSizer(sizer)
       sizer.Fit(self)
       self.CenterOnScreen()
       self.reg1=b1

   def OnButton(self, evt):
       '''Handle button click event'''
       # Get title of clicked button
       label = evt.GetEventObject().GetLabel()

       if label == '=': # Calculate
           try:
               compute = self.display.GetValue()
               # Ignore empty calculation
               if not compute.strip():
                   return
               if compute[-1]=='.':
                    compute+='0'
               if self.last==True and compute[-1]!=')':
                    compute+=')' 
               if self.degorrad==True:
                    
                    compute=compute.replace('sin(',"sin((pi/180)*")  
                    compute=compute.replace('cos(',"cos((pi/180)*")
                    compute=compute.replace('tan(',"tan((pi/180)*")
                    
                    
               #print compute
               result = round(eval(compute),10)
               compute.replace('sin((pi/180)*','sin(')  
               # Add to history
               self.display.Insert(compute, 0)

               
               self.display.SetValue(str(result))
           except Exception as err:
               wx.LogError(str(err))
               return

       elif label == 'C': # Clear
           self.display.SetValue('')
           self.last=False
       elif label =='sin' or label=='cos' or label=='tan' or label=='sqrt':
           self.display.SetValue(self.display.GetValue() + label+'(')
           self.last=True
       elif label =='deg/rad':
           self.degorrad=not self.degorrad

           self.reg1.SetValue(self.degorrad)

       else: # Just add button text to current calculation
           self.display.SetValue(self.display.GetValue() + label)
           self.equal.SetFocus() # Set the [=] button in focus
           if label=='/' or label=='*' or label=='+' or label=='-' or  label=='C' : 
                self.last=False

if __name__ == '__main__':
   # Run the application
   app = wx.App()
   dlg = Calculator()
   dlg.Show()
   app.MainLoop()
   dlg.Destroy()
