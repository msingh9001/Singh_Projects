CREATE OR REPLACE TRIGGER LimitTest
    BEFORE INSERT OR UPDATE ON Course_Prereq    
    FOR EACH ROW  -- A row level trigger
DECLARE     
    v_MAX_PREREQS CONSTANT INTEGER := 2;    
    v_CurNum INTEGER;
BEGIN
    BEGIN
        SELECT COUNT(*) INTO v_CurNum FROM Course_Prereq WHERE courseNo = :new.CourseNo Group by courseNo;
        EXCEPTION -- Before you enter the first row, no data is found
        WHEN no_data_found THEN DBMS_OUTPUT.put_line('not found');
            v_CurNum := 0;
    END;
    if v_curNum > 0 THEN
        IF v_CurNum + 1 > v_MAX_PREREQS THEN
            RAISE_APPLICATION_ERROR(-20000,'Only   2   prereqs   for course');
        END IF;
    END IF;
END;
/
SHOW ERRORS;