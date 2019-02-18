/*============================================= Part A ===========================================================================*/
/*a.Write a query that will list the students who have completed 26 years. Display
their ages in completed years and in the order of decreasing age.*/

SELECT s.s_id , s.s_last,s.s_first,s.s_mi,s.s_address,s.s_city,s.s_state,s.s_zip,
s.s_phone,s.s_class,round((sysdate-s.s_dob)/365) as "age",s.s_pin,s.s_id,s.time_enrolled
FROM student s
where (sysdate-s.s_dob)/365>=26
order by s.s_dob asc;

/*b. Write a query that will list the total building capacity for every building. This list
(in the increasing order of the total capacity) should only contain the buildings
with a total building capacity of 100 or over.*/
select l.bldg_code , sum(l.capacity) as "total building capacity "
from location l
group by l.bldg_code 
having sum(l.capacity)>=100
order by l.bldg_code asc;


/*c. Write a query that will list all the students and their respective (faculty)
supervisors. Arrange your list in the order of faculty supervisors names.
*/

SELECT s.s_first ||','|| s.s_last as "Student Name", f.f_first ||','|| f.f_last as "Faculty supervisors"
FROM student s, faculty f
where s.f_id=f.f_id
order by f.f_last , f.f_first asc;

/*
d. Write a query that will list the faculty members who are located in the (LIB)rary
building.
*/

select f.f_first ||','|| f.f_last as "Faculty Members", l.bldg_code as "located"
from faculty f, location l
where f.LOC_ID=l.LOC_ID and l.bldg_code like '%LIB%'
order by f.f_last asc;

/*
e. Write a query that will list the students (along with their grade and course details)
who got at least B or better grade (i.e. B or A) in any of their courses.
*/

select s.s_first ||', '|| s.s_last as "Student Name", e.grade, c.course_no as "Course Number" ,c.course_name as "Course Details", c.credits
from student s, enrollment e, course_section cs, course c
where s.s_id=e.s_id and e.c_sec_id= cs.c_sec_id and cs.course_no=c.course_no and
e.grade like '%B%'or e.grade like '%A%'
GROUP BY s.s_first ||', '|| s.s_last, e.grade, c.course_no ,c.course_name, c.credits;

/*
f. Write a query that will list students who enrolled in the courses offered in the
terms Spring 2013 or Spring 2014. Do not display the duplicate student names.
*/

select s.s_first ||', '|| s.s_last as "Student Name"
from student s, enrollment e, course_section cs, term t
where s.s_id=e.s_id and e.c_sec_id=cs.c_sec_id and cs.term_id=t.term_id and t.term_desc like '%Spring 2013%' or t.term_desc like '%Spring 2014%'
group by s.s_first ||', '|| s.s_last;

select distinct s.s_first ||', '|| s.s_last as "Student Name"
from student s, enrollment e, course_section cs, term t
where s.s_id=e.s_id and e.c_sec_id=cs.c_sec_id and cs.term_id=t.term_id and t.term_desc like '%Spring 2013%' or t.term_desc like '%Spring 2014%'
;
/*
g. Write a query listing the details of the faculty member(s) who supervises the
highest number of students. Also display the highest number of supervised
students.
*/

select f.f_first ||', '|| f.f_last as "Faculty Members", count(*) as "Student amount"
from faculty f, student s
where f.f_id=s.f_id
group by f.f_first ||', '|| f.f_last
order by count(*) desc;


/*
h. Write a query that will list students enrolled with a total of 12 or more credit points
(in the decreasing order). Do not assume or hard code the value of the course
credits.
*/

select s.s_first ||', '|| s.s_last as "Student Name", sum(c.credits) as "total credits"
from student s, enrollment e, course_section cs, course c
where s.s_id=e.s_id and e.c_sec_id=cs.c_sec_id and cs.course_no=c.course_no and e.grade is not null 
group by s.s_first ||', '|| s.s_last
having sum(c.credits)>=12
order by sum(c.credits) desc;


