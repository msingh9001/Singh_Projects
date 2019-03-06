package courseselector;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.event.*;

public class GUISelection extends JFrame{
    
    private JList selectCourses;
    private JList displayCourses;
    private JButton moveCourses;
    private static String[] courses = {"course1", "course2", "course3", "course4", "course5"};
    
    public GUISelection()
            {
                super("title");
                setLayout(new FlowLayout());
                
                selectCourses = new JList(courses);
                selectCourses.setVisibleRowCount(5);
                selectCourses.setSelectionMode(ListSelectionModel.MULTIPLE_INTERVAL_SELECTION);
                add(new JScrollPane(selectCourses));
                
                moveCourses = new JButton("Select");
                moveCourses.addActionListener(
                        new ActionListener(){
                            public void actionPerformed(ActionEvent event){
                                displayCourses.setListData(selectCourses.getSelectedValues());
                            }
                        }
                );
                
                add(moveCourses);
                displayCourses = new JList();
                displayCourses.setVisibleRowCount(5);
                displayCourses.setFixedCellWidth(100);
                displayCourses.setFixedCellHeight(15);
                displayCourses.setSelectionMode(ListSelectionModel.MULTIPLE_INTERVAL_SELECTION);
                add(new JScrollPane(displayCourses));
            }
}
