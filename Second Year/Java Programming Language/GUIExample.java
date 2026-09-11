//GUI EXAMPLE
import java.awt.*;

class GUIExample
{
	Frame f;
	Button b1, b2;
	TextField t1, t2, t3, t4;

	GUIExample()
	{
		f = new Frame();
		b1 = new Button();
		b2 = new Button("HELLO");
		t1 = new TextField();
		t2 = new TextField(10);
		t3 = new TextField("HELLO");
		t4 = new TextField("HELLO", 20);

		f.setVisible(true);
		f.setLayout(new FlowLayout());
		f.add(b1); f.add(b2);
		f.add(t1); f.add(t2); f.add(t3); f.add(t4); 
		f.setSize(500, 700);
	}

	public static void main(String []args)
	{
		GUIExample g = new GUIExample();
	}
}
