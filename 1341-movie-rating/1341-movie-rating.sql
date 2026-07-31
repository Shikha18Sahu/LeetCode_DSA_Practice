# Write your MySQL query statement below
(Select u.name as results
from Users u
inner join MovieRating mr
on mr.user_id = u.user_id
group by mr.user_id, u.name
order by count(mr.movie_id) desc, u.name asc
limit 1
)
UNION ALL
(
    Select m.title as results
    from Movies m
    join MovieRating mr
    on m.movie_id = mr.movie_id
    where mr.created_at between '2020-02-01' and '2020-02-29'
    group by m.movie_id, m.title
    order by avg(mr.rating) desc, m.title asc
    limit 1
)