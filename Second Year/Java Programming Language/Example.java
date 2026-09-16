import java.awt.*;
class Example
{
	Frame f;
	TextField t1,t2,t3,t4;
	Label l1;	
	Checkbox c1, c2;
	TextArea ta1,ta2,ta3;

	Example()
	{
		f= new Frame();
		t1= new TextField();
		t2= new TextField(10);
		t3= new TextField("Jayatu");
		t4= new TextField("Random",20);
		l1= new Label("Hobbies");
		c1= new Checkbox("Cricket",true);
		c2= new Checkbox("Tennis");
		ta1= new TextArea();
		ta2= new TextArea(10,40);
		ta3= new TextArea("My address is DES college of Engg");

		
		f.add(t1);f.add(t2);f.add(t3);f.add(t4);
		f.add(l1);f.add(c1);f.add(c2);
		f.add(ta1);f.add(ta2);f.add(ta3);
		t1.setBackground(Color.RED);
		t1.setForeground(Color.WHITE);
		
		f.setVisible(true);
		f.setLayout(new FlowLayout());
		f.setSize(300,500);
	
	}
	public static void main (String args[])
	{
		Example e = new Example();
	}

}