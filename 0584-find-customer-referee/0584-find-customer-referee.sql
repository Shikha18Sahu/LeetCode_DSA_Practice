# Write your MySQL query statement below
-- Select name from Customer
-- where referee_id is NULL
--  or referee_id != 2


SELECT name
FROM Customer
WHERE IFNULL(referee_id, 0) <> 2;