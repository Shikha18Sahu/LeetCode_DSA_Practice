# Write your MySQL query statement below
Select p1.product_name, 
 sum(p2.unit)as unit
from Products p1
join Orders p2
on p1.product_id = p2.product_id
where order_date between '2020-02-01' and '2020-02-29'
group by p1.product_id
having sum(p2.unit) >=100