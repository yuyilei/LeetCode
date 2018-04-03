# Write your MySQL query statement below

select class
from courses
group by class 
having count(distinct student) >= 5 ; 

/*
一个课堂中的学生可能会有重复，所以要用distinct。。
*/