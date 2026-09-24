import java.awt.*;
class MenuBarDemo
{

	MenuBar mb;
	Frame f;
	Menu file, edit;
	MenuItem op1,op2,op3,op4;

	MenuBarDemo()
	{
		f= new Frame();
		mb= new MenuBar();

		file= new Menu("File");
		edit= new Menu("Edit");

		op1= new MenuItem("New..");
		op2= new MenuItem("Open..");
		op3= new MenuItem("Cut..");
		op4= new MenuItem("Paste..");

		file.add(op1);file.add(op2);
		edit.add(op3);edit.add(op4);
		

		mb.add(file);mb.add(edit);
		f.setMenuBar(mb);

		f.setVisible(true);
		f.setLayout(new FlowLayout());
		f.setSize(200,300);
	}

	public static void main (String []args)
	{
		MenuBarDemo md= new MenuBarDemo();
	}
}