# Write your MySQL query statement below
Select * 
from Users
where REGEXP_LIKE(mail, '^[A-Za-z][A-Za-z0-9-_.]*@leetcode\\.com$','c')