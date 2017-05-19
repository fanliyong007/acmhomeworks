create table t_xwh(quantity int,price int);
INSERT INTO t_xwh VALUE(3,50);
CREATE VIEW view_t_xwh AS SELECT quantity,price,quantity*price FROM t_xwh;
SELECT * FROM t_xwh;
SELECT * FROM view_t_xwh;
//1
CREATE VIEW stu_glass_xwh(id,name)
AS SELECT student_xwh.s_id,student_xwh.name,stu_info_xwh.class 
FROM student_xwh,stu_info_xwh
WHERE student_xwh.s_id=stu_info_xwh.s_id;
SELECT * FROM stu_info_xwh;
UPDATE view_t_xwh SET quantity=5;
SELECT * FROM view_t_xwh;
SELECT * FROM t_xwh;