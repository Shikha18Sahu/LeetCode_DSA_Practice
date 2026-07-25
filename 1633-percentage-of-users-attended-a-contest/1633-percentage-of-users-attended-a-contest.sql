# Write your MySQL query statement below
Select r.contest_id, round(count(r.contest_id)/(Select count(*) from Users) * 100 ,2) as percentage
from Register r
group by r.contest_id
order by percentage desc, r.contest_id 