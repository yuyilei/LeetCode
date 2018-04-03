# Write your MySQL query statement below

select Request_at as 'Day', 
       round(sum(if(Status='completed',0,1))/count(*),2) as 'Cancellation Rate'
from 
    ( select *
      from Trips 
      where Client_id not in ( select Users_id from Users
                               where Banned = 'Yes' and Role = 'client' )
      and Request_at between '2013-10-01' and '2013-10-03'  ) as T 
group by Request_at 
order by Request_at ; 