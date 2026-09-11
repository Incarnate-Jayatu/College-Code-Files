import java.awt.*;

class LogIn
{
	Frame f;
	Label l1, l2;
	TextField t1, t2;
	Button b1;
	
	LogIn()
	{
		f = new Frame();
		l1 = new Label("Username");
		l2 = new Label("Password");
		t1 = new TextField(30);
		t2 = new TextField(30);		
		b1 = new Button("Submit");

		f.setVisible(true);
		f.setLayout(new BorderLayout());     //0 - left align , 1- center align , 2 - right align
		f.add(t1, BorderLayout.SOUTH);
		f.add(t1, BorderLayout.WEST);
		f.add(l1); f.add(t1);
		f.add(l2); f.add(t2);
		f.add(b1);
		f.setSize(300, 500);		 // define dimension (w, h)
		t2.setEchoChar('*');             //hide i/p in password
	}
	
	public static void main(String []args)
	{
		LogIn li = new LogIn();
	}
}