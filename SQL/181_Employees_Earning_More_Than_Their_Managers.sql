# Write your MySQL query statement below

select E1.Name as Employee 
from Employee as E1 
join Employee as E2 
where E1.ManagerId = E2.Id and E1.Salary and E1.Salary > E2.Salary ; 