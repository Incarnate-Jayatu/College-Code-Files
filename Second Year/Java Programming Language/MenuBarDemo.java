import java.awt.*;

class MenuBarDemo 
{
    Frame f; 
    MenuBar m; 
    Menu file, edit; 
    MenuItem op1, op2, op3, op4; 

    MenuBarDemo() 
    { 
        f = new Frame(); 
        m = new MenuBar(); 
        
        file = new Menu("File"); 
        edit = new Menu("Edit"); 
        
        op1 = new MenuItem("New"); 
        op2 = new MenuItem("Open"); 
        op3 = new MenuItem("Undo"); 
        op4 = new MenuItem("Paste"); 
        
        file.add(op1);
        file.add(op2); 
        edit.add(op3);
        edit.add(op4); 
        
        m.add(file);
        m.add(edit); 
        
        f.setMenuBar(m); 
        f.setSize(300, 500); 
        f.setLayout(new FlowLayout()); 
        f.setVisible(true); 
    } 

    public static void main(String[] args) { 
        MenuBarDemo mb = new MenuBarDemo(); 
    } 
}
