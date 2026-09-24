import java.awt.*;

import java.awt.event.*;

class MouseDemo implements MouseListener 
{

    Frame f;

    Label l;

    MouseDemo() {

        f = new Frame("Mouse Listener");

        l = new Label("Move or click the mouse");

        f.add(l);

        l.addMouseListener(this);   // Listener added to Label

        f.setSize(400, 200);

        f.setVisible(true);

    }

    public void mouseClicked(MouseEvent e) 
    {

        l.setText("Mouse Clicked");
    }

    public void mouseEntered(MouseEvent e) 
    {

        l.setText("Mouse Entered");
    }

    public void mouseExited(MouseEvent e) 
    {

        l.setText("Mouse Exited");
    }

    public void mousePressed(MouseEvent e)
    {

        l.setText("Mouse Pressed");
    }

    public void mouseReleased(MouseEvent e) {

        l.setText("Mouse Released");

    }

    public static void main(String[] args) 
    {

       MouseDemo md =new MouseDemo();
    }

}