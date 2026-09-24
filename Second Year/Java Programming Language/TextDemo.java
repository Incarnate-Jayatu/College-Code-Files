import java.awt.*;

import java.awt.event.*;

class TextDemo implements ActionListener 
{

    Frame f;

    TextField t;

    Button b;

    TextDemo() 
    {

        f = new Frame("Text Demo");

        t = new TextField(30);

        b = new Button("Load");

        f.setLayout(new FlowLayout());

        f.add(t);

        f.add(b);

        b.addActionListener(this);

        f.setSize(400, 200);

        f.setVisible(true);

    }

    public void actionPerformed(ActionEvent e) 
    {

        t.setText("Welcome to Java Programming");
    }

    public static void main(String[] args) {

        TextDemo td= new TextDemo();

    }

}