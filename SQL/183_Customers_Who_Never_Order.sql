# Write your MySQL query statement below

select CC.Name as Customers 
from Customers as CC
where CC.Id not in (
            select C.Id 
            from Customers as C 
            join Orders as O 
            on C.Id = O.CustomerId ) ; 


# 其实不用在子查询中联结表的。。。。

select Name as Customers 
from Customers 
where Id not in ( select CustomerId from Orders ) ; 