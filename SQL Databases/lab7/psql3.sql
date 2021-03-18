CREATE OR REPLACE TRIGGER LimitTest
FOR INSERT OR UPDATE 
ON Course_Prereq
COMPOUND TRIGGER 
/* Declaration Section*/
v_MAX_PREREQS CONSTANT INTEGER := 2;     
v_CurNum INTEGER := 1; 
v_cno INTEGER; 
--ROW level
BEFORE EACH ROW IS
BEGIN
    v_cno := :NEW.COURSENO;
END 
BEFORE EACH ROW; 
--Statement level
AFTER STATEMENT IS
BEGIN
    SELECT COUNT(*) INTO v_CurNum FROM Course_Prereq WHERE courseNo = v_cno Group by courseNo;
    IF v_CurNum  > v_MAX_PREREQS THEN RAISE_APPLICATION_ERROR(-20000,'Only 2 prereqs for course');
    END IF;
END AFTER STATEMENT;
 END ;
 /
 Show Errors;