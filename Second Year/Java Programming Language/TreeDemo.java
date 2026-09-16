import java.awt.*;
import javax.swing.*;
import javax.swing.tree.*;
class TreeDemo
{
	DefaultMutableTreeNode t1,t2,t3,t4,t5, t11, t12, t13, t14, t15;
	JFrame f;
	JTree t;
	TreeDemo()
	{
		f= new JFrame("hello");
		t1= new DefaultMutableTreeNode("College",true);
		t2= new DefaultMutableTreeNode("Computer");
		t3= new DefaultMutableTreeNode("Mechanical");
		t4= new DefaultMutableTreeNode("IT");
		t5= new DefaultMutableTreeNode("E&TC");

		t11=new DefaultMutableTreeNode("AI/ML");
		t12=new DefaultMutableTreeNode("AI/DS");
		t13=new DefaultMutableTreeNode("VLSI");
		t14=new DefaultMutableTreeNode("Robotics");
		t15=new DefaultMutableTreeNode("Normal/Plain");

		t2.add(t15); t2.add(t11); t2.add(t12); t5.add(t13); t5.add(t14);
		t1.add(t2);t1.add(t3);t1.add(t4);t1.add(t5);
		t= new JTree(t1);
		f.add(t);

		f.setSize(300,300);
		f.setVisible(true);
		f.setLayout(new FlowLayout());

	}
	public static void main (String [ ]args)
	{
		TreeDemo td= new TreeDemo();
	}
}