# Write your MySQL query statement below

select D.Name as Department, 
       E.Name as Employee, 
       E.Salary as Salary 
from Department as D 
    join Employee as E 
    on D.Id = E.DepartmentId 
where ( select count(distinct Salary) 
        from Employee 
        where DepartmentId = E.DepartmentId 
        and Salary > E.Salary ) < 3 ;   


/*
先查询出同一个部门中工资比某个人大的个数， 注意这里的前3名是工资的前3名，所以工资一样可以并列，所以计数时要加上distinct 
然后联结表，把少于3的都求出来 
*