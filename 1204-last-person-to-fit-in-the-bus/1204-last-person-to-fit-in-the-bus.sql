# Write your MySQL query statement below
Select person_name 
from 
(Select person_name, 
turn , 
sum(weight)over(order by turn) as total_weight 
from queue) q 
where total_weight<=1000
order by turn desc
limit 1
