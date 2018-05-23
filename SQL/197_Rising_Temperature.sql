# Write your MySQL query statement below

select W2.Id as Id
from Weather as W1, Weather as W2 
where datediff(W2.Date,W1.Date) = 1 
    and W2.Temperature > W1.Temperature ;  

# DATEDIFF() 函数返回两个日期之间的天数。 