/*
i. Write a query that will list student(s) enrolled with the maximum total credit
points.
*/
select s.s_first ||', '|| s.s_last as "Student Name"
from student s, enrollment e, course_section cs, term t
where s.s_id=e.s_id and e.c_sec_id=cs.c_sec_id and cs.term_id=t.term_id and t.term_desc like '%Spring 2013%' or t.term_desc like '%Spring 2014%'
group by s.s_first ||', '|| s.s_last;

select distinct s.s_first ||', '|| s.s_last as "Student Name"
from student s, enrollment e, course_section cs, term t
where s.s_id=e.s_id and e.c_sec_id=cs.c_sec_id and cs.term_id=t.term_id and t.term_desc like '%Spring 2013%' or t.term_desc like '%Spring 2014%'




/*

j. Write a query that lists all the courses (with their course names) and the course
sections that are offered either on a (M)onday or at least four times a week. Also
display the number of the days that the courses are offered (e.g. 5 days).
Note: In table Course_Section, the attribute c_sec_day lists weekdays, where the
first letter represents a weekday (e.g. M-Monday,....F-Friday; for Thursday R is
used). The course section weekdays are listed in the order M(onday) to (F)riday
i.e. Monday being the first. 
*/

select  distinct c.course_no,c.course_name as " Course Name", cs.c_sec_day as "Days taught", length(cs.c_sec_day) as "How many days per week"
from course_section cs, course c
where c.course_no= cs.course_no and cs.c_sec_day like '%M%' or length(cs.c_sec_day)>=4
group by c.course_no,c.course_name, cs.c_sec_day;


/*============================================= Part B ===========================================================================*/

/*k. Write two triggers one statement level and another row level. Display the
successful creation and running of the triggers. Please ensure that you also display
the relevant tables before and after (results of the trigger) the triggers are fired.
Remember to provide the equivalent English statements about your triggers’
purpose.*/


/* A trigger that checks if the age that is going to be inserted is greater 
than 16 as the student will be to young to join uni if he is not old enough*/

create or replace trigger row_level
before insert or update of s_dob
on student
for each row
declare 
no_dob_error exception;
begin 
if floor(months_between( sysdate, :new.s_dob ) / 12) < 16 then
DBMS_OUTPUT.PUT_LINE('Student cannot be less than 16 to enroll, therefore cannot update');
raise no_dob_error;
end if;

exception 
when no_dob_error then
raise_application_error(-20001,'cannot insert or update');
end ;


/* a trigger that fires a message when a new student is added, updated and deleted.*/
create or replace trigger stmt_level
after insert or update or delete on student
declare
begin 
if inserting then 
DBMS_OUTPUT.PUT_LINE('Student is being inserted');
elsif updating then
DBMS_OUTPUT.PUT_LINE('Student is being updated');
elsif deleting then 
DBMS_OUTPUT.PUT_LINE('Student is being deleted');
end if;
end;


/*
l. Write a trigger that does not allow more than two 'Full' ranked professors as part of
the faculty (For example, trigger should fire if a new (third) Full professor is added
or rank is updated to Full for one of the existing Associate professors.). Provide
comprehensive test data and results to confirm that the trigger works.*/

create or replace trigger profes_check
before insert or update of f_id, f_rank on faculty
FOR EACH ROW

DECLARE
  f_rank_count INT;
  f_rank_check char;
  TOO_MANY_FUll EXCEPTION;

BEGIN
  SELECT f_rank INTO f_rank_check FROM faculty WHERE f_rank= :NEW.f_rank;
  IF LOWER(f_rank_check) = 'Full'
  THEN 
    SELECT COUNT(faculty.f_rank) INTO f_rank_count FROM faculty WHERE faculty.f_rank= :NEW.f_rank;
    IF(f_rank_count > 2)
      THEN 
      DBMS_OUTPUT.PUT_LINE('Too Many Full');
      RAISE TOO_MANY_FULL;
    END IF;
  END IF;
    EXCEPTION
    WHEN TOO_MANY_FULL
    THEN RAISE_APPLICATION_ERROR(-20001, 'TOO MANY FULL!');
  END;


