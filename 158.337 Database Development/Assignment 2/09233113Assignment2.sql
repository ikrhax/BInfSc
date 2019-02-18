/*
***********************************
*                                 *
*     159.337 - Assignment 2 	    *	
*	         Simon Parr		          *
*           09233113              *
*                                 *
***********************************
*/

/*
***********************************
*             PART A              *
***********************************
*/


/*
A:
Write a query that will list the students who have completed 26 years. 
Display their ages in completed years and in the order of decreasing age.
*/
SELECT student.s_id, student.s_last, student.s_first, 
ROUND((sysdate-student.s_dob)/365) AS "Age",
student.s_pin, student.s_id, student.time_enrolled
FROM student
WHERE (sysdate-student.s_dob)/365>=26
ORDER BY student.s_dob asc;


/*
B:
Write a query that will list the total building capacity for every building. 
This list (in the increasing order of the total capacity) should only contain 
the buildings with a total building capacity of 100 or over.
*/
SELECT location.bldg_code, SUM(location.capacity) 
AS "Building Capacity"
FROM location
GROUP BY location.bldg_code 
HAVING SUM(location.capacity)>=100
ORDER BY location.bldg_code ASC;


/*
C:
Write a query that will list all the students and their respective 
(faculty)supervisors. Arrange your list in the order of faculty supervisors 
names.
*/

SELECT student.s_first ||','|| student.s_last AS "Student Name", 
faculty.f_first ||','|| faculty.f_last AS "Faculty Supervisors"
FROM student, faculty
WHERE student.f_id = faculty.f_id
ORDER BY faculty.f_last , faculty.f_first ASC;


/*
D:
Write a query that will list the faculty members who are located in the 
(LIB)rary building.
*/

SELECT faculty.f_first ||','|| faculty.f_last AS "Faculty Members", 
location.bldg_code as "Location"
FROM faculty, location
WHERE faculty.LOC_ID=location.LOC_ID AND location.bldg_code like '%LIB%'
ORDER BY faculty.f_last ASC;


/*
E. Write a query that will list the students (along with their grade and course 
details) who got at least B or better grade (i.e. B or A) in any of their 
courses.
*/

SELECT student.s_first ||', '|| student.s_last AS "Student Name", 
course.course_no AS "Course Number" ,
course.course_name AS "Course Details", 
course.credits,enrollment.grade
FROM student, enrollment, course_section, course
WHERE student.s_id=enrollment.s_id 
AND enrollment.c_sec_id=course_section.c_sec_id 
AND course_section.course_no=course.course_no 
AND enrollment.grade LIKE '%B%'or enrollment.grade like '%A%'
GROUP BY student.s_first ||', '|| student.s_last, enrollment.grade, 
course.course_no ,course.course_name, course.credits;


/*
F:
Write a query that will list students who enrolled in the courses offered in
the terms Spring 2013 or Spring 2014. Do not display the duplicate student 
names.
*/

SELECT student.s_first ||', '|| student.s_last AS "Student Name"
FROM student, enrollment, course_section, term
WHERE student.s_id = enrollment.s_id 
AND enrollment.c_sec_id = course_section.c_sec_id 
AND course_section.term_id = term.term_id 
AND term.term_desc LIKE '%Spring 2013%' 
OR term.term_desc LIKE '%Spring 2014%'
GROUP BY student.s_first ||', '|| student.s_last;

SELECT DISTINCT student.s_first ||', '|| student.s_last 
AS "Student Name"
FROM student, enrollment, course_section, term 
WHERE student.s_id=enrollment.s_id 
AND enrollment.c_sec_id = course_section.c_sec_id 
AND course_section.term_id = term.term_id 
AND term.term_desc LIKE '%Spring 2013%' 
OR term.term_desc LIKE '%Spring 2014%';


/*
G:
Write a query listing the details of the faculty member(s) who supervises the
highest number of students. Also display the highest number of supervised
students.
*/

SELECT faculty.f_first ||', '|| faculty.f_last AS "Faculty Members", 
COUNT(*)AS "Number of Students"
FROM faculty, student
WHERE faculty.f_id=student.f_id
GROUP BY faculty.f_first ||', '|| faculty.f_last
ORDER BY COUNT(*) DESC;


