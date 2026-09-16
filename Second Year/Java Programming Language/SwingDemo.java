import javax.swing.*;
import java.awt.*;
class SwingDemo
{
	JMenuBar mb;
	JFrame f;
	JMenu file, edit,view;
	JMenuItem op1,op2,op3,op4,op5;
	JTextField t1,t2;
	JButton b1,b2;
	ImageIcon i;
	SwingDemo()
	{
		f= new JFrame("My first swing prog");
		mb=new JMenuBar();
		file= new JMenu("File");
		edit= new JMenu("Edit");
		view= new JMenu("View");
		
		i = new ImageIcon("abc.png");
		t1= new JTextField(10);
		b1= new JButton("Hello",i);
		b2= new JButton();

		op1= new JMenuItem("New..");
		op2= new JMenuItem("Open..");
		op3= new JMenuItem("Undo..");
		op4= new JMenuItem("Paste..");
		op5= new JMenuItem("Zoom..");

		file.add(op1);file.add(op2);
		edit.add(op3);edit.add(op4);
		view.add(op5);
		edit.add(view);
		mb.add(file);
		mb.add(edit);
		f.add(t1);f.add(b1);f.add(b2);
		
		f.setJMenuBar(mb);
		f.setSize(300,400);
		f.setLayout(new FlowLayout());
		f.setVisible(true);
	}

	public static void main (String [] args)
	{
		SwingDemo sd = new SwingDemo();
	}
}