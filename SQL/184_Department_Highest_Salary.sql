# Write your MySQL query statement below

select Department.Name as Department, Employee.Name as Employee, Employee.Salary 
from Employee join Department 
on Employee.DepartmentId = Department.Id 
where (Department.Id, Employee.Salary) in ( select DepartmentId, max(Salary)
                                            from Employee 
                                            group by DepartmentID ) ; 
                                            