/*
H. Write a query that will list students enrolled with a total of 12 or more 
credit points (in the decreasing order). 
Do not assume or hard code the value of the course credits.
*/

SELECT student.s_first ||', '|| student.s_last AS "Student Name", 
SUM(course.credits) AS "Credit Points"
FROM student, enrollment, course_section, course 
WHERE student.s_id=enrollment.s_id 
AND enrollment.c_sec_id=course_section.c_sec_id 
AND course_section.course_no=course.course_no 
AND enrollment.grade IS NOT NULL 
GROUP BY student.s_first ||', '|| student.s_last
HAVING SUM(course.credits)>=12
ORDER BY SUM(course.credits) DESC;


/*
I. Write a query that will list student(s) enrolled with the maximum total 
credit points.
*/
SELECT student.s_first ||', '|| student.s_last AS "Student Name"
FROM student, enrollment, course_section, term
WHERE student.s_id=enrollment.s_id 
AND enrollment.c_sec_id=course_section.c_sec_id 
AND course_section.term_id=term.term_id 
AND term.term_desc LIKE '%Spring 2013%' 
OR term.term_desc LIKE '%Spring 2014%'
GROUP BY student.s_first ||', '|| student.s_last;

SELECT DISTINCT student.s_first ||', '|| student.s_last AS "Student Names"
FROM student, enrollment, course_section, term
WHERE student.s_id=enrollment.s_id 
AND enrollment.c_sec_id=course_section.c_sec_id 
AND course_section.term_id=term.term_id 
AND term.term_desc LIKE '%Spring 2013%' 
OR term.term_desc LIKE '%Spring 2014%';



/*
J. Write a query that lists all the courses (with their course names) and the 
course sections that are offered either on a (M)onday or at least four times a 
week. Also display the number of the days that the courses are offered 
(e.g. 5 days).
Note: In table Course_Section, the attribute c_sec_day lists weekdays, where the
first letter represents a weekday (e.g. M-Monday,....F-Friday; for Thursday R is
used). The course section weekdays are listed in the order M(onday) to (F)riday
i.e. Monday being the first. 
*/

SELECT DISTINCT course.course_no,course.course_name as " Course Names",
course_section.c_sec_day as "Days Taught", 
LENGTH(course_section.c_sec_day) as "Number of Days Offered"
FROM course_section, course
WHERE course.course_no= course_section.course_no and course_section.c_sec_day 
LIKE '%M%' OR LENGTH(course_section.c_sec_day)>=4
GROUP BY course.course_no,course.course_name, course_section.c_sec_day;


/*
***********************************
*             PART B              *
***********************************
*/

/*
K:
Write two triggers one statement level and another row level. Display the
successful creation and running of the triggers. Please ensure that you also 
display the relevant tables before and after (results of the trigger) the 
triggers are fired.
Remember to provide the equivalent English statements about your triggers'
purpose.
*/



/*
This trigger is fired when a new student is created. It checks, before
anything is inserted, whether or not the student is of the correct age to 
enroll in university. It does this by obtaining the system date, working out
the student's age, and acting on the result
*/

/*
Statement Level
*/
CREATE OR REPLACE TRIGGER statement_level
AFTER 
INSERT OR UPDATE OR DELETE ON student
DECLARE
BEGIN
IF INSERTING
THEN 
DBMS_OUTPUT.PUT_LINE('Student is being inserted');
ELSE IF UPDATING 
THEN
DBMS_OUTPUT.PUT_LINE('Student is being updated');
ELSE IF DELETING
THEN 
DBMS_OUTPUT.PUT_LINE('Student is being deleted');
END IF;
END;


/*
Row Level
*/
CREATE OR REPLACE TRIGGER row_level
BEFORE 
INSERT OR UPDATE OF s_dob
ON student
FOR EACH ROW
DECLARE 
dob_error EXCEPTION;
BEGIN
IF FLOOR(months_between( sysdate, :new.s_dob ) / 12) < 16 
THEN
DBMS_OUTPUT.PUT_LINE('Students must be older than 16 to enroll');
RAISE dob_error;
END IF;

EXCEPTION
WHEN dob_error 
THEN raise_application_error(-20001,'There is no DOB, cannot insert');
END;





