package testcourseselector;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;


public class GUISelection extends JFrame{
    
    private JList selectCourses;
    private JList displayCourses;
    private JList selectCourses2;
    private JList displayCourses2;
    private JButton moveCourses;
    public String[] courseList1;
    public String[] courseList2;
    private static final String[] courses = {"course1", "course2", "course3", "course4", "course5"};
    
    public GUISelection()
            {
                super("title");
                setLayout(new FlowLayout());
                
                selectCourses = new JList(courses);
                selectCourses.setVisibleRowCount(5);
                selectCourses.setSelectionMode(ListSelectionModel.MULTIPLE_INTERVAL_SELECTION);
                add(new JScrollPane(selectCourses));
                
                moveCourses = new JButton("Select");
                moveCourses.addActionListener((ActionEvent event) -> {
                    displayCourses.setListData(selectCourses.getSelectedValues());
                });
                add(moveCourses);
                displayCourses = new JList();
                displayCourses.setVisibleRowCount(5);
                displayCourses.setFixedCellWidth(100);
                displayCourses.setFixedCellHeight(15);
                displayCourses.setSelectionMode(ListSelectionModel.MULTIPLE_INTERVAL_SELECTION);
                add(new JScrollPane(displayCourses));
                
                
                for (int i = 0; i < displayCourses.getModel().getSize(); i++) {
                    courseList1[i] = String.valueOf(displayCourses.getModel().getElementAt(i));
                    }
                
                
                
                selectCourses2 = new JList(courses);
                selectCourses2.setVisibleRowCount(5);
                selectCourses2.setSelectionMode(ListSelectionModel.MULTIPLE_INTERVAL_SELECTION);
                add(new JScrollPane(selectCourses2));
                moveCourses = new JButton("Select");
                moveCourses.addActionListener((ActionEvent event) -> {
                    displayCourses2.setListData(selectCourses2.getSelectedValues());
                });

                add(moveCourses);
                displayCourses2 = new JList();
                displayCourses2.setVisibleRowCount(5);
                displayCourses2.setFixedCellWidth(100);
                displayCourses2.setFixedCellHeight(15);
                displayCourses2.setSelectionMode(ListSelectionModel.MULTIPLE_INTERVAL_SELECTION);
                add(new JScrollPane(displayCourses2));
                
                
                for (int i = 0; i < displayCourses2.getModel().getSize(); i++) {
                    courseList2[i] = String.valueOf(displayCourses2.getModel().getElementAt(i));
                    }
                
                
            }
}
