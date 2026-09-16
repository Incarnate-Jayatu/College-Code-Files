import javax.swing.*;
import java.awt.*;

class SwingD
{
	JFrame f;
	JMenuBar mb;
	JMenu file, edit, view;
	JMenuItem i1, i2, i3, i4, i5;
	JButton b1;
	JTextField t1;
	ImageIcon i;
	
	SwingD()
	{
		f = new JFrame();
		mb = new JMenuBar();
		i= new ImageIcon("");
		file = new JMenu("File");
		edit = new JMenu("Edit");
		view = new JMenu("View");

		i = new ImageIcon("Danger.png");
	
		i1 = new JMenuItem("New ");
		i2 = new JMenuItem("Open ");
		i3 = new JMenuItem("Find");
		i4 = new JMenuItem("Replace");
		i5 = new JMenuItem("Zoom In/Out ");

		b1 = new JButton("Click Here!!", i);
		t1 = new JTextField(10);

		file.add(i1); file.add(i2);
		edit.add(i3); edit.add(i4);
		view.add(i5);
		edit.add(view);
		mb.add(file); mb.add(edit);
			
		f.add(t1); f.add(b1);

		f.setJMenuBar(mb);
		f.setLayout(new FlowLayout());
		f.pack();       //automatically set size as per rerquirement
		f.setVisible(true);
	}

	public static void main(String []args)
	{
		SwingD sd = new SwingD();
	}

}