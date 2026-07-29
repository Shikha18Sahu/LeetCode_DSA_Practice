# Write your MySQL query statement below
Select m.employee_id,
 m.name,
  count(e.employee_id) as reports_count ,
   round(avg(e.age))as average_age
From Employees m
join Employees e
on m.employee_id = e.reports_to
group by m.employee_id
order by m.employee_id
