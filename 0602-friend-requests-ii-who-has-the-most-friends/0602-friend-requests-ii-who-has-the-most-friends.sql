# Write your MySQL query statement below
select result as id, 
count(*) as num
from 
(
    Select requester_id as result
from RequestAccepted 
union all
Select accepter_id as result
from RequestAccepted
) t
group by result
order by num desc
limit 1
