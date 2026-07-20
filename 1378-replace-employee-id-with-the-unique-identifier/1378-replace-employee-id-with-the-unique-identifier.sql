# Write your MySQL query statement below
Select u.unique_id, e.name
from Employees e
left join EmployeeUNI U
on e.id = u.id
