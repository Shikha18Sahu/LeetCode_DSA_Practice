# Write your MySQL query statement below
Select id, 
case 
when id%2 = 0
then lag(student, 1) over(order by id)
else 
Coalesce(lead(student, 1) over(order by id), student)
end as student
From Seat
