import javax.swing.*;
import java.awt.*;

class SwingDem
{
	JTextField t1,t2,t3,t4;
	JTextArea ta1,ta2,ta3,ta4;
	JFrame f;
	SwingDem()
	{
		f= new JFrame();
			
		t1= new JTextField();
		t2= new JTextField(10);
		t3= new JTextField("Hello");
		t4= new JTextField("Hello",20);

		ta1= new JTextArea("EMPTYYYYYYYYY",5,5);
		ta2= new JTextArea(10,30);
		ta3= new JTextArea("RUNNN");
		ta4= new JTextArea("GOOOOOOOOO",10,30);
		
		f.add(t1);f.add(t2);f.add(t3);f.add(t4);
		f.add(ta1);f.add(ta2);f.add(ta3);f.add(ta4);
		f.setLayout(new FlowLayout());
		f.pack();
		f.setVisible(true);
	}

	public static void main(String []args)
	{
		SwingDem sd = new SwingDem();
	}

}