/*m. Write a procedure to insert a new faculty record. The procedure should also
automatically calculate the faculty salary value. This calculated salary is 20% less
than the average salary of the existing faculty members. Provide rest of the
attribute values as input parameters. Execute your procedure to insert at least one
faculty record.*/

create or replace PROCEDURE PRC_INSERT_FACULTY_RECORD(f_id in number, f_last in varchar2,
f_first in varchar2,f_mi in char,f_loc_id in number,f_phn in number,f_rnk in varchar2,
f_sup in number, f_pn in number, f_img in blob) AS
BEGIN
  DECLARE
    f_new_sal NUMBER(9,2);
  begin 
select avg(f_salary) *0.8 into f_new_sal  from FACULTY;
insert into FACULTY (F_ID ,
F_LAST,F_FIRST,F_MI,LOC_ID ,F_PHONE,F_RANK,F_SALARY,F_SUPER,F_PIN,F_IMAGE)
values( f_id,f_last,f_first,f_mi,f_loc_id,f_phn,f_rnk,f_new_sal,f_sup,f_pn,f_img);
end;
END;

/*set serveroutput on;
exec PRC_INSERT_FACULTY_RECORD(6,'Adeel','Cool','A',6,'0800','Full',null,4522,null);
select* from FACULTY;*/

/*n. Write a trigger to check that when salary is updated (for an existing faculty) the
raise is not over 10%.
*/



/*
o. Write a function to format a number (9, 2) to $9,999,999.99. Use this function in a
SQL statement for displaying a faculty member’s salary.*/
	create or replace FUNCTION NUM_FORMAT 
(
  F_SALARY IN NUMBER
) RETURN VARCHAR2 AS 
begin
declare a_salary varchar2(100);

BEGIN
  select to_char(f_salary, '$9,999,999.99') into a_salary from dual;
		return a_salary;
END FUNCTION1;
end;

--select num_format(f_salary) from faculty;
/*============================================= Part C ===========================================================================*/

/*p. List all faculty who earn 90,000 or over.*/

var myQuery=
	from f in Faculties
	where f.FSalary>=90000
	select f;
myQuery.Dump();



/*q. List all courses that have MIS in their course number.*/
var myQuery=
	from c in Faculties
	where c.CourseNo.Contains("MIS")
	select c;
myQuery.Dump(); 

/*r. List all faculty and their location details.*/
var myQuery=
	from f in Faculties join l in Locations
	on f.LocID equal l.LocID
	select new{ Current = f, Previous =l};
myQuery.Dump(); 




/*s. Display the total number of rooms in each building.*/

var myQuery =
	from l in Locations
	group l.Capacity by l.BldgCode into g
	orderby g.Key
	select new{
		bldgCode=g.Key,
		Capacity=g.Sum()
	};
	myQuery.Dump();

/*t. Display total number of students supervised by each faculty in the order of faculty
name*/



/*============================================= Part  D ===========================================================================*/

/*Use the code provided in NoSQL.txt to create a collection of eleven rows called
dragons.
Now write MapReduce code to generate a report based on the gender and average
weight.
(e.g. – for the female gender the average weight will be say 99.99 (some value))
Include both code and the report generated in your printed work. Place the code in
script file as well. */

> var map = function(){
   var key=this.gender;
   /*if (this.gender== "f")*/
     emit(key,this.weight);
 }
> var reduce = function(key,values){
  var sum=0;
  values.forEach(function(value){
     sum += value;
  });

   return sum / values.length;
 }

/*===============================Calling the map reduce===============================*/

db.dragons.mapReduce(
map,
reduce,
{out: "test3"}
);





