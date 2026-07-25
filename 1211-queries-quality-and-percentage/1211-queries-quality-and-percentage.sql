# Write your MySQL query statement below
Select q.query_name, round(avg(q.rating/q.position),2)as quality, round(avg(if(rating<3, 1, 0)) * 100 ,2) as poor_query_percentage
From Queries q
group by q.query_name
