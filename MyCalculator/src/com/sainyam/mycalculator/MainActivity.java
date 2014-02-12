package com.sainyam.mycalculator;


import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

public class MainActivity extends Activity {
	private String numberDisplayed = "";
    private Double resultNumber = 0.0;
    private EditText textView, resultView;
    private boolean plus, minus, divide, mult = false;
    protected String storedNumber;
   

    private void updateTextField() {
            textView.setText(this.numberDisplayed);
            resultView.setText(this.resultNumber.toString());

    }
	@Override
	public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        textView = (EditText) findViewById(R.id.entry);
        resultView = (EditText) findViewById(R.id.result);
        

        final Button button0 = (Button) findViewById(R.id.button0);
       
        button0.setOnClickListener(new View.OnClickListener() {
                public void onClick(View v) {
                        numberDisplayed += "0";
                        updateTextField();
                }
        });

        final Button button1 = (Button) findViewById(R.id.button1);
       
        button1.setOnClickListener(new View.OnClickListener() {
                public void onClick(View v) {
                        numberDisplayed += "1";
                        updateTextField();
                }
        });

        final Button buttonBs = (Button) findViewById(R.id.buttonBackspace);
        buttonBs.setOnClickListener(new View.OnClickListener() {
                public void onClick(View v) {
                	Double d;
           		 try {
           			   d= Double.parseDouble(numberDisplayed);
           		 } catch (NumberFormatException e) {
           			 numberDisplayed = "";
           		        updateTextField();
           		        return ;
           		 }
                        if (numberDisplayed.length() >= 1) {
                                numberDisplayed = numberDisplayed.substring(0,
                                                numberDisplayed.length() - 1);
                        }
                        updateTextField();
                }
        });

        final Button button2 = (Button) findViewById(R.id.button2);
        button2.setOnClickListener(new View.OnClickListener() {
                public void onClick(View v) {
                        numberDisplayed += "2";
                        updateTextField();
                }
        });

        final Button button3 = (Button) findViewById(R.id.button3);
        button3.setOnClickListener(new View.OnClickListener() {
                public void onClick(View v) {
                        numberDisplayed += "3";
                        updateTextField();
                }
        });

        final Button button4 = (Button) findViewById(R.id.button4);
        button4.setOnClickListener(new View.OnClickListener() {
                public void onClick(View v) {
                        numberDisplayed += "4";
                        updateTextField();
                }
        });

        final Button button5 = (Button) findViewById(R.id.button5);
        button5.setOnClickListener(new View.OnClickListener() {
                public void onClick(View v) {
                        numberDisplayed += "5";
                        updateTextField();
                }
        });

        final Button button6 = (Button) findViewById(R.id.button6);
        button6.setOnClickListener(new View.OnClickListener() {
                public void onClick(View v) {
                        numberDisplayed += "6";
                        updateTextField();
                }
        });

        final Button button7 = (Button) findViewById(R.id.button7);
        button7.setOnClickListener(new View.OnClickListener() {
                public void onClick(View v) {
                        numberDisplayed += "7";
                        updateTextField();
                }
        });

        final Button button8 = (Button) findViewById(R.id.button8);
        button8.setOnClickListener(new View.OnClickListener() {
                public void onClick(View v) {
                        numberDisplayed += "8";
                        updateTextField();
                }
        });

        final Button button9 = (Button) findViewById(R.id.button9);
        button9.setOnClickListener(new View.OnClickListener() {
                public void onClick(View v) {
                        numberDisplayed += "9";
                        updateTextField();
                }
        });

        final Button buttonClear = (Button) findViewById(R.id.buttonClear);
        buttonClear.setOnClickListener(new View.OnClickListener() {
                public void onClick(View v) {
                        numberDisplayed = "";
                        storedNumber = "";
                        plus = false;
                        divide = false;
                        minus = false;
                        mult = false;
                        resultNumber = 0d;
                        updateTextField();
                }
        });

        final Button buttonPlus = (Button) findViewById(R.id.buttonadd);
        buttonPlus.setOnClickListener(new View.OnClickListener() {
                public void onClick(View v) {
                        processNumbers();
                        plus = true;
                        divide = false;
                        minus = false;
                        mult = false;

                }

        });
        final Button buttondot = (Button) findViewById(R.id.buttondot);
        buttondot.setOnClickListener(new View.OnClickListener() {
                public void onClick(View v) {
                        if (numberDisplayed.equals("")) {
                                numberDisplayed = "0.";
                        } else if (!numberDisplayed.contains(".")) {
                                numberDisplayed += ".";
                        }
                        updateTextField();
                }
        });

        final Button buttonsubtract = (Button) findViewById(R.id.buttonsubtract);
        buttonsubtract.setOnClickListener(new View.OnClickListener() {
                public void onClick(View v) {

                        processNumbers();
                        plus = false;
                        divide = false;
                        minus = true;
                        mult = false;
                }
        });

        final Button buttonequals = (Button) findViewById(R.id.buttonequals);
        buttonequals.setOnClickListener(new View.OnClickListener() {
                public void onClick(View v) {

                        processNumbers();
                }
        });

        final Button buttonMult = (Button) findViewById(R.id.buttonmultiply);
        buttonMult.setOnClickListener(new View.OnClickListener() {
                public void onClick(View v) {

                        processNumbers();
                        plus = false;
                        divide = false;
                        minus = false;
                        mult = true;
                }
        });
       
        final Button buttondivide = (Button) findViewById(R.id.buttonDivide);
        buttondivide.setOnClickListener(new View.OnClickListener() {
                public void onClick(View v) {

                        processNumbers();
                        plus = false;
                        divide = true;
                        minus = false;
                        mult = false;
                       
                       
                }
        });
       
        
       

}
	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}
	
	private void processNumbers() {
		 Double d;
		 testNumberDisplayed();
		 
		 try {
			   d= Double.parseDouble(numberDisplayed);
		 } catch (NumberFormatException e) {
			 numberDisplayed = "Not a Number\nPress Backspace\nTo carry on your prev calculation";
		        updateTextField();
		        return ;
		 }
        testNumberDisplayed();
        if (plus) {
                resultNumber =  sum(d,
                                resultNumber);
        } else

        if (minus) {
                resultNumber =  difference(resultNumber,
                                d);
        } else if (mult) {
                resultNumber =  product(resultNumber,
                                d);
        } else if (divide) {
                String resultDev =  divide(resultNumber, d);
                if(resultDev.equals("Error!")){
                        divideAlert();
                        return;
                }else{
                        resultNumber = new Double(resultDev);
                }
        } else {
                resultNumber = new Double(numberDisplayed);
        }

        numberDisplayed = "";
        updateTextField();
}
	 private void testNumberDisplayed() {
         if (numberDisplayed.equals("")) {
                 if (!mult && !divide) {
                         numberDisplayed = "0";
                 } else {
                         numberDisplayed = "1";
                 }
                 updateTextField();

         }

 }
	 protected void divideAlert() {
         numberDisplayed="Error! Divide by zero. Learn Some Maths!! \nPress Clear To perform another calculation\nPress Backspace if you pressed 0 in error";
         updateTextField();
 }
	 public double sum(double a, double b) {
	        return a + b;
	    }
	 
	    public String divide(double a, double b) {
	        if (b == 0) {
	            return "Error!";
	        } else {
	            Double c = a / b;
	            return c.toString();
	        }
	    }
	 
	    public double difference(double a, double b) {
	        return a - b;
	    }
	 
	    public double product(double a, double b) {
	        return a * b;
	    }
}



