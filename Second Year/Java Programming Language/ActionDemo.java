import java.awt.*;

import java.awt.event.*;

class ActionDemo implements ActionListener 
{

    Frame f;

    Button b;

    Label l;

    ActionDemo() 
    {

        f = new Frame("Action Listener");

        b = new Button("Click Me");

        l = new Label("Hello");

        f.setLayout(new FlowLayout());

        f.add(l);

        f.add(b);

        b.addActionListener(this);

        f.setSize(300, 200);

        f.setVisible(true);

    }

    public void actionPerformed(ActionEvent e) 
    {

        l.setText("Button Clicked!");

    }

    public static void main(String[] args) 
     {

        ActionDemo cd=new ActionDemo();

    }

}