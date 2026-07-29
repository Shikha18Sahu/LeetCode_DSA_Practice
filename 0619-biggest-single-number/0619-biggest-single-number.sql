# Write your MySQL query statement below
Select max(num)as num
 from
(Select num
From MyNumbers
group by num
having count(num) = 1)
as unique_number