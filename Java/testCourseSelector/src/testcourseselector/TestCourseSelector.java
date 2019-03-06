package testcourseselector;

import javax.swing.JFrame;

public class TestCourseSelector {

    public static void main(String[] args) {
        
        GUISelection courseSelector = new GUISelection();
        courseSelector.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        courseSelector.setSize(600,500);
        courseSelector.setVisible(true);
        
        
    }
    
}
