# Write your MySQL query statement below

select distinct L1.Num as ConsecutiveNums 
from Logs as L1
join Logs L2 on L2.Id = L1.Id + 1 
join Logs L3 on L3.Id = L1.Id + 2
where L1.Num = L2.Num and L2.Num = L3.Num ; 


/*
感觉有点奇怪， where 后面使用连等 L1.Num = L2.Num = L3.Num 不行， 但是 用and连接就可以.  
联结3个表。。。 
*/

# 另一种联结。。。 
select distinct L1.Num as ConsecutiveNums 
from Logs as L1, Logs as L2, Logs as L3 
where L2.Id = L1.Id + 1 and L3.Id = L1.Id + 2 and L1.Num = L2.Num and L2.Num = L3.Num ; 