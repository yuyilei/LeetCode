/* 利用子查询，排除最大的元素 */
select max(Salary) as SecondHighestSalary 
from Employee 
where Salary != ( select max(Salary) from Employee ) ;