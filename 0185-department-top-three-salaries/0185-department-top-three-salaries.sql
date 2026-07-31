# Write your MySQL query statement below
Select Department, 
Employee, 
Salary
from
(
    Select d.name as Department, 
e.name as Employee, 
salary as Salary, 
dense_rank()over(
    partition by e.departmentId 
     order by e.salary desc)
as salary_rank
from Employee e
 join Department d
on e.departmentId = d.id)
table_rank
where salary_rank <=3