/*
L:
Write a trigger that does not allow more than two 'Full' ranked professors 
as part of the faculty (For example, trigger should fire if a new (third) Full 
professor is added or rank is updated to Full for one of the existing Associate 
professors.). Provide comprehensive test data and results to confirm that the
trigger works.
*/

CREATE TRIGGER PROF_RANK_CHECK
BEFORE INSERT OR INSERT OR UPDATE OF f_id, f_rank ON faculty
FOR EACH ROW
  
DECLARE
  f_rank_count INT;
  f_rank_check CHAR;
  OVERLOAD EXCEPTION;

BEGIN
  SELECT f_rank INTO f_rank_check FROM faculty WHERE f_rank= :NEW.f_rank;
  IF LOWER(f_rank_check) = 'Full'
  THEN 
  SELECT COUNT(faculty.f_rank) INTO f_rank_count FROM faculty
  WHERE faculty.f_rank= :NEW.f_rank;
  IF(f_rank_count > 2)
  THEN 
  DBMS_OUTPUT.PUT_LINE('There are too many with code Full');
  RAISE OVERLOAD;
  END IF;
    

EXCEPTION
  WHEN OVERLOAD
  THEN RAISE_APPLICATION_ERROR(-20001, 'There are too many with code Full');
  END;

/*
M: 
Write a procedure to insert a new faculty record. The procedure should also
automatically calculate the faculty salary value. This calculated salary is 20% 
less than the average salary of the existing faculty members. Provide rest of 
the attribute values as input parameters. Execute your procedure to insert at 
least one faculty record.
*/

CREATE [OR REPLACE] PROCEDURE PRC_INSERT_FACULTY_RECORD
(f_id IN NUMBER, f_last IN VARCHAR2,
f_first IN VARCHAR2,f_mi IN CHAR,f_loc_id IN NUMBER,f_phn IN NUMBER,
f_rnk IN VARCHAR2, f_sup IN NUMBER, f_pn IN NUMBER, f_img IN BLOB) AS
BEGIN
DECLARE
f_new_sal NUMBER(9,2);
BEGIN 
SELECT AVG(f_salary) *0.8 INTO f_new_sal
FROM FACULTY;
INSERT INTO 
FACULTY (F_ID ,F_LAST,F_FIRST,F_MI,LOC_ID ,F_PHONE,F_RANK,F_SALARY,
F_SUPER,F_PIN,F_IMAGE)
VALUES( f_id,f_last,f_first,f_mi,f_loc_id,f_phn,f_rnk,f_new_sal,f_sup,
f_pn,f_img);
END;
END;


/*
N: 
Write a trigger to check that when salary is updated (for an existing faculty) the
raise is not over 10%.
*/



/*
O:
Write a function to format a number (9, 2) to $9,999,999.99. 
Use this function in a SQL statement for displaying a faculty member's salary.
*/
CREATE [OR REPLACE] FUNCTION NUM_FORMAT 
 (F_SALARY IN NUMBER)
 RETURN VARCHAR2 AS 
BEGIN
DECLARE a_salary VARCHAR2 (100);

BEGIN
  SELECT to_char(f_salary, '$9,999,999.99') INTO a_salary FROM dual;
		RETURN a_salary;
END FUNCTION1;
END;



/*
***********************************
*             PART C              *
***********************************
*/

/*
P: 
List all faculty who earn $90,000 or over.
*/

VAR myQuery=
FROM f IN Faculty
WHERE f.FSalary>=90000
SELECT f;
myQuery.DUMP();



/*
Q: 
List all courses that have MIS in their course number.
*/
VAR myQuery=
	FROM c IN Course
	WHERE c.CourseNo.Contains("MIS")
	SELECT c;
myQuery.DUMP(); 

/*
R:
List all faculty and their location details.
*/
VAR myQuery=
	FROM f IN Faculty JOIN l IN Locations
	ON f.LocID equal l.LocID
	SELECT NEW{ Current = f, Previous =l};
myQuery.DUMP(); 





/*
***********************************
*             PART D              *
***********************************
*/

/*
Use the code provided in NoSQL.txt to create a collection of nine rows called 
hobbits.  
Now write MapReduce code to generate a report based on the gender and total 
cash.  (e.g. – for the female gender the total cash will be 99999 (some value))  
Include both code and the report generated in your printed work. 
Place the code in script file as well.   
