# Write your MySQL query statement below
Select distinct num as ConsecutiveNums
from 
(Select num, 
Lead(num, 1)over(order by id) as sec, 
Lead(num, 2)over(order by id) as third
from Logs) t
where num = sec and sec= third