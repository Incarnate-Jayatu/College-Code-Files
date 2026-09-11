import java.awt.*;

class GUIGrid
{
	Frame f;
	Button b[] = new Button[20];
	TextField t1;

	GUIGrid()
	{
		f = new Frame();
		//t1 = new TextField();
		b[0] = new Button("%");
		b[1] = new Button("C");
		b[2] = new Button("DEL");
		b[3] = new Button("/");
		b[4] = new Button("7");
		b[5] = new Button("8");
		b[6] = new Button("9");
		b[7] = new Button("X");
		b[8] = new Button("4");
		b[9] = new Button("5");
		b[10] = new Button("6");
		b[11] = new Button("-");
		b[12] = new Button("1");
		b[13] = new Button("2");
		b[14] = new Button("3");
		b[15] = new Button("+");
		b[16] = new Button(".00");
		b[17] = new Button("0");
		b[18] = new Button(".0");
		b[19] = new Button("=");
		
		f.setVisible(true);
		f.setLayout(new GridLayout(5,4));         //rows, cols
		f.add(b[0]); f.add(b[1]); f.add(b[2]); f.add(b[3]);
		f.add(b[4]); f.add(b[5]); f.add(b[6]); f.add(b[7]);
		f.add(b[8]); f.add(b[9]); f.add(b[10]); f.add(b[11]);
		f.add(b[12]); f.add(b[13]); f.add(b[14]); f.add(b[15]);
		f.add(b[16]); f.add(b[17]); f.add(b[18]); f.add(b[19]);
		f.setSize(700, 700);
	} 

	public static void main(String []args)
	{
		GUIGrid c = new GUIGrid();
	}
}