import java.awt.*;
class AWTDemo 
{
	MenuBar mb;
	Menu file, edit;
	MenuItem op1,op2,op3,op4;	
	Frame f;

	AWTDemo()
	{
		f= new Frame();
		mb= new MenuBar();
		
		file= new Menu("File");
		edit= new Menu("Format");
	
		op1= new MenuItem("New...");
		op2= new MenuItem("Open...");
		op3= new MenuItem("Cut...");
		op4= new MenuItem("Paste...");

		file.add(op1);file.add(op2);
		edit.add(op3);edit.add(op4);

		mb.add(file);mb.add(edit);
		f.setMenuBar(mb);
		
		f.setSize(200,200);
		f.setLayout(new FlowLayout());
		f.setVisible(true);

	}
	public static void main (String [] args)
	{	
			new AWTDemo();	
	}

}