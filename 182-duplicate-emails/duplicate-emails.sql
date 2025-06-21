# Write your MySQL query statement below
select Email from Person GROUP BY Email  Having count(*)>1;